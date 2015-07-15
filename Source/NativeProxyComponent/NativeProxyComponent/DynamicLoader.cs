using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using JavaScriptCore;
using System.Runtime.InteropServices;
using System.Reflection;

namespace JavaScriptCore
{
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate void JSObjectInitializeCallback(int ctx, int obj);

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate void JSObjectFinalizeCallback(int obj);

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate int JSObjectGetPropertyCallback(int ctx, int obj, int propName, int exception);
    // returns ptr to JSValueRef

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate bool JSObjectSetPropertyCallback(int ctx, int thisObject, int propertyName, int value, int exception);

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate int JSObjectCallAsFunctionCallback(int ctx, int func, int thisObject, int argumentCount, [MarshalAs(UnmanagedType.LPArray)]int[] arguments, int exception);
    // returns ptr to JSValueRef

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate int JSObjectCallAsConstructorCallback(int ctx, int constructor, int argumentCount, [MarshalAs(UnmanagedType.LPArray)]int[] arguments, int exception);
    // returns ptr to JSObjectRef

    [StructLayout(LayoutKind.Sequential, Pack = 1, CharSet = CharSet.Unicode)]
    public struct JSClassDefinitionStruct
    {
        public Int32 version;
        public UInt32 attributes;
        [MarshalAs(UnmanagedType.LPWStr)]
        public string className;
        public IntPtr parentClass;
        public IntPtr staticValues;
        public IntPtr staticFunctions;
        public IntPtr initialize;
        public IntPtr finalize;
        public IntPtr hasProperty;
        public IntPtr getProperty;
        public IntPtr setProperty;
        public IntPtr deleteProperty;
        public IntPtr getPropertyNames;
        public IntPtr callAsFunction;
        public IntPtr callAsConstructor;
        public IntPtr hasInstance;
        public IntPtr convertToType;
    };
}

namespace NativeProxyComponent
{
    /**
     * This class is intended to be a wrapper around a nive type that bridges to JS. 
     **/
    public sealed class NativeTypeWrapper
    {
        private Type type;
        private JSClassRef jsClassRef;

        public NativeTypeWrapper(Type type)
        {
            this.type = type;
        }

        // When called as a constructor, instantiate instance of native type and wrap it
        public int CallAsConstructor(int ctxi, int constructor, int argumentCount, int[] arguments, int exceptionPtr)
        {
            JSContextRef ctx = new JSContextRef(ctxi);

            // Instantiate an instance of the type. Assume it has a public constructor with no args!
            var typeInfo = type.GetTypeInfo();
            var constructors = typeInfo.DeclaredConstructors;
            var constr = constructors.ElementAt(0);
            var nativeObject = constr.Invoke(null);

            // Now wrap the native instance in a JS instance
            var instance = DynamicLoader.instantiate(ctx, nativeObject, getJSClass());

            // return pointer to the instance
            return instance.GetNativePointerAsInt();
        }

        // When asked for property, dynamically look it up!
        public int GetProperty(int ctxi, int objecti, int propNamei, int exceptionPtr)
        {
            JSContextRef ctx = new JSContextRef(ctxi);
            JSObjectRef obj = new JSObjectRef(objecti);
            JSStringRef propName = new JSStringRef(propNamei);
            var propNameStr = JS.JSStringGetUTF8PlatformString(propName);
            var typeInfo = type.GetTypeInfo();

            // FIXME We need to look up whether the prop is a method or a field/property!
            var method = typeInfo.GetDeclaredMethod(propNameStr);
            if (method != null)
            {
                // TODO Now we need to create a method which converts args between JS and Native for the function call!
                // Create a pointer to that delegate and use that as the callback!
                JSObjectCallAsFunctionCallback callAsFunc = delegate(int ctxi2, int funci, int thisObjecti, int argumentCount, int[] argumentsi, int exceptionPtr2)
                {
                    JSObjectRef thisObj = new JSObjectRef(thisObjecti);
                    var nativeObject = DynamicLoader.Unwrap(thisObj);

                    JSContextRef ctx2 = new JSContextRef(ctxi2);

                    // Now invoke the method on "this"
                    // TODO Convert arguments, then call native method!
                    var returnValue = method.Invoke(nativeObject, new Object[] { });
                    return DynamicLoader.Convert(returnValue, ctx2);
                };
                IntPtr callAsFunction_ptr = System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate(callAsFunc);
                DynamicLoader.Retain(callAsFunction_ptr, method);
                var funcObject = JS.JSObjectMakeFunctionWithCallback(ctx, propName, callAsFunction_ptr.ToInt32());
                return funcObject.GetNativePointerAsInt();
            }
            else
            {
                var prop = typeInfo.GetDeclaredProperty(propNameStr);
                // Unwrap "this" to it's native object, then get the value of the named property on that object
                var propValue = prop.GetValue(DynamicLoader.Unwrap(obj));
                // Now convert the native value to a JSValueRef pointer
                return DynamicLoader.Convert(propValue, ctx);
            }
        }

        public bool SetProperty(int ctxi, int thisObjecti, int propertyNamei, int valuei, int exceptioni)
        {
            JSContextRef ctx = new JSContextRef(ctxi);
            JSObjectRef thisObj = new JSObjectRef(thisObjecti);
            var nativeObject = DynamicLoader.Unwrap(thisObj);
            JSStringRef propName = new JSStringRef(propertyNamei);
            var propNameStr = JS.JSStringGetUTF8PlatformString(propName);
            var typeInfo = type.GetTypeInfo();

            var exc = JS.JSValueMakeNull(ctx);
            JSValueRef value = new JSValueRef(valuei);
            var prop = typeInfo.GetDeclaredProperty(propNameStr);
            var nativeValue = DynamicLoader.Convert(prop.GetType(), value, ctx);
            prop.SetValue(nativeObject, nativeValue);
            return true;
        }


        public JSClassRef getJSClass()
        {
            if (jsClassRef != null)
            {
                return jsClassRef;
            }
            // Generate a JSClass definition for JSC!
            JSClassDefinitionStruct def = new JSClassDefinitionStruct();
            def.className = type.Name;

            IntPtr callAsConstructor_ptr = System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate(new JSObjectCallAsConstructorCallback(CallAsConstructor));
            def.callAsConstructor = callAsConstructor_ptr;

            IntPtr getProperty_ptr = System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate(new JSObjectGetPropertyCallback(GetProperty));
            def.getProperty = getProperty_ptr;

            IntPtr setProperty_ptr = System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate(new JSObjectSetPropertyCallback(SetProperty));
            def.setProperty = setProperty_ptr;

            IntPtr addr = Marshal.AllocHGlobal(Marshal.SizeOf<JSClassDefinitionStruct>());
            Marshal.StructureToPtr<JSClassDefinitionStruct>(def, addr, false);

            var jsClassDef = new JavaScriptCore.JSClassDefinition(addr.ToInt32());
            jsClassRef = JS.JSClassCreate(jsClassDef);
            return jsClassRef;
        }
    }

    public sealed class DynamicLoader
    {
        /**
         * A single global ptr holder. This holds ptr values as keys and the native objects/methods/etc as values.
         * This is a way to ensure that the object doesn't get GC'd and we can manage their lifecycles on the C#/CLR side.
         **/
        private static Dictionary<IntPtr, Object> objectCache = new Dictionary<IntPtr, Object>();

        DynamicLoader()
        {

        }

        public static int Convert(Object nativeObject, JSContextRef ctx)
        {
            // TODO Convert the native object to a JSValueRef and return pointer to it!
            var undef = JS.JSValueMakeUndefined(ctx);
            return undef.GetNativePointerAsInt();
        }

        public static Object Convert(Type nativeType, JSValueRef jsValue, JSContextRef ctx)
        {
            // Convert the JS value to native value!
            if (JS.JSValueIsNumber(ctx, jsValue))
            {
                var exc = JS.JSValueMakeNull(ctx);
                return JS.JSValueToNumber(ctx, jsValue, exc);
            }
            if (JS.JSValueIsBoolean(ctx, jsValue))
            {
                return JS.JSValueToBoolean(ctx, jsValue);
            }
            if (JS.JSValueIsString(ctx, jsValue))
            {
                var exc = JS.JSValueMakeNull(ctx);
                return JS.JSValueToString(ctx, jsValue, exc);
            }
            if (JS.JSValueIsNull(ctx, jsValue) || JS.JSValueIsUndefined(ctx, jsValue))
            {
                return null;
            }
            if (JS.JSValueIsObject(ctx, jsValue))
            {
                var exc = JS.JSValueMakeNull(ctx);
                // Unwrap the native object
                // FIXME What if it's not a native wrapper?!
                return Unwrap(JS.JSValueToObject(ctx, jsValue, exc));
            }
            return jsValue;
        }

        public static void Retain(IntPtr ptr, Object obj)
        {
            objectCache.Add(ptr, obj);
        }

        public static void Release(IntPtr ptr)
        {
            JS.ReleaseObjectKey(ptr.ToInt32());
            objectCache.Remove(ptr);
        }

        public static JSObjectRef instantiate(JSContextRef context, Object nativeObject, JSClassRef jsClass)
        {
            // Generate a ptr for the native object we'll wrap
            IntPtr instancePtr = (IntPtr)JS.CreateNewObjectKey();
            Retain(instancePtr, nativeObject);
            // instantiate an instance of the JSClass with private data holding pointer to native object
            return JS.JSObjectMake(context, jsClass, instancePtr.ToInt32());
        }

        public static Object Unwrap(JSObjectRef objectRef)
        {
            return objectCache[objectRef.GetNativePointer()];
        }

        void Register(TitaniumWindows.Application app)
        {
            app.TitaniumModuleNames += OnTitaniumModuleNames;
            app.TitaniumModulePreload += OnTitaniumModulePreload;
            app.TitaniumModuleRequire += OnTitaniumModuleRequire;
        }

        int OnTitaniumModulePreload(int js_context_ref)
        {
            // TODO "Pre-load" native types into the system?
            return IntPtr.Zero.ToInt32();
        }

        int OnTitaniumModuleRequire(int js_context_ref, String moduleId)
        {
            var context = new JSContextRef(js_context_ref);
            JSValueRef exception = JS.JSValueMakeNull(context);

            // Load up the type using reflection
            Type type = System.Type.GetType(moduleId);
            // TODO If the type doesn't exist, what do we do? Return pointer to undefined?

            var wrapper = new NativeTypeWrapper(type);
            var jsClassRef = wrapper.getJSClass();

            // Create an instance of the class
            IntPtr newObjectKey = (IntPtr)JS.CreateNewObjectKey();
            var typeJSClass = JS.JSObjectMake(context, jsClassRef, newObjectKey.ToInt32());

            return typeJSClass.GetNativePointerAsInt();
        }

        IList<String> OnTitaniumModuleNames(int jsContextRef)
        {
            // TODO Return a list of the modules we can load?
            //// TODO: Insert supported module names here
            var names = new List<String>();
            names.Add("Windows.UI.Xaml.Window");
            names.Add("Windows.UI.Xaml.TextBlock");
            return names;
        }
    }
}

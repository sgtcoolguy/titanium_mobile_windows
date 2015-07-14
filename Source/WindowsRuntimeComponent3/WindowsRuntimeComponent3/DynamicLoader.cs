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

namespace WindowsRuntimeComponent3
{
    public sealed class DynamicLoader
    {

        DynamicLoader()
        {

        }

		void Register(TitaniumWindows.Application app) {
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
            
            // TODO Now we need to wrap the loaded type up in some special JSClass we define which know hows to look up properties based on reflection
            // And can construct instances/etc

            // TODO Register the object we generated in the full namespace off the global!
            var global = JS.JSContextGetGlobalObject(context);
            //JS.JSObjectSetProperty(context, global, propName, value, attributes, exception);

            // Generate a JSClass definition for JSC!
            JSClassDefinitionStruct def = new JSClassDefinitionStruct();
            // TODO We need to generate some special proxy class that can consult the metadata about the properties/functions it has!
            // We can have it set getProperty to do dynamic lookup of properties in metadata...
            def.className = "MyFakeName"; // FIXME Last segment of the moduleId?

            // TODO Set up the function pointers for getProperty/call as constructor/etc
            //IntPtr getProperty_ptr = System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate(jsObjectSetBackgroundColorCallAsFunctionCallback);
            //def.getProperty = getProperty_ptr;
            //new JSObjectCallAsFunctionCallback();
            // new JSObjectInitializeCallback();

            JSObjectCallAsConstructorCallback d = delegate(int ctxi, int constructor, int argumentCount, int[] arguments, int exceptionPtr)
            {
                JSContextRef ctx = new JSContextRef(ctxi);
                var typeInfo = type.GetTypeInfo();
                var constructors = typeInfo.DeclaredConstructors;
                var constr = constructors.ElementAt(0);
                var nativeObject = constr.Invoke(null);
                IntPtr instancePtr = (IntPtr) JS.CreateNewObjectKey();
                // TODO Store the object and key in some map!
                //var objectRef = new JSObjectRef(constructor);
                
                var instance = JS.JSObjectMake(ctx, jsClassRef, instancePtr.ToInt32());
                return instance.GetNativePointerAsInt();
           };

           IntPtr addr = Marshal.AllocHGlobal(Marshal.SizeOf<JSClassDefinitionStruct>());
           Marshal.StructureToPtr<JSClassDefinitionStruct>(def, addr, false);

           var jsClassDef = new JavaScriptCore.JSClassDefinition(addr.ToInt32());
           var jsClassRef = JS.JSClassCreate(jsClassDef);

           // Create an instance of the class
           IntPtr newObjectKey = (IntPtr) JS.CreateNewObjectKey();
           // TODO Store the native object/type in some map here by the newObjectKey
           var typeJSClass = JS.JSObjectMake(context, jsClassRef, newObjectKey.ToInt32());

           return typeJSClass.GetNativePointerAsInt();
        }

        IList<String> OnTitaniumModuleNames(int jsContextRef)
        {
            // TODO Return a list of the modules we can load?
            //// TODO: Insert supported module names here
            //// names->Append("com.example.test");
            //// names->Append("Windows.UI.Xaml.Controls.Button");
            //// names->Append("Windows.UI.Xaml.Controls.ListView");
            return null;
        }
    }
}

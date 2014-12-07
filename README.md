[![Build Status](https://magnum.travis-ci.com/appcelerator/titanium_mobile_windows.svg?token=SxTZxbWRYYpcfE9jALXb&branch=master)](https://magnum.travis-ci.com/appcelerator/titanium_mobile_windows)

# Titanium Mobile Windows

Titanium Mobile Windows is the Titanium platform support for the
latest Microsoft Windows 8.1 and Windows Phone 8.1 platform.

## Folders and Files

Source/Titanium/ - cpp source files that make up the Windows Titanium
SDK

Examples/Touches/ - our reference Touche app that links against the Titanium SDK.

test/apps - small focused apps to test platform features

test/unit - platform specific unit tests

## Prerequisites

### Windows

Step 1. Install Visual Studio 2013

Step 2. Install this version of [CMake](https://cmakems.codeplex.com/releases/view/126914) in order to generate VS 2013 project files.

Step 3. Install [64-bit Cygwin](http://cygwin.com/setup-x86_64.exe).

* Choose the mirror http://mirrors.kernel.org which we have measured is at least 100x faster than the default selected mirror.
* Select both ```curl``` and ```unzip``` in addition to the defaults.

Step 4. Install JavascriptCore

Download our pre-compiled version of JavascriptCore [JavaScriptCore-Windows-1411436814.zip (276 MB)](http://timobile.appcelerator.com.s3.amazonaws.com/jscore/JavaScriptCore-Windows-1411436814.zip), unzip anywhere (the location doesn't matter) and set the environment variable JavaScriptCore_HOME to where you unzipped it.

Just run the following commands from your Cygwin bash prompt to setup your development environment for JavaScriptCore_HOME before
proceeding:

```bash
$ curl -O http://timobile.appcelerator.com.s3.amazonaws.com/jscore/JavaScriptCore-Windows-1411436814.zip
$ unzip JavaScriptCore-Windows-1411436814.zip
```

step 5. Install Google Test

Download our pre-compiled version of Google Test [gtest-1.7.0-windows.zip (3 MB)](http://timobile.appcelerator.com.s3.amazonaws.com/gtest-1.7.0-windows.zip), unzip anywhere (the location doesn't matter) and set the environment variable GTEST_ROOT to where you unzipped it.

Just run the following commands from your Cygwin bash prompt to setup your development environment for Google Test before proceeding:

```bash
$ curl -O http://timobile.appcelerator.com.s3.amazonaws.com/gtest-1.7.0-windows.zip
$ unzip gtest-1.7.0-windows.zip
```

Step 6. Install Boost

Microsoft officially supports and encourages the use of the Boost C++ open source library for Windows Store and Windows Phone apps, and they have contributed a great deal of open source code to the Boost project. Please read the Microsoft article [Using Boost Libraries in Windows Store and Phone Applications](http://blogs.msdn.com/b/vcblog/archive/2014/07/18/using-boost-libraries-in-windows-store-and-phone-applications.aspx) and follow their instructions.

Microsoft instructs us to create the folders named WPSDK\WP81 under the VC Visual Studio installation directory, `C:\Program Files
(x86)\Microsoft Visual Studio 12.0\VC\`, and copy their [phone setup script files](http://blogs.msdn.com/cfs-file.ashx/__key/communityserver-components-postattachments/00-10-54-33-32/BoostSample-.zip) to it. This has been verified to work well with our CMake build infrastructure.

After following Microsoft's instructions, define the environment variable `BOOST_ROOT` to point to where you cloned the boost git repository and add it to your `PATH`. If you are using PowerShell something like the following works:
```
setx.exe BOOST_ROOT $env:HOME\Documents\GitHub\boost
$env:Path += ";$env:BOOST_ROOT";
cd $env:BOOST_ROOT\libs\thread\build
b2 toolset=msvc-12.0 link=static windows-api=store
b2 toolset=msvc-12.0 link=static windows-api=phone
```

Step 7. Install SQLite

Download our pre-compiled version of SQLite [SQLite-Windows-1415143965334.zip (8 MB)](http://timobile.appcelerator.com.s3.amazonaws.com/SQLite-Windows-1415143965334.zip), unzip anywhere (the location doesn't matter) and set the environment variable SQLite_HOME to where you unzipped it.

Just run the following commands from your Cygwin bash prompt to setup your development environment for SQLite_HOME before proceeding:

```bash
$ curl -O http://timobile.appcelerator.com.s3.amazonaws.com/SQLite-Windows-1415143965334.zip
$ unzip SQLite-Windows-1415143965334.zip
```

### OS X

Step 1. Install Xcode 6

Step 2. Install cmake using either `sudo port install cmake` or `sudo brew install cmake`.

Step 3. Install boost using either `sudo port install boost` or `sudo brew install boost`.

Step 4. Download our pre-compiled version of Google Test [gtest-1.7.0-osx.zip (3 MB)](http://timobile.appcelerator.com.s3.amazonaws.com/gtest-1.7.0-osx.zip), unzip anywhere (the location doesn't matter) and set the environment variable GTEST_ROOT to where you unzipped it.

Just run the following commands from your bash prompt to setup your development environment for Google Test before proceeding:

```bash
$ curl -O http://timobile.appcelerator.com.s3.amazonaws.com/gtest-1.7.0-osx.zip
$ unzip gtest-1.7.0-osx.zip
```

## Getting Started

After installing the prerequisites you should try to build our
reference app from Pedro. We recommend performing out-of-source builds,
so to do this run the script Scripts/generate_vs_project.sh from any
directory of your choosing as long as it is not within the
titanium_mobile_windows git repo. A good place might be
`C:\Users\<user name>\Documents\Visual Studio 2013`. For example:

```bash
pushd "${HOME}/Documents/Visual Studio 2013/"
"${HOME}/Documents/GitHub/titanium_mobile_windows/Tools/Scripts/generate_vs_project.sh" Pedro
cygstart Pedro.WindowsPhone.Win32/Pedro.sln
```

### Windows Proxy Objects

If you have been involved with Titanium SDK you have probably heard
the term proxy object. Basically, a proxy is a special JavaScript
object which is a stand-in for a corresponding object in native code.

Titanium uses a factory pattern to create objects so from JavaScript
methods like `Ti.UI.createView()` will create a proxy object. Object
methods and properties are added during creation. The sample below
illustrates creating a proxy object.

Currently we are using the JavaScriptCore runtime from WebKit to
execute the JavaScript application code. This may change in the future
so the code described might change but the basic pattern will
remain. All C based JavaScript runtime engines have similar APIs. A
reference to help with JavaScriptCore development can be had by
examining the public header files. The header files contain a
reasonable descriptions about how to use the JavaScriptCore C API. The
Installation Section below contains a link to the pre-built
JavaScriptCore library. Inside the zip file you will find the public
header files.

Code snippet that shows creating an object including functions and methods:
   
    JSClassDefinition classDefinition = kJSClassDefinitionEmpty;

    JSStaticValue StaticValueArray[] = {{ "top", GetTop, SetTop, kJSPropertyAttributeNone },
    JSClassDefinition classDefinition = kJSClassDefinitionEmpty;

    classDefinition.staticValues = StaticValueArray;
    JSStaticFunction StaticFunctionArray[] = {{ "setBackgroundColor", SetBackground, kJSPropertyAttributeNone },
    {0, 0, 0}};
    classDefinition.staticFunctions = StaticFunctionArray;

    JSClassRef clsRef = JSClassCreate(&classDefinition);

    PrivateObjectContainer* poc = new PrivateObjectContainer();
    Canvas^ nobj = ref new Canvas();
    poc->set(nobj);

    JSObjectRef classDef = JSObjectMake(ctx, clsRef, poc);

Here in the c++ proxy source file an object will be created and a
property and method is associated with the object. When the object's
property or method is called from JavaScript the exposed C or C++
method is called. It is in these calls from the JavaScript runtime
where we access the native Windows system. The signatures looks like:

    static bool SetTop(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, const JSValueRef value, JSValueRef* exception);
    static JSValueRef GetTop(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, JSValueRef* exception);

    static JSValueRef SetBackground(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

A private data object is created and associated with every proxy
object. The private object contains a pointer to the native object. In
the code above the object created is a proxy to the Windows Canvas
object. Since a pointer and access to the native object is always
available from the JavaScript objects it greatly simplifies much of
the code and makes the proxy cpp code stateless.

To ensure created proxy objects release memory and resourses when they
are no longer needed by the JavaScript runtime, during proxy
contruction a finializer method can be attached to the proxy. When the
JavaScript runtime does Garbage Collect the finalize method will be
called. The finalize method is added during project creation with
`classDefinition.finalize = classDestructor;` where class destructor
is the callback method.

    void titanium::UIPrototype::classDestructor(JSObjectRef object) {
	    void* raw = JSObjectGetPrivate(object);
	    reinterpret_cast<PrivateObjectContainer*>(raw)->clean();
	    delete reinterpret_cast<PrivateObjectContainer*>(raw);
    }


Under the Source/Titanium/ folder you will find the proxy source
code. Poking around in the cpp files is a good way to see how the
proxy code works.

The various proxies are all contained in the Titanium WinRT dll and in
the titanium c++ namespace. As we add support for native Market Place
modules we may change the namespaces and packaging a bit.

### Developing Proxy Objects

Now that we know what a Windows proxy object is how do we build one?
Under the dev folder in this repo is a Visual Studio solution
file. Opening this file you will see 2 projects. One is called app and
is simply used during proxy development to launch and run the Titanium
application. The second project is titanium. In titanium is where the
proxies live and the SDK developer spends most of their time.

### Booting Up

When the application is run a reference to the Titanium WinRT dll
causes the Titanium dll to load and the overridden
Application.OnLaunched method is called. You can find the method in
the TiApp.cpp file and class. It is here that a minimal amount of
JavaScript runtime initialization is done. It basically creates the
Titanium UI object and sets an alias to Ti. Now the JavaScript
developer code is loaded (typically app.js) and code like `var win =
Ti.UI.createdWindow();' can be executed.


## Installation

## Contributing

Titanium is an open source project.  Titanium wouldn't be where it is
now without contributions by the community. Please consider forking
this repo to improve, enhance or fix issues. If you feel like the
community will benefit from your fork, please open a pull request.

To protect the interests of the Titanium contributors, Appcelerator,
customers and end users we require contributors to sign a Contributors
License Agreement (CLA) before we pull the changes into the main
repository. Our CLA is simple and straightforward - it requires that
the contributions you make to any Appcelerator open source project are
properly licensed and that you have the legal authority to make those
changes. This helps us significantly reduce future legal risk for
everyone involved. It is easy, helps everyone, takes only a few
minutes, and only needs to be completed once.

[You can digitally sign the CLA](http://bit.ly/app_cla) online. Please
indicate your email address in your first pull request so that we can
make sure that will locate your CLA.  Once you've submitted it, you no
longer need to send one for subsequent submissions.


## Legal

Titanium Mobile Windows is developed by Appcelerator and the community
and is Copyright (c) 2012-2014 by Appcelerator, Inc. All Rights
Reserved.

Titanium Mobile Windows is made available under the Apache Public
License, version 2.  See the
[LICENSE](https://github.com/appcelerator/titanium_mobile_windows/blob/master/LICENSE)
file for more information.

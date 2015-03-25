[![Build Status](http://studio-jenkins.appcelerator.org/buildStatus/icon?job=titanium_mobile_windows)](http://studio-jenkins.appcelerator.org/job/titanium_mobile_windows/)

# Titanium Mobile Windows

Titanium Mobile Windows is the Titanium platform support for the Microsoft Windows 8.1 Store and Phone platforms.

## Prerequisites

```bash
git clone https://github.com/appcelerator/titanium_mobile_windows.git
pushd titanium_mobile_windows
git submodule init
git submodule update
```

### Windows

Step 1. Install [Visual Studio 2013 Update 4 (or higher)](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx) - Community, Professional, Premium or Ultimate. *Not* Express.

Step 2. Install [Node](https://nodejs.org/download/).

Step 3. Run the setup.js Node script included in this repository in cmd.exe or Powershell:
```bash
cd Tools\Scripts
npm install .
node setup.js
```

The script should download any necessary development libraries and set the appropriate environment variables for you. Once set up, you may proceed to [Getting Started](#getting-started) section to generate an example app to use as a development base.

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

Please note that while you may do HAL and TitaniumKit builds and development work on the mac, you will not be able to do any Windows Platform development or generate apps/examples (as documented in [Getting Started](#getting-started)).

## Getting Started

After installing the prerequisites you should try to build our
reference app NG. We recommend performing out-of-source builds,
so to do this run the script Scripts/generate_project.js from any
directory of your choosing as long as it is not within the
titanium_mobile_windows git repo. A good place might be
`C:\Users\<user name>\Documents`. For example:

```bash
# If you have not yet run the following from the prerequisite installation steps above, please do:
cd Tools\Scripts
npm install .
# Now go to directory where you'd like project generated
cd "${HOME}/Documents"
# Generates a project from our included NG example
node "${HOME}/Documents/GitHub/titanium_mobile_windows/Tools/Scripts/generate_project.js" new NG
# Now open the project in Visual Studio for development
NG.WindowsPhone.Win32/NG.sln
```

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
and is Copyright (c) 2012-2015 by Appcelerator, Inc. All Rights
Reserved.

Titanium Mobile Windows is made available under the Apache Public
License, version 2.  See the
[LICENSE](https://github.com/appcelerator/titanium_mobile_windows/blob/master/LICENSE)
file for more information.


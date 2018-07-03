# Dynamixel SDK

There are (2) codebases I could use to control the dynamixel:

1. https://github.com/ROBOTIS-GIT/DynamixelSDK
   This is the SDK for the actual dynamixel servos.

2. https://github.com/Xevel/usb2ax
   This is a (last updated 2015) library for using the USB2AX 3.2b TTL device to
   control the dynamixel.

I decided to go with the second. I don't need cross-platform compatibility and
the source code for usb2ax was really readable. I converted the build to use
bazel too, which would have been slightly more difficult with the dynamixel SDK.

In the future if I need more functionality I should definitely grab the official
Dynamixel SDK and import it.

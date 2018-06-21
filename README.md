# 3D Lidar with RP Lidar

This is Sam's attempt to turn the RPLidar A1 into a 3D lidar by mounting it and
syncing sweep collections with the angle of the controlling servo.

## RP Lidar Library On Bazel

Unfortuantely the RPLidar build process uses makefiles and I hate them. So I'm
re-implementing their code's build process using Bazel. Hopefully by reading
their make files I can understand what the dependencies are...

## Status

Doesn't work yet. Seems like some of the headers (at a minimum `rplidar_cmd.h`,
`rplidar_driver.h`,  `rplidar.h`,  `rplidar_protocol.h`, `rptypes.h` -- possibly
all of them) are pure C and not C++, written in C99 standard. So when we try to
compile with Bazel it chokes and complains that the code is wrong (it's trying
to compile as C++).

I tried `bazel build --copt='-std=gnu99' -c opt :all` but it says the std flag
is only valid for C/objective C. And all my code is being interpreted as C++
:(

I suspect one solution might be to rename all the headers with `.c` as the
extension to indicate they are C files. No idea if that'll work.

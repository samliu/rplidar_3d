# 3D Lidar with RP Lidar

This is Sam's attempt to turn the RPLidar A1 into a 3D lidar by mounting it and
syncing sweep collections with the angle of the controlling servo.

## RP Lidar Library On Bazel

Unfortuantely the RPLidar build process uses makefiles and I hate them. So I'm
re-implementing their code's build process using Bazel. Hopefully by reading
their make files I can understand what the dependencies are...

## Build

~~~bash
bazel build main:all
~~~

## Usage

`sudo ./bazel-bin/main/collect_sweeps_main /dev/ttyUSB0`

# 3D Lidar with RP Lidar

This is my attempt to turn the RPLidar A1 into a 3D lidar by mounting it and
syncing sweep collections with the angle of the controlling servo.

## RP Lidar Library On Bazel

Unfortuantely the RPLidar SDK build process used makefiles and I hate them. So I re-implemented the entire build using Google's awesome Bazel library. In doing so I identified some random things (e.g circular dependencies, C99 mixed with C++ libraries, etc). It was nice to get all that untangled; now if you want to just use RPLidar's SDK from this repo that's OK too, it's all under `rplidar_lib`. I ran all the code through clang-format as well.

## Build

~~~bash
bazel build main:all
~~~

## Usage

The following binary collects 2D scans:

`sudo ./bazel-bin/main/collect_sweeps_main /dev/ttyUSB0`

It doesn't do anything 3D yet though. We need to add a separate binary that controls a servo and collects a round of scans per theta.

## Dev Roadmap

- [x] Make RPLidar SDK build with bazel.
- [ ] Decide 3d point data format.
- [ ] Modify scan collector to take a file to which it'll output and write scans to it.
- [ ] Write a simple 3D point cloud visualizer.
- [ ] Write C++ code to control servo (maybe Dynamixel Ax-12).
- [ ] Write class to simultaneously turn servo and collect sweeps.

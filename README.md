# 3D Lidar with RP Lidar

This is my attempt to turn the RPLidar A2 into a 3D lidar by mounting it and
syncing sweep collections with the angle of the controlling servo.

## Hermetic Build using Bazel

Unfortuantely the RPLidar SDK build process used makefiles and I hate them. So I
re-implemented the entire build using Google's awesome Bazel library. In doing
so I identified some random things (e.g circular dependencies, C99 mixed with
C++ libraries, etc). It was nice to get all that untangled; now if you want to
just use RPLidar's SDK from this repo that's OK too, it's all under
`rplidar_lib`. I ran all the code through clang-format as well.

I did similar with the USB2AX library.

I totally could have generated dynamically linked shared objects by adding a
genrule that leveraged each native import's build, but I wanted to understand
exactly what I was adding and not add some shitty nondeterminism for days down
the road when I want to rebuild this thing and forgot how everything fits
together.

## Installation

Some minor requirements

* Expects Google's Abseil common libraries source to be at
  `/opt/cpp/abseil-cpp`. Feel free to change this in the `WORKSPACE` file.

## Build

~~~bash
bazel build main:all
~~~

## Usage

The following binary collects 2D scans:

`sudo ./bazel-bin/main/collect_sweeps_main /dev/ttyUSB0`

It doesn't do anything 3D yet though. We need to add a separate binary that
controls a servo and collects a round of scans per theta.

## Dev Roadmap

- [x] Make RPLidar SDK build with bazel.
- [ ] Write C++ code to control servo (Dynamixel Ax-12).
- [ ] Write a scan collector.
- [ ] Write IMU code to get localization for each scan so that we can combine
      scans over time given movement; otherwise our point clouds won't make any
      sense.
- [ ] Decide 3d point data format.
- [ ] Modify scan collector to take a file to which it'll output and write scans to it.
- [ ] Write a simple 3D point cloud visualizer.
- [ ] Write class to simultaneously turn servo and collect sweeps.

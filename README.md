# CSE-Tactics

[![C/C++ CI](https://github.com/Cerulean-Shot-Entertainment/CSE-Tactics/actions/workflows/cpp.yml/badge.svg)](https://github.com/Cerulean-Shot-Entertainment/CSE-Tactics/actions/workflows/cpp.yml)
[![Gitpod ready-to-code](https://img.shields.io/badge/Gitpod-ready--to--code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/Cerulean-Shot-Entertainment/CSE-Tactics)

## Description

A turn based RPG in SDL2

## Building

You do not have to compile nor install SDL2 yourself, because the toolchain has a copy of SDL2 in tree

To cross compile, simply pass in `cmake . -DPLATFORM={os}-{arch}`

Supported archs:

- X86
- X64

Archs for Linux only:

- ARMHF
- ARMEABI

Supported Operating Systems:

- LINUX
- WINDOWS

Please note that this toolchain was meant to compile on GCC only

To cross compile from Linux to Windows, mingw-w64 needs to be installed

## Dependencies

The installation requirements are the same as building SDL2, along with cmake.

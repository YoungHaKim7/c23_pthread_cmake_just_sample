# C11~ C23까지 잘 정리됨.
- https://github.com/AnthonyCalandra/modern-c-features

# c23_pthread_cmake_just_sample

- [cmake Documentation](https://cmake.org/cmake/help/latest/index.html)
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [Clang Documentation](https://clang.llvm.org/docs/index.html)
- [justfile Documentation](https://just.systems/man/en/)

```bash
$ /opt/gcc-15/bin/gcc --version
gcc (GCC) 15.1.0
Copyright (C) 2025 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


$ /usr/bin/clang-20 --version
Ubuntu clang version 20.1.8 (++20250804090239+87f0227cb601-1~exp1~20250804210352.139)
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/lib/llvm-20/bin

$ cmake --version
cmake version 4.1.0

CMake suite maintained and supported by Kitware (kitware.com/cmake).

$ just --version
just 1.42.4

$ clang-format-20 --version
Ubuntu clang-format version 20.1.8 (++20250804090239+87f0227cb601-1~exp1~20250804210352.139)
```

# cmake build 잘 설명
- [(250828) CMake for the Impatient - Steve Love - C++ on Sea 2025 | cpponsea](https://youtu.be/t6iV5_plo20?si=hbBFRwxSQKOVlWET)
- [(250830) Post-Modern Cmake - From 3.0 to 4.0 - Vito Gamberini - C++Now 2025 | CppNow](https://youtu.be/K5Kg8TOTKjU?si=hbfYk_m2JjlpmXKg)
  - set명령에 command실행시 추가하는 방법
    - https://stackoverflow.com/questions/44284275/passing-compiler-options-in-cmake-command-line

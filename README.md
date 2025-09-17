# link


<hr />

# C23 wiki에 잘 정리됨.
- https://en.wikipedia.org/wiki/C23_(C_standard_revision)

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
- [(250804) How to Avoid Headaches with Simple CMake - Bret Brown - C++Now 2025 | CppNow](https://youtu.be/xNHKTdnn4fY?si=AKuMXfdIrpggll_P)
- [(250828) CMake for the Impatient - Steve Love - C++ on Sea 2025 | cpponsea](https://youtu.be/t6iV5_plo20?si=hbBFRwxSQKOVlWET)
- [(250830) Post-Modern Cmake - From 3.0 to 4.0 - Vito Gamberini - C++Now 2025 | CppNow](https://youtu.be/K5Kg8TOTKjU?si=hbfYk_m2JjlpmXKg)
  - set명령에 command실행시 추가하는 방법
    - https://stackoverflow.com/questions/44284275/passing-compiler-options-in-cmake-command-line
- [(250418) CMake 4 0: What You Need to Know | Kitware](https://youtu.be/TESpxsilA1k?si=LOCfjoLCeNLeOf3l)
- [(250215) import CMake; // Mastering C++ Modules - Bill Hoffman - CppCon 2024 | CppCon](https://youtu.be/7WK42YSfE9s?si=mmlQQDcx1F5Jb1fZ)
- CmakePresets.json
  - [(210507)CMakePresets.json 소개 | Microsoft Developer](https://youtu.be/NFbnm1t6Mc4?si=fEynkOaO6XlI1-EF)
    - CMakePresets.json은 CMake 3.19/3.20에서 CMake에 추가되었으며, 사용자가 일반적인 구성, 빌드 및 테스트 옵션을 다른 사용자와 공유할 수 있도록 합니다. Microsoft와 Kitware 담당자들이 CMakePresets.json과 이를 통해 해결하고자 하는 문제에 대해 논의하는 자리에 함께해 보세요. 또한 Visual Studio, Visual Studio Code 및 CLI에서 CMakePresets.json을 지원하는 방법을 시연합니다 



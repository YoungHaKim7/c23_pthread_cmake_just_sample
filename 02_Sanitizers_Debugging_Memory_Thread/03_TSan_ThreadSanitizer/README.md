# Result

```bash
FATAL: ThreadSanitizer: unexpected memory mapping 0x6317dab9c000-0x6317dab9d000

```


# Result

- tsan

```bash
$ just tsan
rm -rf target
mkdir -p target
/usr/bin/clang-20 -g -fsanitize=thread -fno-omit-frame-pointer -c ./src/main.c
/usr/bin/clang-20 -g -fsanitize=thread *.o
mv a.out *.o ./target
./target/a.out
Thread 1 done
==================
WARNING: ThreadSanitizer: data race (pid=10103)
  Write of size 4 at 0x5555569e8718 by thread T2:
    #0 worker /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/03_TSan_ThreadSanitizer/./src/main.c:10:16 (a.out+0xe89ca) (BuildId: a619a03e2b856d7871a18c353678dfeb3775e62b)

  Previous write of size 4 at 0x5555569e8718 by thread T1:
    #0 worker /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/03_TSan_ThreadSanitizer/./src/main.c:10:16 (a.out+0xe89ca) (BuildId: a619a03e2b856d7871a18c353678dfeb3775e62b)

  Location is global 'counter' of size 4 at 0x5555569e8718 (a.out+0x1494718)

  Thread T2 (tid=10106, running) created by main thread at:
    #0 pthread_create <null> (a.out+0x64aae) (BuildId: a619a03e2b856d7871a18c353678dfeb3775e62b)
    #1 main /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/03_TSan_ThreadSanitizer/./src/main.c:22:5 (a.out+0xe8a67) (BuildId: a619a03e2b856d7871a18c353678dfeb3775e62b)

  Thread T1 (tid=10105, running) created by main thread at:
    #0 pthread_create <null> (a.out+0x64aae) (BuildId: a619a03e2b856d7871a18c353678dfeb3775e62b)
    #1 main /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/03_TSan_ThreadSanitizer/./src/main.c:21:5 (a.out+0xe8a4f) (BuildId: a619a03e2b856d7871a18c353678dfeb3775e62b)

SUMMARY: ThreadSanitizer: data race /home/g/my_project/Rust_Lang/9999/2222/c23_pthread_cmake_just_sample/02_Sanitizers_Debugging_Memory_Thread/03_TSan_ThreadSanitizer/./src/main.c:10:16 in worker
==================
Thread 2 done
Counter = 1051611
ThreadSanitizer: reported 1 warnings
error: Recipe `tsan` failed on line 192 with exit code 66

```

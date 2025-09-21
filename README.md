# MAI OOP Labs
Homework for the OOP course at MAI

## Build
```Bash
git clone https://github.com/n3tw4lk3r/MAI-OOP-labs
cd MAI-OOP-labs
cmake -B build
cmake --build build
```

## Launch a particular homework (for instance, lab_1)
```Bash
./build/lab_1/lab_1
```
## Run tests for a particular homework
```Bash
ctest --test-dir build/lab_1
```
or 
```Bash
./build/lab_1/run_tests_lab_1
```
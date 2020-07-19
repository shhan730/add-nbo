# add-nbo

## Introduction

### 1. Overview

This project is to implement a adder program

This program adds two 32bit network byte order number regardless of Big or Little endian.

### 2. Usage Example & Testing

1. Makefile is provided use it to compile main.cpp

```bash
make
c++    -c -o main.o main.cpp
```

2. Test with sample files

```bash
./add-nbo thousand.bin five-hundred.bin
1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)
```

3. Make clean

```bash
make clean
rm -f *.o
```


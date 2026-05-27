# Analysis of Algorithms - Lab 07

This repository contains my C++ implementations for Lab 07. The assignment focuses on solving linear equations using Gaussian elimination and working with heap data structures.

## Lab Contents

There are four main programs in this lab:

1. **Forward Elimination** (`gelimination.cpp`): Transforms a system of linear equations into an upper triangular matrix.
2. **Backward Substitution** (`substitution.cpp`): Solves the upper triangular matrix to find the variables.
3. **Max-Heap** (`maxheap.cpp`): Transforms a random, unsorted array into a max-heap in place.
4. **LU Decomposition** (`LU.cpp`): Decomposes a matrix into lower and upper triangular matrices using Gaussian elimination.

## How to Compile and Run

The code is written in standard C++. You can compile it using `g++` in the terminal.

For example, to run the LU Decomposition program:

1. Compile the code:
   ```bash
   g++ -o Lu Lu.cpp

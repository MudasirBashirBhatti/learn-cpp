# Compilation and Execution in C++

Compilation and execution are two separate steps in running a C++
program.

## 1. Compilation

Compilation converts C++ source code (`.cpp`) into an executable
program.

``` bash
g++ cin.cpp -o cin
```

-   `g++` --- the C++ compiler
-   `cin.cpp` --- the source file
-   `-o cin` --- names the output executable `cin`

If the code has compilation errors, the executable will not be created
successfully.

## 2. Execution

After compilation succeeds, run the executable:

``` bash
./cin
```

In Git Bash, `./` means to run the executable from the current
directory.

## 3. Compile and execute in one command

``` bash
g++ cin.cpp -o cin && ./cin
```

The `&&` operator means the second command runs only if the first
command succeeds.

So:

1.  `g++ cin.cpp -o cin` --- compilation
2.  `./cin` --- execution

## Important

A C++ program needs a valid `main()` function as its entry point. If
`main()` is missing or commented out, linking can fail and no executable
will be produced.

Example:

``` cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, Programmer!" << endl;
    return 0;
}
```

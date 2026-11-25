# Understanding Compiler Errors in C++

Compiler errors are messages produced when the compiler cannot accept
your C++ source code. They usually indicate that the code violates C++
syntax, type rules, declarations, or other language requirements.

The goal is not to memorize every error message. Learn to read the
message, locate the problem, understand its cause, and fix the
underlying issue.

## 1. What is a compiler error?

Example:

``` cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World"
    return 0;
}
```

The semicolon is missing after `"Hello World"`.

A compiler may report:

``` text
error: expected ';' before 'return'
```

Correct version:

``` cpp
cout << "Hello World";
```

The reported line is where the compiler detected the problem. Sometimes
the actual mistake is on an earlier line.

## 2. Common types of compiler errors

### A. Syntax errors

Syntax errors happen when code does not follow C++ grammar.

``` cpp
int main() {
    int age = 25

    cout << age;

    return 0;
}
```

Problem: the declaration is missing a semicolon.

Correct:

``` cpp
int age = 25;
```

Common causes include missing semicolons, braces, parentheses, quotation
marks, or incorrect statement structure.

### B. Undeclared identifier errors

This happens when you use a variable or function that has not been
declared in the current scope.

``` cpp
#include <iostream>
using namespace std;

int main() {
    cout << username;
    return 0;
}
```

Possible message:

``` text
error: 'username' was not declared in this scope
```

Correct:

``` cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string username = "Shabbir";
    cout << username;
    return 0;
}
```

### C. Type errors

C++ is statically typed. An expression or assignment must use compatible
types.

``` cpp
int age = "twenty";
```

The string literal cannot be assigned to an `int`.

Correct alternatives:

``` cpp
int age = 20;
```

or:

``` cpp
#include <string>
std::string age = "twenty";
```

### D. Missing header errors

A standard library feature usually requires its corresponding header.

``` cpp
#include <iostream>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3};
    return 0;
}
```

Problem: `vector` is used without including `<vector>`.

Correct:

``` cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3};
    return 0;
}
```

### E. Function call errors

The arguments supplied to a function must match its parameter
requirements.

``` cpp
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(10);
    return 0;
}
```

Problem: `add` requires two arguments, but the call supplies one.

Correct:

``` cpp
int result = add(10, 20);
```

### F. Redefinition errors

A name generally cannot be declared twice in the same scope when the
declarations conflict.

``` cpp
int main() {
    int age = 20;
    int age = 25;
    return 0;
}
```

Correct:

``` cpp
int main() {
    int age = 20;
    age = 25;
    return 0;
}
```

## 3. How to read a compiler error message

Example:

``` text
main.cpp:8:10: error: 'name' was not declared in this scope
```

Breakdown:

-   `main.cpp`: source file name.
-   `8`: line number.
-   `10`: column number.
-   `error`: severity; the compiler cannot successfully compile the
    affected code.
-   `'name' was not declared in this scope`: explanation of the problem.

A useful debugging routine:

1.  Find the first meaningful error in the output.
2.  Open the file named in the message.
3.  Go to the reported line.
4.  Inspect the surrounding lines too.
5.  Read the message and identify the underlying cause.
6.  Fix the root cause.
7.  Compile again.

**Tip:** One early syntax mistake can cause several follow-up errors.
Fix the first meaningful error and compile again before trying to fix
every message.

## 4. Warnings vs. errors

  -----------------------------------------------------------------------
  Compiler error                      Compiler warning
  ----------------------------------- -----------------------------------
  Usually prevents successful         Usually allows compilation to
  compilation.                        continue.

  Indicates code the compiler cannot  Highlights code that may be
  accept.                             problematic or unintended.

  Must be resolved to produce a       Should be investigated and usually
  successful build.                   fixed.
  -----------------------------------------------------------------------

Example warning:

``` cpp
int main() {
    int age = 20;
    return 0;
}
```

A compiler may warn that `age` is unused.

With GCC, enable useful warnings using:

``` bash
g++ -Wall -Wextra -Wpedantic main.cpp -o app
```

These options enable many helpful diagnostics. They do not enable every
possible warning.

## 5. Compiler errors vs. runtime errors vs. logical errors

  -----------------------------------------------------------------------
  Type                    Meaning                 Example
  ----------------------- ----------------------- -----------------------
  Compiler error          The code cannot be      Missing semicolon.
                          compiled successfully.  

  Runtime error           A problem occurs while  Invalid memory access.
                          the program is running. 

  Logical error           The program runs but    Subtracting instead of
                          produces an incorrect   adding.
                          result.                 
  -----------------------------------------------------------------------

Compiler error:

``` cpp
int age = ;
```

Runtime issue / undefined behavior:

``` cpp
int arr[3] = {1, 2, 3};
std::cout << arr[10];
```

Accessing an array out of bounds is undefined behavior. It may not cause
a visible crash or a compiler error.

Logical error:

``` cpp
int a = 10;
int b = 20;

int sum = a - b;
```

If the intention is to add the values, the correct operation is `a + b`.
The original code can compile and run, but its logic is wrong.

## 6. Practice exercises

For each example, identify the problem before reading the answer.

### Exercise 1

``` cpp
int age = 25
cout << age;
```

**Answer:** Missing semicolon after `25`.

### Exercise 2

``` cpp
cout << username;
```

**Answer:** If `username` has not been declared in the current scope,
this is an undeclared identifier error.

### Exercise 3

``` cpp
int add(int a, int b) {
    return a + b;
}

int result = add(5);
```

**Answer:** Too few arguments. The function requires two arguments.

### Exercise 4

``` bash
g++ -Wall -Wextra main.cpp -o app
```

**Answer:** `-Wall` and `-Wextra` enable many useful compiler warnings.

### Exercise 5

``` cpp
int result = 10 - 5;
```

If the intended operation is addition, what kind of error is this?

**Answer:** A logical error. The expression is valid C++, but it does
not perform the intended calculation.

## 7. What to practice next

-   Read compiler output instead of immediately searching for a fix.
-   Identify syntax errors.
-   Understand variable scope and data types.
-   Learn to debug with breakpoints.
-   Compile with warning flags.
-   Distinguish compiler, linker, runtime, and logical errors.

## 8. Next topic: compiler errors vs. linker errors

C++ build processes involve multiple stages, commonly preprocessing,
compilation, assembly, and linking.

A useful next topic is linker errors, including:

-   `undefined reference`
-   Multiple definitions
-   Missing object files
-   Missing library dependencies

Understanding which build stage reports an error makes debugging much
easier.

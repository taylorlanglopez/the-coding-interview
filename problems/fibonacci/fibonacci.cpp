/* # Fibonacci

By definition, the first two numbers in the Fibonacci sequence are 0 and 1, and each subsequent number is the sum of the previous two.

For example, the first ten Fibonacci numbers are:

```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34
```

Write a function that accepts a number and returns the number at that position in the fibonnaci sequence.
*/

#include <iostream>
#include <cstdlib>

int fib(int i) {
    if(i < 2) return i;
    return fib(i-1) + fib(i-2);
}

int main() {
    for(int i = 0; i < 10; i++) {
        std::cout << fib(i) << std::endl;
    }
}
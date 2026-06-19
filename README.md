# Linear Algebra Library

A C++ library for basic linear algebra calculations.

It currently provides Gaussian elimination for linear systems and a `Fraction` class for rational-number arithmetic.

## Features

- Matrix representation with `std::vector<std::vector<double>>`
- Row-reduction by Gaussian elimination
- Rank calculation for coefficient and augmented matrices
- Fraction arithmetic with automatic reduction

## Structure

```text
.
├── README.md
└── Procedure
    ├── Fraction.cpp
    ├── Fraction.h
    ├── Gaussian_Elimination.cpp
    └── Gaussian_Elimination.h
```

## Usage

### Basic Example

```cpp
#include "Procedure/Gaussian_Elimination.h"

int main()
{
    Matrix A = {
        {1, 2, 5},
        {3, 4, 11}
    };

    PrintMatrix(A);
    RREF(A);
    PrintMatrix(A);

    return 0;
}
```

The matrix above represents the following system:

```text
x + 2y = 5
3x + 4y = 11
```

### Interactive Example

```cpp
#include "Procedure/Gaussian_Elimination.h"

#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    int n, m;

    std::cout << "Number of equations n: ";
    std::cin >> n;

    std::cout << "Number of unknowns m: ";
    std::cin >> m;

    Matrix A(n, std::vector<double>(m + 1));

    std::cout << "\nEnter coefficient matrix A\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> A[i][j];
        }
    }

    std::cout << "\nEnter right-hand side vector b\n";
    for (int i = 0; i < n; i++) {
        std::cin >> A[i][m];
    }

    std::cout << "\nAugmented matrix\n";
    PrintMatrix(A);

    RREF(A);

    std::cout << "\nAfter row reduction\n";
    PrintMatrix(A);

    return 0;
}
```

### Fraction Example

```cpp
#include "Procedure/Fraction.h"

#include <iostream>

int main()
{
    Fraction f1(6, 4);
    Fraction f2(1, 3);

    Fraction sum = f1 + f2;
    Fraction product = f1 * f2;
    Fraction quotient = f1 / f2;

    std::cout << f1.toString() << '\n';
    std::cout << f2.toString() << '\n';
    std::cout << sum.toString() << '\n';
    std::cout << product.toString() << '\n';
    std::cout << quotient.toString() << '\n';

    return 0;
}
```

## Build Example

```bash
g++ main.cpp Procedure/Gaussian_Elimination.cpp Procedure/Fraction.cpp -std=c++17 -o solver
./solver
```

## Notes

- Matrix calculations currently use `double`, so small floating-point errors may occur.
- `Fraction` uses `int` internally, so very large values may overflow.
- When using this library, compile the corresponding `.cpp` files together with your own source files.

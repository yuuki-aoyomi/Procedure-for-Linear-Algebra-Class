/*
You can solve Linear Equations.
*/

#include "Gaussian_Elimination.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

namespace
{
constexpr double EPS = 1e-10;
}

void PrintMatrix(const Matrix &A)
{
  for (const auto &row : A)
  {
    for (double x : row)
    {
      if (std::fabs(x) < EPS)
        x = 0;
      std::cout << std::setw(10)
                << std::fixed
                << std::setprecision(4)
                << x;
    }
    std::cout << '\n';
  }
}

void RREF(Matrix &A)
{
  int n = A.size();
  int m = A[0].size();

  int pivot_row = 0;

  for (int col = 0; col < m - 1 && pivot_row < n; col++)
  {

    int pivot = -1;

    for (int row = pivot_row; row < n; row++)
    {
      if (std::fabs(A[row][col]) > EPS)
      {
        pivot = row;
        break;
      }
    }

    if (pivot == -1)
      continue;

    std::swap(A[pivot_row], A[pivot]);

    double p = A[pivot_row][col];

    for (int j = 0; j < m; j++)
    {
      A[pivot_row][j] /= p;
    }

    for (int row = 0; row < n; row++)
    {

      if (row == pivot_row)
        continue;

      double factor = A[row][col];

      if (std::fabs(factor) < EPS)
        continue;

      for (int j = 0; j < m; j++)
      {
        A[row][j] -= factor * A[pivot_row][j];
      }
    }

    pivot_row++;
  }
}

int Rank(const Matrix &A, bool augmented)
{
  int n = A.size();
  int m = A[0].size();

  int rank = 0;

  for (int i = 0; i < n; i++)
  {

    bool nonzero = false;

    int limit = augmented ? m : m - 1;

    for (int j = 0; j < limit; j++)
    {
      if (std::fabs(A[i][j]) > EPS)
      {
        nonzero = true;
        break;
      }
    }

    if (nonzero)
      rank++;
  }

  return rank;
}

#pragma once
#include <vector>

using Matrix = std::vector<std::vector<double>>;

void PrintMatrix(const Matrix &A);

void RREF(Matrix &A);

int Rank(const Matrix &A, bool augmented);

/*
You can solve Linear Equations.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPS = 1e-10;

using Matrix = vector<vector<double>>;

void PrintMatrix(const Matrix& A)
{
    for(const auto& row : A){
        for(double x : row){
            if(fabs(x) < EPS) x = 0;
            cout << setw(10)
                 << fixed
                 << setprecision(4)
                 << x;
        }
        cout << '\n';
    }
}

void RREF(Matrix& A)
{
    int n = A.size();
    int m = A[0].size();

    int pivot_row = 0;

    for(int col = 0; col < m - 1 && pivot_row < n; col++){

        int pivot = -1;

        for(int row = pivot_row; row < n; row++){
            if(fabs(A[row][col]) > EPS){
                pivot = row;
                break;
            }
        }

        if(pivot == -1) continue;

        swap(A[pivot_row], A[pivot]);

        double p = A[pivot_row][col];

        for(int j = 0; j < m; j++){
            A[pivot_row][j] /= p;
        }

        for(int row = 0; row < n; row++){

            if(row == pivot_row) continue;

            double factor = A[row][col];

            if(fabs(factor) < EPS) continue;

            for(int j = 0; j < m; j++){
                A[row][j] -= factor * A[pivot_row][j];
            }
        }

        pivot_row++;
    }
}

int Rank(const Matrix& A, bool augmented)
{
    int n = A.size();
    int m = A[0].size();

    int rank = 0;

    for(int i = 0; i < n; i++){

        bool nonzero = false;

        int limit = augmented ? m : m - 1;

        for(int j = 0; j < limit; j++){
            if(fabs(A[i][j]) > EPS){
                nonzero = true;
                break;
            }
        }

        if(nonzero) rank++;
    }

    return rank;
}


/*実行例
int main()
{
    int n, m;

    cout << "方程式の本数 n : ";
    cin >> n;

    cout << "未知数の数 m : ";
    cin >> m;

    Matrix A(n, vector<double>(m + 1));

    cout << "\n係数行列 A を入力\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }

    cout << "\n右辺ベクトル b を入力\n";

    for(int i = 0; i < n; i++){
        cin >> A[i][m];
    }

    cout << "\n拡大係数行列\n";
    PrintMatrix(A);

    RREF(A);

    cout << "\n掃き出し後\n";
    PrintMatrix(A);

    bool inconsistent = false;

    for(int i = 0; i < n; i++){

        bool left_zero = true;

        for(int j = 0; j < m; j++){
            if(fabs(A[i][j]) > EPS){
                left_zero = false;
                break;
            }
        }

        if(left_zero && fabs(A[i][m]) > EPS){
            inconsistent = true;
        }
    }

    if(inconsistent){
        cout << "\n解なし\n";
        return 0;
    }

    int rankA = 0;
    int rankAb = 0;

    for(int i = 0; i < n; i++){

        bool nonzeroA = false;
        bool nonzeroAb = false;

        for(int j = 0; j < m; j++){
            if(fabs(A[i][j]) > EPS){
                nonzeroA = true;
                nonzeroAb = true;
            }
        }

        if(fabs(A[i][m]) > EPS){
            nonzeroAb = true;
        }

        if(nonzeroA) rankA++;
        if(nonzeroAb) rankAb++;
    }

    if(rankA < m){
        cout << "\n自由変数あり（解は無限個）\n";
        return 0;
    }

    cout << "\n一意解\n";

    vector<double> x(m);

    for(int i = 0; i < m; i++){
        x[i] = A[i][m];
    }

    for(int i = 0; i < m; i++){
        cout 
             << x[i]
             << '\n';
    }

    return 0;
}

*/
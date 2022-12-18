#ifndef HEAT_EQUATION_LU_H
#define HEAT_EQUATION_LU_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class SolveLU
{

private:
    vector<vector<double>> A;
    vector<vector<double>> L, U;
    vector<double> B, V;
    int i, j, m, N;
    double s;

public:

    SolveLU(const int& N0,
            const vector<vector<double>>& A0,
            const vector<double>& B0)
    {
        A = A0;		B = B0;
        L = A0;		U = A0;
        N = N0;		V = B0;
        for (i = 0; i < N; i++)
        {
            V[i] = 0.0;
            for (j = 0; j < N; j++)
            {
                L[i][j] = 0.0;
                U[i][j] = 0.0;
            }
        }
    }

    ~SolveLU() {}

    //upper triangular matrix
    void urow(int i);
    //lower triangular matrix
    void lcol(int j);
    //to solve X based Ax=B
    void Xsolve(vector<double>& X);

};
#endif //HEAT_EQUATION_LU_H

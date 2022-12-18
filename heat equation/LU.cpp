#include "LU.h"

//upper triangular matrix
void SolveLU::urow(int i)
{
    double s;
    int j, k;
    for (j = i; j < N; j++)
    {
        s = 0;
        for (k = 0; k < i; k++)
            s += U[k][j] * L[i][k];
        U[i][j] = A[i][j] - s;
    }
}


//lower triangular matrix
void SolveLU::lcol(int j)
{
    double s;
    int i, k;
    for (i = j + 1; i < N; i++)
    {
        s = 0;
        for (k = 0; k <= i - 1; k++)
            s += U[k][j] * L[i][k];
        L[i][j] = (A[i][j] - s) / U[j][j];
    }
}

void SolveLU::Xsolve(vector<double>& X)
{
    X = B;
    for (i = 0; i < N; i++)
    {
        L[i][i] = 1.0;
    }
    for (m = 0; m < N; m++)
    {
        urow(m);
        if (m < (N - 1))
            lcol(m);
    }

    for (i = 0; i < N; i++)
    {
        s = 0;
        for (j = 0; j <= i - 1; j++)
            s += L[i][j] * V[j];
        V[j] = B[i] - s;
    }
    for (i = N - 1; i >= 0; i--)
    {
        s = 0;
        for (j = i + 1; j < N; j++)
            s += U[i][j] * X[j];
        X[i] = (V[i] - s) / U[i][i];
    }
}


void SolveLU::printmat(vector<double>& x)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout << setw(8) << setprecision(4) << x[i][j];
		cout << endl;
	}
}

#include "PDEim.h"
#include "LU.h"

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


void PDEim::Initial()
{
    for (int i = 0; i < N + 1; ++i)
    {
        U0.push_back(i);
        Un.push_back(i);
        A.push_back(vector<double>());
        temp = Dx * i;
        X.push_back(temp);
    }
    for (int i = 0; i < N + 1; ++i)
    {
        for (int j = 0; j < N + 1; ++j)
        {
            A[i].push_back(0.0);
        }
    }

    //U0≥ı ºªØ
    for (int i = 0; i < N + 1; ++i)
    {
        if (i < int(0.5 * N)) { U0[i] = 1.0; }
        if (i > int(0.5 * N)) { U0[i] = 10.0; }
        if (i == int(0.5 * N)) { U0[i] = 5.5; }
    }

    //æÿ’ÛA≥ı ºªØ
    for (int i = 0; i < N + 1; ++i)
    {
        for (int j = 0; j < N + 1; ++j)
        {
            if (i == 0)
            {
                A[i][0] = Dtx + 1.0;
                A[i][1] = -Dtx;
            }
            else if (i == N)
            {
                A[i][N] = Dtx + 1.0;
                A[i][N - 1] = -Dtx;
            }
            else if (i > 0 && i < N)
            {
                A[i][i - 1] = -Dtx;
                A[i][i - 0] = 2.0 * Dtx + 1.0;
                A[i][i + 1] = -Dtx;
            }
        }
    }

}

void PDEim::Solve(const int& k, int& T)
{
    if (k == 1)
    {
        if (T > Nt/Dt) T = Nt/Dt;
        cout << "Solve T = " << T << endl;
        for (int i = 0; i < T; ++i)
        {
            SolveLU AUX(N + 1, A, U0);
            AUX.Xsolve(Un);
            U0 = Un;
        }
        fileout = "output_U_T20000.txt";
        ofstream fout(fileout);
        fout << fixed << setprecision(4);
        for (int i = 0; i < N + 1; i++)
        {
            fout << X[i] << setw(16) << Un[i] << endl;
        }
        fout.close();

    }
    if (k == 2)
    {
        fileout2 = "output_U_X20%.txt";
        ofstream fout2(fileout2);
        fout2 << fixed << setprecision(4);
        cout << "Solve T = " << Nt << endl;
        cout << "Output Loc = " << T * LL / N << ",so " << T << "%" << endl;
        for (int i = 0; i < int(Nt / Dt); ++i)
        {
            SolveLU AUX(N + 1, A, U0);
            AUX.Xsolve(Un);
            U0 = Un;
            fout2 << i * Dt << setw(16) << Un[T * (N / 100)] << endl;
        }
        fout2.close();
    }
}
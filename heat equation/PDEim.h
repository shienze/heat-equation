#ifndef HEAT_EQUATION_PDEIM_H
#define HEAT_EQUATION_PDEIM_H
#include <vector>
#include <string>

using namespace std;

class PDEim
{

private:
    int N, Nt;
    double LL, Dt;
    double Dx, Dtx, temp;

    vector<double> U0;
    vector<double> Un;
    vector<double> X;
    vector<vector<double>> A;

    string fileout;
    string fileout2;

public:

    PDEim(const int& L0, const int& N0,
          const int& Nt0, const double& Dt0)
    {
        N = N0;
        LL = L0;
        Nt = Nt0;
        Dt = Dt0;
        Dx = LL / N;
        Dtx = Dt / (Dx * Dx);
    }

    void Initial();
    void Solve(const int& k, int& T);

    ~PDEim() {}

};
#endif //HEAT_EQUATION_PDEIM_H

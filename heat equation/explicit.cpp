#include <iostream>
#include "explicit.h"
#include "PDEex.h"


int main()
{
    LL = 20.0;   //x的总长度
    N = 100;     //x划分的总段数,要求为偶数
    Nt = 600;    //时间步推进总次数
    Dt = 0.04;   //时间间隔步
    IN1 = 1;     //计算选择设置： =1，表示输出某一时刻下各位置U的数值
    //               =2，表示某一位置处U随时间变化的数值
    IN2 = 15;    //计算选择设置：IN1=1时，IN2的数值表示迭代步，最大值为Nt/Dt
    //				 IN1=2时，IN2的数值表示点的位置坐标的百分比，范围为0-100

    cout << " Dt = " << Dt << endl;
    cout << " Dx = " << LL / N << endl;
    cout << " Dt/(Dx*Dx) = " << Dt / ((LL / N) * (LL / N)) << endl;

    PDEex PDE(LL, N, Nt, Dt);
    PDE.Initial();
    PDE.Solve(IN1, IN2);

    cout << "Finished Everything succeed!" << endl;
    return 0;
}

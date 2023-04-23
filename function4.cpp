#include "function4.h"

double Opt_fun4_grad1::calc(const vector<double>&v)
{
    return -v[0]*(6*sin(v[0])+3*v[0]*cos(v[0])-14);
}

Opt_fun4_grad1::Opt_fun4_grad1()
{
    dim = 2;
}

double Opt_fun4_grad2::calc(const vector<double>& v)
{
    return v[1]*(v[1]*sin(v[1])-2*cos(v[1])+8);
}

Opt_fun4_grad2::Opt_fun4_grad2()
{
    dim = 2;
}

double Opt_fun4_Hess11::calc(const vector<double>&v)
{
    return 3*v[0]*v[0]*sin(v[0])+2*(-3*sin(v[0]))-12*v[0]*cos(v[0]);
}

Opt_fun4_Hess11::Opt_fun4_Hess11()
{
    dim = 2;
}

double Opt_fun4_Hess12::calc(const vector<double>& v)
{
    return 0.0;
}

Opt_fun4_Hess12::Opt_fun4_Hess12()
{
    dim = 2;
}

double Opt_fun4_Hess22::calc(const vector<double>&v)
{
    return v[1]*v[1]*cos(v[1])+4*v[1]*sin(v[1])+2*(4-cos(v[1]));
}

Opt_fun4_Hess22::Opt_fun4_Hess22()
{
    dim = 2;
}

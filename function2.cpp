#include "function2.h"

double Opt_fun2_grad1::calc(const vector<double>&v)
{
    return 2*(200.*v[0]*v[0]*v[0]-200.*v[0]*v[1]+v[0]-1);
}

Opt_fun2_grad1::Opt_fun2_grad1()
{
    dim = 2;
}

double Opt_fun2_grad2::calc(const vector<double>& v)
{
    return 200*(v[1]-v[0]*v[0]);
}

Opt_fun2_grad2::Opt_fun2_grad2()
{
    dim = 2;
}

double Opt_fun2_Hess11::calc(const vector<double>&v)
{
    return 1200.*v[0]*v[0]-400.*v[1]+2;
}

Opt_fun2_Hess11::Opt_fun2_Hess11()
{
    dim = 2;
}

double Opt_fun2_Hess12::calc(const vector<double>& v)
{
    return -400.*v[0];
}

Opt_fun2_Hess12::Opt_fun2_Hess12()
{
    dim = 2;
}

double Opt_fun2_Hess22::calc(const vector<double>&)
{
    return 200.;
}

Opt_fun2_Hess22::Opt_fun2_Hess22()
{
    dim = 2;
}

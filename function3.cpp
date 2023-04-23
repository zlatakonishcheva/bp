#include "function3.h"

double Opt_fun3_grad1::calc(const vector<double>&v)
{
    return (2*v[0])/((v[0]*v[0])+(v[1]*v[1]*v[1]*v[1])+1);
}

Opt_fun3_grad1::Opt_fun3_grad1()
{
    dim = 2;
}

double Opt_fun3_grad2::calc(const vector<double>& v)
{
    return (4*v[1]*v[1]*v[1])/((v[0]*v[0])+(v[1]*v[1]*v[1]*v[1])+1);
}

Opt_fun3_grad2::Opt_fun3_grad2()
{
    dim = 2;
}

double Opt_fun3_Hess11::calc(const vector<double>&v)
{
    return (2-((4*v[0]*v[0])/((v[0]*v[0])+(v[1]*v[1]*v[1]*v[1])+1)))/((v[0]*v[0])+(v[1]*v[1]*v[1]*v[1])+1);
}

Opt_fun3_Hess11::Opt_fun3_Hess11()
{
    dim = 2;
}

double Opt_fun3_Hess12::calc(const vector<double>& v)
{
    return (-8*v[0]*v[1]*v[1]*v[1])/(((v[0]*v[0])+(v[1]*v[1]*v[1]*v[1])+1)*((v[0]*v[0])+(v[1]*v[1]*v[1]*v[1])+1));
}

Opt_fun3_Hess12::Opt_fun3_Hess12()
{
    dim = 2;
}

double Opt_fun3_Hess22::calc(const vector<double>&v)
{
    return ((12*v[1]*v[1])-((16*v[1]*v[1]*v[1]*v[1]*v[1]*v[1])/((v[0]*v[0])+(v[1]*v[1]*v[1]*v[1])+1)))/((v[0]*v[0])+(v[1]*v[1]*v[1]*v[1])+1);
}

Opt_fun3_Hess22::Opt_fun3_Hess22()
{
    dim = 2;
}

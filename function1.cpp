#include"function1.h"

double Opt_fun1_grad1::calc(const vector<double>&v)
{
	return 2*v[0];
}
Opt_fun1_grad1::Opt_fun1_grad1()
{
	dim = 2;
}

double Opt_fun1_grad2::calc(const vector<double>& v)
{
	return 2 * v[1];
}
Opt_fun1_grad2::Opt_fun1_grad2()
{
	dim = 2;
}

double Opt_fun1_Hess11::calc(const vector<double>& v)
{
	return 2;
}
Opt_fun1_Hess11::Opt_fun1_Hess11()
{
	dim = 2;
}

double Opt_fun1_Hess12::calc(const vector<double>& v)
{
	return 0;
}
Opt_fun1_Hess12::Opt_fun1_Hess12()
{
	dim = 2;
}

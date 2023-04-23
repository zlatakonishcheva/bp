#include "sup_stop.h"

sup_stop_Newton::sup_stop_Newton(Opt_fun* func, vector<double>x_0):func(func),x_n(x_0)
{
}

void sup_stop_Newton::set_x_n(vector<double> x_n_)
{
	x_n_old = x_n;
	x_n = x_n_;
}

const vector<double> sup_stop_Newton::get_x_n()
{
	return x_n;
}

const vector<double> sup_stop_Newton::get_x_n_old()
{
	return x_n_old;
}

double sup_stop_Newton::get_fun_x_n()
{
	return func->calc(x_n);
}

double sup_stop_Newton::get_fun_x_n_old()
{
	return  func->calc(x_n_old);
}

vector<double> sup_stop_Newton::get_grad_x_n()
{
	return  func->calc_grad(x_n);
}

sup_stop_random_search::sup_stop_random_search(Opt_fun* func, vector<double>x_0) :func(func), x_n(x_0)
{
}

void sup_stop_random_search::set_x_n(vector<double> x_n_)
{
	x_n_old = x_n;
	x_n = x_n_;
}


double sup_stop_random_search::get_fun_x_n()
{
	return func->calc(x_n);
}

double sup_stop_random_search::get_fun_x_n_old()
{
	return  func->calc(x_n_old);
}

const int sup_stop_random_search::get_last_change_count()
{
	return last_change_count;
}

const vector<double> sup_stop_random_search::get_x_n_old()
{
	return x_n_old;
}

void sup_stop_random_search::last_change_count_set_zero()
{
	last_change_count=0;
}

void sup_stop_random_search::last_change_count_increment()
{
	++last_change_count;
}

sup_stop_Newton::~sup_stop_Newton()
{

    {
        if (func != nullptr) {
            delete func;
            func = nullptr;
        }
    }
}

sup_stop_random_search::~sup_stop_random_search()
{
    {
        if (func != nullptr) {
            delete func;
            func = nullptr;
        }

    }
}

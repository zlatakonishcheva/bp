#pragma once
#include"Expr.h"
#include"instead_of_eigen.h"
#include"function.h"

class sup_stop
{
	virtual void set_x_n(vector<double>)=0;
};

class sup_stop_Newton:public sup_stop{
	protected:
		vector<double> x_n;
		vector<double> x_n_old;
		Opt_fun*  func;
	public:
		sup_stop_Newton(Opt_fun*,vector<double>);
		virtual void set_x_n(vector<double>) override;
		~sup_stop_Newton();
		const vector<double> get_x_n();
		const vector<double> get_x_n_old();
		double get_fun_x_n();
		double get_fun_x_n_old();
	    vector<double> get_grad_x_n();
};

class sup_stop_random_search :public sup_stop {
protected:
	vector<double> x_n;
	vector<double> x_n_old;
	Opt_fun* func;
	int last_change_count=0;
public:
	sup_stop_random_search(Opt_fun*, vector<double>);
	virtual void set_x_n(vector<double>) override;
    ~sup_stop_random_search();
	double get_fun_x_n();
	double get_fun_x_n_old();
	const int get_last_change_count();
	const vector<double> get_x_n_old();
	void last_change_count_set_zero();
	void last_change_count_increment();
};

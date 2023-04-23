#pragma once
#include"dom.h"
#include"function.h"
#include"Stop_crit.h"
#include"instead_of_eigen.h"

class Opt_method
{
protected:
	vector<vector<double>> x_n;

	Area* area=nullptr;
	Opt_fun* opt_fun=nullptr;
	Stop_crit* stop_crit=nullptr;
public:
	virtual vector<vector<double>> optim(vector<double>) = 0;
	void set_area(Area*);
	void set_opt_fun(Opt_fun*);
	void set_stop_crit(Stop_crit*);
	~Opt_method();
	virtual vector<string> info() = 0;
};

class Newton :public Opt_method {
protected:
	vector<double> p_n;
public:
	virtual vector<vector<double>> optim(vector<double>) override;
	Newton(Area*, Opt_fun*, Stop_crit*);
	virtual vector<string> info() override;
};

class Random_search :public Opt_method {
protected:
	double delta;
	double p;
public:
	virtual vector<vector<double>> optim(vector<double>) override;
	Random_search(Area*, Opt_fun*,Stop_crit*,double, double);
	virtual vector<string> info() override;
};
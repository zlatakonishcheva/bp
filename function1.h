#pragma once
#include"Expr.h"



class Opt_fun1_grad1:public Expr {
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun1_grad1();
};
class Opt_fun1_grad2 :public Expr {
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun1_grad2();
};

class Opt_fun1_Hess11 :public Expr {//���� ��� � 22
public:
	virtual double calc(const vector<double>&) override;

	Opt_fun1_Hess11();
};
class Opt_fun1_Hess12 :public Expr {//���� ��� � 21
public:
	virtual double calc(const vector<double>&) override;
	Opt_fun1_Hess12();
};

#pragma once
#include"Expr.h"



class Opt_fun3_grad1 :public Expr {
public:
    virtual double calc(const vector<double>&) override;

    Opt_fun3_grad1();
};
class Opt_fun3_grad2 :public Expr {
public:
    virtual double calc(const vector<double>&) override;
    Opt_fun3_grad2();
};

class Opt_fun3_Hess11 :public Expr {
public:
    virtual double calc(const vector<double>&) override;

    Opt_fun3_Hess11();
};
class Opt_fun3_Hess12 :public Expr {
public:
    virtual double calc(const vector<double>&) override;
    Opt_fun3_Hess12();
};

class Opt_fun3_Hess22 :public Expr {
public:
    virtual double calc(const vector<double>&) override;
    Opt_fun3_Hess22();
};


#pragma once
#include"Expr.h"



class Opt_fun4_grad1 :public Expr {
public:
    virtual double calc(const vector<double>&) override;

    Opt_fun4_grad1();
};
class Opt_fun4_grad2 :public Expr {
public:
    virtual double calc(const vector<double>&) override;
    Opt_fun4_grad2();
};

class Opt_fun4_Hess11 :public Expr {
public:
    virtual double calc(const vector<double>&) override;

    Opt_fun4_Hess11();
};
class Opt_fun4_Hess12 :public Expr {
public:
    virtual double calc(const vector<double>&) override;
    Opt_fun4_Hess12();
};

class Opt_fun4_Hess22 :public Expr {
public:
    virtual double calc(const vector<double>&) override;
    Opt_fun4_Hess22();
};


#pragma once
#include <iostream>
#include<vector>
#include"Expr.h"

#include <random>

using namespace std;

class SingletonGenerator {
    static mt19937 mersennetwister;
public:
    static mt19937& get_mt();
    static double getu01_sing();
};


vector<double> operator+(const vector<double>& a, const vector<double>& b);
vector<double> operator-(const vector<double>& a, const vector<double>& b);
vector<double> operator*(double b, const vector<double>& a);
vector<double> operator/(const vector<double>& a, double b);
vector<double> LinEqSolve(vector<vector<double>>A, vector<double>b);
double abs(vector<double>);
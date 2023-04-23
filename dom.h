#pragma once
#include<vector>
#include<string>
#include"instead_of_eigen.h"
using namespace std;
class Area
{
protected:
	unsigned dim;
public:
	virtual bool inside(vector<double>) = 0;
	virtual vector<double> correct_point(vector<double>, vector<double>)=0;
	const unsigned get_dim();
	virtual string info()=0;
};

class All_space:public Area {
public:
	All_space(unsigned);
	virtual bool inside(vector<double>) override;
	virtual vector<double> correct_point(vector<double>, vector<double>) override;
	virtual string info() override;
};

class Dom :public Area {
protected:
	vector<double> left;
	vector<double> right;
public:
	Dom(unsigned, vector<double>, vector<double>);
	virtual bool inside(vector<double>) override;
	vector<double> get_random_point();
	virtual vector<double> correct_point(vector<double>, vector<double>) override;
	Dom cross_dom(vector<double>, double);
	virtual string info() override;

    vector<double> get_left();
    vector<double> get_right();
};

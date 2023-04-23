#include "opt_method.h"

double eps =1.e-10;

void Opt_method::set_area(Area*area_)
{
	area = area_;
}

void Opt_method::set_opt_fun(Opt_fun*opt_fun_)
{
	opt_fun = opt_fun_;
}

void Opt_method::set_stop_crit(Stop_crit*stop_crit_)
{
	stop_crit = stop_crit_;
}

Opt_method::~Opt_method()
{
    if (area != nullptr) {
        delete area;
        area = nullptr;
    }

    if (stop_crit != nullptr) {
        delete stop_crit;
        stop_crit = nullptr;
    }

    if (opt_fun != nullptr) {
        delete opt_fun;
        opt_fun = nullptr;
    }
}

vector<vector<double>> Newton::optim(vector<double> v)
{
    dynamic_cast<Stop_crit_count*>(stop_crit)->reset();
	sup_stop_Newton* sup = new sup_stop_Newton(opt_fun,v);
	vector<double> l=v, r=v, l_=v, r_=v;
	
	if (area->inside(v) == false)
		throw domain_error("x_0 not inside");
	x_n.clear();
	x_n.push_back(v);
	while (stop_crit->check(sup)) {
		p_n = -1*LinEqSolve(opt_fun->calc_Hess(x_n.back()),opt_fun->calc_grad(x_n.back()));
		l = x_n.back();
		r = x_n.back() + p_n;
		while (abs(l - r) > eps) {
			
			l_ = (2 * l + r) / 3;
			r_ = (l + 2 * r) / 3;
			if (opt_fun->calc(l_) < opt_fun->calc(r_))
				r = r_;
			else
				l = l_;
		}
		if (!(area->inside((l+r)/2)))
		{
			x_n.push_back((area->correct_point(x_n.back(),(l+r)/2)));
			return x_n;
		}
		x_n.push_back((l + r) / 2);
		sup->set_x_n(x_n.back());
	}
	return x_n;
}

Newton::Newton(Area* area_, Opt_fun*opt_fun_, Stop_crit*stop_crit_)
{
	if (area_->get_dim() != opt_fun_->get_dim())
		throw domain_error("area_->dim != opt_fun_->dim");

	area = area_;
	opt_fun = opt_fun_;
	stop_crit = stop_crit_;
}

vector<string> Newton::info()
{
	vector<string> res;
	res.push_back("Newton's method");
	res.push_back(opt_fun->info());
	res.push_back(area->info());
	res.push_back(stop_crit->info());
	string temp;
	for (unsigned i = 0; i < x_n.size(); i += max(1, int(pow(10, int(log10(x_n.size() - 1)))))) {
		temp = "x_" + to_string(i) + ": ";
		for (unsigned j = 0; j < x_n[i].size(); ++j)
			temp += to_string(x_n[i][j]) + " ";
		temp += "f(x_" + to_string(i) + "): " + to_string(opt_fun->calc(x_n[i]));
		res.push_back(temp);
	}
	temp = "x_" + to_string(x_n.size()-1) + ": ";
	for (unsigned j = 0; j < x_n.back().size(); ++j)
		temp += to_string(x_n.back()[j]) + " ";
	temp += "f(x_" + to_string(x_n.size() - 1) + "): " + to_string(opt_fun->calc(x_n.back()));
	res.push_back(temp);
	return res;
}

vector<vector<double>> Random_search::optim(vector<double> v)
{
    dynamic_cast<Stop_crit_count*>(stop_crit)->reset();
	sup_stop_random_search* sup = new sup_stop_random_search(opt_fun, v);
	vector<double> y_n;

	double delta_multiplier=1;

	if (area->inside(v) == false)
		throw domain_error("x_0 not inside");

	x_n.clear();
	x_n.push_back(v);

	Dom* dom = dynamic_cast<Dom*>(area);
	bool local_opt = false;

	while (stop_crit->check(sup)) {
		local_opt = (SingletonGenerator::getu01_sing() < p);

		if (local_opt)
			y_n = dom->cross_dom(x_n.back(), delta_multiplier*delta).get_random_point();
        else{
            y_n = dom->get_random_point();
            delta_multiplier = 1;
        }

		if (opt_fun->calc(y_n) < opt_fun->calc(x_n.back())) {
            if (local_opt){
                if(delta_multiplier * delta > numeric_limits<double>::epsilon())
                delta_multiplier /= 2;}
			x_n.push_back(y_n);
			sup->set_x_n(x_n.back());
			sup->last_change_count_set_zero();
		}
		else {
			x_n.push_back(x_n.back());
			sup->last_change_count_increment();
		}
	}
	return x_n;
}

Random_search::Random_search(Area*area_, Opt_fun*opt_fun_, Stop_crit*stop_crit_,double delta_=1e-7,double p_=0.5)
{
	if (area_->get_dim() != opt_fun_->get_dim())
		throw domain_error("area_->dim != opt_fun_->dim");
	if (dynamic_cast<Dom*>(area_) == nullptr)
		throw domain_error("area is not correct");

	area = area_;
	opt_fun = opt_fun_;
	stop_crit = stop_crit_;
	delta = delta_;
	p = p_;

}

vector<string> Random_search::info()
{

	vector<string> res;
	res.push_back("Random search(delta = "+to_string(delta)+", p = "+to_string(p)+")");
	res.push_back(opt_fun->info());
	res.push_back(area->info());
	res.push_back(stop_crit->info());
	string temp;
	for (unsigned i = 0; i < x_n.size(); i += max(1, int(pow(10, int(log10(x_n.size() - 1)))))) {
		temp = "x_" + to_string(i) + ": ";
		for (unsigned j = 0; j < x_n[i].size(); ++j)
			temp += to_string(x_n[i][j]) + " ";
		temp += "f(x_" + to_string(i) + "): " + to_string(opt_fun->calc(x_n[i]));
		res.push_back(temp);
	}
	temp = "x_" + to_string(x_n.size() - 1) + ": ";
	for (unsigned j = 0; j < x_n.back().size(); ++j)
		temp += to_string(x_n.back()[j]) + " ";
	temp += "f(x_" + to_string(x_n.size() - 1) + "): " + to_string(opt_fun->calc(x_n.back()));
	res.push_back(temp);
	return res;

}

#include "Stop_crit.h"

bool Stop_crit_count::check(sup_stop * =nullptr)
{

    if (count >= max) {
        return false;

    }
    ++count;
    return true;
}

Stop_crit_count::Stop_crit_count(int max_)
{
    if (max_ < 1)
        throw invalid_argument("max < 1");
    max = max_;
}

void Stop_crit_count::set_max(int max_)
{
    max = max_;
}

const int Stop_crit_count::get_count()
{
    return count;
}

void Stop_crit_count::reset()
{
    count = 0;
}

string Stop_crit_count::info()
{
    return "Stopping criterion: by the number of iterations("+to_string(max)+")";
}

bool Stop_crit_Newton_dif::check(sup_stop*sup)
{
    sup_stop_Newton*sup_N = dynamic_cast<sup_stop_Newton*>(sup);

    if (count >= max) {
        return false;

    }
    if (!(sup_N->get_x_n_old().empty())&&(abs((sup_N->get_x_n())-(sup_N->get_x_n_old())) < epsi)) {
        return false;

    }
    ++count;
    return true;
}

Stop_crit_Newton_dif::Stop_crit_Newton_dif(int max_, double epsi_):Stop_crit_count(max_)
{

    if (epsi_ < 0)
        throw invalid_argument("epsilon < 0");
    epsi = epsi_;

    
}

string Stop_crit_Newton_dif::info()
{
    return "Stopping criterion: by the number of iterations(" + to_string(max) + ") and |x_n-x_{n-1}|<"+to_string(epsi);
}

bool Stop_crit_Newton_grad::check(sup_stop*sup)
{
    sup_stop_Newton* sup_N = dynamic_cast<sup_stop_Newton*>(sup);

    if (count >= max) {
        return false;

    }
    if (abs(sup_N-> get_grad_x_n()) < epsi) {
        return false;

    }
    ++count;
    return true;
}

Stop_crit_Newton_grad::Stop_crit_Newton_grad(int max_, double epsi_) :Stop_crit_count(max_)
{

    if (epsi_ < 0)
        throw invalid_argument("epsilon < 0");
    epsi = epsi_;
}

string Stop_crit_Newton_grad::info()
{
    return "Stopping criterion: by the number of iterations(" + to_string(max) + ") and ||grad(x_n)||<" + to_string(epsi);
}

bool Stop_crit_Newton3::check(sup_stop* sup)
{
    sup_stop_Newton* sup_N = dynamic_cast<sup_stop_Newton*>(sup);

    if (count >= max) {
        return false;

    }
    if (!(sup_N->get_x_n_old().empty()) && (abs((sup_N->get_fun_x_n()-sup_N->get_fun_x_n_old())/ sup_N->get_fun_x_n()) < epsi)) {
        return false;
    }
    ++count;
    return true;
}

Stop_crit_Newton3::Stop_crit_Newton3(int max_, double epsi_) :Stop_crit_count(max_)
{

    if (epsi_ < 0)
        throw invalid_argument("epsilon < 0");
    epsi = epsi_;
}

string Stop_crit_Newton3::info()
{
    return "Stopping criterion: by the number of iterations(" + to_string(max) + ") and |(f(x_n)-f(x_{n-1})/f(x_n))|<" + to_string(epsi);
}

bool Stop_crit_random_search_dif::check(sup_stop* sup)
{
    sup_stop_random_search* sup_rs = dynamic_cast<sup_stop_random_search*>(sup);

    if (count >= max) {
        return false;

    }
    if (!(sup_rs->get_x_n_old().empty()) && (abs((sup_rs->get_fun_x_n()) - (sup_rs->get_fun_x_n_old())) < epsi)) {
        return false;

    }
    ++count;
    return true;
}

Stop_crit_random_search_dif::Stop_crit_random_search_dif(int max_, double epsi_) :Stop_crit_count(max_)
{

    if (epsi_ < 0)
        throw invalid_argument("epsilon < 0");
    epsi = epsi_;
}

string Stop_crit_random_search_dif::info()
{
    return "Stopping criterion: by the number of iterations(" + to_string(max) + ") and |x_n-x_{n-1}|<" + to_string(epsi)+"(x_n!=x_{n-1})";
}

bool Stop_crit_random_search_last_change::check(sup_stop* sup)
{
    sup_stop_random_search* sup_rs = dynamic_cast<sup_stop_random_search*>(sup);

    if (count >= max) {
        return false;

    }
    if (sup_rs->get_last_change_count()>=max_lc) {
        return false;

    }
    ++count;
    return true;
}

Stop_crit_random_search_last_change::Stop_crit_random_search_last_change(int max_, int max_lc_) :Stop_crit_count(max_),max_lc(max_lc_)
{
    if (max_ < max_lc_)
        throw invalid_argument("max < max since last change");
}

string Stop_crit_random_search_last_change::info()
{
    return "Stopping criterion: by the number of iterations(" + to_string(max) + ") and the number of iterations since the last change("+ to_string(max_lc) + ")";
}

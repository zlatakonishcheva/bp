#include "dom.h"

All_space::All_space(unsigned dim_)
{
    dim = dim_;
}

bool All_space::inside(vector<double> v)
{
    if (dim != v.size())
        throw domain_error("dim != v.size()");
    return true;
}

vector<double> All_space::correct_point(vector<double> inside, vector<double> outside)
{
    return outside;
}

string All_space::info()
{
    return "Domain: R^"+ to_string(dim);
}

Dom::Dom(unsigned dim_, vector<double> left_, vector<double> right_)
{
    dim = dim_;
    if (dim != left_.size() || dim != right_.size())
        throw domain_error("dim != left_.size() || dim != right_.size()");
    for (unsigned i = 0; i < left_.size(); ++i)
        if (left_[i] >= right_[i])
            throw domain_error("left_["+to_string(i)+"] >= right_[" + to_string(i) + "]");
    left = left_;
    right = right_;
}

bool Dom::inside(vector<double>v)
{
    if (dim != v.size())
        throw domain_error("dim != v.size()");
    for (unsigned i = 0; i < dim; ++i) {
        if (v[i]<left[i]) {
            return false;
        }
        if (v[i] > right[i]) {
            return false;
        }
    }
    return true;
}

vector<double> Dom::get_random_point()
{
    vector<double> point;
    for (unsigned i = 0; i < dim; ++i)
        point.push_back(((right[i]-left[i])*SingletonGenerator::getu01_sing())+left[i]);
    return point;
}

vector<double> Dom::correct_point(vector<double>inside , vector<double>outside)
{
    if (!(this->inside(inside)))
        throw invalid_argument("inside point not inside");
    if ((inside.size() != outside.size())||(inside.size() != dim))
        throw domain_error("dimension error");
    if (this->inside(outside))
        return outside;

    vector<double> new_left = left - inside, new_right = right - inside,new_outside=outside-inside,res;
    
    for (unsigned i = 0; i < dim; ++i) {
        if (new_outside[i] < new_left[i]) {
            res = ((new_left[i] / new_outside[i]) * new_outside)+inside;
            if (this->inside(res))
                return res;
        }
        if (new_outside[i] > new_right[i]) {
            res = ((new_right[i] / new_outside[i]) * new_outside) + inside;
            if (this->inside(res))
                return res;
        }
    }
    return outside;
}

Dom Dom::cross_dom(vector<double>v, double delta)
{
    vector<double> left_, right_;
    for (unsigned i = 0; i < v.size(); ++i) {
        left_.push_back(max(left[i], v[i] - delta));
        right_.push_back(min(right[i],v[i]+delta));
    }
    try {
        return Dom(v.size(), left_, right_);
    }
    catch (exception& e) {
        cout << "left:" << left[0] <<" "<< left[1] << endl;
        cout << "right:" << right[0] << " " << right[1] << endl;
        cout << "v:" << v[0] << " " << v[1] << endl;
        cout << "delta:" << delta << endl;

        cout << "left_:" << left_[0] << " " << left_[1] << endl;
        cout << "right_:" << right_[0] << " " << right_[1] << endl;
        throw e;
    }
}

string Dom::info()
{
    string res="Domain: ";
    for (unsigned i = 0; i < left.size(); ++i)
        res += ("[" + to_string(left[i])+", "+ to_string(right[i])+"]x");
    res.pop_back();
    return res;
}

vector<double> Dom::get_left()
{
    return left;
}

vector<double> Dom::get_right()
{
    return right;
}

const unsigned Area::get_dim()
{
    return dim;
}

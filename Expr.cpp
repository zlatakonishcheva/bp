#include "Expr.h"

double Expr::operator()(const vector<double>&a)
{
    if (dim != a.size())
        throw domain_error("dim != a.size()");
    return calc(a);
}


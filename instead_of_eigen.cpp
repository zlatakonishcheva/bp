#include"instead_of_eigen.h"

vector<double> operator+(const vector<double>& a, const vector<double>& b) {
    if (a.size() != b.size())
        throw invalid_argument("a.size()!=b.size()");
    vector<double> c(a.size());
    for (unsigned i = 0; i < a.size(); ++i)
        c[i] = a[i] + b[i];
    return c;
}
vector<double> operator-(const vector<double>& a, const vector<double>& b) {
    if (a.size() != b.size())
        throw invalid_argument("a.size()!=b.size()");
    vector<double> c(a.size());
    for (unsigned i = 0; i < a.size(); ++i)
        c[i] = a[i] - b[i];
    return c;
}

vector<double> operator*(double b, const vector<double>& a) {
    vector<double> c(a.size());
    for (unsigned i = 0; i < a.size(); ++i)
        c[i] = b * a[i];
    return c;
}

vector<double> operator/(const vector<double>& a, double b) {
    vector<double> c(a.size());
    for (unsigned i = 0; i < a.size(); ++i)
        c[i] = a[i] / b;
    return c;
}

vector<double> LinEqSolve(vector<vector<double>>A, vector<double>b) {
    if (A.size() != b.size())
        throw("A.size() != b.size()");

    int n = b.size();
    vector<double> x(n);
    for (int i = 0; i < n - 1; ++i) {

        for (int j = i + 1; j < n; ++j) {
            b[j] -= (A[j][i] / A[i][i]) * b[i];
            A[j] = A[j] - ((A[j][i] / A[i][i]) * A[i]);
        }

    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << A[i][j] << ' ';
        cout << ' '<<' '<<b[i] << endl;

    }*/
    double d = 0;
    for (int i = n - 1; i >= 0; --i) {
        d = 0;
        for (int j = i + 1; j < n; ++j) {
            d += A[i][j] * x[j];
        }
        x[i] = (b[i] - d) / A[i][i];
    }
    return x;
};

double abs(vector<double>v){
    double s = 0;
    for (unsigned i = 0; i < v.size(); ++i)
        s += (v[i] * v[i]);
    return sqrt(s);
};

std::mt19937& SingletonGenerator::get_mt() {
    return mersennetwister;
}

double SingletonGenerator::getu01_sing()
{
    std::uniform_real_distribution<double> unif_real_01(0.0, 1.0);
    return unif_real_01(SingletonGenerator::get_mt());
}

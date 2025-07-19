#include<iostream>
#include<fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<double> solveCubic(double a, double b, double c, double d) {
    vector<double> roots;

    // Handle degenerate cases
    if (fabs(a) < 1e-12) {
        // quadratic: bx^2 + cx + d = 0
        if (fabs(b) < 1e-12) {
            // linear: cx + d = 0
            if (fabs(c) < 1e-12) return roots;
            roots.push_back(-d / c);
            return roots;
        }
        double Δ = c*c - 4*b*d;
        if (Δ > 0) {
            roots.push_back((-c + sqrt(Δ)) / (2*b));
            roots.push_back((-c - sqrt(Δ)) / (2*b));
        } else if (fabs(Δ) < 1e-12) {
            roots.push_back(-c / (2*b));
        }
        return roots;
    }

    // Depress the cubic: x = t - b/(3a)
    double p = (3*a*c - b*b) / (3*a*a);
    double q = (2*b*b*b - 9*a*b*c + 27*a*a*d) / (27*a*a*a);
    double discr = q*q/4 + p*p*p/27;
    double shift = -b / (3*a);

    if (fabs(discr) < 1e-14) discr = 0;

    if (discr > 0) {
        // one real root
        double U = cbrt(-q/2 + sqrt(discr));
        double V = cbrt(-q/2 - sqrt(discr));
        roots.push_back(U + V + shift);

    } else if (discr == 0) {
        // multiple real roots (at least two equal)
        double U = cbrt(-q/2);
        roots.push_back(2*U + shift);
        roots.push_back(-U + shift);

    } else {
        // three distinct real roots
        double rho   = sqrt(-p*p*p/27);
        double theta = acos((-q/2) / rho);
        double r     = 2 * sqrt(-p/3);

        roots.push_back(r * cos(theta/3)            + shift);
        roots.push_back(r * cos((theta + 2*M_PI)/3) + shift);
        roots.push_back(r * cos((theta + 4*M_PI)/3) + shift);

        sort(roots.begin(), roots.end());
    }

    return roots;
}
int main(){
    // a + b + c = 50
    // b/a + c/b + a/c = 450
    // b^2 c + c^2 a + a^2 b = 450 a b c
    int c1,c2,c3,c4;
    double a;
    double b,c;
    vector<double> roots;
    ofstream cout;
    cout.open("abc.txt");
    for(a = 1.0; a<50; a++){
        c1 = -1;
        c2 = 450.0*a + 50;
        c3 = 453.0*a*a - 22600.0*a;
        c4 = (50.0-a)*(50.0-a)*a;
        // the above is a cubic equation in b when I sub the value of a and c as 50 - a - b
        roots = solveCubic(c1,c2,c3,c4);
        for(auto root : roots){
            b = root;
            c = 50 - a - b;
            double sum = a + b + c;
            double lhs = b/a + c/b + a/c;
            double spl = a*a + b*b + c*c;
            if(a > 0 && b > 0 && c > 0){
                cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<"\n";
                cout<<"a + b + c = "<<sum<<"\n";
                cout<<"b/a + c/b + a/c = "<<lhs<<"\n";
                cout<<"a*a + b*b + c*c = "<<spl<<"\n";
                cout<<"\n";
            }
        }
    }
}
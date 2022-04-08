#include<bits/stdc++.h>
using namespace std;
struct fraction {
    int a, b;
    fraction(int x, int y) {assert(y != 0); a = x; b = y; int c = __gcd(a, b); a/=c; b/=c;}
    friend istream& operator>>(istream& in, fraction& f) {in >> f.a >> f.b; return in;}
    friend ostream& operator<<(ostream& out, fraction& f) {out << f.a << ' ' << f.b; return out;}
    bool operator<(fraction& f) {return a*f.b < b*f.a;}
    bool operator<=(fraction& f) {return a*f.b <= b*f.a;}
    bool operator>(fraction& f) {return a*f.b > b*f.a;}
    bool operator>=(fraction& f) {return a*f.b >= b*f.a;}
    fraction operator+(fraction& f) {return fraction(a*f.b + b*f.a, b*f.b);}
    fraction operator-(fraction& f) {return fraction(a*f.b - b*f.a, b*f.b);}
    fraction operator*(fraction& f) {return fraction(a*f.a, b*f.b);}
    fraction operator/(fraction& f) {return fraction(a*f.b, b*f.a);}
};
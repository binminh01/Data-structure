struct fraction {
    int a, b;
    fraction(int x, int y = 1) {
        assert(y != 0);
        a = x; b = y;
        int c = __gcd(abs(a), abs(b));
        a/=c;
        b/=c;
        if (b < 0) a = -a, b = -b;
    }
    friend istream& operator>>(istream& in, fraction &f) {in >> f.a >> f.b; return in;}
    friend ostream& operator<<(ostream& out, fraction f) {out << f.a << '/' << f.b; return out;}
    bool operator==(fraction f) const {return a == f.a && b == f.b;}
    bool operator<(fraction f) const {return a*f.b < b*f.a;}
    bool operator<=(fraction f) const {return a*f.b <= b*f.a;}
    bool operator>(fraction f) const {return a*f.b > b*f.a;}
    bool operator>=(fraction f) const {return a*f.b >= b*f.a;}
    fraction operator+(fraction f) const {return fraction(a*f.b + b*f.a, b*f.b);}
    fraction operator-(fraction f) const {return fraction(a*f.b - b*f.a, b*f.b);}
    fraction operator*(fraction f) const {return fraction(a*f.a, b*f.b);}
    fraction operator/(fraction f) const {return fraction(a*f.b, b*f.a);}
    fraction operator+(int n) const {return fraction(a + b*n, b);}
    fraction operator-(int n) const {return fraction(a - b*n, b);}
    fraction operator*(int n) const {return fraction(a*n, b);}
    fraction operator/(int n) const {return fraction(a, b*n);}
};
using F = fraction;

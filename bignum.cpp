struct bignum {
    string s;
    bignum() {
        this->s = "0";
    }
    bignum(string a) {
        s = a;
    }
    bignum(int a) {
        s = to_string(a);
    }
    bignum(ll a) {
        s = to_string(a);
    }
    friend istream &operator>>(istream &is, bignum &a) {
        is >> a.s;
        return is;
    }
    friend ostream &operator<<(ostream &os, const bignum &a) {
        os << a.s;
        return os;
    }
    bool operator<(const bignum &a) const {
        if (sz(s) < sz(a.s)) return 1;
        if (sz(s) > sz(a.s)) return 0;
        return s < a.s;
    }
    bool operator>(const bignum &a) const {
        if (sz(s) > sz(a.s)) return 1;
        if (sz(s) < sz(a.s)) return 0;
        return s > a.s;
    }
    bool operator==(const bignum &a) {
        return s == a.s;
    }
    bool operator!=(const bignum &a) {
        return s != a.s;
    }
    bool operator<=(const bignum &a) {
        if (sz(s) < sz(a.s)) return 1;
        if (sz(s) > sz(a.s)) return 0;
        return s <= a.s;
    }
    bool operator>=(const bignum &a) {
        if (sz(s) > sz(a.s)) return 1;
        if (sz(s) < sz(a.s)) return 0;
        return s >= a.s;
    }
    bignum operator+(const bignum &a) {
        string x = "";
        int m = s.size(), n = a.s.size();
        int d = abs(m - n), c = 0;
        for (int i = min(m, n) - 1; i >= 0; i--) {
            int sum = c;
            if (m < n) sum+=s[i] - '0' + a.s[i + d] - '0';
            else sum+=s[i + d] - '0' + a.s[i] - '0';
            x+=sum % 10 + '0';
            c = sum/10;
        }
        if (m < n) {
            for (int i = n - m - 1; i >= 0; i--) {
                int sum = ((a.s[i] - '0') + c);
                x+=sum % 10 + '0';
                c = sum/10;
            }
        } else {
            for (int i = m - n - 1; i >= 0; i--) {
                int sum = ((s[i] - '0') + c);
                x+=sum % 10 + '0';
                c = sum/10;
            }
        }
        if (c) x+=c + '0';
        while (x.size() > 1 && x.back() == '0') x.pop_back();
        reverse(x.begin(), x.end());
        return bignum(x);
    }
    bignum operator-(const bignum &a) {
        string x = "";
        int m = s.size(), n = a.s.size();
        int d = m - n, c = 0;
        for (int i = n - 1; i >= 0; i--) {
            int sub = ((s[i + d] - '0') - (a.s[i] - '0') - c);
            if (sub < 0) {
                sub = sub + 10;
                c = 1;
            } else c = 0;
            x+=sub + '0';
        }
        for (int i = m - n - 1; i >= 0; i--) {
            if (s[i] == '0' && c) {
                x+='9';
                continue;
            }
            int sub = ((s[i] - '0') - c);
            if (i > 0 || sub > 0) x+=sub + '0';
            c = 0;
        }
        while (x.size() > 1 && x.back() == '0') x.pop_back();
        reverse(x.begin(), x.end());
        return bignum(x);
    }
    bignum operator*(const bignum &a) {
        int m = s.size(), n = a.s.size();
        string x(m + n, '0');
        int p = 0;
        for (int i = m - 1; i >= 0; i--) {
            int c = 0, q = 0;
            for (int j = n - 1; j >= 0; j--) {
                int sum = (s[i] - '0')*(a.s[j] - '0') + x[p + q] - '0' + c;
                x[p + q] = sum % 10 + '0';
                c = sum/10;
                q++;
            }
            if (c > 0) x[p + q]+=c;
            p++;
        }
        while (x.size() > 1 && x.back() == '0') x.pop_back();
        reverse(x.begin(), x.end());
        return bignum(x);
    }
};

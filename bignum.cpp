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
        return !(s < a.s);
    }
    bool operator==(const bignum &a) {
        return s == a.s;
    }
    bool operator>=(const bignum &a) {
        return s == a.s || s > a.s;
    }
    bool operator<=(const bignum &a) {
        return s == a.s || s < a.s;
    }
    bignum operator+(const bignum &a) {
        string x = "";
        int m = s.size(), n = a.s.size();
        int d = n - m, c = 0;
        for (int i = min(m, n) - 1; i >= 0; i--) {
            int sum = ((s[i] - '0') + (a.s[i + d] - '0') + c);
            x.push_back(sum % 10 + '0');
            c = sum/10;
        }
        if (m < n) {
            for (int i = n - m - 1; i >= 0; i--) {
                int sum = ((a.s[i] - '0') + c);
                x.push_back(sum % 10 + '0');
                c = sum/10;
            }
        } else {
            for (int i = m - n - 1; i >= 0; i--) {
                int sum = ((s[i] - '0') + c);
                x.push_back(sum % 10 + '0');
                c = sum/10;
            }
        }
        if (c) x.push_back(c + '0');
        while (sz(x) > 1 && x.back() == '0') x.pop_back();
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
            x.push_back(sub + '0');
        }
        for (int i = m - n - 1; i >= 0; i--) {
            if (s[i] == '0' && c) {
                x.push_back('9');
                continue;
            }
            int sub = ((s[i] - '0') - c);
            if (i > 0 || sub > 0) x.push_back(sub + '0');
            c = 0;
        }
        while (sz(x) > 1 && x.back() == '0') x.pop_back();
        reverse(x.begin(), x.end());
        return bignum(x);
    }
    bignum operator*(const bignum &a) {
        if (s == "0" || a.s == "0") return bignum(0);
        string x = "";
        int m = s.size() - 1, n = a.s.size() - 1, c = 0;
        for (int i = 0; i <= m + n; i++) {
            for (int j = max(0, i - n); j <= min(i, m); j++) {
                c+=(s[m - j] - '0')*(a.s[n - i + j] - '0');
            }
            x+=c % 10 + '0';
            c/=10;
        }
        reverse(x.begin(), x.end());
        return bignum(x);
    }
};

#include <bits/stdc++.h>
using namespace std;
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
    bignum operator+(const bignum &a) {
        string x = "";
        int l1 = s.size(), l2 = a.s.size();
        int d = l2 - l1;
        int carry = 0;
        for (int i = min(l1, l2) - 1; i >= 0; i--)
        {
            int sum = ((s[i] - '0') + (a.s[i + d] - '0') + carry);
            x.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (l1 < l2) {
            for (int i = l2 - l1 - 1; i >= 0; i--)
            {
                int sum = ((a.s[i] - '0') + carry);
                x.push_back(sum % 10 + '0');
                carry = sum / 10;
            }
        } else {
            for (int i = l1 - l2 - 1; i >= 0; i--) {
                int sum = ((s[i] - '0') + carry);
                x.push_back(sum % 10 + '0');
                carry = sum / 10;
            }
        }
        if (carry) x.push_back(carry + '0');
        reverse(x.begin(), x.end());
        return bignum(x);
    }
    bignum operator-(const bignum &a) {
        string x = "";
        int l1 = s.size(), l2 = a.s.size();
        int d = l1 - l2;
        int carry = 0;
        for (int i = l2 - 1; i >= 0; i--)
        {
            int sub = ((s[i + d] - '0') - (a.s[i] - '0') - carry);
            if (sub < 0)
            {
                sub = sub + 10;
                carry = 1;
            }
            else carry = 0;
            x.push_back(sub + '0');
        }
        for (int i = l1 - l2 - 1; i >= 0; i--)
        {
            if (s[i] == '0' && carry)
            {
                x.push_back('9');
                continue;
            }
            int sub = ((s[i] - '0') - carry);
            if (i > 0 || sub > 0) x.push_back(sub + '0');
            carry = 0;
        }
        reverse(x.begin(), x.end());
        return bignum(x);
    }
};
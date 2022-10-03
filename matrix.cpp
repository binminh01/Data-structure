template<class T>
struct matrix {
    int n, m;
    vector<vector<T>> a;
    matrix(int N, int M) {
        n = N; m = M;
        a.assign(n, vector<T>(m));
    }
    matrix(const vector<vector<T>> &b) {
        a = b;
        n = sz(a); m = sz(a[0]);
    }
    friend istream& operator>>(istream& in, matrix &b) {in >> b.a; return in;}
    friend ostream& operator<<(ostream& out, matrix b) {out << b.a; return out;}
    static matrix single(int k) {
        matrix b(k, k);
        while (k--) b.a[k][k] = 1;
        return b;
    }
    matrix operator*(const matrix &b) {
        matrix c(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                for (int j = 0; j < b.m; j++) {
                    c.a[i][j]+=a[i][k]*b.a[k][j];
                    if (c.a[i][j] >= mod) c.a[i][j]%=mod;
                }
            }
        }
        return c;
    }
    matrix pow(int k) {
        matrix x = single(n), b = a;
        for (; k; k>>=1, b = b*b) {
            if (k & 1) x = x*b;
        }
        return x;
    }
};
using mat = matrix<ll>;

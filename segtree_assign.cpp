template<class T>
struct segtree_assign {
    int n;
    vector<T> t;
    vector<bool> c;
    void init(int N) {
        n = N;
        t.resize(4*n);
        c.resize(4*n);
    }
    void down(int i) {
        if (c[i]) {
            t[2*i] = t[2*i + 1] = t[i];
            c[2*i] = c[2*i + 1] = 1;
            c[i] = 0;
        }
    }
    void set(int l, int r, int x, int lx, int rx, T d) {
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r) {
            t[x] = d;
            c[x] = 1;
            return;
        }
        down(x);
        int m = (lx + rx)/2;
        set(l, r, 2*x, lx, m, d);
        set(l, r, 2*x + 1, m + 1, rx, d);
    }
    T get(int i, int x, int lx, int rx) {
        if (lx == rx) return t[x];
        down(x);
        int m = (lx + rx)/2;
        if (i <= m) return get(i, 2*x, lx, m);
        return get(i, 2*x + 1, m + 1, rx);
    }
    void set(int l, int r, T d) {set(l, r, 1, 1, n, d);}
    T get(int i) {return get(i, 1, 1, n);}
};

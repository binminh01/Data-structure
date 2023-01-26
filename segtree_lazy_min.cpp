template<class T>
struct segtree_lazy_min {
    int n;
    vector<T> t, la;
    T neutral = 0;
    T merge(T a, T b) {return min(a, b);}
    void init(int N) {
        n = N;
        t.resize(4*n);
        la.resize(4*n);
    }
    void build(const vector<T> &a, int x, int lx, int rx) {
        if (lx == rx) {
            t[x] = a[lx];
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x, lx, m);
        build(a, 2*x + 1, m + 1, rx);
        t[x] = merge(t[2*x], t[2*x + 1]);
    }
    void down(int i) {
        t[2*i]+=la[i], t[2*i + 1]+=la[i];
        la[2*i]+=la[i], la[2*i + 1]+=la[i];
        la[i] = 0;
    }
    void set(int l, int r, int x, int lx, int rx, int d) {
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r) {t[x]+=d; la[x]+=d; return;}
        down(x);
        int m = (lx + rx)/2;
        set(l, r, 2*x, lx, m, d);
        set(l, r, 2*x + 1, m + 1, rx, d);
        t[x] = merge(t[2*x], t[2*x + 1]);
    }
    T get(int l, int r, int x, int lx, int rx) {
        if (lx > r || rx < l) return neutral;
        if (lx >= l && rx <= r) return t[x];
        down(x);
        int m = (lx + rx)/2;
        return merge(get(l, r, 2*x, lx, m), get(l, r, 2*x + 1, m + 1, rx));
    }
    void build(const vector<T> &a) {build(a, 1, 1, n);}
    void set(int l, int r, int d) {set(l, r, 1, 1, n, d);}
    T get(int l, int r) {return get(l, r, 1, 1, n);}
};

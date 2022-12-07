template<class T>
struct segtree {
    int n;
    vector<T> t;
    T neutral = 0;
    T merge(T a, T b) {return a + b;}
    void init(int N) {n = N; t.resize(4*n);}
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
    void set(int i, T v, int x, int lx, int rx) {
        if (lx == rx) {
            t[x] = v;
            return;
        }
        int m = (lx + rx)/2;
        if (i <= m) set(i, v, 2*x, lx, m);
        else set(i, v, 2*x + 1, m + 1, rx);
        t[x] = merge(t[2*x], t[2*x + 1]);
    }
    T get(int l, int r, int x, int lx, int rx) {
        if (lx > r || rx < l) return neutral;
        if (lx >= l && rx <= r) return t[x];
        int m = (lx + rx)/2;
        return merge(get(l, r, 2*x, lx, m), get(l, r, 2*x + 1, m + 1, rx));
    }
    void build(const vector<T> &a) {build(a, 1, 1, n);}
    void set(int i, int v) {set(i, v, 1, 1, n);}
    T get(int l, int r) {return get(l, r, 1, 1, n);}
};

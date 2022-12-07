template<class T>
struct segtree_lazy {
    int n;
    vector<T> t, la;
    T neutral = 0;
    T merge(T a, T b) {return a + b;}
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
    void down(int i, int l, int r) {
        T k = la[i];
        int m = (l + r)/2;
        if (k != 0) {
            t[2*i]+=k*(m - l + 1);
            t[2*i + 1]+=k*(r - m);
            la[2*i]+=k; la[2*i + 1]+=k;
            la[i] = 0;
        }
    }
    void set(int l, int r, int x, int lx, int rx, T d) {
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r) {t[x]+=d*(rx - lx + 1); la[x]+=d; return;}
        down(x, lx, rx);
        int m = (lx + rx)/2;
        set(l, r, 2*x, lx, m, d);
        set(l, r, 2*x + 1, m + 1, rx, d);
        t[x] = merge(t[2*x], t[2*x + 1]);
    }
    T get(int l, int r, int x, int lx, int rx) {
        if (lx > r || rx < l) return neutral;
        if (lx >= l && rx <= r) return t[x];
        down(x, lx, rx);
        int m = (lx + rx)/2;
        return merge(get(l, r, 2*x, lx, m), get(l, r, 2*x + 1, m + 1, rx));
    }
    void build(const vector<T> &a) {build(a, 1, 1, n);}
    void set(int l, int r, int d) {set(l, r, 1, 1, n, d);}
    T get(int l, int r) {return get(l, r, 1, 1, n);}
};

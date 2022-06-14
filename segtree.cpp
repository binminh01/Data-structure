struct segtree {
    int n;
    vector<ll> t;
    int neutral = 0;
    int merge(int a, int b) {return a + b;}
    void init(int N) {n = N; t.assign(4*n, 0ll);}
    void build(vector<int> &a, int x, int lx, int rx) {
        if (lx == rx) {
            t[x] = a[lx];
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x, lx, m);
        build(a, 2*x + 1, m + 1, rx);
        t[x] = merge(t[2*x], t[2*x + 1]);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (lx == rx) {
            t[x] = v;
            return;
        }
        int m = (lx + rx)/2;
        if (i <= m) set(i, v, 2*x, lx, m);
        else set(i, v, 2*x + 1, m + 1, rx);
        t[x] = merge(t[2*x], t[2*x + 1]);
    }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx > r || rx < l) return neutral;
        if (lx >= l && rx <= r) return t[x];
        int m = (lx + rx)/2;
        return merge(get(l, r, 2*x, lx, m), get(l, r, 2*x + 1, m + 1, rx));
    }
    void build(vector<int> &a) {build(a, 1, 1, n);}
    void set(int i, int v) {set(i, v, 1, 1, n);}
    int get(int l, int r) {return get(l, r, 1, 1, n);}
};
struct segtree_lazy {
    int n;
    vector<ll> t, la;
    void init(int N) {
        n = N;
        t.assign(4*n, 0ll);
        la.assign(4*n, 0ll);
    }
    void build(vector<int> &a, int x, int lx, int rx) {
        if (lx == rx) {
            t[x] = a[lx];
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x, lx, m);
        build(a, 2*x + 1, m + 1, rx);
        t[x] = max(t[2*x], t[2*x + 1]);
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
        t[x] = max(t[2*x], t[2*x + 1]);
    }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx > r || rx < l) return 0;
        if (lx >= l && rx <= r) return t[x];
        down(x);
        int m = (lx + rx)/2;
        return max(get(l, r, 2*x, lx, m), get(l, r, 2*x + 1, m + 1, rx));
    }
};

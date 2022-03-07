#include<bits/stdc++.h>
using namespace std;
struct segtree {
    int sz;
    vector<int> t;
    void init(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        t.assign(sz << 1, 0ll);
    }
    void build(int n, vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < n) t[x] = a[lx];
            return;
        }
        int m = (lx + rx) >> 1;
        build(n, a, (x << 1) + 1, lx, m);
        build(n, a, (x << 1) + 2, m, rx);
        t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = v;
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m) set(i, v, (x << 1) + 1, lx, m);
        else set(i, v, (x << 1) + 2, m, rx);
        t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
    }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return t[x];
        int m = (lx + rx) >> 1;
        return get(l, r, (x << 1) + 1, lx, m) + get(l, r, (x << 1) + 2, m, rx);
    }
    void build(int n, vector<int> &a) {build(n, a, 0, 0, sz);}
    void set(int i, int v) {set(i, v, 0, 0, sz);}
    int get(int l, int r) {return get(l, r, 0, 0, sz);}
};
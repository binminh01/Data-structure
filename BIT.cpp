struct BIT {
    int n;
    vector<int> bit;
    void init(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void build(int n, vector<int> &a) {
        this->n = n;
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++) set(i, a[i]);
    }
    void set(int i, int v) {
        for (i++; i <= n; i+=i & (-i)) bit[i]+=v;
    }
    int get(int i) {
        int x = 0;
        for (i++; i; i-=i & (-i)) x+=bit[i];
        return x;
    }
    int get(int l, int r) {
        if (l == 0) return get(r);
        return get(r) - get(l - 1);
    }
};

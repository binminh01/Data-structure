struct BIT {
    int n;
    vector<int> bit;
    void init(int N) {
        n = N;
        bit.assign(n + 1, 0);
    }
    void build(vector<int> &a) {
        for (int i = 1; i <= n; i++) set(i, a[i]);
    }
    void set(int i, int v) {
        for (; i <= n; i+=i & (-i)) bit[i]+=v;
    }
    int get(int i) {
        int x = 0;
        for (; i; i-=i & (-i)) x+=bit[i];
        return x;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} bit;

template<class T>
struct BIT {
    int n;
    vector<T> bit;
    void init(int N) {
        n = N;
        bit.resize(n + 1);
    }
    void build(const vector<T> &a) {
        for (int i = 1; i <= n; i++) set(i, a[i]);
    }
    void set(int i, T v) {
        for (; i <= n; i+=i & (-i)) bit[i]+=v;
    }
    T get(int i) {
        T x = 0;
        for (; i; i-=i & (-i)) x+=bit[i];
        return x;
    }
    T get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

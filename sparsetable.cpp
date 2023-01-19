int Log2(int n) {
    return 31 - __builtin_clz(n);
}
int st[20][200001];
void build(vi &a, int n) {
    for (int i = 0; i < n; i++) st[0][i] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
}
int query(int l, int r) {
    int i = Log2(r - l + 1);
    return min(st[i][l], st[i][r - (1 << i) + 1]);
}

int st[200001][20];
void build(vi &a, int n) {
    for (int i = 0; i < n; i++) st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int query(int l, int r) {
    int i = (int)log2(r - l + 1);
    return __gcd(st[l][i], st[r - (1 << i) + 1][i]);
}

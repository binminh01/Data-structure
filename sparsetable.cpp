int Log2(int n) {
    int x = 0;
    while ((1 << x) <= n) x++;
    return x - 1;
}
int st[200001][20];
void build(vi &a, int n) {
    for (int i = 0; i < n; i++) st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int query(int l, int r) {
    int i = (int)Log2(r - l + 1);
    return min(st[l][i], st[r - (1 << i) + 1][i]);
}

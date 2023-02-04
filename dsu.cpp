struct dsu {
    vector<int> par, sz;
    void init(int n) {
        par.resize(n);
        sz.assign(n, 1);
        iota(all(par), 0);
    }
    int get(int u)  {return u == par[u] ? u: par[u] = get(par[u]);}
    void merge(int u, int v) {
        u = get(u), v = get(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            par[v] = u;
            sz[u]+=sz[v];
        }
    }
};

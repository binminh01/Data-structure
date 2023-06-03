vi manacher_odd(string s) {
    int n = sz(s);
    s = "!" + s + "@";
    vi p(n + 2);
    int l = 1, r = 1;
    FOR(i,1,n){
        p[i] = max(0, min(r - i, p[l + r - i]));
        while (s[i - p[i]] == s[i + p[i]]) p[i]++;
        if (i + p[i] > r) l = i - p[i], r = i + p[i];
    }
    p.erase(p.begin()); p.pop_back();
    return p;
}
vi manacher(const string &s) {
    string t;
    trav(i,s) t+='#', t+=i;
    t+='#';
    vi a = manacher_odd(t);
    a.erase(a.begin()); a.pop_back();
    return a;
}

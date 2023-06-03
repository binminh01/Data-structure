vi prefix_function(const string &s) {
    int n = sz(s);
    vi p(n);
    For(i,1,n){
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}
vi kmp(const string &s, const string &t) {
    int n = sz(s), m = sz(t);
    vi p = prefix_function(s);
    int j = 0;
    vi a;
    For(i,0,m){
        while (j > 0 && t[i] != s[j]) j = p[j - 1];
        if (t[i] == s[j]) j++;
        if (j == n) a.push_back(i - n + 1);
    }
    return a;
}

struct customhash {
    static uint64_t splitmix64(uint64_t x) {
        x += 11400714819323198485ULL;
        x = (x ^ (x >> 30)) * 13787848793156543929ULL;
        x = (x ^ (x >> 27)) * 10723151780598845931ULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        return splitmix64(x + chrono::steady_clock::now().time_since_epoch().count());
    }
};

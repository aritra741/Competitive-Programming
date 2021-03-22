const int K = MAX_D / 64 + 1;
unsigned long long x[MAX_N][K];
int intersection(int i, int j) {
	int total = 0;
	for(int z = 0; z < K; z++) {
		total += __builtin_popcountll(x[i][z] & x[j][z]);
	}
	return total;
}

// Another
template<const int n> struct Bitset{
    const static int  m =  (n + 63) / 64, ex = 64 - m * 64 + n;
    unsigned long long a[m], all = (1ull << 63) | ((1ull << 63) - 1);
    Bitset() { memset(a,0,sizeof(a)); }
    bool operator [] (const int i) {
        return a[i / 64] & (1ull << (i & 63));
    }
    void set(int i) {
        a[i / 64] |= (1ull << (i & 63));
    }
    void set() {
        for(int i = 0; i < m; i++) a[i] = all;
    }
    void reset(int i) {
        a[i / 64] &= (all ^ (1ull << (i & 63)));
    }
    void reset() { memset(a, 0, sizeof a);}
    void flip(int i) {
        a[i / 64] ^= (1ull << (i & 63));
    }
    int count() {
        int ans = 0; for(int i = 0; i < m; i++) ans += __builtin_popcountll(a[i]);
        return ans;
    }
    Bitset operator << (const int k) const{
        Bitset b;
        int s1 = k & 63, s2 = 64 - s1;
        for (int i = m-1, j = i - (k + 63) / 64; j > -2; i--, j--){
            b.a[i] = a[j+1] << s1;
            if (j > -1) b.a[i] |= a[j] >> s2;
        }
        if (ex!=64) b.a[m-1] ^= (b.a[m-1]>>ex)<<ex;
        return b;
    }
    Bitset operator >> (const int k) const{
        Bitset b;
        int s1 = k & 63, s2 = 64 - s1;
        for (int i = 0, j = (k + 63) / 64; j <= m; i++, j++){
            b.a[i] = a[j-1] >> s1;
            if (j < m ) b.a[i] |= a[j] << s2;
        }
        return b;
    }
    Bitset operator | (const Bitset &r) const{
        Bitset b; for (int i = 0; i < m; i++) b.a[i] = a[i] | r.a[i];
        return b;
    }
    Bitset operator & (const Bitset &r) const{
        Bitset b; for (int i = 0; i < m; i++) b.a[i] = a[i] & r.a[i];
        return b;
    }
    void operator &= (const Bitset &r) const{
        Bitset b; for (int i = 0; i < m; i++) a[i] = a[i] & r.a[i];
    }
    Bitset operator ^ (const Bitset &r) const{
        Bitset b; for (int i = 0; i < m; i++) b.a[i] = a[i] ^ r.a[i];
        return b;
    }
};
 
const int N = 2e5 + 1;
 
bitset<N> bs[26], ans; int p[26];
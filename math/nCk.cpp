const int MOD  = (int)1e9 + 7;
const int MAXN = 2000010;

int mul(int a, int b) { return ((long long) a * b) % MOD; }
int add(int a, int b) { return ((long long) a + b) % MOD; }

int fexp(int b, int e) {
    if (b == 0 || e == 1) return b;
    if (b == 1 || e == 0) return 1;
    int r = fexp(b, e / 2);
    if (e & 1) return mul(mul(r, r), b);
    return mul(r, r);
}

int fat[MAXN], ifat[MAXN];

void build() {
    fat[0] = 1;
    for(int i = 1; i < MAXN; ++i)
        fat[i] = mul(i, fat[i - 1]);

  /*
    proof: 
    (k + 1) ^-1 = k! ^-1 * (k + 1) ^-1
    (k + 1) ^-1 * (k + 1) = k! ^-1
    ifat[k] = (k + 1) * ifat[k + 1]
  */

    ifat[MAXN - 1] = fexp(fat[MAXN - 1], MOD - 2);

    for(int i = MAXN - 2; i >= 0; --i)
        ifat[i] = mul(i + 1, ifat[i + 1]);
}

int comb(int n, int r) { 
    if (n < r) return 0; 
    return mul(fat[n], mul(ifat[r], ifat[n - r])); 
}

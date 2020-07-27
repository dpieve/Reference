using LL = long long;
const int MAXN = 101;
const int MOD = 1000000007;

struct Matrix {
    
    LL mat[MAXN][MAXN];

    Matrix () { 
        for(int i = 0; i < MAXN; ++i)
            for(int j = 0; j < MAXN; ++j)
                mat[i][j] = 0;
    }

    Matrix operator * (Matrix b) {
        Matrix a;
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                for (int k = 0; k < MAXN; ++k) {
                    a.mat[i][j] += ((mat[i][k] % MOD) * (b.mat[k][j] % MOD)) % MOD;
                    a.mat[i][j] %= MOD;
                }
            }
        }
        return a;
    }

};

// Matrix total = fexp(mat, k);

Matrix fexp (Matrix b, LL e) {
    Matrix prod;
    for(int i = 0; i < MAXN; ++i)
        prod.mat[i][i] = 1;
    while(e > 0) {
        if (e % 2) prod = prod * b;
        b = b * b;
        e /= 2;
    }
    return prod;
}

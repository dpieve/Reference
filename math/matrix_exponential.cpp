#define ll long long 

const int MOD = 1e9;

struct Matrix {
	
	ll mat[10][10];

	Matrix () { memset (mat, 0, sizeof mat); }

	Matrix operator * (Matrix b) {
		Matrix a;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					a.mat[i][j] += ((mat[i][k] % MOD) * (b.mat[k][j] % MOD)) % MOD;
					a.mat[i][j] %= MOD;
				}
			}
		}
		return a;
	}

};

ll N; // resp = fexp (F, N) * D;

Matrix fexp (Matrix b, ll e) {
	if (e == 1) return b;
	if (e & 1) return b * fexp (b, e - 1);
	Matrix r = fexp (b, e / 2);
	return r * r;

}
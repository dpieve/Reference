#include <bits/stdc++.h>

using namespace std;
#define ll long long 

const int MAXN = 2;

struct Matrix { 
	
	ll mat[MAXN][MAXN]; 
	
	Matrix () { 
		memset (mat, 0, sizeof mat); 
	}

	void print () {
		for (int i = 0; i < MAXN; ++i){
			for (int j = 0; j < MAXN; ++j) {
				cout << mat[i][j] << ' ';
			}
			cout << '\n';
		}
	}


};	

Matrix matMult (Matrix a, Matrix b) {
		Matrix ans;
		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				for (int k = 0; k < MAXN; ++k) {
					ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				}
			}
		}
		return ans;
}


Matrix fexp (Matrix base, ll p) {
	Matrix ans;

	for (int i = 0; i < MAXN; ++i) 
		for (int j = 0; j < MAXN; ++j) 
			ans.mat[i][j] = (i == j);

	while (p) {
		if (p & 1) ans = matMult(ans, base);
		base = matMult(base, base);
		p >>= 1;
	}

	return ans;    
}

int main () {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	ll n;
	cin >> n;

	Matrix F;

	F.mat[0][0] = 3;
	F.mat[0][1] = 0;
	
	F.mat[1][0] = 2;
	F.mat[1][1] = 1;

	Matrix DP;

	DP.mat[0][0] = 1;
	DP.mat[1][0] = 0;

	Matrix mult = matMult (fexp(F, n - 1), DP);

	mult.print();



	return 0;
}



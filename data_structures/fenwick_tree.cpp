const int MAXN = 200010;

int t[MAXN], N;

void add (int k, int v) {
	while (k < MAXN) {
		t[k] += v;
		k += (k & (-k));
	}
}

int sum (int k) {
	int s = 0;
	while (k > 0) {
		s += t[k];
		k -= (k & (-k));
	}
	return s;
}

int ask (int L, int R) { 
	return ((L == 1) ? sum (R) : (sum(R) - sum (L - 1))); 
}

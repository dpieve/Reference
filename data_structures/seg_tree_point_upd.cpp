const int N = 200000 + 5;

int t[4*N], a[N];
 
// build (1, 0, n); 
// index of the array starts with zero

void build(int i, int l, int r) {							
	if (l == r) {
		t[i] = a[l];
	} 
	else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = t[2*i] + t[2*i+1];
	}
}

// query (1, 0, n, x, y);
int query(int i, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return t[i];
	if (qr < l || r < ql) return 0;
	
	int m = (l+r) / 2;
	return query(2*i, l, m, ql, qr)
		 		+ query(2*i+1, m+1, r, ql, qr);
}

//a[p] = x // update (1, 0, n, p, x)
void update(int i, int l, int r, int p, int x) {
	if (l == r) {
		t[i] = x;
	} 
	else {	
		int m = (l+r)/2;
		if (p <= m) update(2*i, l, m, p, x);
		else update(2*i+1, m+1, r, p, x);
		
		t[i] = t[2*i] + t[2*i+1];
	}
}

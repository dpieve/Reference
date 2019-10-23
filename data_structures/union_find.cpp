const int MAXN = 200000 + 5;

int p[MAXN], sz[MAXN];

int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }

void unite(int a, int b) {
	
	/*connects smaller set to the larger set.*/
	
	if((a = find (a)) != (b = find (b))){
		if (sz[a] < sz[b]) 
			swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
	}
}

bool isSame(int a, int b) { return (find(a) == find(b)); }

void init () {
	for(int i = 0; i < MAXN; i++) {
		p[i] = i; 
		sz[i] = 1;
	}
}
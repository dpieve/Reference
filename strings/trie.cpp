// O(N * max|S|)

const int MAXN = 500500;

int nxt = 1, trie[MAXN][26], finish[MAXN];

void insert(const string S) {
	int node = 0;
	for(char s : S) {
		if (trie[node][s - 'a'] == 0) 
			node = trie[node][s - 'a'] = nxt++;
		else node = trie[node][s - 'a'];
	}
	finish[nxt - 1]++;
}

int search(const string S) {
	int idx = 0;
	for(char s : S) {
		if (trie[idx][s - 'a'] == 0)
			return 0;
		else idx = trie[idx][s - 'a'];
	}
	return finish[idx];
}

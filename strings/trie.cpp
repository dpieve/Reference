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

int main() {
	
	ios_base :: sync_with_stdio(0); cin.tie(NULL);

	int N;
	cin >> N;

	for(int i = 0; i < N; ++i) {
		string S;
		cin >> S;
		insert(S);
	}

	int M;
	cin >> M;

	for(int i = 0; i < M; ++i) {
		string T;
		cin >> T;

		cout << (search(T) ? "Y" : "N") << '\n';
	}

	return 0;	
}

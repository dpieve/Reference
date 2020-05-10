#include<bits/stdc++.h>

using namespace std;

using LL = long long;

const int MAXN = 200010;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
vector< pair<int,int> > G[MAXN];

void dijkstra(int source, int target) {
	priority_queue < pair<LL, int> > Q;
	Q.push(make_pair(0LL, source));

	vector< LL > D(N, INF);
	D[source] = 0;

	vector< int > P(N, -1);

	while(!Q.empty()) {
		int u = Q.top().second;
		LL d = -Q.top().first;

		Q.pop();

		if (u == target)
			break;

		if (d > D[u])
			continue;

		for(int i = 0; i < (int)G[u].size(); ++i) {
			pair<int,int> v = G[u][i];

			if (D[v.second] > D[u] + v.first) {
				D[v.second] = D[u] + v.first;
			
				P[v.second] = u;
				Q.push(make_pair(-D[v.second], v.second));
			}
		}
	}

	if (D[target] == INF) {
		cout << -1 << '\n';
		return;
	}

	vector<int> ans;
	int x = target;
	while(x != -1) {
		ans.push_back(x);
		x = P[x];
	}

	reverse(ans.begin(), ans.end());

	for(int i = 0; i < ans.size(); ++i) {
		cout << ans[i]  + 1 << ' ';
	}
	cout << '\n';

}


int main() {
	
	ios_base :: sync_with_stdio(0); cin.tie(NULL);

	cin >> N >> M;

	for(int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		G[u].push_back({w, v});
		G[v].push_back({w, u});
	}

	dijkstra(0, N - 1);


	return 0;	
}

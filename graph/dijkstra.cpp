#define MAX 100001
#define LL unsigned long long

typedef pair< LL, int > ii;

vector< ii > G[MAX];
vector< LL > dist;

int s, t, n; //read

LL dijkstra() {

	dist.assign(n, INF); dist[s] = 0;
	priority_queue< ii, vector< ii >, greater< ii > > q;
	q.push(ii(0, s));
	
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (u == t) break;
		for (auto v : G[u]) {
			if (dist[v.second] > dist[u] + v.first) {
				dist[v.second] = dist[u] + v.first;
				q.push(ii(dist[v.second], v.second));
			}
		}
	}
	return dist[t];
}

/*G[i].push_back(ii(l, a));
  G[a].push_back(ii(l, i)); */

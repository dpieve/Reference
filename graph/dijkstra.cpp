using LL = long long;

const LL INF = 1e17;
const int MAXN = 200010;

vector< LL > dist;
vector< int> parent;
vector< pair<LL, int> > G[MAXN];

LL dijkstra(int s, int t, int n) {

	dist.assign(n, INF); dist[s] = 0;
	parent.assign(n, -1); parent[s] = s;

	priority_queue< pair<LL,int> , vector< pair<LL, int> >, greater< pair<LL, int>  > > q;
	q.push(make_pair(0LL, s));
	
	while (!q.empty()) {
		int u = q.top().second; 
		q.pop();
		
		if (u == t) break;
		
		for (pair<LL,int> v : G[u]) {
			if (dist[v.second] > dist[u] + v.first) {
				dist[v.second] = dist[u] + v.first;

				parent[v.second] = u;
				q.push(make_pair(dist[v.second], v.second));
			}
		}
	}
	
	return dist[t];
	
}

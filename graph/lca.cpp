
using namespace std;
 
const int LOGN = 21;
const int MAXN = 200100;
const int INF  = 0x3f3f3f3f;
 
vector< pair<int,int> > g[MAXN];
 
int h[MAXN + 10], up[MAXN + 10][LOGN + 10], mn[MAXN + 10][LOGN + 10], mx[MAXN + 10][LOGN + 10];
 
void dfs (int x) {
 
	for (pair<int,int> y : g[x]) {
		
		if (up[x][0] == y.first) continue;
		
		h[y.first] = h[x] + 1;
		up[y.first][0] = x;
		mn[y.first][0] = mx[y.first][0] = y.second;
 
		dfs (y.first);
 
	}
 
}
 
void build (int n) {
	for (int j = 1; j < LOGN; ++j) {
		for (int i = 1; i <= n; ++i) {
			
			int p = up[i][j - 1];

			up[i][j] = up[p][j - 1];
			mn[i][j] = min (mn[p][j - 1], mn[i][j - 1]);   // get minimum edge value
			mx[i][j] = max (mx[p][j - 1], mx[i][j - 1]);   // get maximum edge value
		}
	}
}
 
 
 
pair<int,int>  ED (int x, int y) {
	
	if (h[x] < h[y]) 
		swap (x, y);
	
	int d = h[x] - h[y], D = INF, U = -INF;
 
	for (int i = LOGN - 1; i >= 0; --i) {
		if (d & (1 << i)) {
			U = max (U, mx[x][i]);
			D = min (D, mn[x][i]);
			x = up[x][i];
		}
	}
 
	if (x == y) 
		return {D, U};
 
	for (int i = LOGN - 1; i >= 0; --i) {
		if (up[x][i] != up[y][i]) {
			
			U = max (U, mx[x][i]);
			D = min (D, mn[x][i]);
 
			U = max (U, mx[y][i]);
			D = min (D, mn[y][i]);
 
			x = up[x][i];
			y = up[y][i];
		}
	}
 
 
	D = min (D, mn[x][0]);
	D = min (D, mn[y][0]);
 
	U = max (U, mx[x][0]);
	U = max (U, mx[y][0]);
 
	return {D, U};
}
 
inline void init () {
	for (int i = 0; i < MAXN; ++i) {
		for (int j = 0; j < LOGN; ++j)
		{
			up[i][j] = -1;
			mx[i][j] = -INF;
			mn[i][j] = INF;
		}
	}
}

inline void add (int a, int b, int c) {
		g[a].push_back({b, c});
		g[b].push_back({a, c});
}

int main () {
 
	
	init ();
	add (u, v, w); // u -> v, weight  = w
 
	dfs (1);
	build (n);
 
	pair<int, int> q = ED (a, b); // query
	 

	return 0;
} 
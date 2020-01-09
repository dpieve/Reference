//Para cada consulta imprimir a quantidade de valores maiores que X existem no intervalo [A, B].
//Find values greater than X between [A, B].

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
using namespace std;

using pii = pair<int,int>;

#define ordered_set tree< pii , null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 

const int MAXN = 100005;

int v[MAXN];
ordered_set t[4 * MAXN];

void build(int i, int l, int r) {
	if (l > r) return;
	
	for (int j = l; j <= r; ++j) 
		t[i].insert({v[j], j});
	
	if (l == r) return;

	int m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);

}

void upd(int i, int l, int r, int p, int x) {
	t[i].erase({v[p], p});
	t[i].insert({x,   p});	
	
	if(l == r) return;
	
	int m = (l + r) / 2;
	if (p <= m) upd(2 * i, l, m, p, x);
	else upd(2 * i + 1, m + 1, r,p, x);
}

int ask(int i, int l, int r, int x, int ql, int qr) {
	if(qr < l || r < ql) 
		return 0;
	
	if (ql <= l && r <= qr) {
		int k = t[i].order_of_key({x + 1, -1});
		return (r - l + 1) - k;
	}
	
	int m = (l + r) / 2;
	return ask(2 * i, l, m, x, ql, qr) +
			ask(2 * i + 1, m + 1, r, x, ql, qr);
}


int main() {
	ios_base :: sync_with_stdio(0); cin.tie(NULL);

	int N, Q;
	cin >> N >> Q;
	
	for (int i = 0; i < N; ++i) 
		cin >> v[i];
		
	build(1, 0, N - 1);	
	
	while(Q--) {
		int OP;
		cin >> OP;
	
		if(OP == 1) {                   // update
			int A, Y;
			cin >> A >> Y; 
			upd(1, 0, N - 1, A - 1, Y);
			v[A - 1] = Y;
		}
		else {                          // OP == 2 => query [A, B] values > X
			int X, A, B;
			cin >> X >> A >> B;
			cout << ask(1, 0, N - 1, X, A - 1, B - 1) << '\n';
		}
	}
	
	return 0;
}

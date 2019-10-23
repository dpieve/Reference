#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
const int MAXN = 200000 + 5;

// ii = L, R. int = position
vector< pair< ii, int > > queries;											

// read n and a[i]
int n, a[MAXN], freq[MAXN], ans[MAXN], block;

int cmp(const pair< ii,int >& x, const pair< ii, int >& y){
	int a = x.first.first / block;	
	int b = y.first.first / block;

	if(a != b) return x.first.first < y.first.first;
	return x.first.second < y.first.second;
}

void MO () {
	block = static_cast<int>(sqrt(n));

	int num_queries;
	scanf("%d", &num_queries);

	for(int i = 0, l, r; i < num_queries; ++i){
		scanf("%d %d", &l, &r);
		queries.push_back({{l-1, r-1}, i});	
	}

	sort(queries.begin(), queries.end(), cmp);

	int start = 0, end = -1, cnt = 0;
	
	/*count number different elements [L, R] */

	for(auto x : queries) {

		int left = x.first.first;
		int right= x.first.second;

		while(end < right){
			++end;
			++freq[a[end]];
			if(freq[a[end]] == 1) ++cnt;
		}

		while(end > right){
			--freq[a[end]];
			if(freq[a[end]] == 0 && cnt>0) --cnt;
			--end;
		}
		
		while(start < left){
			--freq[a[start]];
			if(freq[a[start]] == 0 && cnt>0) --cnt;		
			++start;
		}
		
		while(start > left){
			--start;
			++freq[a[start]];
			if(freq[a[start]] == 1) ++cnt;
		}

		// ans[i] -> correct position for queries
		ans[x.second] = cnt; 

	}

	for(int i = 0; i < num_queries; ++i) 
		printf("%d\n", ans[i]);

}

int main () {	

	int n; 
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) { 
		scanf("%d", &a[i]); 
	}
	
	MO();
	
	return 0;
}
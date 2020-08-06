#include <bits/stdc++.h>

using namespace std;


#define what_is(x) cerr << #x << " is " << x << endl;


int main () {
	
    	freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
	
	
	int a[10], n = 10;

	for (int i = 0; i < n; ++i)
		cout << a[i] << " \n"[i == n - 1];

	auto f = [] (int a, int b) -> int { return a + b; }; 
	cout << f(1, 2);
	
	sort(begin(v), end(v), [] (int a, int b) { return a > b; }); 
	
	for (auto i: v) 
		cout << i << ' ';

	// one element
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	
	//substring
	string str = "................";
	std::string str2 = str.substr (3,5); // 3 = start, 5 = len
	
	//binary search pair
	x.lower_bound({first, -inf}); // iterator to the first pair with value >= first. -INF get the first
	x.upper_bound({first,  inf}); // iterator to the first pair with value  > first  +INF get the next when tie happen
	
	
	return 0;
}

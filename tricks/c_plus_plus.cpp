#include <bits/stdc++.h>

using namespace std;


#define what_is(x) cerr << #x << " is " << x << endl;


int main () {
	
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
	
	return 0;
}

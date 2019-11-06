#include <bits/stdc++.h>

using namespace std;

tuple <int,int,int> gcd (int a, int b) {
		if (b == 0) {
			return {1, 0, a};
		}
		else {
			int x, y, g;
			tie (x, y, g) = gcd (b, a % b);
			return {y, x - (a / b) * y, g};
		}
}

int main () {

	int a=30, b=12, x, y, g;
	tie (x, y, g) = gcd (a, b);
	printf("%d * %d + %d * %d = %d\n", a, x, b, y, g);

	return 0;
}

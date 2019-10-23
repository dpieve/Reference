string T, P;
int b[100005];

/*best j = b[j]*/
void kmpProcess() {
	int i = 0, j = -1; b[0] = -1;
	while (i < (int)P.size()) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}
void kmpSearch() {
	/*prefix function*/
	kmpProcess();
	int i = 0, j = 0;
	while (i < (int)T.size()) {
		/*is it difft? find best b*/
		while (j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if (j == P.size()) {
			cout << "P found: " << i - j << endl; //  Start (i + 1 -j)   -- > End (i + 1 - j + (int)P.size() )
			j = b[j];
		}
	}
}

int main() {

	/*text T and patt P*/
	cin >> T >> P;
	kmpSearch();

	return 0;
}
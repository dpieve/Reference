const int MAXN = 200010;      // EX: 7 (3) (5) 3 (6) 2 9 (8)  => R = 4
 
int N, A[MAXN];

int solve() {
    vector<int> stk;
    for(int i = 0; i < N; ++i) {
        vector<int>::iterator it = lower_bound(stk.begin(), stk.end(), A[i]);
        if(it == stk.end()) stk.push_back(A[i]);
        else *it = A[i];
    }
    return stk.size();
}

const int MAXN = 200010;

int bridges_count = 0;

vector<int> G[MAXN];
int lvl[MAXN], dp[MAXN];

void dfs(int u) {
    dp[u] = 0;
    for(int v : G[u]) {
        if (lvl[v] == 0) {
            lvl[v] = lvl[u] + 1;
            dfs(v);
            dp[u] += dp[v];
        }
        else if (lvl[v] < lvl[u])       // edge upwards
            ++dp[u];
        else if (lvl[v] > lvl[u])       // edge downwards
            --dp[u];
    }
    if (lvl[u] > 1 && dp[u] == 0) {     // if I have one subtree with no backwards edge => I'm articulation point
        ++bridges_count;
    }

}

void solver() {
    int root = 1;
    lvl[root]= 1;
    dfs(1);    

    cout << bridges_count << '\n';
}

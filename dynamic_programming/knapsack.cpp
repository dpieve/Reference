// n = number_items, W = max_weight

const int MAXN = 5000 + 5;

int n, W, w[MAXN], qt[MAXN], dp1[MAXN], dp2[MAXN], dp3[MAXN];

void knapsack () {

		for (int i = 0; i < n; ++i) {
			for (int j = W; j >= w[i]; j--) { 

				// dp[j] = max (dp[j], value[i] + dp[j - weight[i] ] );

				if (dp1[j] < qt[i] + dp1[j - w[i]]) { 
					dp1[j] = qt[i] + dp1[j - w[i]];
					dp2[j] = 1 + dp2[j - w[i]];
					dp3[j] = w[i]  + dp3[j - w[i]];	
				}

			}
		}

		printf("%d total  value\n", dp1[W]); 
		printf("%d total weight\n", dp3[W]); 
		printf("%d total  items\n", dp2[W]); 
		
}

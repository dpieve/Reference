   //check if a Graph G is Bipartite
   
   bool isBipartite(int N, const vector< vector<int> >& G) {
        
        vector<int> color(N, -1);
        
        // checking for every component
        for(int source = 0; source < N; ++source) {               
            
            if (color[source] == -1) {
                
                color[source] = 1;
                
                queue<int> Q;
                Q.push(source);
                
                while(!Q.empty()) {
                    int u = Q.front();
                    Q.pop();

                    for(int v : G[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            Q.push(v);
                        }
                        else if (color[v] == color[u])
                            return false;
                    }
                }
            }

        }
        
        return true;
    }
    

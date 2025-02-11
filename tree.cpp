
//https://cses.fi/paste/d0649eb7444333dcb7ad9f/
struct Tree {
    std::vector<std::vector<int>> adj, lift;    
    std::vector<int> d, tin, tout, par, sub, head;
    int n, timer;
    bool initialized = false;
    bool dfsed = false;
 
    void init(int nn){
        n = nn;
        adj.resize(n + 1);
        d.resize(n + 1);
        lift.resize(n + 1);
        tin.resize(n + 1);
        tout.resize(n + 1);
        par.resize(n + 1);
        sub.resize(n + 1);
        head.resize(n + 1);
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i <= n; i++) lift[i].resize(20, 0);
        initialized = true;
    }
 
    void addEdge(int u, int v){
        if (!initialized){ std::cout << "STUPID INITIALIZE\n"; exit(0);}
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    void build(){
        for (int j = 1; j < 20; j++){
            for (int i = 1; i <= n; i++){
                lift[i][j] = lift[lift[i][j - 1]][j - 1];
            }
        }
    }
    
    void dfs1(int u, int par1){
        sub[u] = 1;
        for (int v : adj[u]) if (v != par1){
            dfs1(v, u);
            sub[u] += sub[v];
        }
    }
 
    void dfs(int u, int par1, int h){
        par[u] = par1;
        tin[u] = ++timer;
        head[u] = h;
        bool fir = true;
        for (int v : adj[u]){
            if (v != par1){
                d[v] = d[u] + 1;
                lift[v][0] = u;
                int hh;
                if (fir) hh = h;
                else hh = v;
                fir = false;
                dfs(v, u, hh);
            }
        }
        tout[u] = timer;
    }
 
    void dfs(int root = 1){
        if (!initialized){ std::cout << "STUPID INITIALIZE\n"; exit(0);}
        d[root] = 0;
        timer = 0;
        dfs1(root, 0);
        for (int i = 1; i <= n; i++){
            sort(adj[i].begin(), adj[i].end(), [&](int x, int y){
                return sub[x] > sub[y]; 
            });
        }
        dfs(root, 0, root);
        build();
        dfsed = true;
    }
 
    int jump(int x, int depth){
        for (int i = 0; i < 20; i++) if (depth >> i & 1){
            x = lift[x][i];
        }
        return x;
    }
 
    int lca(int a, int b){
        if (!dfsed){ std::cout << "STUPID DFS\n"; exit(0);}
        if (d[a] < d[b]) std::swap(a, b);
        int del = d[a] - d[b];
        for (int i = 0; i < 20; i++) if (del >> i & 1) a = lift[a][i];
 
        if (a == b) return a;
        for (int i = 19; i >= 0; i--) if (lift[a][i] != lift[b][i]){
            a = lift[a][i];
            b = lift[b][i];
        }
        return lift[a][0];
    }
 
    int dist(int a, int b){
        return d[a] + d[b] - 2 * d[lca(a, b)];
    }
 
    bool anc(int x, int y){
        return tin[x] <= tin[y] && tout[x] >= tout[y];
    }
};
/*
 * example of HLD being used to find max in a path.
 * 
            seg.modify(T.tin[x], y);
 * while (T.head[x] != T.head[y]){
                if (T.d[T.head[x]] < T.d[T.head[y]]){
                    swap(x, y);
                }
                int g = T.head[x];
                ans = max(ans, seg.query(T.tin[g], T.tin[x]+1));
                x = T.par[g];
            }
            
            if (T.d[x] > T.d[y]){
                swap(x, y);
            }
 *
*/

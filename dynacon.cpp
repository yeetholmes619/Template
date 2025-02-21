struct DSU{
	vi par;
	int n;
	int num_comp;
	std::stack<std::array<int,5>> history;
	DSU(int n_) : n(n_),  num_comp(n_) , par(std::vector(n_,-1)){}
	int get_par(int x){
		return par[x] < 0 ? x : get_par(par[x]);
	}
	int get_rank(int x){
		return -par[get_par(x)];
	}
	void merge(int x, int y){
		auto xp = get_par(x), yp = get_par(y);
		history.push({xp,par[xp],yp,par[yp],num_comp});
		if(xp == yp)
			return;
		num_comp--;
		if(par[xp] > par[yp])
			std::swap(xp,yp);
		if(par[xp] == par[yp])
			par[xp]--;
		par[yp] =xp;
	}
	void rollback(){
		if( history.empty())
			return;
		auto [x,xp,y,yp,nc] = history.top(); history.pop();
		num_comp = nc;
		par[x] = xp;
		par[y] = yp;
	}
};

class dynacon{
        int q;
	int v;
	using Edge = std::array<int,2>;
	using EdgeTime = std::array<int,3>;
	using T = std::vector<Edge>;
        std::vector<T> Tree;
        T Neutral = T{};
	std::vector<EdgeTime> edges;
	int time;
        public:
        dynacon(size_t q_,int v) : v(v){
		q = std::bit_ceil(q_);
		debug(q);
		Tree.assign(2*q,Neutral);
		time= 0;
        }
        
        void applyEdge(Edge edge,int l, int r){
                for(l += q, r += q; l < r; l>>=1,r>>=1){
                        if(l&1)  Tree[l++].pb(edge);
                        if(r&1)  Tree[--r].pb(edge);
                }
        }
	void addEdge(int u, int v){
		if(u > v)
			std::swap(u,v);
		edges.pb({u,v,time++});
	}
	vi work(){
		std::sort(allvec(edges));
		DSU dsu(v);
		vi ans(q,0);
		int m = edges.size();
		for(int i =0 ; i < m; i++){
			if(i == m-1){
				applyEdge({edges[i][0],edges[i][1]},edges[i][2],time);
			}else if(edges[i][0] == edges[i+1][0] && edges[i][1] == edges[i+1][1]){
				applyEdge({edges[i][0],edges[i][1]},edges[i][2],edges[i+1][2]);
				i++;

			}else{
				applyEdge({edges[i][0],edges[i][1]},edges[i][2],time);
			}
		}
		debug(Tree,time);
		debug(edges);
		auto dfs = [&](int vertex, auto&& dfs)->void{
			for(auto [x,y] : Tree[vertex]){
				dsu.merge(x,y);
			}
			if(vertex >= q){
				ans[vertex-q] = dsu.num_comp;
			}else{
				dfs(vertex<<1,dfs);
				dfs(vertex<<1|1,dfs);
			}
			for(auto [x,y] : Tree[vertex]){
				dsu.rollback();
			}
		};
		dfs(1,dfs);
		return ans;
	}
};


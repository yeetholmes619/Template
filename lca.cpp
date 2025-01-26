//https://judge.yosupo.jp/submission/263705
struct Lca {
	static constexpr int K = 20;
	int n{};
	std::vector<int> depth, first;
	std::vector<std::array<int, K>> st;

	Lca(const std::vector<std::vector<int>>& adj, int root = 0) : n{int(adj.size())}, depth(n), first(n) {
		std::vector<int> euler{};
		auto dfs = [&](auto&& self, int u, int p = -1) -> void {
			first[u] = int(euler.size());
			euler.push_back(u);
			for (auto v : adj[u]) {
				if (v == p) continue;
				depth[v] = depth[u] + 1;
				self(self, v, u);
				euler.push_back(u);
			}
		};
		dfs(dfs, root);

		st.resize(euler.size());
		for (int i = 0; auto& x : st) x[0] = euler[i++];
		for (int j = 1; j < K; ++j) {
			for (int i = 0; i + (1 << j) <= int(euler.size()); ++i) {
				auto ua = st[i][j - 1], va = st[i + (1 << (j - 1))][j - 1];
				st[i][j] = depth[ua] < depth[va] ? ua : va;
			}
		}
	}

	int ascend(int u, int steps) {
		for (int j = 0; j < K; j++)
			if (steps >> j & 1) u = st[u][j];
		return u;
	}

	int lca(int u, int v) {
		auto l = first[u], r = first[v];
		if (l > r) std::swap(l, r);
		auto j = std::__lg(r - l + 1);
		auto ua = st[l][j], va = st[r - (1 << j) + 1][j];
		return depth[ua] < depth[va] ? ua : va;
	}

	int distance(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
	int parent(int u) { return st[u][1]; }
	bool is_ancestor(int u, int v) { return u == lca(u, v); }
};
//Lca lca(adj,3 root);

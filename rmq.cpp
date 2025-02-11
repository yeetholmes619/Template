//https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/RMQ.h
template<class T>
struct RMQ {
	std::vector<std::vector<T>> jmp;
	RMQ(const std::vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= ssize(V); pw *= 2, ++k) {
			jmp.emplace_back(ssize(V) - pw * 2 + 1);
                        for(int j =0 ; j < ssize(jmp[k]); j++)
				jmp[k][j] = std::min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
                if(a == b){
                    return INT_MAX;
                }
		int dep = 31 - __builtin_clz(b - a);
		return std::min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};


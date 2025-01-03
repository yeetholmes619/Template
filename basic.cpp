//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]
//https://github.com/yeetholmes619/Template.git
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#endif
#ifndef DEBUG
#define debug(args...)
#endif
#define curtime             std::chrono::high_resolution_clock::now()
#pragma GCC optimize("Ofast")
#define timedif(start,end)  std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define vi std::vector<int>
#define pii std::pair<int,int>
#define vpii std::vector<std::pair<int,int>>
template <typename T>
using matrix = std::vector<std::vector<T>>;

#define SZ(x) (int)(x.size())
#define allvec(v) v.begin(), v.end()
#define int long long
#define output(value) std::cout << value << "\n"
const int mod1 = 1000000007;
const int mod2 = 998244353;
template<typename T1, typename T2> // std::cin >> pair<T1, T2>
std::istream& operator>>(std::istream &istream, std::pair<T1, T2> &p) { return (istream >> p.first >> p.second); } 
template<typename T> // std::cin >> vector<T>
std::istream& operator>>(std::istream &istream, std::vector<T> &v)
{
	for (auto &it : v)
		istream >> it;
	return istream;
}
 
template<typename T1, typename T2> // std::cout << pair<T1, T2>
std::ostream& operator<<(std::ostream &ostream, const std::pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // std::cout << vector<T>
std::ostream& operator<<(std::ostream &ostream, const std::vector<T> &c) { for (auto &it : c) ostream << it << " "; return ostream; }
 
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\GLOBAL VARIABLES/\/\/\/\/\/\/\/\/\/\/\/\///\/\/

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///\/\/\/\/\/\/
void take(){
}

void solve(){
        take();

}


int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    auto time0 = curtime;
	int t = 1;
	std::cin >> t;
	for(int i = 1 ; i <= t; i++) {
		//std::cout << "Case #" << i << ": ";
        debug(i);
		solve();
	}
#ifdef YEET
    std::cerr << "Execution Time: " << timedif(time0,curtime)*1e-9 << " sec\n";
#endif
    return 0;
}

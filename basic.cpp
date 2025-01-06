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
#define output(value) std::cout << value << "\n"
const int mod1 = 1000000007;
const int mod2 = 998244353;
template<class T, size_t N>
std::istream& operator>>(std::istream& istream, std::array<T,N>& v){
	for(auto &it : v)
		istream >> it;
	return istream;
}
template<typename T1, typename T2> // std::cin >> pair<T1, T2>
std::istream& operator>>(std::istream &istream, std::pair<T1, T2> &p) { return (istream >> p.first >> p.second); } 
template<typename T> // std::cin >> vector<T>
std::istream& operator>>(std::istream &istream, std::vector<T> &v)
{
	for (auto &it : v)
		istream >> it;
	return istream;
}
 
template<class T1, class T2> // std::cout << pair<T1, T2>
std::ostream& operator<<(std::ostream &ostream, const std::pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }

// Overload for std::array
template<class T, size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T,N>& c){
	for(const auto &it : c){
		os << it <<" ";
	}
	return os;
}
// Overload for std::vector
template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c) {
    for (const auto& it : c) os << it << " ";
    return os;
}
 
namespace  stressers{
	std::mt19937 rng_int(std::chrono::steady_clock::now().time_since_epoch().count());
	std::mt19937_64 rng_ll(std::chrono::steady_clock::now().time_since_epoch().count());
	
	template<class Integer>
	Integer rng(Integer L, Integer R){
	//inclusive
		return std::uniform_int_distribution<Integer>(L,R)(rng_ll);
	}
	template<class RandomIt>
	void shuffle(RandomIt first, RandomIt second){
		std::shuffle(first,second,rng_int);
	}
	std::vector<int> permutation(size_t n,int start = 1){
		std::vector<int> v(n);
		std::iota(v.begin(),v.end(),start);
		shuffle(v.begin(),v.end());
		return v;
	}
	template<class T>
	std::vector<T> rvg(size_t n, T L, T R){
		std::vector<T> v(n);
		for(auto& x : v){
			x = rng(L,R);
		}
		return v;
	}
	std::string rsg(size_t n, char L, char R){
		std::string s(n,'a');
		for(auto& x : s){
			x = char(L + rng(0,R-L));
		}
		return s;
	}
};
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\GLOBAL VARIABLES/\/\/\/\/\/\/\/\/\/\/\/\///\/\/

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///\/\/\/\/\/\/
void take(){
}

void solve(){
        take();

}
void stress(){
	using namespace stressers;
	for(int T_ = 0; T_ <= 1000; T_++){

	}
	output("ALL GOOD");
}


int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    auto time0 = curtime;
	int t = 1;
#ifndef STRESS_YEET
	std::cin >> t;
#endif
	
	for(int i = 1 ; i <= t; i++) {
		//std::cout << "Case #" << i << ": ";
        debug(i);
#ifndef STRESS_YEET
		solve();
#endif
#ifdef STRESS_YEET
		stress();
#endif
	}
#ifdef YEET
    std::cerr << "Execution Time: " << timedif(time0,curtime)*1e-9 << " sec\n";
#endif
    return 0;
}

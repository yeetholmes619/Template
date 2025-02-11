//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]
//https://github.com/yeetholmes619/Template.git
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug_better.h"
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
	std::vector<std::array<int,2>> tree_generator(size_t n){
		std::vector<std::array<int,2>> edges;
		auto names = permutation(n);
		for(int i = 2; i <= n; i++){
			edges.pb({rng(1,i-1),i});
		}
		shuffle(edges.begin(),edges.end());
		for(auto& [u,v] : edges){
			u = names[u-1];
			v = names[v-1];
			if(rng(0,1)){
				std::swap(u,v);
			}
		}
		return edges;
	}
};
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\GLOBAL VARIABLES/\/\/\/\/\/\/\/\/\/\/\/\///\/\/

//https://github.com/the-tourist/algo/blob/master/numeric/mint.cpp
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; std::swap(a, m);
    u -= t * v; std::swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename std::decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { value += other.value; value -= (value >= mod()) * mod(); return *this; }
  Modular& operator-=(const Modular& other) { value -= other.value; value += (value < 0) * mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename std::enable_if<std::is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename std::enable_if<std::is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename std::enable_if<!std::is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  friend const Type& abs(const Modular& x) { return x.value; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};


template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T>
std::string to_string(const Modular<T>& number) {
  return std::to_string(number());
}

template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename std::common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

constexpr int md = mod2;
using Mint = Modular<std::integral_constant<std::decay<decltype(md)>::type, md>>;


constexpr int md1 = mod1;
constexpr int md2 = mod2;
struct Hashing{
	
	using mint1 = Modular<std::integral_constant<std::decay<decltype(md)>::type, md1>>;
	using mint2 = Modular<std::integral_constant<std::decay<decltype(md)>::type, md2>>;

	std::vector<mint1> powers1;
	std::vector<mint2> powers2;

	int base;
	int n;
	std::vector<mint1> hash1;
	std::vector<mint2> hash2;
	std::vector<mint1> rhash1;
	std::vector<mint2> rhash2;
	auto get_hash(int l, int r){
		if(l == 0){
			return std::pair{hash1[r],hash2[r]};
		}else{
			return std::pair{hash1[r]-hash1[l-1], hash2[r]-hash2[l-1]};
		}
	}
	auto get_rhash(int l, int r){
		if(l == 0){
			return std::pair{rhash1[r],rhash2[r]};
		}else{
			return std::pair{rhash1[r]-rhash1[l-1], rhash2[r]-rhash2[l-1]};
		}

	}
	Hashing(std::string s){
		n = ssize(s);
		powers1.assign(n,1);
		powers2.assign(n,1);
		base = stressers::rng<int>(1e3,1e9);
		for(int  i= 1; i < n; i++){
			powers1[i] = base*powers1[i-1];
			powers2[i] = base*powers2[i-1];
		}
		hash1.assign(n,0);
		hash2.assign(n,0);
		for(int i = 0; i < n; i++){
			hash1[i] = (s[i] - 'a')*powers1[i];
			hash2[i] = (s[i] - 'a')*powers2[i];
		}
		std::reverse(allvec(s));
		rhash1.assign(n,0);
		rhash2.assign(n,0);
		for(int i = 0; i < n; i++){
			rhash1[i] = (s[i] - 'a')*powers1[i];
			rhash2[i] = (s[i] - 'a')*powers2[i];
		}
		for(int i = 1; i < n; i++){
			hash1[i] += hash1[i-1];
			hash2[i] += hash2[i-1];
			rhash1[i] += rhash1[i-1];
			rhash2[i] += rhash2[i-1];
		}

	}



};


// using ModType = int;

// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;
//
// // vector<Mint> fact(1, 1);
// vector<Mint> inv_fact(1, 1);

// Mint C(int n, int k) {
//   if (k < 0 || k > n) {
//     return 0;
//   }
//   while ((int) fact.size() < n + 1) {
//     fact.push_back(fact.back() * (int) fact.size());
//     inv_fact.push_back(1 / fact.back());
//   }
//   return fact[n] * inv_fact[k] * inv_fact[n - k];
// }
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

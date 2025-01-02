//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]
//https://github.com/yeetholmes619/Template.git
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#endif
#ifndef DEBUG
#define debug(args...)
#endif
#define curtime             chrono::high_resolution_clock::now()
#pragma GCC optimize("Ofast")
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
using namespace std;
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
template <typename T>
using matrix = vector<vector<T>>;

#define SZ(x) (int)(x.size())
#define allvec(v) v.begin(), v.end()
#define int long long
#define output(value) cout << value << "\n"
const int mod1 =1000000007;
const int mod2 = 998244353;
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); } 
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v)
{
	for (auto &it : v)
		cin >> it;
	return istream;
}
 
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\GLOBAL VARIABLES/\/\/\/\/\/\/\/\/\/\/\/\///\/\/

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///\/\/\/\/\/\/
void take(){
}

void solve(){
        take();

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto time0 = curtime;
	ll t = 1;
	cin >> t;
	for(int i = 1 ; i <= t; i++) {
		//cout << "Case #" << i << ": ";
        debug(i);
		solve();
	}
#ifdef YEET
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
#endif
    return 0;
}

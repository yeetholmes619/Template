
//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]

#include<bits/stdc++.h>
using namespace std;
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define ll long long
#define ld long double
#define INF 1000000007
#define fu(i,a,b) for(ll i = a; i<=b;i++)
#define fd(i,a,b) for(ll i = a; i>=b; i--)
#define fdd(i,a) for(ll i = a; i>=1; i--)
#define fuu(i,a)for(ll i = 1; i<=a; i++)
#define pb push_back
#define pf push_front
#define cinarr(a) for(auto &zz:a)cin>>zz
#define allvec(v) v.begin(), v.end()
#define vstr vector<string>
#define vll vector<ll>
#define vint vector<int>
#define allarr(a,n) a, a+n
#define MOD 1000000007
// precedence order :- double > float > long long int > long int > int > char
// remember that boolean arrays and variables if uninitialized are given false
//Check if constraints are correct
// for single arrays declare them as long long int
//overflow must be taken care of!! use strings when big
//	0 < |int| < 1e9
//	0 < |long int| < 1e12
//	0 < |long long int| < 1e18
//when you are working with stacks, remember to take care of stacks of 0 size
//when you see a problem, and you know how you would tackle it in the real world, but don't know how
//you would do it in code, go step by step, in each step try to be concious of what you want to do
//and once you have done so, review through and remember what data structure would be perfect
//when we pass an array in a function the pointer is passed but when we pass a vector, a copy is passed

using namespace std;

class Graph{
        public:
//        map<int,vector<int>>adj;
//        map<int,bool> visited;
//        map<int,int> color;
        vector<vector<int>> adj;
        vector<bool> visited;
        vector<int> color;
        int n;
        Graph(int x =1){
                n = x;
                adj.resize(n+1);
                visited.resize(n+1,false);
                color.resize(n+1,-1);
        }


        void addEdge(int f, int t);

        void dfs(int a);
        void dfs_main(int a);

        void bfs(int b);
        void multibfs(vector<int>& v);
        void clr(int x);
};

void Graph::clr(int x= 1){
        n = x;
        adj.resize(n+1);
        visited.resize(n+1,false);
        color.resize(n+1,-1);
}
void Graph::multibfs(vector<int>& v){
        visited.clear();
        visited.resize(n+1,false);
        queue<int> q;
        for(auto t: v){
                //cout<<t<<" ";
                q.push(t);
                visited[t] = true;
        }
        while(q.size() != 0){
                int s = q.front();
                q.pop();
                for(auto t: adj[s]){
                        if(visited[t]) continue;
                        visited[t] = true;
                        //cout<<t<<" ";
                        q.push(t);
                }
        }

        return;
}


void Graph:: addEdge(int f, int t){
        adj[f].pb(t);
        return;
}

void Graph::dfs_main(int a){
        visited[a] = true;
        //cout<<a<<" ";
        for(auto t : adj[a]){
                if(visited[t]) continue;
                dfs(t);
        }
        return;
}

void Graph::dfs(int a){
        visited.clear();
        visited.resize(n+1,false);
        dfs(a);
        return;
}

void Graph::bfs(int b){

        queue<int> q;
        visited.clear();
        visited.resize(n+1,false);
        visited[b] = true;
        //cout<<b<<" ";
        q.push(b);
        while(q.size() != 0){
                int s = q.front();
                q.pop();
                for(auto t: adj[s]){
                        if(visited[t]) continue;
                        visited[t] = true;
                        //cout<<t<<" ";
                        q.push(t);
                }
        }

        return;
}


void take(){
}

void solve() {
        take();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	cin >> t;
	fuu(i, t) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

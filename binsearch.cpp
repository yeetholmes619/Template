#include<bits/stdc++.h>
using namespace std;
int binsearch(vector<int> v, int st, int en, int x){
        if(st > en) return (int)v.size();
        int mid = st + (en-st)/2;
        if(v[mid] == x) return mid;
        if(x < v[mid]) return binsearch(v,st,mid-1,x);
        else return binsearch(v,mid+1,en,x);
}
//Nor's method
/*
so here we basically we end our search with l being in last true
ans r being in first false, this method helps a lot cuz the last true
and first false are both something that might be what is being asked.
*/
template <class Integer, class F>
Integer find_first_false(Integer start, Integer end, F &&f){
        start--;
        end++;
        while(end-start > 1){
                Integer mid = start + (end - start)/2;
                if(f(mid) == false){
                        end = mid;
                }
                else{
                        start = mid;
                }
        }
        return end;
}

/*
the [l,r] way, where the remaining search space is [l,r] and so our answer
will be return l or return r based on our comparator tbh

the idea behind binary search is just reducing the search space.
so here after we have an empty search space we roll back onto our previous
best answer.
*/

template <class Integer, class F>
Integer find_first_false_2(Integer start, Integer end, F &&f){
        int ans=  end; //if we are searching for first false;
        while(end-start >= 0){
                Integer mid = start + (end - start)/2;
                if(f(mid) == false){
                        ans = mid;
                        end=  mid-1;
                }
                else{
                        start = mid+1;;
                }
        }
        return ans;
}


/*
the last idea is [l,r) way where our search space will merge with l == r;
*/
template <class Integer, class F>
Integer find_first_false_3(Integer start, Integer end, F &&f){
        end++;
        while(end-start > 0){
                Integer mid = start + (end - start)/2;
                if(f(mid) == false){
                        end=  mid;
                }
                else{
                        start = mid+1;;
                }
        }
        return end;
}
int find(vector<int> v, int x){
        //return binsearch(v,0,v.size()-1,x);
        auto f = [&](int i){
                if(v[i] >= x) return false;
                else return true;
        };
        int ind = lower_bound(v.begin(),v.end(),x) - v.begin();
        if(ind == (int)v.size() || v[ind] != x) return (int)v.size();
        else return ind;
}
int main(){
        int t;
        cin>>t;
        while(t--){
                int n;
                vector<int> v;
                cin>>n;
                v.resize(n);
                for(auto &t: v) cin>>t;
                int x;
                cin>>x;
                cout<<find(v,x)<<"\n";
        }
}

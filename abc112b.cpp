#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;


void solve(){
    int n,time;
    cin >> n >> time;
    int ans = 10000;
    vector<pair<int,int>> v;
    rep(i,n){
        int c,t;
        cin >> c >> t;
        v.emplace_back(make_pair(c,t));
    }
    rep(i,n){
        int c,t;
        c = v[i].first;
        t = v[i].second;
        if(t <= time){
            ans = min(ans, c);
        }
    }
    if(ans==10000) cout << "TLE" << endl;
    else cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

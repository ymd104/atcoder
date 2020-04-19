#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

vector<pair<int,int>> v;

void solve(){

    ll n,m;
    cin >> n >> m;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        v.eb(make_pair(b-1,a));
    }
    sort(v.begin(), v.end());
    ll pre = v[0].first;
    ll ans = 1;
    for(ll i=1; i<v.size(); i++){
        ll x,y;
        x = v[i].second;
        y = v[i].first;
        if(x<=pre&&pre<=y){
            continue;
        }
        else{
            pre = y;
            ans++;
        }   
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

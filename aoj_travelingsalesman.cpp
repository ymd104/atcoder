#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

vector<pair<ll,ll>> a[20];
ll s[1<<18];

void solve(){

    ll v,e;
    cin >> v >> e;
    rep(i,e){
        int s,t,d;
        cin >> s >> t >> d;
        s--;
        t--;
        a[s].emplace_back(make_pair(t,d));
    }
    rep(i,1<<18){
        s[i]=INF;
    }
    s[1<<(v-1)]=0;
    queue<ll> q;
    q.push(1<<(v-1));
    while(true){
        ll x = q.top();
        q.pop();
        
    }

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

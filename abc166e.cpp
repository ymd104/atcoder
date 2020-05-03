#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll a[200010];
ll p[200010];
map<ll, ll> mp;

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
        p[i]=i-a[i];
        mp[p[i]] = mp[p[i]]+1;
        //cout << p[i] << " ";
        //cout << mp[p[i]] << endl;
    }

    ll ans = 0;
    rep(i,n){
        ans += mp[(-1) * (p[i]-2*i)];
        //mp[p[i]] = mp[p[i]]-1;
        //cout << i << " " << ans << endl;
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll n;
ll h[100010];
ll s[100010];

bool c(ll x){
    ll t[n];
    rep(i,n){
        if (x<h[i]) return false;
        t[i]=min(ll(100000000),(x-h[i]) / s[i]);
    }
    sort(t,t+n);
    rep(i,n){
        if(t[i]<i) return false;
    }
    return true;
}

void solve(){

    cin >> n;
    rep(i,n){
        cin >> h[i] >> s[i];
    }

    ll l=0;
    ll r=1e16;
    while(r-l>1){
        ll m=(l+r)/2;
        if(c(m)) r=m;
        else l=m;
    }
    if(c(r)) cout << r << endl;
    else cout << l << endl; 

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

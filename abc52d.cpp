#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
*/

void solve(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll x[n+10];
    rep(i,n){
        cin >> x[i];
    }
    ll ans=0;
    for(int i=1; i<n; i++){
        ll tmp = x[i]-x[i-1];
        if(tmp*a>b){
            ans += b;
        }
        else{
            ans += tmp*a;
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

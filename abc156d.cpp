#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


ll l[35];

ll power(ll m, ll n){

    l[0]=m;
    for(ll i=1; i<35; i++){
        l[i] = (l[i-1]*l[i-1]) % MOD;
    }

    ll tmp = n;
    ll ans = 1;
    rep(i,35){
        if(tmp%2==1){
            ans = (ans*l[i]) % MOD;
        }
        tmp /= 2;
    }
    return ans%MOD;

}


void solve(){

    ll n,a,b;
    cin >> n >> a >> b;
    ll ans = (power(2,n)-1 + MOD)%MOD;
    ll tmp1 = 1;

    for(ll i = n; i>=n-a+1; i--){
        tmp1 = (tmp1 * i) % MOD; 
    }
    for(ll i = a; i>=1; i--){
        tmp1 = (tmp1 * (power(i, MOD-2)%MOD)) % MOD; 
    }

    ll tmp2 = 1;
    for(ll i = n; i>=n-b+1; i--){
        tmp2 = (tmp2 * i) % MOD; 
    }
    for(ll i = b; i>=1; i--){
        tmp2 = (tmp2 * (power(i, MOD-2)%MOD)) % MOD; 
    }

    cout << (ans - tmp1 - tmp2 + 100*MOD)%MOD << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll l[35];
ll dis[120010];

ll power(ll m, ll n){

    l[0]=m;
    for(ll i=1; i<30; i++){
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
    return ans;

}

vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

ll s[100010];

void solve(){

    ll n,k;
    cin >> n >> k;

    for(ll i=k; i>=1; i--){
      s[i]=(power((k/i),n))%MOD;
      for(ll c=2; c*i<=k; c++){
        s[i] = (s[i] - s[i*c] + MOD)%MOD;
      }
    }

    ll ans = 0;
    rep(i,k+1){
      //cout << s[i] << endl;
      ans = (ans + s[i]*i)%MOD;
    }

    cout << ans << endl;

    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

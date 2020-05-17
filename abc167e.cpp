#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;

const int MAX = 510000;
const int MOD = 998244353;

ll fac[MAX], finv[MAX], inv[MAX];

ll l[35];

ll power(ll m, ll n){

    l[0]=m;
    for(ll i=1; i<35; i++){
        l[i] = (l[i-1]*l[i-1]) % MOD;
    }
    /*
    rep(i,35){
        cout << l[i] << " ";
    }
    cout << endl;
    */

    ll tmp = n;
    ll ans = 1;
    rep(i,35){
        if(tmp%2==1){
            ans = (ans*l[i]) % MOD;
        }
        tmp /= 2;
        //cout << ans << " ";
    }
    //cout << endl;
    return ans%MOD;

}

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void solve(){

    ll n,m,k;
    cin >> n >> m >> k;
    COMinit();


    ll ans = 0;
    rep(i,k+1){
        ans = (ans + (((power(m-1,n-i-1) % MOD) * (COM(n-1,i))%MOD)%MOD*m)%MOD )%MOD;
    }

    cout << ans << endl;
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

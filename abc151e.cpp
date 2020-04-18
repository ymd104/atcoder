#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

const int MAX = 510000;

ll fac[MAX], finv[MAX], inv[MAX];

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



ll a[100010];

void solve(){
    
    COMinit();
    
    ll n,k;
    cin >> n >> k;
    rep(i,n){
        cin >> a[i];
    }
    sort(a,a+n);
    ll ans = 0;
    for(int i=0; i<n; i++){
        if(i<k-1){
            continue;
        }
        ans = (ans+a[i]*COM(i,k-1) )% MOD;
    }
    

    for(int i=0; i<n; i++){
        if(n-i-1<k-1){
            break;
        }
        ans = (ans-a[i]*COM(n-i-1,k-1)) % MOD;
    }
    if(ans<0){
        ans += MOD;
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

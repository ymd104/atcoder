#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


const ll MAX=100010;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void solve(){
    ll h,w,a,b;
    cin >> h >> w >> a >> b;
    /*
    ...........
    ...........
    ...........
    ###........
    ###........
    dp[i][j](i=h-a~h-1,j=0~b-1)
    */
    /*
    dp[0][0]=1;
    rep(i,h){
        rep(j,w){
            if(i==0&&j==0) dp[i][j]=1;
            else if(h-a<=i&&i<=h-1&&0<=j&&j<=b-1){
                dp[i][j]=0;
            }
            else if(i==0){
                dp[i][j]=dp[i][j-1];
            }
            else if(j==0){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
    */
    COMinit();
    /*
    i=b〜w-1について、
    (h-a-1+i)C(h-a)*(w-i)C(a)
    ....
    ....
    #...
    h=3 w=4 a=1 b=1
    2C1*3C1 + 3C2*2C1 + 4C3*1C1

    ...
    #..

    */
    ll ans = 0;
    for(ll i=b; i<w; i++){
        ans += (COM(h-a-1+i, h-a-1)*COM(w-i+a-2,a-1)) % MOD;
        ans = ans % MOD;
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


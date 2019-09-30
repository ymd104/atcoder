#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
MODの扱い
・+=演算子は危険. 丁寧に書かないとたまに死ぬ.
・負になりうるものにMODを噛ませるのは危険. 謎に通らない時は引き算を含む式に一度MODを足してからMODをとる.
*/

void solve(){
    ll n,m;
    cin >> n >> m;
    ll s[n+10];
    ll t[m+10];
    rep(i,n){
        cin >> s[i+1];
    }
    rep(i,m){
        cin >> t[i+1];
    }
    ll dp[n+10][m+10];
    ll sum[n+10][m+10];

    rep(i,n+1){
        dp[i][0]=0;
        sum[i][0]=0;
        sum[i][m]=0;
    }
    rep(i,m+1){
        dp[0][i]=0;
        sum[0][i]=0;
        sum[n][i]=0;
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(s[i]==t[j]) dp[i][j]=(sum[i-1][j-1]+1)%MOD;
            else dp[i][j]=0;
            sum[i][j]=((sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+MOD)%MOD+dp[i][j])%MOD;
        }
    }
    
    ll ans = 0;
    rep(i,n+1){
        rep(j,m+1){
            //cout << "dp[" << i << "][" << j << "]:" << dp[i][j] << endl;
            //cout << "sum[" << i << "][" << j << "]:" << sum[i][j] << endl;
            ans =  (ans + dp[i][j]) % MOD;
        }
    }



    cout << ans+1 << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
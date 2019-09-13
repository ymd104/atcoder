#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
dp[i][j]:高さiのあみだくじで、1がjに行く総数
dp[1][1]=
dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]
*/

ll f[9];
void filling(){
    f[0] = 1;
    f[1] = 1;
    rep(i,7){
        f[i+2] = f[i]+f[i+1];
    }
}

ll dp[105][10];

void solve(){
    filling();
    int h,w,k;
    cin >> h >> w >> k;
    rep(i,h){
        dp[i+1][0]=0;
        dp[i+1][w+1]=0;
    }
    dp[1][1] = f[w-1];
    dp[1][2] = f[w-2];
    //w=1,w=2で例外処理したい
    if(w==1) cout << 1 << endl;
    //else if(w==2){

    //}
    else{
    for(int i=3; i<=w; i++){
        dp[1][i]=0;
    }
    for(int i=2; i<=h; i++){
        for(int j=1; j<=w; j++){
            dp[i][j] = (((f[j-2]*f[w-j]*dp[i-1][j-1]) % MOD)
                     + ((f[j-1]*f[w-j]*dp[i-1][j]) % MOD)
                     + ((f[j-1]*f[w-1-j]*dp[i-1][j+1]) % MOD) )%MOD;
                     //cout << "i:" << i << " j:" << j << " dp:" << dp[i][j] << endl;
        }
    }
    cout << dp[h][k] << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

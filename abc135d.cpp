#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

/*
dp[i][j]=先頭i文字として考えられる数値のうち、13で割った余りがjであるものの数　とする。
この時、例えばsが.........1であるなら、この数を13で割った余りが、
(m*10+1)%13となる個数：dp[i-1][m*10+1] (を10^9+7で割った値)となる。
すなわち、各m=0~12について、
dp[i][(m*10+s[i])%13]=dp[i-1][m]*10+s[i]とすればいい。
s[i]が？の時は、各k=0~9について、各m=0~9で
dp[i][(m+10+1)%13]=dp[i-1][m]*10+kとする。

例：s=123
dp[0][_]=0
dp[1][0]=
*/

void solve(){
    int MOD = 1e9+7;
    string s;
    cin >> s;
    uint64_t res = 0;
    int n = s.size();
    uint64_t dp[n+10][13];
    rep(i,n+1){
        rep(j,13){
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for(int i=1; i<=n; i++){
        if(s[i-1]!='?'){
            int number = s[i-1] - '0';
            rep(m,13){
                dp[i][(m*10+number)%13] = (dp[i-1][m]) % MOD;
                //cout << "dp[" << i << "][" << (m*10+number)%13 << "]=" << dp[i-1][m]+1 << endl;
            }
        }
        else{
            rep(k,10){
                rep(j,13){
                    dp[i][(j*10+k)%13] = (dp[i][(j*10+k)%13] + dp[i-1][j]) % MOD;
                }
            }
        }
    }
    res = dp[n][5];
    cout << res << endl;
}

int main(){
  solve();
  return 0;
}
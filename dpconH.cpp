#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
dp[i][j]:i+1行j+1列までの経路の総数。
a[i-1][j], a[i][j-1]が共に.なら、それらの総和のmod

*/

void solve(){
    int h,w;
    cin >> h >> w;
    char a[h+5][w+5];
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w){
            a[i][j] = s[j];
        }
    }
    int dp[h+5][w+5];
    int tmp=1;
    rep(i,h){
        if(a[i][0]=='#') tmp=0;
        dp[i][0] = tmp;
    }
    tmp = 1;
    rep(i,w){
        if(a[0][i]=='#') tmp=0;
        dp[0][i] = tmp;
    }

    for(int i=1; i<h; i++){
        for(int j=1; j<w; j++){
            if(a[i-1][j]=='.' && a[i][j-1]=='.') dp[i][j]=(dp[i-1][j]+dp[i][j-1]) % MOD;
            else if (a[i-1][j]=='.') dp[i][j]=dp[i-1][j];
            else if (a[i][j-1]=='.') dp[i][j]=dp[i][j-1];
            else dp[i][j]=0;
        }
    }

    cout << dp[h-1][w-1] << endl;
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

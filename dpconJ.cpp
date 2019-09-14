#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
どう足掻いてもDPには見えないけど、どうやってその発想に至るのだろう
3個の寿司の皿の枚数をa、2をb、1をcとする
dp[a][b][c]:寿司がa,b,cの時の操作回数の期待値
これは、
・dp[a-1][b+1][c]
・dp[a][b-1][c+1]
・dp[a][b][c-1]
・dp[a][b][c]
の線形和で表現できる。
例えば、a=1,b=1,c=2の時、
1/4*dp[0][2][2] + 1/4*dp[1][0][3] + 1/4*dp[1][1][1] + 0 + 1 

dp[i][j][k]=(i/n)*dp[i-1][j+1][k] + (j/n)*dp[i][j-1][k+1] +
(k/n)*dp[i][j][k-1] + (n-i-j-k/n)*dp[i][j][k] + 1
この式から、
(i+j+k/n)*dp[i][j][k] = (i/n)*dp[i-1][j+1][k] + (j/n)*dp[i][j-1][k+1] +
(k/n)*dp[i][j][k-1] + 1
あるいは、
dp[i][j][k] = (i/i+j+k)*dp[i-1][j+1][k] + (j/i+j+k)*dp[i][j-1][k+1] +
(k/i+j+k)*dp[i][j][k-1] + (n/i+j+k)

dp[1][0][0]= dp[0][1][0] + 1/3
dp[0][0][2] = dp[0][0][1] + 1/2
dp[0][0][1] = dp[0][0][0] + 1

*/

double dp[305][305][305];

void solve(){
    int n;
    cin >> n;
    int v[n+10];
    int a,b,c;
    a=0;
    b=0;
    c=0;
    rep(i,n){
      cin >> v[i];
      if(v[i]==3) a++;
      else if(v[i]==2) b++;
      else c++;
    }
    dp[0][0][0]=0;
    rep(i,n+1){
      rep(j,n+1){
        rep(k,n+1){
          if(i==0&&j==0&&k==0) dp[i][j][k]=0;
          else{
            if(i==0&&j==0) dp[i][j][k]= ((double)k/(double)(i+j+k))*dp[i][j][k-1] + ((double)n/(double)(i+j+k));
            else if(i==0&&k==0) dp[i][j][k]= ((double)j/(double)(i+j+k))*dp[i][j-1][k+1] + ((double)n/(double)(i+j+k));
            else if(j==0&&k==0) dp[i][j][k]= ((double)i/(double)(i+j+k))*dp[i-1][j+1][k] + ((double)n/(double)(i+j+k));
            else if(i==0) dp[i][j][k] = ((double)j/(double)(i+j+k))*dp[i][j-1][k+1] + ((double)k/(double)(i+j+k))*dp[i][j][k-1] + ((double)n/(double)(i+j+k));
            else if(j==0) dp[i][j][k] = ((double)i/(double)(i+j+k))*dp[i-1][j+1][k] + ((double)k/(double)(i+j+k))*dp[i][j][k-1] + ((double)n/(double)(i+j+k));
            else if(k==0) dp[i][j][k] = ((double)i/(double)(i+j+k))*dp[i-1][j+1][k] + ((double)j/(double)(i+j+k))*dp[i][j-1][k+1] + ((double)n/(double)(i+j+k));
            else dp[i][j][k] = ((double)i/(double)(i+j+k))*dp[i-1][j+1][k] + ((double)j/(double)(i+j+k))*dp[i][j-1][k+1] + ((double)k/(double)(i+j+k))*dp[i][j][k-1] + ((double)n/(double)(i+j+k));
            //cout << "i:" << i << " j:" << j << " k:" << k << " " << dp[i][j][k] << endl;
          }
        }
      }
    }
    cout << setprecision(12) << dp[a][b][c] << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

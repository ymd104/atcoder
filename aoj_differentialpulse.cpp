#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
dp[i][j]: i-1番目までで値jになっているときの誤差の最小値
i=1~n
j=0~255 
dp[i][j]=min(dp[i-1][j-c[k]])
*/

int c[20];
int x[20010];
int dp[20010][260];

vector<int> a;

void solve(){

  while(true){

  int n,m;
  cin >> n >> m;
  if(n==0&&m==0) break;
  rep(i,m){
    cin >> c[i];
  }
  rep(i,n){
    cin >> x[i];
  }

  rep(i,20010){
    rep(j,260){
      dp[i][j]=INF;
    }
  }

  
  rep(i,260){
    dp[0][i]=0;
  }
  
  //dp[0][128]=0;

  for(int i=1; i<=n; i++){
    rep(j,256){
      rep(k,m){
        if(0<=j-c[k]&&j-c[k]<=255) {
          dp[i][j]=min(int(dp[i][j]), int(dp[i-1][j-c[k]]+(j-x[i-1])*(j-x[i-1])) );
        }
      }
    }
  }

  int ans = INF;
  rep(i,256){
    ans = min(ans, dp[n][i]);
  }
  a.emplace_back(ans);

  
  rep(i,n+1){
    rep(j,256){
      if(dp[i][j]!=INF) cout << dp[i][j] << " ";
      else cout << "? ";
    }
    cout << endl;
  }
  

  }

  rep(i,a.size()){
    cout << a[i] << endl;
  }

  

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

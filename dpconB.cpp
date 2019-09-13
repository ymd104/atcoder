#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;

void solve(){
    int n,k;
    cin >> n >> k;
    int h[n+10];
    rep(i,n){
        cin >> h[i];
    }
    int dp[n+10];
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=2; i<n; i++){
        //dp[i-k]+abs(h[i]-h[i-k])の最小値を求めればいい
        //dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]) , dp[i-2]+abs(h[i]-h[i-2]));
        int m=1e9;
        for(int j=1; j<=k; j++){
            if(i>=j) m = min(m, dp[i-j]+abs(h[i]-h[i-j]));
        }
        dp[i]=m;
    }
    cout << dp[n-1] << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

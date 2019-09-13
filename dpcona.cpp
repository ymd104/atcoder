#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;

/*
位置jにたどり着くコストの最小値は、
min(dp[j-1]+|h[j]-h[j-1]|, dp[j-2]+|h[j]-h[j-2]|)
*/

void solve(){
    int n;
    cin >> n;
    int h[n+10];
    rep(i,n){
        cin >> h[i];
    }
    int dp[n+10];
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=2; i<n; i++){
        dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]) , dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout << dp[n-1] << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

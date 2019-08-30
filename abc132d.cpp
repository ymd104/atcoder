#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define rep1(i,n) for(ll i=0; i<=n; i++)
#define rep1r(i,n) for(ll i=1; i<=n; i++)
typedef long  ll;

ll mod = 1000000007;


/*
c[4][2]
=c[3][2]+c[3][1]
=...

c[1][1]
c[2][1]
c[3][1]
c[4][1]
c[1][2]=0
c[2][2]
c[3][2]
c[4][2]

*/

ll dp[2019][2019]={};
ll C(ll n, ll r){
    //n = n+1;
    //r = r+1;
    if(dp[n][r]) return dp[n][r];
    /*
        rep1r(j,r){
            rep1(i,n){
                if(i<j) dp[i][j]=0;
                else if(i==j||j==0) dp[i][j]=1;
                else dp[i][j]=(dp[i-1][j] + dp[i-1][j-1]) % mod;
                //cout << "dp[" << i << "][" << j << "]:" << dp[i][j] << endl;
            }
        }
        */
    else{
        if(n<r) {
            dp[n][r]=0;
            return 0;}
        else if(n==r||r==0) {
            dp[n][r]=1;
            return 1;}
        else{
            ll tmp = (C(n-1,r) + C(n-1,r-1)) % mod;
            dp[n][r]=tmp;
            return tmp;
        }
    }
        //return dp[n][r];
}



void solve(){
    ll n,k;
    cin >> n >> k;
    for(ll i=1; i<=k; i++){
        ll ans;
        if(n-k+1<i) ans = 0;
        else{
        //ans = ((C(k-1,i-1)%mod)*(C(n-k+1,i)%mod)) % mod;
        ans = ((C(k-1,i-1))*(C(n-k+1,i))) % mod;
        }
    cout << ans << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
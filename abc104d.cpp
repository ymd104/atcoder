#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll dp[100010][4];

void solve(){

    string s;
    cin >> s;
    ll n = s.length();
    dp[n][3]=1;
    rep(j,3){
        dp[n][j]=0;
    }
    for(ll i=n-1; i>=0; i--){
        dp[i][3]=(dp[i+1][3]*(s[i]=='?'? 3:1))%MOD;
    }
    for(ll i=n-1; i>=0; i--){
        ll m1,m2;
        if(s[i]=='?') {
            m1 = 3;
            m2 = 1;
        }
        else if(s[i]=='C') {
            m1 = 1;
            m2 = 1;
        }
        else {
            m1 = 1;
            m2 = 0;
        }
        dp[i][2]=(m1 * dp[i+1][2] + m2 * dp[i+1][3])%MOD;
    }
    for(ll i=n-1; i>=0; i--){
        ll m1,m2;
        if(s[i]=='?') {
            m1 = 3;
            m2 = 1;
        }
        else if(s[i]=='B') {
            m1 = 1;
            m2 = 1;
        }
        else {
            m1 = 1;
            m2 = 0;
        }
        dp[i][1]=(m1 * dp[i+1][1] + m2 * dp[i+1][2])%MOD;
    }
    for(ll i=n-1; i>=0; i--){
        ll m1,m2;
        if(s[i]=='?') {
            m1 = 3;
            m2 = 1;
        }
        else if(s[i]=='A') {
            m1 = 1;
            m2 = 1;
        }
        else {
            m1 = 1;
            m2 = 0;
        }
        dp[i][0]=(m1 * dp[i+1][0] + m2 * dp[i+1][1])%MOD;
    }

    /*
    rep(j,4){
        rep(i,n){
            cout << dp[i][3-j] << " ";
        }
        cout << endl;
    }
    */
    
    cout << dp[0][0] << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

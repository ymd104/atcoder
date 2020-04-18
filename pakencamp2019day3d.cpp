#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

char m[1010][6];
int dp[1010][6];

void solve(){

    int n;
    cin >> n;
    rep(i,5){
        string st;
        cin >> st;
        rep(j,n){
            m[j+1][i]=st[j];
        }
    }
    rep(i,1010){
        rep(j,6){
            dp[i][j]=INF;
        }
    }
    rep(i,6){
        dp[0][i]=0;
    }
    
    for(int i=1; i<=n; i++){
        int a[5];
        a[0]=0;
        a[1]=0;
        a[2]=0;
        a[3]=0;
        rep(x,5){
            if(m[i][x]=='R') a[0]++;
            else if(m[i][x]=='B') a[1]++;
            else if(m[i][x]=='W') a[2]++;
            else a[3]++;
        }
        rep(j,3){
            if(j==0) dp[i][j]=min(dp[i-1][1]+5-a[0], dp[i-1][2]+5-a[0]);
            else if(j==1) dp[i][j]=min(dp[i-1][0]+5-a[1], dp[i-1][2]+5-a[1]);
            else dp[i][j]=min(dp[i-1][1]+5-a[2], dp[i-1][0]+5-a[2]);
        }
    }

    /*
    rep(i,5){
        rep(j,n){
            cout << m[j+1][i] << " ";
        }
        cout << endl;
    }

    rep(j,4){
        rep(i,n+1){
            if(dp[i][j]==INF) cout << "?? ";
            else cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << min(dp[n][0],min(dp[n][1],dp[n][2])) << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

char st[110][110];
ll dp[110][110];


void solve(){

    /*
    cout << 100 << " " << 100 << endl;
    rep(i,100){
        rep(j,100){
            if((j+i)%2==0) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
    */

    ll h,w;
    cin >> h >> w;
    rep(i,h+2){
        rep(j,w+2){
            st[i][j] = '!';
            dp[i][j] = INF;
        }
    }
    rep(i,h){
        rep(j,w){
            cin >> st[i+1][j+1];
        }
    }
    dp[1][1]= (st[1][1]=='.'? 0:1);
    for(ll i=1; i<=h; i++){
        for(ll j=1; j<=w; j++){
            if(i==1&&j==1) continue;
            ll a=i;
            ll b=j;
            if(st[a][b]=='.'){
                if(st[a-1][b]=='.'){
                    if(st[a][b-1]=='.'){
                        dp[a][b]=min(dp[a-1][b], dp[a][b-1]);
                    }
                    else if(st[a][b-1]=='#'){
                        dp[a][b]=min(dp[a-1][b], dp[a][b-1]);
                    }
                    else{
                        dp[a][b]=dp[a-1][b];
                    }
                }
                else if (st[a-1][b]=='#'){
                    if(st[a][b-1]=='.'){
                        dp[a][b]=min(dp[a-1][b], dp[a][b-1]);
                    }
                    else if(st[a][b-1]=='#'){
                        dp[a][b]=min(dp[a-1][b], dp[a][b-1]);
                    }
                    else{
                        dp[a][b]=dp[a-1][b];
                    }
                }
                else{
                    if(st[a][b-1]=='.'){
                        dp[a][b]=dp[a][b-1];
                    }
                    else if(st[a][b-1]=='#'){
                        dp[a][b]=dp[a][b-1];
                    }
                }
            }
            else if(st[a][b]=='#'){
                if(st[a-1][b]=='.'){
                    if(st[a][b-1]=='.'){
                        dp[a][b]=min(dp[a-1][b]+1, dp[a][b-1]+1);
                    }
                    else if(st[a][b-1]=='#'){
                        dp[a][b]=min(dp[a-1][b]+1, dp[a][b-1]);
                    }
                    else{
                        dp[a][b]=dp[a-1][b]+1;
                    }
                }
                else if (st[a-1][b]=='#'){
                    if(st[a][b-1]=='.'){
                        dp[a][b]=min(dp[a-1][b], dp[a][b-1]+1);
                    }
                    else if(st[a][b-1]=='#'){
                        dp[a][b]=min(dp[a-1][b], dp[a][b-1]);
                    }
                    else{
                        dp[a][b]=dp[a-1][b];
                    }
                }
                else{
                    if(st[a][b-1]=='.'){
                        dp[a][b]=dp[a][b-1]+1;
                    }
                    else if(st[a][b-1]=='#'){
                        dp[a][b]=dp[a][b-1];
                    }
                }
            }
        }
    }

    cout << dp[h][w] << endl;

    /*
    rep(i,h){
        rep(j,w){
            cout << dp[i+1][j+1];
        }
        cout << endl;
    }
    */
    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

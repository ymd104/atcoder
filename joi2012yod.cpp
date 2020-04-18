#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
*/

ll dp[110][5][5][5];
ll st[110];

void solve(){

    ll n,k;
    cin >> n >> k;
    rep(i,110){
        st[i]=0;
    }
    rep(i,k){
        int x,y;
        cin >> x >> y;
        st[x]=y;
    }
    rep(i,3){
        rep(j,3){
            rep(k,3){
                if(i==j&&j==k) dp[1][i+1][j+1][k+1]=0;
                else dp[1][i+1][j+1][k+1]=1;
            }
        }
    }
    for(ll i=2; i<=n-2; i++){

        rep(l,3){
            rep(j,3){
                rep(k,3){
                    if(l==j&&j==k) dp[i][l+1][j+1][k+1]=0;
                    else if(l==j){
                        if(l==1) dp[i][l+1][j+1][k+1]=dp[i-1][2][1][1]+dp[i-1][3][1][1];
                        if(l==2) dp[i][l+1][j+1][k+1]=dp[i-1][1][1][1]+dp[i-1][3][1][1];
                        if(l==3) dp[i][l+1][j+1][k+1]=dp[i-1][1][1][1]+dp[i-1][2][1][1];
                    }
                    else{
                        dp[i][l+1][j+1][k+1]=0;
                        rep(x,3){
                            dp[i][l+1][j+1][k+1] += dp[i-1][x+1][l+1][j+1];
                        }
                    }
                }
            }
        }

        if(st[i]!=0){
            rep(x,3){
                rep(y,3){
                    rep(z,3){
                        if(x+1!=st[i]) dp[i][x+1][y+1][z+1]=0;
                    }
                }
            }
        }
        if(st[i+1]!=0){
            rep(x,3){
                rep(y,3){
                    rep(z,3){
                        if(y+1!=st[i+1]) dp[i][x+1][y+1][z+1]=0;
                    }
                }
            }
        }
        if(st[i+2]!=0){
            rep(x,3){
                rep(y,3){
                    rep(z,3){
                        if(z+1!=st[i+2]) dp[i][x+1][y+1][z+1]=0;
                    }
                }
            }
        }

    }

    ll ans = 0;
    rep(i,3){
        rep(j,3){
            rep(k,3){
                ans += dp[n-2][i+1][j+1][k+1];
            }
        }
    }

    rep(i,3){
        rep(j,3){
            rep(k,3){
                if(dp[n-2][i+1][j+1][k+1]!=0) cout << dp[n-2][i+1][j+1][k+1] << endl;
            }
        }
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

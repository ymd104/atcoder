#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
struct bill{
    int t;
    int f;
    int o;
};
*/
//bill dp[2019][2019];
//dp[i][j]:i枚でj円を達成できるような紙幣の組み合わせ

void solve(){
    int n,m;
    cin >> n >> m;
    
    /*
    y = y/1000;
    
    rep(i,n+1){
        rep(j,y+1){
            dp[i][j].t = -1;
            dp[i][j].f = -1;
            dp[i][j].o = -1;
        }
    }

    bill b={0,0,0};
    dp[0][0]=b;
    bill b1={-1,-1,-1};
    bill b2={-1,-1,-1};
    bill b3={-1,-1,-1};

    for(int i=1; i<=n; i++){
        for(int j=1; j<=y; j++){
            if(j>=10) b1=dp[i-1][j-10];
            if(j>=5) b2=dp[i-1][j-5];
            b3=dp[i-1][j-1];

            if(j>=10&&b1.t!=-1){
                dp[i][j].t = b1.t +1;
                dp[i][j].f = b1.f;
                dp[i][j].o = b1.o;
            }

            else if(j>=5&&b2.t!=-1){
                dp[i][j].t = b2.t;
                dp[i][j].f = b2.f+1;
                dp[i][j].o = b2.o;
            }

            else if(b3.t!=-1){
                dp[i][j].t = b3.t;
                dp[i][j].f = b3.f;
                dp[i][j].o = b3.o+1;
            }

            else{
                dp[i][j].t=-1;
                dp[i][j].f=-1;
                dp[i][j].o=-1;
            }

            cout << "i:" << i << " j:" << j << " dp[i][j]:" << dp[i][j].t << " " << dp[i][j].f << " " << dp[i][j].o  << endl;

        }
        
    }
    
    cout << dp[n][y].t << " " << dp[n][y].f << " " << dp[n][y].o << endl;
    */
    int x=-1;
    int y=-1;
    int z=-1;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            int k = n-i-j;
            if(k>=0){
                if(i*10000+j*5000+k*1000==m){
                    x=i;
                    y=j;
                    z=k;
                }
            }
        }
    }

    cout << x << " " << y << " " << z << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

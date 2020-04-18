#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
1~i番目までの商品を用いて重みをj以下にするときの価値の最大値p[i][j]
*/

int p[110][10100];

void solve(){

    int N,W;
    cin >> N >> W;
    int v[1010];
    int w[1010];
    rep(i,N){
        cin >> v[i+1] >> w[i+1];
    }
    rep(i,W+1){
        p[0][i]=0;
    }
    rep(i,N+1){
        p[i][0]=0;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=W; j++){
            if(j>=w[i]) p[i][j]=max(p[i-1][j], max(p[i-1][j-w[i]]+v[i],p[i][j-w[i]]+v[i]));
            else p[i][j]=p[i-1][j];
        }
    }

    /*
    rep(i,N+1){
        rep(j,W+1){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << p[N][W] << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

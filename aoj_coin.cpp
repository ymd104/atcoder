#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
1~i番目までのコインを用いて値段をj以上にするときのコイン枚数の最小値p[i][j]
*/

int p[25][50010];

void solve(){

    int n,m;
    cin >> n >> m;
    int c[30];
    rep(i,m){
        cin >> c[i+1];
    }
    rep(j,n+1){
        p[0][j]=INF;
    }
    rep(i,m+1){
        p[i][0]=0;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(j>=c[i]) p[i][j]=min(p[i-1][j], min(p[i-1][j-c[i]]+1, p[i][j-c[i]]+1));
            else p[i][j]=p[i-1][j];
        }
    }

    cout << p[m][n] << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

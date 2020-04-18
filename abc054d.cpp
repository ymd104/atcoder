#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[50];
int b[50];
int c[50];
int p[50][500][500];

void solve(){

    int n,ma,mb;
    cin >> n >> ma >> mb;
    rep(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }

    rep(i,500){
        rep(j,500){
            rep(k,n+1){
                p[k][i][j]=INF;
            }
        }
    }
    p[0][0][0]=0;
    
    for(int i=1; i<n+1; i++){
        rep(x,450){
            rep(y,450){
                if(x>=a[i-1]&&y>=b[i-1]) p[i][x][y]=min(min(p[i-1][x][y], p[i][x][y]), p[i-1][x-a[i-1]][y-b[i-1]]+c[i-1]);
                else p[i][x][y]=p[i-1][x][y];
            }
        }
    }

    /*
    rep(i,30){
        rep(j,30){
                if(p[n][i][j]!=INF) cout << p[n][i][j] << " ";
                else cout << "?? ";
        }
        cout << endl;
    }
    */
    
    

    int tmp = INF;
    for(int i=1; i<=39; i++){
        if(p[n][i*ma][i*mb]!=INF) {
            tmp = min(tmp,p[n][i*ma][i*mb]);
        }
    }
    if (tmp!=INF) cout << tmp << endl;
    else cout << -1 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

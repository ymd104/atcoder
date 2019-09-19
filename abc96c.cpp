#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;




void solve(){
    int h,w;
    cin >> h >> w;
    char grid[h+10][w+10];
    rep(i,h+2){
        rep(j,w+2){
            grid[i][j] = '.';
        }
    }
    rep(i,h){
        rep(j,w){
            cin >> grid[i+1][j+1];
        }
    }
    string ans = "Yes";
    rep(i,h){
        rep(j,w){
            if(grid[i+1][j+1]=='#'){
                //全方位'.'ならfalse
                if(grid[i+1][j+2]=='.' && grid[i+1][j]=='.' && grid[i][j+1]=='.' && grid[i+2][j+1]=='.'){
                    ans = "No";
                }
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

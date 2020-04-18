#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){

    ll a[4][4];
    rep(i,3){
        rep(j,3){
            cin >> a[i][j];
        }
    }
    ll n;
    cin >> n;
    ll b[12];
    rep(i,n){
        cin >> b[i];
        rep(x,3){
            rep(y,3){
                if(a[x][y]==b[i]) a[x][y]=-1;
            }
        }
    }

    bool ans = false;
    rep(i,3){
        if(a[i][0]==-1 && a[i][1]==-1 && a[i][2]==-1) ans = true;
        if(a[0][i]==-1 && a[1][i]==-1 && a[2][i]==-1) ans = true;
    }
    if(a[0][0]+a[1][1]+a[2][2]==-3) ans = true;
    if(a[2][0]+a[1][1]+a[0][2]==-3) ans = true;

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
 
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

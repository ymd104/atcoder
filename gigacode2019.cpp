#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll a[150][150];
ll sum[150][150];
//sum[i][j]:0,0からi-1,j-1までの地価の和

void solve(){

    ll h,w,k,v;
    cin >> h >> w >> k >> v;
    rep(i,h){
        sum[i][0]=0;
    }
    rep(j,w){
        sum[0][j]=0;
    }
    rep(i,h){
        rep(j,w){
            int x;
            cin >> x;
            a[i][j]=x+k;
            sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+a[i][j];
        }
    }

    /*
    rep(i,h+1){
        rep(j,w+1){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    */

    ll ans = 0;
    for(ll i1=0; i1<=h; i1++){
        for(ll i2=i1+1; i2<=h; i2++){
            for(ll j1=0; j1<=w; j1++){
                for(ll j2=j1+1; j2<=w; j2++){
                    ll tmp = sum[i2][j2]-sum[i2][j1]-sum[i1][j2]+sum[i1][j1];
                    //cout << tmp << endl;
                    if(tmp<=v) ans = max(ans,(j2-j1)*(i2-i1));
                    else break;
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

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[12][10010];
ll h[10010];

void solve(){

    int r,c;
    cin >> r >> c;
    rep(i,r){
        rep(j,c){
            cin >> a[i][j];
        }
    }
    rep(i,10010){
        h[i]=0;
    }

    ll ans=0;
    for(int bit=0; bit<(1<<r); bit++){

        ll count = 0;
        int tmp=bit;
        for(int j=0; j<r; j++){
            if(tmp%2==1) {
                rep(k,c){
                    if(a[j][k]==0){
                        h[k]++;
                    }
                }
            }
            else{
                rep(k,c){
                    if(a[j][k]==1){
                        h[k]++;
                    }
                }
            }
            tmp = tmp/2;
        }

        /*
        cout << bit << endl;
        rep(i,c){
            cout << h[i] << " ";
        }
        cout << endl;
        */

        rep(i,c){
            count += max(ll(h[i]), ll(r-h[i]));
        }

        ans = max(ll(count), ll(ans));

        rep(i,10010){
            h[i]=0;
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

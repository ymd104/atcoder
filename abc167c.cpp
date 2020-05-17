#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll c[20];
ll a[20][20];

ll d[20];
void base2(ll x){
    ll i=0;
    while(x!=0){
        d[i]=x%2;
        x = x/2;
        i++;
    }
}


void solve(){

    ll n,m,x;
    cin >> n >> m >> x;
    rep(i,n){
        cin >> c[i];
        rep(j,m){
            cin >> a[i][j];
        }
    }

    /*
    base2(30);
    rep(i,20){
        cout << d[i];
    }
    cout << endl;
    */

    ll ans = INF;
    ll rikai[20];
    rep(i,20){
        rikai[i]=0;
    }
    rep(i,(1 << n)){
        rep(i,20){
            rikai[i]=0;
        }
        ll tmp=0; //値段
        base2(i);
        /*
        rep(t,n){
            cout << d[t];
        }
        cout << endl;
        */
        //d[j]:j番目の本を買う
        rep(j,n){
            if(d[j]==1){
                tmp += c[j];
                rep(k,m){
                    rikai[k] += a[j][k];
                }
            }
        }
        bool b=true;
        rep(j,m){
            if(rikai[j]<x){
                b = false;
            }
        }
        if(b) ans = min(ans,tmp);
    }

    if(ans!=INF) cout << ans << endl;
    else cout << -1 << endl;




}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

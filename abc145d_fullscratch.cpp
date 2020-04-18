#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
w+hCw= (w+h)! / w!h!
*/

ll l[35];

ll power(ll m, ll n){

    l[0]=m;
    for(ll i=1; i<35; i++){
        l[i] = (l[i-1]*l[i-1]) % MOD;
    }
    /*
    rep(i,35){
        cout << l[i] << " ";
    }
    cout << endl;
    */

    ll tmp = n;
    ll ans = 1;
    rep(i,35){
        if(tmp%2==1){
            ans = (ans*l[i]) % MOD;
        }
        tmp /= 2;
        //cout << ans << " ";
    }
    //cout << endl;
    return ans%MOD;

}

void solve(){

    ll x,y;
    cin >> x >> y;
    if((2*x-y)%3!=0||(2*y-x)%3!=0){
        cout << 0 << endl;
        return;
    }
    ll h = (2*x-y)/3;
    ll w = (2*y-x)/3;
    if(h<0||w<0){
        cout << 0 << endl;
        return;
    }
    ll ans = 1;
    rep(i,h+w){
        ans = (ans*(i+1))%MOD;
    }
    rep(i,h){
        ans = (ans * power(i+1,MOD-2))%MOD;
    }
    rep(i,w){
        ans = (ans * power(i+1,MOD-2))%MOD;
    }

    cout << ans << endl;


}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

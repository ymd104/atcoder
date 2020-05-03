#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

ll pow5(ll x){
    ll y;
    y=x*x*x*x*x;
    return y;
}

void solve(){

    /*
    ll t = 1;
    while(pow5(t+1)-pow5(t)<=1000000000){
        t++;
    }

    cout << t << endl;
    cout << pow5(t) << " " << pow5(t+1) << endl;
    */

    ll x_;
    cin >> x_;
    
    ll th = 120;

    for(ll i=(-1)*th; i<=th; i++){
        for(ll j=(-1)*th; j<=th; j++){
            if(pow5(i)-pow5(j)==x_){
                cout << i << " " << j << endl;
                return;
            }
        }
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

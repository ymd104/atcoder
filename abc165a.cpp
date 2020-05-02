#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;



void solve(){

    ll k;
    cin >> k;

    ll a,b;
    cin >> a >> b;

    bool b_=false;

    for(ll i=a; i<=b; i++){
        if(i%k==0) b_=true;
    }

    if(b_) cout << "OK" << endl;
    else cout << "NG" << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

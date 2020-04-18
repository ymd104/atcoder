#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){

    ll a,b;
    cin >> a >> b;
    rep(i,20000){
        //cout << i*1.08 << " " << i*1.10 << endl;
        if(int(i*0.08)==a&&int(i*0.10)==b) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

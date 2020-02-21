#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*

*/

bool is_prime(const unsigned n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: return true;
    } // n > 2 が保証された

    if(n%2 == 0) return false;

    // 上で i=2 相当は調べたので、i=3から奇数のみ調べる
    for(unsigned i=3;i*i<=n;i+=2){
        if(n%i == 0) return false;
    }

    return true;
}


void solve(){

    ll x;
    cin >> x;
    ll ans;
    ll tmp = x;
    while(true){
        if(is_prime(tmp)){
            ans = tmp;
            break;
        }
        else{
            tmp++;
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

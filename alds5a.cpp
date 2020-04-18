#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll q[25];
ll m[2010];
ll lis[2000000];

void solve(){

    ll n;
    cin >> n;
    rep(i,n){
        cin >> q[i];
    }
    ll a;
    cin >> a;
    rep(i,a){
        cin >> m[i];
    }

    

    for (int bit = 0; bit < (1<<n); ++bit) {
        ll count = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                count += q[i];
            }
            lis[bit]=count;
        }
        
    }
        
    rep(i,a){
        bool b = false;
        rep(bit, 1<<n){
            if(lis[bit]==m[i]) {
                b=true;
                break;
            }
        }
        if(b) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    

    
    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

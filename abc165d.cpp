#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;


void solve(){

    ll a,b,n;
    cin >>a >> b >> n;

    if(b-1<=n){
        cout << (a*(b-1))/b - a*((b-1)/b) << endl;
    }
    else{
        cout << (a*(n))/b - a*((n)/b) << endl;
    }

    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

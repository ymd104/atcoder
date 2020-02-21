#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*

*/


void solve(){

    ll a,b,k;
    cin >> a >> b >> k;
    ll a1, a2;
    if(a<k){
        a1 = 0;
        a2 = max((ll)0,b-(k-a));
    }
    else{
        a1 = a-k;
        a2 = b;
    }

    cout << a1 << " " << a2 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

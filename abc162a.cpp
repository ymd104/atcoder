#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){

    ll n;
    cin >> n;
    int a,b,c;
    a = n%10;
    b = (n/10)%10;
    c = (n/100)%10;
    if(a==7||b==7||c==7) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

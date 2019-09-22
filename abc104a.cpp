#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){
    int r;
    cin >> r;
    if(r<1200) cout << "ABC" << endl;
    else if(r<2800) cout << "ARC" << endl;
    else cout << "AGC" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

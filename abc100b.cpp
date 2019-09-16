#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int d,n;
    cin >> d >> n;
    int tmp = pow(100,d);
    if(n!=100) cout << n * tmp << endl;
    else cout << 101*(tmp) << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

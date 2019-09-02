#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;


void solve(){
    int r,d,x;
    cin >> r >> d >> x;
    rep(i,10){
        x = r*x - d;
        cout << x << endl; 
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
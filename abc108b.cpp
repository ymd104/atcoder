#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int x = c-a;
    int y = d-b;
    cout << c - y << " " << d + x << " " << c - y - x << " " << d + x - y << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
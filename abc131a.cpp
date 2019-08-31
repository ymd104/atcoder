#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

void solve(){
    int s;
    bool b;
    int a1, a2, a3, a4;
    cin >> s;
    a4 = s%10;
    s /= 10;
    a3 = s%10;
    s /= 10;
    a2 = s%10;
    s /= 10;
    a1 = s%10;
    b = (a1 == a2) || (a2 == a3) || (a3 == a4);
    if(b) cout << "Bad" << endl;
    else cout << "Good" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
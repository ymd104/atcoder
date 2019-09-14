#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

/*
例えば2 3 1 4をそれぞれ1 2 3 4で割り、割った余りの総和の最大値を計算する
2 3 4 ... n-1 n 1とすると、余りの総和は1+2+...+(n-1)となり、これが最大？
*/

void solve(){
    ll n;
    cin >> n;
    cout << (n*(n-1))/2 << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
全探索？
aNまでの全ての数の最小公倍数で1ループするので、1からその数まで調べれば良い
→時間が厳しそう。
最小公倍数-1?
6+45+10+19+10=90なのでそれっぽい

実際、最小公倍数から1を引いた数は全ての整数値から1を引いたあまりになるのでこれが最大
*/

void solve(){
    int n;
    cin >> n;
    int a[n+10];
    ll ans = 0;
    rep(i,n){
        cin >> a[i];
        ans += a[i]-1;
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

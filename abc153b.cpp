#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[100010];

void solve(){
  int h,n;
  cin >> h >> n;
  ll sum = 0;
  rep(i,n){
      cin >> a[i];
      sum += a[i];
  }
  cout << (sum>=h? "Yes": "No") << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

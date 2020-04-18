#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll m[10010];
ll a[10010];
ll b[10010];

void solve(){
  ll h,n;
  cin >> h >> n;
  vector<pair<int,int>> v;
  rep(i,n){
      cin >> a[i] >> b[i];
  }
  m[0]=0;
  for(ll i=1; i<=h; i++){
      m[i]= (i>=a[0]? m[i-a[0]]+b[0]: b[0]);
      for(ll j=1; j<n; j++){
          m[i]=min(m[i], (i>=a[j]? m[i-a[j]]+b[j]: b[j]));
      }
  }

  rep(i,h){
      //cout << m[i] << endl;
  }

  cout << m[h] << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

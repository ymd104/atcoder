#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){
  int n;
  cin >> n;
  int d[n+10];
  rep(i,n){
      cin >> d[i];
  }
  ll sum = 0;
  for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
          sum += d[i]*d[j];
      }
  }
  cout << sum << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

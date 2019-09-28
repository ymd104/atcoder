#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){
  int n,k;
  cin >> n >> k;
  int h[n+10];
  rep(i,n){
    cin >> h[i];
  }
  int count = 0;
  rep(i,n){
    if(h[i]>=k) count++;
  }
  cout << count << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

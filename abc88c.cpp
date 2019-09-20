#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;




void solve(){
  int a[3][3];
  cin>>a[0][0]>>a[0][1]>>a[0][2];
  cin>>a[1][0]>>a[1][1]>>a[1][2];
  cin>>a[2][0]>>a[2][1]>>a[2][2];
  
  string ans="Yes";
  rep(j,3){
  int tmp=a[j][0]-a[0][0];
  rep(i,2){
    if(tmp!=a[j][i+1]-a[0][i+1]) ans="No";
  }
  }
  
  rep(j,3){
  int tmp=a[0][j]-a[0][0];
  rep(i,2){
    if(tmp!=a[i+1][j]-a[i+1][0]) ans="No";
  }
  }
  
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

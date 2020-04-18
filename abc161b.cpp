#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[1010];

void solve(){

  int n,m;
  cin >> n >> m;
  int s = 0;
  rep(i,n){
    cin >> a[i];
    s += a[i];
  }

  sort(a,a+n, greater<int>());
  bool b=true;
  rep(i,m){
    if(a[i]< double(double(s)/double(4*m))) b=false;
  }

  if(b) cout << "Yes" << endl;
  else cout << "No" << endl;



}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

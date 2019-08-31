#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

void solve(){
  int n;
  cin >> n;
  vector<int> w;
  rep(i,n){
    int a;
    cin >> a;
    w.emplace_back(a);
  }
  
  int ans=100000000;
  rep(i,n){
    int s1=0;
    int s2=0;
    for(int j=0; j<=i; j++){
       s1 += w[j];
    }
    for(int k=n-1; k>i; k--){
       s2 += w[k]; 
    }
    ans = min(ans, abs(s2-s1)); 
  }
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
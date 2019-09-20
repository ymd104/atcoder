#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;




void solve(){
  int n;
  cin >> n;
  string s[n+10];
  rep(i,n){
    cin>> s[i];
  }
  ll count[5];
  rep(i,5){
    count[i]=0;
  }
  rep(i,n){
    char c=s[i][0];
    if(c=='M') count[0]++;
    if(c=='A') count[1]++;
    if(c=='R') count[2]++;
    if(c=='C') count[3]++;
    if(c=='H') count[4]++;
  }
  ll ans=0;
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      for(int k=0; k<5; k++){
        if(i<j&&j<k) ans+=count[i]*count[j]*count[k];
      }
    }
  }
  cout<<ans<<endl;
  
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

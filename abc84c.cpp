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
    int c[n+10];
    int s[n+10];
    int f[n+10];
    rep(i,n-1){
      cin >> c[i] >> s[i] >> f[i];
    }
    rep(i,n-1){
      int t=0;
      for(int j=i; j<n-1; j++){
        if(t<s[j]) t=s[j]+c[j];
        else{
          int tmp = t-s[j];
          if(tmp%f[j]!=0){
            t = s[j]+((tmp/f[j])+1)*f[j]+c[j];
          }
          else{
            t += c[j];
          }
        }
      }
      cout << t << endl;
    }
    cout << 0 << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

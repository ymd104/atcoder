#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int a,b;
    cin >> a >> b;
    if(a==1) a +=13;
    if(b==1) b += 13;
    string ans;
    if(a>b) ans = "Alice";
    else if(a<b) ans = "Bob";
    else ans = "Draw";
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;


void solve(){
    int a,b,c;
    int k;
    cin >> a >> b >> c;
    cin >> k;
    rep(i,k){
        if(a>=b&&a>=c) a = a*2;
        else if(b>=c) b = b*2;
        else c = c*2;
    }
    cout << a+b+c << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

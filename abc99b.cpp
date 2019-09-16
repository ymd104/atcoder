#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

int sum(int x){
    int s = 0;
    rep(i,x+1){
        s += i;
    }
    return s;
}

void solve(){
    int a,b;
    cin >> a >> b;
    cout << sum(b-a)-b << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

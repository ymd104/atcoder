#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[10000];
int sorted[10000];

void solve(){

    random_device rnd;
    cout << 10000 << endl;
    rep(i,10000){
        cout << rnd()%10 << " ";
    }
    cout << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

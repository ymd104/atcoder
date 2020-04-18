#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll fib[50];

void solve(){

    int n;
    cin >> n;
    fib[0]=1;
    fib[1]=1;
    for(int i=2; i<=n; i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    cout << fib[n] << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

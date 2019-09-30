#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){
    int n;
    cin >> n;
    int a[3][n+10];
    rep(i,n){
        cin >> a[0][i];
    }
    rep(i,n){
        cin >> a[1][i];
    }
    int m = 0;
    rep(i,n){
        int sum = 0;
        for(int j=0; j<=i; j++){
            sum += a[0][j];
        }
        for(int k=i; k<n; k++){
            sum += a[1][k];
        }
        m = max(m,sum);
    }
    cout << m << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
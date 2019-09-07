#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int n;
    cin >> n;
    int a[n+10], b[n+10], c[n+10];
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    rep(i,n-1){
        cin >> c[i];
    }
    int sum = b[0];
    for(int i=1; i<n; i++){
        if(a[i]-a[i-1]==1){
            sum += c[a[i-1]-1];
        }
        sum += b[i];
    }
    cout << sum << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

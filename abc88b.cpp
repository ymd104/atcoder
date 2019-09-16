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
    int a[n+1];
    rep(i,n){
        cin >> a[i];
    }
    a[n]=0;
    sort(a, a+n+1, greater<>());
    //cout << a[1] << endl;
    int suma = 0;
    int sumb = 0;
    for(int i=0; i<n; i=i+2){
        suma += a[i];
        sumb += a[i+1];
    }
    cout << suma-sumb << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

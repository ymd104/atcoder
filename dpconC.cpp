#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;

void solve(){
    int n;
    cin >> n;
    int a[n+10], b[n+10], c[n+10];
    rep(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }
    int dpa[n+10], dpb[n+10], dpc[n+10];
    dpa[0]=a[0];
    dpb[0]=b[0];
    dpc[0]=c[0];
    for(int i=1; i<n; i++){
        dpa[i]=max(dpb[i-1]+a[i], dpc[i-1]+a[i]);
        dpb[i]=max(dpa[i-1]+b[i], dpc[i-1]+b[i]);
        dpc[i]=max(dpa[i-1]+c[i], dpb[i-1]+c[i]);
    }
    cout << max(dpa[n-1], max(dpb[n-1], dpc[n-1])) << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

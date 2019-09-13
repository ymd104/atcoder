#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*
mの約数で、m/x>=nを満たす最大のx
*/

void solve(){
    int n, m;
    cin >> n >> m;
    int thres = m;
    int ans=1;
    vector<int> v = enum_div(m);
    int s = v.size();
    for(int i=n; i<=m/2+1; i++){
        if(m%i==0){
            ans = m/i;
            break;
        }
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

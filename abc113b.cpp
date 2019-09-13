#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

/*

*/

void solve(){
    int n;
    cin >> n;
    double t,a;
    cin >> t >> a;
    double h[n+10];
    rep(i,n){
        cin >> h[i];
    }
    double err = 1000000000;
    int point = 0;
    rep(i,n){
        double tmp = t - h[i]*0.006;
        //cout << tmp << endl;
        if(err>abs(tmp-a)) {
            point = i;
            err = abs(tmp-a);
        }
    }
    cout << point + 1 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

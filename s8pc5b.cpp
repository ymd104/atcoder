#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

long double x[210];
long double y[210];
long double r[210];
vector<long double> maxr;

void solve(){

    int n,m;
    cin >> n >> m;

    rep(i,n){
        cin >> x[i] >> y[i] >> r[i];
    }
    rep(i,m){
        cin >> x[n+i] >> y[n+i];
    }

    rep(i,m){
        rep(j,n){
            maxr.emplace_back( sqrt(pow(x[j]-x[n+i],2) + pow(y[j]-y[n+i],2)) - r[j]);
        }
        rep(j,m){
            if(i==j) continue;
            maxr.emplace_back( 0.5 *  sqrt(pow(x[n+j]-x[n+i],2) + pow(y[n+j]-y[n+i],2)) );
        }
    }

    /*
    for(auto e:maxr){
        cout << e << " ";
    }
    cout << endl;
    */

    rep(i,n){
        maxr.emplace_back(r[i]);
    }

    sort(maxr.begin(), maxr.end());
    cout << setprecision(12) << maxr[0] << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

int t[510][510];
int sum[510][510];

void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    rep(i,510){
        rep(j,510){
            t[i][j]=0;
        }
    }
    rep(i,m){
        int l,r;
        cin >> l >> r;
        t[l][r] += 1;
    }
    rep(i,510){
        rep(j,510){
            sum[i][j]=0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t[i][j];
        }
    }
    vector<pair<int,int>> v;
    rep(i,q){
        int a,b;
        cin >> a >> b;
        v.emplace_back(make_pair(a,b));
    }

    rep(i,q){
        int a,b;
        a=v[i].first;
        b=v[i].second;
        cout << sum[b][b]+sum[a-1][a-1]-sum[b][a-1]-sum[a-1][b] << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

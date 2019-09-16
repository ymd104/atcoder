#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;


void solve(){
    int n,x;
    cin >> n >> x;
    int m[n+10];
    int mi = INF;
    int sum=0;
    rep(i,n){
        cin >> m[i];
        mi = min(mi, m[i]);
        sum += m[i];
    }
    int tmp = (x-sum)/mi;
    cout << n+tmp << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

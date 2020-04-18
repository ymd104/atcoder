#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){

    int n;
    cin >> n;
    int a[110];
    rep(i,n){
        cin >> a[i];
    }
    string ans = "APPROVED";
    rep(i,n){
        if(a[i]%2==0 && a[i]%3!=0 && a[i]%5 !=0){
            ans = "DENIED";
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

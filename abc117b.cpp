#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int n;
    cin >> n;
    int l[n+10];
    int sum=0;
    int m = 0;
    rep(i,n){
        cin >> l[i];
        sum += l[i];
        m = max(m, l[i]);
    }
    if(m < sum-m) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
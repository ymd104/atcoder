#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int n;
    cin >> n;
    int h[n+10];
    rep(i,n){
        cin >> h[i];
    }

    int count = 0;
    int ans = 0;
    for(int i=n-2; i>=0; i--){
        if(h[i]>=h[i+1]){
            count++;
        }
        else{
            count = 0;
        }
        ans = max(ans,count);
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

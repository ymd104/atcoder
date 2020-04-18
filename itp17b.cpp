#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


void solve(){

    while(true){
        ll n,x;
        cin >> n >> x;
        if(n==0&&x==0) break;
        ll count=0;
        for(ll i=1; i<=n; i++){
            for(ll j=i+1; j<=n; j++){
                if(x-i-j>=1&&x-i-j<=n&&x-i-j>i&&x-i-j>j) count++;
            }
        }
        cout << count << endl;
    }    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

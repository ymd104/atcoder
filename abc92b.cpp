#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;


void solve(){
    int n;
    cin >> n;
    int d,x;
    cin >> d >> x;
    int a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    int sum=x;
    rep(i,n){
        if(d%a[i]!=0) sum += d/a[i]+1;
        else sum += d/a[i];
    }
    cout << sum << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

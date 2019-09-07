#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int n;
    cin >> n;
    int  b[n+10];
    rep(i,n-1){
        cin >> b[i];
    }
    /*
    数列a0,a1,a2,...
    は、
    b[0], min(b[0],b[1]), min(b[1],b[2]), ..., min(b[n-3], b[n-2]), b[n-2]
    0 0 10 10 10 23
    */
    int sum = 0;
    sum += b[0];
    //cout << b[0] << endl;
    sum += b[n-2];
    //cout << b[n-1] << endl;
    for(int i=0; i<n-2; i++){
        sum += min(b[i],b[i+1]);
    }
    cout << sum << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

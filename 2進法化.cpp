#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


int d[10];


void base2(int x){
    int i=9;
    while(x!=0){
        d[i]=x%2;
        x = x/2;
        i--;
    }
}


void solve(){
    rep(i,10){
    d[i]=0;
    }
    int n;
    cin >> n;
    base2(n);
    rep(i,10){
        cout << d[i];
    }
    cout << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


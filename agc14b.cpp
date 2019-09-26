#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
奇数個登場する頂点があると駄目？

1 2
1 3
奇数個の頂点があって木になる場合を生み出したい
なさそう

用いられてる頂点
*/

void solve(){
    int n,m;
    cin >> n >> m;
    int c[n+10];
    rep(i,n){
        c[i]=0;
    }
    rep(i,2*m){
        int tmp;
        cin >> tmp;
        c[tmp-1]++;
    }
    rep(i,n){
        if(c[i]%2!=0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


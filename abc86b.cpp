#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

bool sq(int x){
    bool b = false;
    rep(i,x){
        if(i*i==x) b=true;
    }
    return b;
}

void solve(){
    int a,b;
    cin >> a >> b;
    int connect;
    if(b<10) connect = 10*a+b;
    else if(b<100) connect = 100*a+b;
    else connect = 1000*a+b;

    if(sq(connect)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

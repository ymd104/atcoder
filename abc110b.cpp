#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;


void solve(){
    int n,m,X,Y;
    cin >> n >> m >> X >> Y;
    int x[n+10];
    int y[m+10];
    rep(i,n){
        cin >> x[i];
    }
    rep(i,m){
        cin >> y[i];
    }
    /*
    int tmp = 0;
    rep(i,n){
        tmp = max(tmp,x[i]);
    }
    int tmp2=INF;
    rep(i,m){
        tmp2 = min(tmp2, y[i]);
    }

    string ans = "War";
    if(tmp<tmp2) {
    //tmp+1 ~ tmp2までのすべての整数値
        for(int i=tmp+1; i<=tmp2; i++){
            if(X < i && i <= Y) ans = "No War";
        }
    }
    cout << ans << endl;
    */
    string ans = "War";
    for(int z = -100; z<=100; z++){
        bool b=true;
        if(X>=z) b=false;
        if(z>Y) b=false;
        rep(i,n){
            if(x[i]>=z) b=false;
        }
        rep(i,m){
            if(y[i]<z) b=false;
        }
        if(b) ans = "No War";
    }
    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

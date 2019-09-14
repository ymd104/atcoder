#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;


void solve(){
    int d;
    cin >> d;
    int tmp = 25-d;
    string s = "Christmas";
    rep(i,tmp){
        s += " Eve";
    }
    cout << s << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
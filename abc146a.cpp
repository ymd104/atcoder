#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*



*/


void solve(){

    string s;
    cin >> s;

    if(s == "SUN") cout << 7 << endl;
    if(s == "MON") cout << 6 << endl;
    if(s == "TUE") cout << 5 << endl;
    if(s == "WED") cout << 4 << endl;
    if(s == "THU") cout << 3 << endl;
    if(s == "FRI") cout << 2 << endl;
    if(s == "SAT") cout << 1 << endl;
    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

void solve(){
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    string ans="YES";
    while(s.size()!=0){
        if(s.substr(0,5)=="maerd") s = s.substr(5);
        else if(s.substr(0,7)=="remaerd") s = s.substr(7);
        else if(s.substr(0,5)=="esare") s = s.substr(5);
        else if(s.substr(0,6)=="resare") s = s.substr(6);
        else {
            ans = "NO";
            break;
        }
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

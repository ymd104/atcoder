#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    string ans = "";
    rep(i,n){
        for(ll j=1; j<=n-i; j++){
            string str = s.substr(i,j);
            bool b=true;
            rep(k,str.length()){
                if(str[k]!='A'&&str[k]!='C'&&str[k]!='G'&&str[k]!='T'){
                    b=false;
                }
            }
            if(b) {
                if(ans.length()<str.length()) ans = str;
            }
        }
    }

    cout << ans.length() << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

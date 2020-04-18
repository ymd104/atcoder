#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
Xのi番目とYのj番目までのLCS
*/

int lcs[1010][1010];

void solve(){

    int q;
    cin >> q;
    vector<int> v;
    rep(i,q){
        string s,t;
        cin >> s;
        cin >> t;
        rep(i,1010){
            rep(j,1010){
                lcs[i][j]=0;
            }
        }
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<t.length(); j++){
                if(s[i]==t[j]) lcs[i+1][j+1]=lcs[i][j]+1;
                else lcs[i+1][j+1]=max(lcs[i+1][j], lcs[i][j+1]);
            }
        }
        v.emplace_back(lcs[s.length()][t.length()]);
    }

    for(auto e: v){
        cout << e << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;



void solve(){
    string s,t;
    cin >> s >> t;
    int sizes = s.size();
    int sizet = t.size();
    int repeat = sizes-sizet+1;
    //例えば|S|=5,|T|=2なら、i=0~3.
    //i=0~sizes-sizetまで繰り返したものを格納
    vector<string> a;
    rep(i,repeat){
        bool b=true;
        rep(j,sizet){
            if(s[i+j]!='?'&&s[i+j]!=t[j]){
                b=false;
            }
        }
        string tmp=s;
        if(b) {
            rep(j,sizes){
                if(j<i){
                    if(s[j]=='?') tmp[j]='a';
                }
                else if(i+sizet<=j) {
                    if(s[j]=='?') tmp[j]='a';
                }
                else{
                    tmp[j]=t[j-i];
                }
            }
            a.emplace_back(tmp);
        }
    }
    sort(a.begin(), a.end());
    if(a.size()==0) cout << "UNRESTORABLE" << endl;
    else cout << a[0] << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

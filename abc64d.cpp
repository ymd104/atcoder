#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
)()( -> ()()()
))(( -> (())(())
sからペアを削っていき、残ったものを考える
*/

void solve(){;
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    t=s;
    rep(i,n){
        for(int j=1; j<n; j++){
            if(s[j-1]=='('&&s[j]==')'){
                s.erase(s.begin()+j-1, s.begin()+j+1);
            }
        }
    }
    int c1=0;
    int c2=0;
    //cout << s << endl;
    rep(i,s.size()){
        if(s[i]=='(') c1++;
        if(s[i]==')') c2++;
    }
    rep(i,c2){
        t = '(' + t;
    }
    rep(i,c1){
        t = t + ')';
    }
    cout << t << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

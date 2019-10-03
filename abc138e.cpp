#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
*/

ll dist(char c){
    int tmp = c - 'a';
    return tmp;
}

ll nex[300100][30];

void solve(){
    string s,t;
    cin >> s >> t;
    ll i=0;
    ll j=0;
    ll ss = s.size();
    ll ts = t.size();
    
    rep(i,300100){
        rep(j,30){
            nex[i][j]=-1;
        }
    }

    string str = s + s;
    /*
    for(int i=str.size()-1; i>0; i--){
        for(int j=i-1; j>=0; j--){
            nex[j][dist(str[i])] = i-j;
        }
    }
    */
    rep(i,26){
        nex[str.size()][i] = -1;
    }
    rep(i,26){
        for(int j=str.size()-1; j>=0; j--){
            nex[j][i] = i==dist(str[j+1])? 1: nex[j+1][i]==-1? -1:nex[j+1][i]+1;
        }
    }
    
    /*
    rep(i,str.size()+10){
        rep(j,30){
            cout << nex[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    
    set<char> st;
    rep(i,ss){
        st.insert(s[i]);
    }
    rep(i,ts){
        if(st.count(t[i])==0){
            cout << -1 << endl;
            return;
        }
    }
    

    ll ans = t[0]==s[0]? 1:nex[0][dist(t[0])]+1;
    
    ll tmp = t[0]==s[0]? 0:nex[0][dist(t[0])];
    for(ll i=1; i<ts; i++){
        if(nex[tmp%ss][dist(t[i])]==-1){
            ans = -1;
            break;
        }
        ans += nex[tmp%ss][dist(t[i])];
        tmp += nex[tmp%ss][dist(t[i])];
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
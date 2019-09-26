#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
kが最大でも5なので、答えになるのは長さが1~5まで
最大の長さが固定されていれば、O(n)で全探索できる
*/


void pr(set<string> k){
    int siz = k.size();
    for(int i=0; i<siz; i++){
        auto itr = k.begin();
        rep(j,i){
            itr++;
        }
        cout << *itr << " " << endl;
    }
}


void solve(){
    string s;
    int k;
    cin >> s;
    cin >> k;

    int n=s.size();
    set<string> st;
    string tmp;
    rep(i,n){
        char c = s[i];
        string t{c};
        st.insert(t);
        //cout << "tmp:" << t << endl;
    }
    /*
    if(n>=2){
    for(int i=1; i<n; i++){
        st.insert(s.substr(i,2));
        cout << "tmp:" << tmp << endl;
    }
    }
    */

    for(int m=2; m<=5; m++){
        if(n>=m){
            for(int i=m-1; i<n; i++){
                string result = s.substr(i-m+1,m);
                //cout << "result:" << result << endl;
                st.insert(result);
            //cout << "tmp:" << tmp << endl;
            }
        }
    }


    //pr(st);
    auto i = st.begin();
    rep(j,k-1){
        i++;
    }
    cout << *i << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

void solve(){
    int n;
    cin >> n;
    bool b[n+10][n+10];
    vector<int> v[n+10];
    //v[i]:頂点iから辺が伸びている頂点の集合
    rep(i,n){
        string s;
        cin >> s;
        rep(j,n){
            if(s[j]=='1') {
                b[i][j]=true;
                v[i].emplace_back(j);
            }
            else b[i][j]=false;
        }
    }
    /*
    rep(j,n){
        for(auto i:v[j]){
            cout << i << " ";
        }
        cout << endl;
    }
    */
    
    int ans = -1;
    rep(i,n){
        int d[n+10];
        bool visited[n+10];
        fill(d,d+n+10,0);
        fill(visited,visited+n+10,false);
        visited[i]=true;
        stack<int> st;
        st.push((int)i);
        while(!st.empty()){
            int tmp = st.top();
            st.pop();
            for(auto j:v[tmp]){
                if(!visited[j]){
                    d[j]=d[tmp]+1;
                    visited[j]=true;
                    st.push(j);
                }
            }
        }
        bool ok=true;
        rep(j,n){
            rep(k,n){
                if(b[j][k]){
                    //cout << "i,j:" << i << " " << j << ", d[i],d[j]:" << d[i] << " " << d[j] << endl;
                    if(d[j]==d[k]) ok=false;
                }
            }
        }
        int m = 0;
        rep(j,n){
            //cout << "d[" << j << "]:" << d[j] << endl;
            m = max(m,d[j]);
        }
        if(ok) ans = max(ans, m+1);
    }

    cout << ans << endl;
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
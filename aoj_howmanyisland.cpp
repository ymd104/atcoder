#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int c[55][55];
bool v[55][55];

void solve(){

    int w,h;
    vector<int> a;

    while(true){
        cin >> w >> h;
        if(w==0&&h==0) break;
        rep(i,h){
            rep(j,w){
                v[i][j]=false;
            }
        }
        rep(i,h) v[i][w]=true;
        rep(j,w) v[h][j]=true;
        v[h][w]=true;

        rep(i,h){
            rep(j,w){
                cin >> c[i][j]; 
                if(c[i][j]==0) v[i][j]=true;
            }
        }

        int ans=0;
            
            rep(i,h){
                rep(j,w){
                    if(!v[i][j]) {
                        stack<pair<int,int>> st;
                        st.push(make_pair(i,j));
                        while(!st.empty()){
                            int ti = st.top().first;
                            int tj = st.top().second;
                            st.pop();
                            v[ti][tj]=true;
                            
                            if(v[ti+1][tj]==false) st.push(make_pair(ti+1,tj));
                            if(v[ti][tj+1]==false) st.push(make_pair(ti,tj+1));
                            if(ti>0) {if(v[ti-1][tj]==false) st.push(make_pair(ti-1,tj));}
                            if(tj>0) {if(v[ti][tj-1]==false) st.push(make_pair(ti,tj-1));}
                            if(v[ti+1][tj+1]==false) st.push(make_pair(ti+1,tj+1));
                            if(ti>0) {if(v[ti-1][tj+1]==false) st.push(make_pair(ti-1,tj+1));}
                            if(tj>0) {if(v[ti+1][tj-1]==false) st.push(make_pair(ti+1,tj-1));}
                            if(ti>0&&tj>0) {if(v[ti-1][tj-1]==false) st.push(make_pair(ti-1,tj-1));}
                            
                        }
                        ans++;
                    }
                }
            }

        a.emplace_back(ans);
        


    }

    for(auto e:a){
        cout << e << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

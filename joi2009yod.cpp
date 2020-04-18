#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int ice[100][100];
int constice[100][100];
int dis[100][100];
bool v[100][100];
int w,h;

int ans = 0;

int rec(int ice[100][100], int a, int b, int d){
    ice[a][b]=0;
    cout << "a: " << a << " b: " << b << " d: " << d << endl;
    if(ice[a+1][b]==0&&ice[a-1][b]==0&&ice[a][b+1]==0&&ice[a][b-1]==0){
        if(d>ans) ans = d;
    }
    if(ice[a+1][b]==1){
        ice[a+1][b]=0;
        rec(ice, a+1,b,d+1);
    }
    if(ice[a-1][b]==1){
        ice[a-1][b]=0;
        rec(ice, a-1,b,d+1);
    }
    if(ice[a][b+1]==1){
        ice[a][b+1]=0;
        rec(ice, a,b+1,d+1);
    }
    if(ice[a][b-1]==1){
        ice[a][b-1]=0;
        rec(ice, a,b-1,d+1);
    }

    rep(i,100){
        rep(j,100){
            ice[i][j]=constice[i][j];
        }
    }

    return 0;

}

void solve(){

    cin >> w >> h;

    rep(i,100){
        rep(j,100){
            ice[i][j]=0;
            constice[i][j]=0;
            dis[i][j]=0;
            v[i][j]=false;
        }
    }
    rep(i,h){
        rep(j,w){
            cin >> ice[i+1][j+1];
            constice[i+1][j+1]=ice[i+1][j+1];
        }
    }

    /*
    ll ans = 0;
    rep(i,h){
        rep(j,w){

            if(ice[i+1][j+1]==0) continue;
            stack<pair<int,int>> st;
            st.push(make_pair(i+1,j+1));
            dis[i+1][j+1]=1;
            ice[i+1][j+1]=0;
            //v[i+1][j+1]=true;
            while(!st.empty()){
                auto p = st.top();
                st.pop();
                int a = p.first;
                int b = p.second;
                ice[a][b]=0;
                if(ice[a+1][b]==1) {
                    dis[a+1][b]=dis[a][b]+1;
                    st.push(make_pair(a+1,b));
                }
                if(ice[a-1][b]==1) {
                    dis[a-1][b]=dis[a][b]+1;
                    st.push(make_pair(a-1,b));
                }
                if(ice[a][b+1]==1) {
                    dis[a][b+1]=dis[a][b]+1;
                    st.push(make_pair(a,b+1));
                }
                if(ice[a][b-1]==1) {
                    dis[a][b-1]=dis[a][b]+1;
                    st.push(make_pair(a,b-1));
                }
            }

            
            rep(n,h){
                rep(m,w){
                    cout << dis[n+1][m+1] << " ";
                }
                cout << endl;
            }
            

            ll tmpans = 0;

            rep(s,h){
                rep(t,w){
                    tmpans = max(ll(tmpans), ll(dis[s+1][t+1]));
                }
            }

            cout << "tmpans: " << tmpans << endl;

            ans = max(ll(ans), ll(tmpans));

            rep(i,100){
                rep(j,100){
                    dis[i][j]=0;
                    //v[i][j]=false;
                    ice[i][j]=constice[i][j];
                }
            }

        }
        
    }
    */

    rep(i,h){
        rep(j,w){
            rec(ice, i+1,j+1,1);
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

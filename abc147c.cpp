#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int n;
bool c[15];
void bit2(int x){
    rep(i,n){
        c[i] = x%2;
        x /= 2;
    }
}

void solve(){

    cin >> n;
    vector<vector<pair<int,int>>> v;
    rep(i,n){
        int tmp;
        vector<pair<int,int>> tmpv;
        cin >> tmp;
        rep(j,tmp){
            int a,b;
            cin >> a >> b;
            tmpv.emplace_back(make_pair(a,b));
        }
        v.emplace_back(tmpv);
    }
    //c[i]が1なら正直、0なら嘘つき

    int ans = 0;
    int m=0;
    bool flag = true;

    rep(i,pow(2,n)){
        bit2(i);
        m=0;
        //全員について全探索
        rep(j,n){
            int siz = v[j].size();
            if(c[j]==true){
                rep(k,siz){
                    if( !(c[v[j][k].first-1]==(v[j][k].second==1?true:false)))  {
                        flag=false;
                        break;
                    }
                    m++;
                }
            }
            else{
                rep(k,siz){
                    if( !(c[v[j][k].first-1]==(v[j][k].second==1?false:true)))  {
                        flag=false;
                    }
                }
            }
        }
        if(flag) ans = max(m,ans);
        flag = true;
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

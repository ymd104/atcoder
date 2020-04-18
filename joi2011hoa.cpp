#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

ll jsum[1010][1010];
//jsum[i][j]:0,0からi-1,j-1までのjungleの数
ll osum[1010][1010];
ll isum[1010][1010];

void solve(){

    ll m,n;
    cin >> m >> n;
    ll k;
    cin >> k;
    rep(i,m){
        jsum[i][0]=0;
        osum[i][0]=0;
        isum[i][0]=0;
    }
    rep(i,n){
        jsum[0][i]=0;
        osum[0][i]=0;
        isum[0][i]=0;
    }

    rep(i,m){
        string st;
        cin >> st;
        rep(j,n){
            if(st[j]=='J') {
                jsum[i+1][j+1]=jsum[i+1][j]+jsum[i][j+1]-jsum[i][j]+1;
                osum[i+1][j+1]=osum[i+1][j]+osum[i][j+1]-osum[i][j];
                isum[i+1][j+1]=isum[i+1][j]+isum[i][j+1]-isum[i][j];
            }
            else if(st[j]=='O') {
                jsum[i+1][j+1]=jsum[i+1][j]+jsum[i][j+1]-jsum[i][j];
                osum[i+1][j+1]=osum[i+1][j]+osum[i][j+1]-osum[i][j]+1;
                isum[i+1][j+1]=isum[i+1][j]+isum[i][j+1]-isum[i][j];
            }
            else{
                jsum[i+1][j+1]=jsum[i+1][j]+jsum[i][j+1]-jsum[i][j];
                osum[i+1][j+1]=osum[i+1][j]+osum[i][j+1]-osum[i][j];
                isum[i+1][j+1]=isum[i+1][j]+isum[i][j+1]-isum[i][j]+1;
            }
        }
    }

    /*
    rep(i,m+1){
        rep(j,n+1){
            cout << jsum[i][j] << " ";
        }
        cout << endl;
    }
    */

    vector<ll> ans;
    vector<ll> ans2;
    vector<ll> ans3;
    rep(i,k){
        int p,q,r,s;
        cin >> p >> q >> r >> s;
        ans.emplace_back(jsum[r][s]-jsum[p-1][s]-jsum[r][q-1]+jsum[p-1][q-1]);
        ans2.emplace_back(osum[r][s]-osum[p-1][s]-osum[r][q-1]+osum[p-1][q-1]);
        ans3.emplace_back(isum[r][s]-isum[p-1][s]-isum[r][q-1]+isum[p-1][q-1]);
    }

    rep(i,k){
        cout << ans[i] << " " << ans2[i] << " " << ans3[i] << endl;
    }

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

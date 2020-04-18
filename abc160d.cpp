#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int d[2010][2010];
int k[2010];

void solve(){

    int n,x,y;
    cin >> n >> x >> y;
    x--;
    y--;
    rep(i,n){
        for(int j=i; j<n; j++){
            d[i][j]=j-i;
            d[j][i]=j-i;
        }
    }

    rep(i,n){
        for(int j=i; j<n; j++){

            if(x>=i){
                d[i][j]=min(d[i][j],d[i][x]+1+d[j][y]);
                d[j][i]=min(d[i][j],d[i][x]+1+d[j][y]);
            }

            else{
                d[i][j]=min(d[i][j], d[x][i]+1+d[j][y]);
                d[j][i]=min(d[i][j], d[x][i]+1+d[j][y]);
            }
        }
    }

    rep(i,2010){
        k[i]=0;
    }
    
    rep(i,n){
        for(int j=i; j<n; j++){
            //cout << d[i][j] << " ";
            k[d[i][j]]++;
        }
        //cout << endl;
    }

    rep(i,n){
        if(i==0) continue;
        cout << k[i] << endl;
    }


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

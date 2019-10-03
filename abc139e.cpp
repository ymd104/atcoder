#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
*/

int a[1010][1010];
int mp[1010][1010];

void solve(){
    ll n;
    cin >> n;

    int i = 0;
    for(int j=0; j<n-1; j++){
        for(int k = j+1; k<n; k++){
            mp[j][k]=i;
            i++;
        }
    }
    
    vector<pair<int,int>> vec;
    vector<int> ve[n*n/2];
    rep(i,n){
        rep(j,n-1){
            int tmp;
            cin >> tmp;
            a[i][j] = tmp-1;
        }
    }
    rep(i,n){
        rep(j,n-2){
            int x,y;
            x = a[i][j];
            y = a[i][j+1];
            int k=i;
            int l=i;
            if(k>x) swap(k,x);
            if(l>y) swap(l,y);
            ve[mp[k][x]].emplace_back(mp[l][y]); 
        }
    }

    n = n*(n-1)/2;
    vector<int> v[n+10];
    rep(i,n){
        for(int j:ve[i]){
            v[j].emplace_back(i);
        }
    }
    //閉路検出

    int sta;
    rep(i,n){
        if(v[i].empty()){
            sta = i;
            break;
        }
    }


    //トポロジカルソート
    vector<int> sorted;
    stack<int> stac;
    rep(i,n){
        if(v[i].empty()){
            sorted.emplace_back(i);
            stac.push(i);
        }
    }
    //入次数を管理する
    int g[n+10];
    rep(i,n){
        g[i] = v[i].size();
        //cout << g[i] << endl;
    }
    while(!stac.empty()){
        int tmp = stac.top();
        //cout << tmp << endl;
        stac.pop();
        for(int i:ve[tmp]){
            //cout << "i:" << i << endl;
            g[i]--;
            if(g[i]==0) {
                sorted.emplace_back(i);
                stac.push(i);
            }

        }
    }

    if(sorted.size()!=n){
        cout << -1 << endl;
        return;
    }

    //最長パスの検出
    //トポロジカルソートしたのでそれを元にDP

    int d[n+10];
    fill(d,d+n+10,0);

    for(int i:sorted){
        for(int j:ve[i]){
            d[j] = max(d[j],d[i]+1);
        }
    }

    int m=0;
    rep(i,n){
        m = max(m,d[i]);
    }
    cout << m+1 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
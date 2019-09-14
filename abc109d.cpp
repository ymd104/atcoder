#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

/*
00 01 02 ... 0w-1 1w-1 1w-2 ...

h=3 w=4
00 01 02 03 13 12 11 10 20 21 22 23 
iからの写像は
i/wが奇数の時  i/w (w-1)-i%w
i/wが偶数の時  i/w i%w
*/


void solve(){
    int h,w;
    cin >> h >> w;
    int a[h+2][w+2];
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    vector<pair<int,int>> v;
    rep(i,h*w){
        if((i/w%2)==1) v.emplace_back(make_pair(i/w, (w-1)-i%w));
        else v.emplace_back(make_pair(i/w, i%w));
    }

    vector<string> ans;

    rep(i,h*w-1){
        int x,y;
        x = v[i].first;
        y = v[i].second;
        if(a[x][y]%2 == 1){
            a[v[i+1].first][v[i+1].second]++;
            ans.emplace_back(to_string(x+1) + " " + to_string(y+1) + " " + to_string(v[i+1].first+1) + " " + to_string(v[i+1].second+1) );
        }
    }

    cout << ans.size() << endl;
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }



}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
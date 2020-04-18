#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

char m[60][60];
int dis[60][60];
bool v[60][60];

void solve(){

    int r,c;
    int sy,sx;
    int gy,gx;
    cin >> r >> c;
    cin >> sy >> sx;
    cin >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    rep(i,r){
        string st;
        cin >> st;
        rep(j,c){
            m[i][j]=st[j];
        }
    }

    rep(i,60){
        rep(j,60){
            dis[i][j]=0;
            v[i][j]=false;
        }
    }

    queue<pair<int,int>> q;
    q.push(make_pair(sy,sx));
    dis[sy][sx]=0;
    v[sy][sx]=true;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        //cout << y << ", " << x << endl;
        v[y][x]=true;
        q.pop();
        if(m[y+1][x]=='.'){
            q.push(make_pair(y+1,x));
            dis[y+1][x]=dis[y][x]+1;
            m[y+1][x]='#';
            //q.pop(make_pair(y+1,x));
        }
        if(m[y-1][x]=='.'){
            q.push(make_pair(y-1,x));
            dis[y-1][x]=dis[y][x]+1;
            m[y-1][x]='#';
            //q.pop(make_pair(y-1,x));
        }
        if(m[y][x+1]=='.'){
            q.push(make_pair(y,x+1));
            dis[y][x+1]=dis[y][x]+1;
            m[y][x+1]='#';
            //q.pop(make_pair(y,x+1));
        }
        if(m[y][x-1]=='.'){
            q.push(make_pair(y,x-1));
            dis[y][x-1]=dis[y][x]+1;
            m[y][x-1]='#';
            //q.pop(make_pair(y,x-1));
        }
    }

    cout << dis[gy][gx] << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

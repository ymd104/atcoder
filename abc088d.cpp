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
bool visit[60][60];

void solve(){

    int h,w;
    cin >> h >> w;
    rep(i,60){
        rep(j,60){
            m[i][j]='#';
            dis[i][j]=0;
            visit[i][j]=false;
        }
    }
    int wallcount=0;
    rep(i,h){
        string st;
        cin >> st;
        rep(j,w){
            if(st[j]=='#') wallcount++;
            m[i+1][j+1]=st[j];
        }
    }

    queue<pair<int,int>> q;
    q.push(make_pair(1,1));
    visit[1][1]=true;
    int a=0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        //cout << x << " " << y << endl;
        q.pop();
        if(x==h&&y==w){
            a=dis[x][y];
            break;
        }
        if(!visit[x+1][y]&&m[x+1][y]=='.'){
            visit[x+1][y]=true;
            dis[x+1][y]=dis[x][y]+1;
            q.push(make_pair(x+1,y));
        }
        if(!visit[x-1][y]&&m[x-1][y]=='.'){
            visit[x-1][y]=true;
            dis[x-1][y]=dis[x][y]+1;
            q.push(make_pair(x-1,y));
        }
        if(!visit[x][y+1]&&m[x][y+1]=='.'){
            visit[x][y+1]=true;
            dis[x][y+1]=dis[x][y]+1;
            q.push(make_pair(x,y+1));
        }
        if(!visit[x][y-1]&&m[x][y-1]=='.'){
            visit[x][y-1]=true;
            dis[x][y-1]=dis[x][y]+1;
            q.push(make_pair(x,y-1));
        }
    }

    //cout << a << endl;

    if(a!=0) cout << h*w-a-wallcount-1 << endl;
    else cout << -1 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

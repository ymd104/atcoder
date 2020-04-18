#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long double ld;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int m[1010][1010];
bool visit[1010][1010];
int dis[1010][1010];

void solve(){

    int h,w,n;
    cin >> h >> w >> n;
    int s,t;
    rep(i,1010){
        rep(j,1010){
            m[i][j]=-1;
        }
    }
    rep(i,h){
        string st;
        cin >> st;
        rep(j,w){
            if(st[j]=='S') {
                m[i+1][j+1]=10;
                s=i+1;
                t=j+1;
            }
            else if(st[j]=='.') m[i+1][j+1]=0;
            else if(st[j]=='X') m[i+1][j+1]=-1;
            else m[i+1][j+1] = (st[j] - '0');
        }
    }

    /*
    rep(i,h+2){
        rep(j,w+2){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    */

    rep(i,1010){
        rep(j,1010){
            visit[i][j]=false;
            dis[i][j]=0;
        }
    }

    int sx = s;
    int sy = t;
    int a=0;
    //cout << s << " " << t << endl;
    rep(i,n){
        int ans;
        queue <pair<int,int>> q;
        q.push(make_pair(sx,sy));
        visit[sx][sy]=true;
        //cout << "sx: " << sx << ", sy: " << sy << ", dis: " << dis[sx][sy] << endl; 
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(m[x][y]==i+1){
                ans = dis[x][y];
                sx=x;
                sy=y;
                //cout << "sx: " << sx << ", sy: " << sy << ", dis: " << dis[x][y] << endl; 
                break;
            }
            if(m[x+1][y]!=-1&&visit[x+1][y]==false){
                visit[x+1][y]=true;
                q.push(make_pair(x+1,y));
                dis[x+1][y]=dis[x][y]+1;
                //cout << x+1 << " " << y << endl;
            }
            if(m[x-1][y]!=-1&&visit[x-1][y]==false){
                visit[x-1][y]=true;
                q.push(make_pair(x-1,y));
                dis[x-1][y]=dis[x][y]+1;
                //cout << x-1 << " " << y << endl;
            }
            if(m[x][y+1]!=-1&&visit[x][y+1]==false){
                visit[x][y+1]=true;
                q.push(make_pair(x,y+1));
                dis[x][y+1]=dis[x][y]+1;
                //cout << x << " " << y+1 << endl;
            }
            if(m[x][y-1]!=-1&&visit[x][y-1]==false){
                visit[x][y-1]=true;
                q.push(make_pair(x,y-1));
                dis[x][y-1]=dis[x][y]+1;
                //cout << x << " " << y-1 << endl;
            }
        }
        a += ans;
        rep(i,1010){
            rep(j,1010){
                visit[i][j]=false;
                dis[i][j]=0;
            }
        }
        //cout << i+1 << endl;
    }

    cout << a << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

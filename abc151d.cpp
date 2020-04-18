#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

char maze[25][25];

void solve(){
    int h,w;
    cin >> h >> w;
    rep(i,w+2){
        maze[0][i]='#';
    }
    rep(i,w+2){
        maze[h+1][i]='#';
    }
    rep(i,h+2){
        maze[i][0]='#';
    }
    rep(i,h+2){
        maze[i][w+1]='#';
    }

    rep(i,h){
        rep(j,w){
            cin >> maze[i+1][j+1];
        }
    }

    rep(i,h+2){
        rep(j,w+2){
            //cout << maze[i][j];
        }
        //cout << endl;
    }

    int score=0;
    rep(i,h+2){
        rep(j,w+2){
            
            if(maze[i][j]=='.'){

                queue<pair<int,int>> q;
                int dis[22][22];
                rep(p,22){
                    rep(q,22){
                        dis[p][q]=-1;
                    }
                }
                bool visit[22][22];
                rep(p,22){
                    rep(q,22){
                        visit[p][q]=false;
                    }
                }
                visit[i][j]=true;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    auto p = q.front();
                    q.pop();
                    auto x = p.first;
                    auto y = p.second;
                    if(maze[x+1][y]=='.' && visit[x+1][y]==false){
                        dis[x+1][y]=dis[x][y]+1;
                        q.push(make_pair(x+1,y));
                        visit[x+1][y]=true;
                    }
                    if(maze[x-1][y]=='.' && visit[x-1][y]==false){
                        dis[x-1][y]=dis[x][y]+1;
                        q.push(make_pair(x-1,y));
                        visit[x-1][y]=true;
                    }
                    if(maze[x][y+1]=='.' && visit[x][y+1]==false){
                        dis[x][y+1]=dis[x][y]+1;
                        q.push(make_pair(x,y+1));
                        visit[x][y+1]=true;
                    }
                    if(maze[x][y-1]=='.' && visit[x][y-1]==false){
                        dis[x][y-1]=dis[x][y]+1;
                        q.push(make_pair(x,y-1));
                        visit[x][y-1]=true;
                    }
                }
                rep(i,h+2){
                    rep(j,w+2){
                        score=max(score,dis[i][j]);
                    }
                }

            }
        }
    }

    cout << score+1 << endl;
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

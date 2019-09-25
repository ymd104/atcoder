#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
要するに迷路を解けという問題
左上から順に、min(上,左,下,右)をその位置での最短距離とする
#のスコアは-1
ただし、いずれも-1であるなら、その位置でのスコアは-1
これをh*w回繰り返す。(今回は制約的に間に合う)
*/

void solve(){
    int h,w;
    cin >> h >> w;
    char c[h+10][w+10];
    rep(i,h+2){
        rep(j,w+2){
            c[i][j]='#';
        }
    }
    int count=0;
    rep(i,h){
        string tmp;
        cin >> tmp;
        rep(j,w){
            if(tmp[j]=='#') count++;
            c[i+1][j+1] = tmp[j];
        }
    }
    //cout << count << endl;

    int score[h+10][w+10];
    rep(i,h+2){
        rep(j,w+2){
            score[i][j]=INF;
            //cout << c[i][j];
        }
        //cout << endl;
    }
    score[1][1]=0;
    rep(k, h*w){
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(c[i][j]=='#'){
                score[i][j]=INF;
            }
            else{
                //cout << score[i][j-1] << " " << score[i][j+1] << " " << score[i-1][j] << " " << score[i+1][j] << endl;
                score[i][j]=min((min(min(score[i][j-1], score[i][j+1]),min(score[i-1][j], score[i+1][j]))+1), score[i][j]);
                //cout << "score[" << i << "][" << j << "]:" << score[i][j] << endl;
            }
        }
    }
    }

    if(score[h][w]==INF) cout << -1 << endl;
    else{
        cout << h*w - count - score[h][w] -1 << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


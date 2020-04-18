#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
p????q
q??p
という組
1~9について、先頭がi,末尾がjである数字の個数をc[i][j]で表す

i!=jの場合、計上する場合の数は？
例：i=1, j=2
12, 102, 112, 21, 201, 211
単純な掛け算.

i==jのときは？
同じ数どうしを重複して数え上げるため、単純な掛け算という訳には行かない
例：1,11,101,111,121
このときの場合の数は5C2

*/

int first(int x){
    return (to_string(x).front()) - '0';
}
int last(int x){
    return (to_string(x).back()) - '0';
}

int c[12][12];

void solve(){
    int n;
    cin >> n;
    rep(i,12){
        rep(j,12){
            c[i][j]=0;
        }
    }

    for(int i=1; i<=n; i++){
        c[first(i)][last(i)]++;
    }

    ll ans = 0;

    rep(i,10){
        rep(j,10){
            if(i!=j){
                ans += c[i][j]*c[j][i];
                //cout << "先頭が" << i << ", 末尾が" << j << ", 足す数は" << c[i][j]*c[j][i] << endl;
            }
            else{
                ans += c[i][j]*(c[i][j]-1)+c[i][j];
                //cout << "先頭が" << i << ", 末尾が" << j << ", 足す数は" << c[i][j]*(c[i][j]-1)/2+c[i][j] << endl;
            }
        }
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

/*
部分文字列として、
ACG CAG A?GC AG?C
012 102 0?21 02?1
のいずれも含まないもの
dp[a][b][c][d]:
文字数がa文字で、最後から3文字目がb、2文字目がc、1文字目がd
a=0
c=1
g=2
t=3

dp[a][b][c][d] = 
if(b==0&&c==1) 
*/

ll dp[105][5][5][5];

void solve(){
    int n;
    cin >> n;
    dp[a][b][c][d] = 
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
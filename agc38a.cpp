#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;


/*
3,3,1,0?
111
111
000

4,4,2,1?

1110
1110
0001
0001

6,6,3,2?

111000
111000
111000
111000
000111
000111

すなわち、
・最初のw-a個は１、それ以外は０
・これをh-b行繰り返す



*/

void solve(){
  int h,w,a,b;
  cin >> h >> w >> a >> b;
  string tmp="";
  rep(i,w-a){
    tmp = tmp + '1';
  }
  rep(i,a){
    tmp = tmp + '0';
  }
  string tmp2 = "";
  rep(i,w-a){
    tmp2 = tmp2 + '0';
  }
  rep(i,a){
    tmp2 = tmp2 + '1';
  }
  rep(i,h-b){
    cout << tmp << endl;
  }
  rep(i,b){
    cout << tmp2 << endl;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

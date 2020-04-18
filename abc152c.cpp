#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
iについて、iより小さい全ての整数jに対して、p[i]がp[j]以下

4 2 5 1 3
i=1は自明
i=2 p[2]=2, p[1]=4
i=3 p[3]=5, p[2]=2 ...

つまり、左側の数列のどの数よりも小さければ良い
線形オーダで実装するために、各数列の最小値を左から順に格納していく
*/

int p[200010];
int m[200010];

void solve(){
    int n;
    cin >> n;
    rep(i,n){
        cin >> p[i];
    }
    int mi = p[0];
    rep(i,n){
        mi=min(mi,p[i]);
        m[i]=mi;
    }
    int count = 0;
    rep(i,n){
        if(m[i]==p[i]) count++;
    }

    
    cout << count << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

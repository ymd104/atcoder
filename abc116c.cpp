#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

/*
全ての高さが0になるまで、以下を繰り返す。
・数列hについて、h[i]が1以上であるような区間の数をcountとする
・h[i]--し、全値が0になるまでこれを繰り返す

122121 countは0
-> 011010
-> 
*/


void solve(){
    int n;
    cin >> n;
    int h[n+10];
    rep(i,n){
        cin >> h[i];
    }
    int count = 0;
    int ans = 0;
    int check = 1;
    
    while(check>0){
        check = 0;
        // 0 1 0 0 1 2 0 ...のような数列の正の部分の数
        if(h[0]!=0) count = 1;
        else count = 0;
        for(int i=1; i<n; i++){
            if(h[i-1]==0&&h[i]>0){
                count++;
            }
        }
        ans += count;
        //count = 0;
        rep(i,n){
            if(h[i]>=1) h[i] = h[i]-1;
        }
        rep(i,n){
            check += h[i];
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
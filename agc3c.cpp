#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


/*
操作1は連続する2整数を、操作2はひとつ飛ばしの2整数を逆順にする
本来の位置とずれている距離が奇数なら1を足す

51234
21435

*/

void solve(){
    int n;
    cin >> n;
    int a[n+10];
    int b[n+10];
    rep(i,n){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    unordered_map<int,int> um;
    //各値が何番目に小さい値かを保持する
    rep(i,n){
        um.emplace(b[i],i);
    }
    int dist = 0;
    rep(i,n){
        //cout << "a[i]:" << a[i] << " um[a[i]]:" << um[a[i]] << " i:" << i << endl;
        dist += (abs(um[a[i]] - i)%2);
    }
    //cout << dist << endl;

    /*
    sort(a,a+n, greater<int>());
    unordered_map<int,int> um2;
    //各値が何番目に小さい値かを保持する
    rep(i,n){
        um2.emplace(b[i],i);
    }
    int dist2 = 0;
    rep(i,n){
        dist2 += (abs(um2[a[i]] - i)%2);
    }
    

    cout << min(dist,dist2)/2 << endl;
    */
    cout << dist/2 << endl;


}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


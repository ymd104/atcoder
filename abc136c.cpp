#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long i=0; i<n; i++)

//あるi,jについて、i>jでHi>Hjかつその差が2以上であるようなi,jの組が存在すれば単調非現象にできない
//頭から、区間における最大値を計算する。
//後ろから順に見ていく。区間の最大値と比較し、2以上小さかったら達成できないことがわかる。
// h1, h2, ..., hi-1の最大値と、hiを比較する

void solve(){
    int n;
    cin >> n;
    int h[n+10];
    rep(i,n){
        cin >> h[i];
    }

    //区間最大値を計算する
    int maximum[n+10];
    maximum[0]=h[0];
    for(int i=1; i<n; i++){
        maximum[i]=max(maximum[i-1], h[i]);
    }
    string s = "Yes";
    for(int i=1; i<n; i++){
        if(maximum[i-1] - h[i] >= 2){
            s = "No";
            break;
        }
    }
    cout << s << endl;
}

int main(){
  solve();
  return 0;
}

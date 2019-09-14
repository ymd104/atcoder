#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;



void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    /*
    目の前の人が自分と同じ方向を向いている数
    例えば
    LLLRRLLLLRRRRL
    の時、
    2+1+3+3+0.
    結局、同じ記号の長さ-1の総和が幸福度。
    奇数回だけ回転させることは1回回転させることと同じである
    [3,2,4,4,1]のようなリストを作り、
    「３つの要素を選んで合併する」という操作をk回行える
    どこを回転させても幸福の人数は同じ。上の例だと、5パートにわかれていて、
    N=１４
    幸福の人数＝１４−５＝９
    つまり、何パートに分かれているかを計算し、
    それから2*kを引けばいい
    */
    int pointer = 0;
    int count = 1;
    char c = s[0];
    while(pointer < n){
        if(c != s[pointer]){
            count++;
            c = s[pointer];
        }
        pointer++;
    }
    //cout << count << endl;
    cout << min(n-1, n-(count-2*k)) << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
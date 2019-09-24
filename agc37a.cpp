#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


/*
aababab
頭から順に見ていく
一致すれば
*/


void solve(){
    string s;
    cin >> s;
    int siz = s.size();
    int pointer = 0; //pointerは次の文字の先頭を指す. siz-1までの値をとる
    int count=0;
    string tmp=""; //前の文字列が代入される

    while(pointer<siz){
        char c = s[pointer];
        string ch{c};
        //cout << "ch:" << ch << " tmp:" << tmp << endl;
        if(tmp.size()==2) {
            pointer++;
            count++;
            tmp = ch;
            //cout << "前に2つに分割したので、次は必ず1文字" << endl;
            //cout << 1 << endl;
        }
        else if(tmp==ch){
            pointer += 2;
            count++;
            tmp = ch + s[pointer-1];
            //cout << "前の部分文字列が1文字で、かつ次の文字列と被っているので、次の文字列は2文字" << endl;
            //cout << 2 << endl;
        }
        else{
            pointer++;
            count++;
            tmp = ch;
            //cout << "前の部分文字列が1文字だが、次の文字とは異なるので、次の文字列は1文字" << endl;
            //cout << 3 << endl;
         }
         //cout << pointer << endl;
    }

    if(pointer>siz) cout << count-1 << endl;
    else cout << count << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

/*

*** C++における順序つき集合set ***

順序づけされたデータを木によって保持するデータ構造。
以下の3つのメソッドをサポートしている
・木にデータを追加。logN
・木からデータを削除。logN
・木へのアクセス。logN
通常のvectorにおいて、二分探索などを用いれば検索はlogNで済む。
しかし動的追加にNかかるので、データの追加や削除が多い場合はsetを用いると良い。

問題に戻る。
1~Nの順列があり、全区間[L,R]における2番目に大きい数字X(L,R)の和はいくらか？
この総和は、Pi=X(L,R)となるような区間[L,R]の個数Ciの総和である。(それはそう)
このCiを求める。
P1, P2, ..., Pi, ..., Pn
さて、集合Si=「j<i, Pi<Pjなるjの集合」
集合Ti=「i<j, Pi<Pjなるjの集合」とする。
例えば順列 2 4 1 5 3について、
P1=2 P2=4 P3=1 P4=5 P5=3
S1={} T1={2,4,5}
S2={} T2={4}
S3={1,2} T3={4,5}
S4={} T4={}
S5={2,4} T5={}
この時、Siの最大値をxi, 2番目の要素をwi
Tiの最小値をyi, 2番目に小さい要素をziとする
定義から、wi < xi < i < yi < zi
Pi=X(L,R)となるのはどういう場合か？

wi < L <= xi < i < R <= yi < zi
wi < xi <= L < i < yi <= R < zi
の時に限られる。
例えば
1 2 3 4 5 6 
について、i=3は
S={} T={4,5,6}
P3が2番目に大きい要素になるのは、
0 < L <= 0 < 3 < R <= 4 < 5

2 7 5 1 3 4 6
について、i=4は
S={2,3} T={6,7}
P4が2番目に大きい要素になるのは、
・Lが7より右で５より左、かつ4より左
・Lが5より右で、4より右かつ6より左
のいずれか。
よって、Ciは
(xi-wi)*(yi-i)+(i-xi)*(zi-yi)
で表される。

7,2
6,7
5,3
4,6
3,5
2,1
1,4

*/

void solve(){
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

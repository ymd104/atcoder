#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


/*
a+b=kx
b+c=ky
c+a=kz
より、
a=k(x-y+z)/2
b=k(x+y-z)/2
c=k(-x+y+z)/2
a,b,cはいずれもk/2の倍数。k/2の倍数ならなんでもいいという訳ではなく、
全ての数の偶奇が一致していなければならない

kが奇数の時、a,b,cが全てkの倍数。この時xyzは存在する
kが偶数の時、a,b,cが全てkの倍数であるか、kの倍数でないのなら全てkl+k/2である必要がある
それらの個数をp,qとすると、
奇数なら
3つかぶる->p
2つかぶる->p*(p-1)*3
かぶらない->p*(p-1)*(p-2)
偶数なら、これに加えてqで同じものを加算する必要がある

*/

ll cal(ll p){
    return p+p*(p-1)*3+p*(p-1)*(p-2);
}

void solve(){
    ll n,k;
    cin >> n >> k;
    ll p=n/k;
    ll q;
    if(k!=1) q=((n/(k/2))+1)/2;
    if(k%2==1){
        cout << cal(p) << endl;
    }
    else {
        cout << cal(p)+cal(q) << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

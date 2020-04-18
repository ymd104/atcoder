#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[10000];
int sorted[10000];

void solve(){

    int n;
    cin >> n;
    fill(a,a+10000, -INF);
    rep(i,n){
        cin >> a[i];
    }

    //ヒープ化
    //a[n-1]から順に
    for(int i=n-1; i>=0; i--){
        int par = (i-1)/2;
        while( a[par]<a[2*par+1] || a[par]<a[2*par+2] ){
            if(a[2*par+1]>a[2*par+2]) {
                swap(a[par],a[2*par+1]);
                par = 2*par+1;
            }
            else {
                swap(a[par],a[2*par+2]);
                par = 2*par+2;
            }     
        }
    }
    //おそらくnlogn.

    //根の要素とヒープの最後尾を交換する.
    //交換後、根の値をswapしていく.

    for(int i=n-1; i>=0; i--){
        swap(a[0],a[i]);
        sorted[n-1-i]=a[i];
        a[i]=-INF;

        int root=0;
        //i：ヒープの要素数.
        while(a[root]<a[2*root+1] || a[root]<a[2*root+2]){
            if(a[2*root+1]>a[2*root+2]) {
                swap(a[root],a[2*root+1]);
                root = 2*root+1;
            }
            else {
                swap(a[root],a[2*root+2]);
                root = 2*root+2;
            }   
        }
    }
    //各要素について最悪logn必要だからnlogn.

    rep(i,n){
        cout << sorted[i] << " " << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

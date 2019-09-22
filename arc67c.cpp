#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
xの約数の個数：
xを素因数分解し、xの素因数のべきそれぞれに1を足したものの積

n/2以下の素数のリストを作り、各i(i>=2)について
・iの素因数の数だけリストの値を更新
素因数分解は、小さい方の素数から割っていき、1になったら終了
*/

bool is_prime[1010];
vector<int> p;
void era( const int N ){
    for( int i = 0; i <= N; i++ ) is_prime[ i ] = true;//初期化  
    for( int i = 2; i <= N; i++ ){
        if( is_prime[ i ] ){
            for( int j = 2 * i; j <= N; j += i ){
                is_prime[ j ] = false;
            }
            p.emplace_back( i );
        }
    }
}

void solve(){
    int n;
    cin >> n;
    era(n);
    //cout << p[0] << p[1] << endl;
    int siz = p.size();
    //cout << p.size() << endl;
    int a[siz];//n!の素因数になりうる素数の数を表現するリスト
    rep(i,siz){
        a[i]=0;
    }
    for(int i=2; i<=n; i++){
        int x=i;
        int j=0;
        while(x!=1){
            if(x%p[j]==0){
                x = x/p[j];
                a[j]++;
            }
            else{
                j++;
            }
        }
    }
    ll count = 1;
    rep(i,siz){
        count = count*(1+a[i]);
        count = count % MOD;
    }
    cout << count << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

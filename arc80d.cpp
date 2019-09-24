#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a,b;
pair<int,int> func(int x){
    //xをグリッドへと写像する
    /*
    0  1  2  3  4  ...  b-1
    2*b-1 ...      b+1  b

    xをbで割った商が偶数の時、(x/b, x%b)
    奇数の時、(x/b, (b-1)-x%b)
    */
    if((x/b)%2==0) return make_pair(x/b,x%b);
    else return make_pair(x/b, (b-1)-x%b);
}

void solve(){
    int h,w;
    cin >> h >> w;
    a=h;
    b=w;
    int n;
    cin >> n;
    int a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    vector<int> p;
    rep(i,n){
        rep(j,a[i]){
            p.emplace_back(i);
        }
    }
    int c[h][w];
    rep(i,p.size()){
        int x,y;
        x=func(i).first;
        y=func(i).second;
        c[x][y]=p[i];
    }
    rep(i,h){
        rep(j,w){
            cout << c[i][j]+1 << " ";
        }
        cout << endl;
    }

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

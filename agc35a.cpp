#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
xorの性質
・交換・結合法則が成り立つ
・単位元は0
・逆元は自分自身
・要するに、任意のaでa^a=0

左右x,zについて、x^z=yであるから、これはx^y^z=0と同値
4つの連続する数a,b,c,dについて、
a^b^c=b^c^d
a=b^c^d^c^b
 =b^b^c^c^d
 =d
よって、a[i]が３つの同じ数で構成されていればいい
例えばn=4の時、
a b c d
a=d、b=a、c=bよりa=b=c=d
nが3の倍数でないのなら、全部同じ数
かつ、a^a=0だから全部0
3の倍数の時、
・全部0
・2種類の数があり、そのうち１つがもう１つのちょうど2倍の数存在する
・3種類の数があり、全部同数
2つめの場合について、a a b a a b...なので、b=0

110
010
100
*/

void solve(){
    int n;
    cin >> n;
    int a[n+10];
    bool judgeall0 = true;
    bool double2 = true;
    bool triplesame = true;
    rep(i,n){
        cin >> a[i];
        if(a[i]!=0) judgeall0 = false;
    }
    sort(a,a+n);
    int p,q,r;
    p=a[0];
    q=a[n/3];
    r=a[n-1];
    int nump=0;
    int numq=0;
    int numr=0;
    rep(i,n){
        bool flag = false;
        if(a[i]==p) {
            nump++;
            flag=true;
        }
        if(a[i]==q) {
            numq++;
            flag=true;
        }
        if(a[i]==r) {
            numr++;
            flag=true;
        }
        if(!flag) {
            double2=false;
            triplesame=false;
            //cout << "!" << endl;
        }
        //cout << "a[i]" << a[i] << endl;
    }
    //cout << p << r << nump << numr << endl;
    if(nump!=numq || numq!=numr) triplesame=false;
    if(nump==numq&&numq==numr){
        if(p==q) triplesame=false;
        if(q==r) triplesame=false;
        if(p==r) triplesame=false;
        int x,y,z;
        x=p^q;
        y=q^r;
        z=r^p;
        if(x!=r&&y!=p&&z!=q) triplesame=false;
    }
    if(nump*2!=numr) double2=false;
    if(nump*2==numr&&p!=0) double2=false;
    if(nump*2==numr&&p==r) double2=false;

    if(n%3!=0) {
        if(!judgeall0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    else{
        if(judgeall0 || triplesame || double2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

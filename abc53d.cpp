#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

/*
3枚のカードは1枚に
2枚のカードはどれか1枚を犠牲にして1枚に
すなわち、
・3枚以上あるものは、そこから2を引く
・2枚のもののペアがあれば、1枚ずつ減らせる
・2枚のものが１つだけ残れば、1種類のカードを犠牲に
*/

void solve(){
    int n;
    cin >> n;
    int a[n+10];
    rep(i,n){
        cin >> a[i];
    }
    sort(a,a+n);
    int point = a[0];
    int count=1;
    vector<int> v;
    for(int i=1; i<n; i++){
        if(point!=a[i]){
            point = a[i];
            v.emplace_back(count);
            count=1;
        }
        else{
            count++;
        }
    }
    v.emplace_back(count);
    //cout << v[0] <<" "<< v[1]<<" " << v[2]<<" " << v[3] << endl;
    rep(i,v.size()){
        if(v[i]>=3){
            //偶数で2, 奇数で1
            v[i]=(v[i]+1)%2+1;
        }
    }
    int num2=0;
    rep(i,v.size()){
        if(v[i]==2) num2++;
    }
    cout << v.size()-num2%2 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}


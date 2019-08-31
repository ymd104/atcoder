#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
ll mod = 1000000007;

/*
操作 A: Dに詰められた宝石のうち、左端の宝石を取り出して手に入れる。
操作 B: Dに詰められた宝石のうち、右端の宝石を取り出して手に入れる。
操作 C: 持っている宝石を1つ選んでDの左端に詰める。
操作 D: 持っている宝石を1つ選んでDの右端に詰める。

操作AをA回、操作BをB回行うとする。捨てる操作はK-(A+B)回行える。
A,Bが決まると最適な捨てる回数は一意に定まる。
A+B<=min(N,K)=Rであるから、
・A+BがR通り
・AはさらにR通り
・それらをソートして最適解を導出するのにRlogR
R^3logRは間に合う。
*/

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> v;
    rep(i,n){
        int tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }
    int r=min(n,k);
    int ans = 0;
    for(int i=1; i<=r; i++){
        for(int a=0; a<=i; a++){
            int b=i-a;
            priority_queue<int, vector<int>, greater<int>> get;
            rep(left,a){
                get.push(v[left]);
            }
            rep(right,b){
                get.push(v[n-1-right]);
            }
            //cout << "a:" << a << ", b:" << b;
            
            //sort(get.begin(),get.end());
            int sum = 0;
            /*
            rep(t,get.size()){
                sum+=get.top();
                cout << " " << get.top();
                get.pop();
            }
            */
            /*
            rep(t,get.size()){
                sum+=get[t];
                cout << " " << get[t];
            }
            */
            for(int x=0; x<k-a-b; x++){
                if(get.size()==0 || get.top()>=0 ) {
                    //cout << " Yeah "; 
                    break;
                }
                //cout << " top:" << get.top();
                get.pop();
            }

            int siz = get.size();
            rep(t,siz){
                //cout << "+++t+++ " << t << " +++size+++ " << get.size() << " +++top+++ " << get.top();
                sum+=get.top();
                //cout <<  " " << get.top();
                get.pop();
            }

            //cout << ", sum:" << sum << endl;
            ans = max(sum, ans);
        }
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;
ll INF = 1000000009;

struct problems{
    int point;
    int number;
    int bonus;
};

int a[11];

void base2(int x, int d){
    rep(i,d){
        a[i] = x%2;
        x = x/2;
    }
}

void solve(){
    int d,g;
    cin >> d >> g;
    vector<problems> v;
    rep(i,d){
        struct problems p;
        p.point = (i+1)*100;
        cin >> p.number >> p.bonus;
        v.emplace_back(p);
    }

    /*
    制約が弱い。問題の難易度は100~1000, 問題数はそれぞれ100問以下。
    各問題を、「全部解く」「全部解かない」により場合分けし、残りの点数を大きいものから順に取っていく
    */

    int ans = INF;
    int i = 0;
    //base2(7,4);
    //cout << a[0] << " " << a[1] << " " << a[2] << endl;
    rep(i,pow(2,d)){
        int sum=0;
        int maxproblem=0;
        int numberofproblem = 0;
        base2(i, d);
        rep(j,d){
            if(a[j]==1) {
                sum += (v[j].point)*(v[j].number) + v[j].bonus;
                numberofproblem += v[j].number;
            }
            else maxproblem=j;
        }
        //cout << "i:" << i << ", maxproblem" << maxproblem << endl;
        int rest;
        rest = g - sum;
        if(rest>0){
        if(rest<=(v[maxproblem].point)*(v[maxproblem].number-1)) {
            int tmp = rest / v[maxproblem].point;
            if(rest%v[maxproblem].point==0){
                numberofproblem += tmp;
            }
            else{
                numberofproblem += tmp + 1;
            }
        }
        else{
            numberofproblem = INF;
        }
        }
        //cout << numberofproblem << endl;
        ans = min(ans, numberofproblem);
    }
    cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

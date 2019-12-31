#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

/*
123
132
213
231
312
321

12:4
13:4
23:4

全部のパターン：n!*(n-1)
これをnC2=n*(n-1)/2で割って、(n-1)!*2
n!で割って、2/n

*/

int fact(int n){
    if(n==1) return 1;
    else{
        return n*fact(n-1);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> town;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        town.push_back(make_pair(x,y));
    }



    long double sum = 0;

    rep(i,n){
        rep(j,n){
            if(i<j){
                long double p=town[i].first;
                long double q=town[i].second;
                long double r=town[j].first;
                long double s=town[j].second;
                sum += sqrt((p-r)*(p-r) + (q-s)*(q-s)) * 2 / n;
            }
        }
    }


    cout << setprecision(10) << sum << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

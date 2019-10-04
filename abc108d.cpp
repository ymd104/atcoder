#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

//t以下で最小の2^x-1となるxを返す
int notover2(int t){
    double tt = (double) t+1;
    return floor(log2(tt));
}
//t以下で最小の2^xとなるxを返す
int notover(int t){
    double tt = (double) t;
    return floor(log2(tt));
}
//t以下で最小の2^x-1となる2^x-1を返す
int no2(int t){
    double tt = (double) t+1;
    return pow(2,floor(log2(tt)))-1;
}
//t以下で最小の2^xとなる2^xを返す
int no(int t){
    double tt = (double) t;
    return pow(2,floor(log2(tt)));
}

struct edge{
    int a;
    int b;
    int c;
};

void solve(){
    int l;
    cin >> l;

    int x;
    x = notover(l);
    int n=x+1;
    vector<edge> v;
    int numedge=0;
    
    for(int i=1; i<n; i++){
        //cout << i << " " << i+1 << " " << pow(2,n-i-1) << endl;
        int tm = pow(2,n-i-1);
        v.emplace_back(edge{i,i+1,tm});
        //cout << i << " " << i+1 << " " << 0 << endl;
        v.emplace_back(edge{i,i+1,0});
        numedge += 2;
    }
    int tmp = l - pow(2,n-1);
    int i=0;
    int pointer = pow(2,n-1);
    while(tmp>0){
        int y = tmp%2;
        if(y==1){
            int p = pow(2,n-1);
            int d = pow(2,i);
            v.emplace_back(edge{1,n-i,pointer});
            pointer += d;
            numedge++;
        }
        tmp /= 2;
        i++;
    }

    cout << n << " " << numedge << endl;
    for(auto i:v){
        cout << i.a << " " << i.b << " " << i.c << endl;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

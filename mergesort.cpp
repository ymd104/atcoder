#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[1000010];
int sorted[1000010];

vector<int> merge(vector<int>& a, vector<int>& b){
    vector<int> v;
    int pa=0;
    int pb=0;
    while(pa<a.size()||pb<b.size()){
        if(pa==a.size()) {
            v.emplace_back(b[pb]);
            pb++;
        }
        else if(pb==b.size()) {
            v.emplace_back(a[pa]);
            pa++;
        }
        else{
            if(a[pa]<b[pb]){
                v.emplace_back(a[pa]);
                pa++;
            }
            else{
                v.emplace_back(b[pb]);
                pb++;
            }
        }
    }
    return v;
}

void solve(){

    int n;
    cin >> n;
    random_device rnd;
    rep(i,n){
        a[i] = rnd()%10 ;
    }

    queue<vector<int>> q;
    rep(i,n){
        vector<int> vec;
        vec.emplace_back(a[i]);
        q.push(vec);
    }

    clock_t st = clock();

    while(q.size()>1){
        auto a = q.front();
        q.pop();
        auto b = q.front();
        q.pop();
        q.push(merge(a,b));
    }

    clock_t end = clock();

    auto sorted = q.front();
    rep(i,n){
        //cout << sorted[i] << " ";
    }
    cout << endl;

    //scout << (double)(end-st) << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

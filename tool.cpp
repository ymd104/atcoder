#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1e9+1;

mt19937 create_rand_engine(){
    random_device rnd;
    vector<std::uint_least32_t> v(10);// 初期化用ベクタ
    generate(v.begin(), v.end(), std::ref(rnd));// ベクタの初期化
    seed_seq seed(v.begin(), v.end());
    return std::mt19937(seed);// 乱数エンジン
}

vector<int> make_rand_array_select(const size_t size, int rand_min, int rand_max){
    if(rand_min > rand_max) swap(rand_min, rand_max);
    const size_t max_min_diff = static_cast<size_t>(rand_max - rand_min + 1);
    if(max_min_diff < size) throw runtime_error("引数が異常です");

    vector<int> tmp;
    tmp.reserve(max_min_diff);

    for(int i = rand_min; i <= rand_max; ++i)tmp.push_back(i);

    auto engine = create_rand_engine();
    uniform_int_distribution<int> distribution(rand_min, rand_max);

    for(size_t cnt = 0; cnt < size; ++cnt){
        size_t pos =uniform_int_distribution<size_t>(cnt, tmp.size()-1)(engine);

        if(cnt != pos) std::swap(tmp[cnt], tmp[pos]);
    }
    tmp.erase(std::next(tmp.begin(), size), tmp.end());

    return std::move(tmp);
}

/*
28ペア乱拓して、条件に合っていれば出力
*/

const int n = 14;
const int num = 28;
//試合数

vector<int> v[num];
int m=0;
int per[n+1];
void solve(){

    while(true){
        m=0;
    bool b =true;
    rep(i,num){
        v[i]=make_rand_array_select(4,1,14);
    }
    
    rep(i,num){
        cout << "{" << v[i][0] << " " << v[i][1] << " " << v[i][2] << " " <<  v[i][3] << "} ";
    }
    
    cout << endl;
    int match[n+1][n+1];
    rep(i,n+1){
        rep(j,n+1){
            match[i][j]=0;
        }
    }
    rep(i,num){
        auto tmp = v[i];
        sort(tmp.begin(),tmp.end());
        int a,b,c,d;
        a=tmp[0];
        b=tmp[1];
        c=tmp[2];
        d=tmp[3];
        match[a][b]++;
        match[a][c]++;
        match[a][d]++;
        match[b][c]++;
        match[b][d]++;
        match[c][d]++;
    }
    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            m = max(m,match[i][j]);
            
            if(match[i][j]<=0) {
                b=false;
                continue;
            }
            
            if(match[i][j]>5) {
                b=false;
                continue;
            }
        }
    }


    fill(per,per+n+1,0);
    rep(i,num){
        per[v[i][0]]++;
        per[v[i][1]]++;
        per[v[i][2]]++;
        per[v[i][3]]++;
    }
    rep(i,n){
        if(per[i+1]<=5){
            b=false;
            continue;
        }
        if(per[i+1]>=10){
            b=false;
            continue;
        }
    }

    if(b) break;
    }

    rep(i,num){
        cout << "{" << v[i][0] << " " << v[i][1] << " " << v[i][2] << " " << v[i][3] << "}" << endl;
    }
    
    for(int i=1; i<=n; i++){
        cout << per[i] << " ";
    }
    cout << endl;
    cout << m << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

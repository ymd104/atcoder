#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;


class UnionFind{
    vector<int> par;
    int all = 0;
    vector<int> siz;
    int treenum;

    public:UnionFind(int N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par.emplace_back(i);
        for(int i = 0; i < N; i++) siz.emplace_back(1);
        all = N;
        treenum = N;
    }

    public:int root(int x){
        if(par[x]==x) return x;
        else{
            par[x]=root(par[x]);
            return par[x];
        }
    }

    public:bool same(int x, int y){
        return root(x)==root(y);
    }

    public:void unite(int x, int y){
        if(same(x,y)) return;
        else{
            int rx=root(x);
            int ry=root(y);
            par[ry]=rx;
            siz[rx]=siz[rx]+siz[ry];
            siz[ry]=siz[rx];
            treenum--;
            return;
        }
    }

    public:int size(int x){
        siz[x]=siz[root(x)];
        return siz[x];
    }

    public:void sizall(){
        rep(i,all){
            siz[i] = siz[root(i)];
        }
    }

    public:int treenumber(){
        return treenum;
    }

    public:void add(){
        par.emplace_back(all);
        siz.emplace_back(1);
        all++;
        treenum++;
    }

    public:void del(int x){
        //xを木から外して単一ノードの木に分離する
        //子の検索にO(n)かける. UF木の弱点なので使用は推奨されない
        //根であれば繋ぎ直し、素集合としてみなさない.
        bool isroot=false;
        //あるノードの根であるかどうか.
        rep(i,all){
            if(root(i)==x) isroot=true;
        }
        if(!isroot){
            rep(i,all){
                if(par[i]==x){
                    par[i]=par[x];
                }
            }
            par[x]=x;
            return;
        }

        if(isroot){
            sizall();
            if(size(x)==1) return;
            rep(i,all){
                if(par[i]==x){
                    treenum++;
                    par[i]=i;
                }
            }
            return;
        }

    }

};



void solve(){

    int n;
    cin >> n;
    vector<pair<ll,ll>> ve;
    rep(i,n){
        ll x,y;
        cin >> x >> y;
        ve.emplace_back(make_pair(x,y));
    }

    vector<pair<ll,ll>> xi;
    vector<pair<ll,ll>> yi;
    rep(i,ve.size()){
        xi.emplace_back(make_pair(ve[i].first, i));
        yi.emplace_back(make_pair(ve[i].second, i));
    }
    sort(xi.begin(), xi.end());
    sort(yi.begin(), yi.end());


    vector<tuple<int,int,int>> t;
    /*
    rep(i,e){
        int x,y,z;
        cin >> x >> y >> z;
        t.emplace_back(make_tuple(z,x,y));
    }
    */
    rep(i,n-1){
        t.emplace_back(make_tuple(xi[i+1].first-xi[i].first, xi[i+1].second, xi[i].second));
        t.emplace_back(make_tuple(yi[i+1].first-yi[i].first, yi[i+1].second, yi[i].second));
    }

    sort(t.begin(), t.end());
    UnionFind uf(n);
    int pointer=0;
    int ans = 0;
    while(uf.treenumber()>1){
        int d = get<0>(t[pointer]);
        int x = get<1>(t[pointer]);
        int y = get<2>(t[pointer]);
        if(!uf.same(x,y)){
            ans += d;
            uf.unite(x,y);
        }
        pointer++;
    }
    cout << ans << endl;

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

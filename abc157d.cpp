#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
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
        for(int i = 0; i < N; i++) par.eb(i);
        for(int i = 0; i < N; i++) siz.eb(1);
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
        par.eb(all);
        siz.eb(1);
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

    int n,m,k;
    cin >> n >> m >> k;
    UnionFind uf(n);
    int v[n];
    rep(i,n){
        v[i]=-1;
    }
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a,b);
        v[a]--;
        v[b]--;
    }
    rep(i,n){
        v[i] += uf.size(i);
    }
    rep(i,k){
        int c,d;
        cin >> c >> d;
        c--;
        d--;
        if(uf.same(c,d)){
            v[c]--;
            v[d]--;
        }
    }

    rep(i,n){
        cout << v[i] << " ";
    }
    cout << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

struct SqrtRoot{

    vector<int> a;
    int number;
    int b_size;//バケツ幅
    int b_number;//バケツサイズ
    vector<int> b;

    SqrtRoot(int n){
        rep(i,n){
            a.emplace_back(0);
        }
        number = n;
    }

    public:void pre(int *c){
        rep(i,number){
            a[i]=*(c+i);
            //cout << a[i] << endl;
        }
        b_size = int(sqrt(number));
        b_number = number/b_size;
        int count=0;
        rep(i,b_number){
            b.emplace_back(INF);
        }

        while(count*b_size<number){
            rep(j,b_size){
                b[count]=min(b[count], a[count*b_size+j]);
            }
            count++;
        }
        
    }

    public:void print_input(){
        rep(i,number){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    public:void print_backet(){
        rep(i,b_number){
            cout << b[i] << " ";
        }
        cout << endl;
    }

    public:int minimum(int i, int j){
        int backet_first = (i+3)/b_size;
        int backet_last = (j-3)/b_size;

        int ans=INF;
        for(int k=backet_first; k<=backet_last; k++){
            ans = min(ans, b[k]);
        }
        for(int k=i; k<=backet_first*b_size; k++){
            ans = min(ans, a[k]);
        }
        for(int k=backet_last*b_size+3; k<=j; k++){
            ans = min(ans, a[k]);
        }
        return ans;
    }

    public:void update(int i, int x){
        int backet_number = i/b_size;
        b[backet_number] = min(b[backet_number], x);
    }


};

void solve(){

    int n;
    cin >> n;
    SqrtRoot sr(n);
    int input[n];
    rep(i,n){
        cin >> input[i];
    }

    sr.pre(input);
    sr.print_input();
    sr.print_backet();
    cout << sr.minimum(11,20) << endl;
    sr.update(19,-2);
    sr.print_backet();
    cout << sr.minimum(11,20) << endl;
    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

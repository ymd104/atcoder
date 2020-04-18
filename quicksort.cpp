#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll MOD = 1000000007;
ll INF = 1000000009;

int a[1000010];

int partition(int left, int right){
    int p;
    p = (left+right)/2;
    swap(a[p],a[right]);
    int store = left;

    for(int i=left; i<right; i++){
        if(a[i]<=a[right]){
            swap(a[i],a[store]);
            store++;
        }
    }
    swap(a[store], a[right]);
    return store;
}

void quickSort(int left, int right){
    if(left<right){
        int pivot = partition(left ,right);
        quickSort(left,pivot-1);
        quickSort(pivot+1,right);
    }
}

void solve(){

    int n;
    cin >> n;
    random_device rnd;
    rep(i,n){
        a[i] = rnd()%10 ;
    }


    clock_t st = clock();

    quickSort(0,n-1);

    clock_t end = clock();

    rep(i,n){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << (double)(end-st) << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

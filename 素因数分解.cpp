//関数prime_factorは引数を素因数分解し、map[i]:nをそう因数分解した時の素数iの数を返す
//O(n^1/2)で動作

map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
/**
* author : r_hasan
* created: 17.10.18 9 56
**/
#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6+5;
int mark[mx];
vector < int > primes;
void sieve() {
      mark[0] = mark[1] = 1;
      for(int i = 4; i < mx; i += 2) mark[i] = 1;
      for(int i = 3; i * i < mx; i += 2) {
            if(!mark[i]) {
                  for(int j = i * i; j < mx; j += (i + i)) {
                        mark[j] = 1;
                  }
            }
      }
}
void sieve2() {
      mark[0] = mark[1] = 1;
      for(int i = 2; i < mx; i++) {
            if(mark[i] == 0) primes.push_back(i);
            for(int j = 0; j < primes.size() && i * primes[j] < mx; j++) {
                  mark[i * primes[j]] = 1;
                  if(i % primes[j] == 0) break;
            }
      }
}
int solve(int n) {
      int mul = 1, ans = 1;
      for(int i = 0; n > 1 ; i++) {
            if(n % primes[i] == 0) {
                  mul = 1;
                  while(n % primes[i] == 0) {
                        mul *= primes[i];
                        n /= primes[i];
                  }
                  mul /= primes[i];
                  mul *= (primes[i] - 1);
                  ans *= mul;
            }
      }
      return ans;
}
int main() {
      ios_base::sync_with_stdio(0), cin.tie(0);
      sieve2();
      int n, t;
      cin >> t;

      while(t--) {
            cin >> n;
            if(mark[n] == 0) {
                  cout << n-1 << endl;
            }
            else{
                  cout << solve(n) << endl;
            }
      }
      return 0;
}

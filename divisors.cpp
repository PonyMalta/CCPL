#include <bits/stdc++.h>
using namespace std;

vector<int> factors;
const int MAX = 1000000;
const int SQRT = 1000;
vector<int> primes;
bitset<MAX+1> marked;

void sieve() {
    marked[1] = 1;
    int i = 2;
    for (; i <= SQRT; i++) if (!marked[i]) {
        primes.push_back(i);
        for (int j = i*i; j <= MAX; j += i<<1) marked[j] = 1;
    }
    for (; i <= MAX; i++) if (!marked[i]) primes.push_back(i);
}

void primeFactors(int n) {
    factors.clear();
    for (int i = 0, p = primes[i]; p*p <= n; p = primes[++i]) {
        while (n % p == 0) {
            factors.push_back(p);
            n /= p;
        }
    }
    if (n > 1) factors.push_back(n);
}

int main() {
        int casos;
        cin>>casos;
        while (casos--) {
        sieve();
        int n,m;
        cin>>n>>m;
        int max = 0;
        int num = 0;
            for (int i = n; i <= m; i++) {
                int div = 1;
                primeFactors(i);
                int exp = 1;
                int index=-1;
                if(!factors.empty()){
                index = (int)factors[0];
                }
                for (int e = 1; e < factors.size(); e++) {
                    if ((int) factors[e] == index) {
                        exp++;
                    } else {
                        if (div == 0) {
                            div = (exp + 1);
                        } else {
                            div = (exp + 1) * div;
                        }
                        exp = 1;
                        index = (int) factors[e];
                    }
                    if (e == factors.size() - 1) {
                        div = (exp + 1) * div;
                    }
                }
                if (div > max) {
                    max = div;
                    num = i;
                }
            }
            cout<<"Between "<<n<<" and "<<m<<", "<<num<<" has a maximum of "<<max<<" divisors."<<"\n";
        }
        return 0;
    }
	

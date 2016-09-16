 #include <map>
 #include <set>
 #include <vector>
 #include <list>
 #include <cmath>
 #include <cstring>
 #include <string>
 #include <sstream>
 #include <iostream>
 #include <algorithm>

 #define sz(a) int((a).size())
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define FOR(a,b,i) for(int i=a; i<=b; i++)
 #define RFOR(a,b,i) for(int i=b; i>=a; i--)
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back
 #define mp make_pair

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;

 #define MAX 1000000000

 int main(){
    int t;
    int64_t m,n;
    int root = (int)sqrt((double)MAX);
    vi is_prime(root + 1,1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for(int i = 2;i*i <= root;i++){
    if(is_prime[i])
        for(int j = i*i;j<=root ;j += i)
            is_prime[j] = 0;
    }
    cin >> t;
    while(t--){
        cin >> m >> n;
        vi primes(n-m+1,1);
        for(int i = 2;i<=sqrt(n);i++){
            if(is_prime[i]){
                int64_t first ;
                if(m%i == 0){
                    first = m;
                } else{
                    first = (static_cast<int>(m/i))*i + i;
                }
                    for(int64_t j = first;j<=n;j += i){
                        if(j != i)
                        primes[j-m] = 0;
                    }

            }
        }
        if(m == 1) primes[0] = 0;
        FOR(0,n-m,i)
            if(primes[i] == 1) cout << m+i << endl;
    }
 return 0;
 }

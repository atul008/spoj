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
 #define  x first
 #define  y second

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


 int main(){
    int t;
    cin >> t;
    string a,b;
    while(t--){
        stringstream ss;
        int64_t x,y,sum;
        cin >> a >> b;
        reverse(all(a));
        reverse(all(b));
        ss << a;
        ss >> x;
        ss.clear();
        ss << b;
        ss >> y;
        ss.clear();
        sum = x + y;
        while(sum % 10 == 0) sum /=10;
         ss << sum ;
         ss >> a;
         reverse(all(a));
        cout << a << endl;
    }
 return 0;
 }


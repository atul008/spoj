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
     int n,m;
     cin >> n >> m;
     if(n == 0 || m == 0){
         if(n == 0){
            cout << "0 " << "1" << endl;
            cout << "0 " << m << endl;
            cout << "0 " << "0" << endl;
            cout << "0 " << m-1 << endl;
         } else {
            cout << "1" << " 0" << endl;
            cout << n << " 0" << endl;
            cout << "0" << " 0" << endl;
            cout << n-1 << " 0" << endl;
         }
        } else {
            cout << "0 " << "0" << endl;
            cout << n << " " << m << endl;
            if(m > n){
                cout << n << " 0" << endl;
                cout << "0 " << m << endl;
            } else{
                cout << "0 " << m << endl;
                cout << n << " 0" << endl;
            }
        }

 return 0;
 }

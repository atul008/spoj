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
 int n;
 string a,b;
 cin >> n >> a >> b;
 int mpl = 0,ans = 0;
 FOR(0,n-1,i){
    int tpl = 0,k,j;
    if(b[i] == a[0]){
        tpl++;
        j = 1;
        k = (i+1)%n;
        while(j < n){
            if(a[j] == b[k]){
                tpl++;
                j++;
                k = (k+1)%n;
            }else{
                break;
            }
        }
    }
    if(tpl > mpl){
        mpl = tpl;
        ans = i;
    }
 }
    cout << ans << endl;
 return 0;
 }

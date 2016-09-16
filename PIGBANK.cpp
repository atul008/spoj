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
 #define INF 99999999
 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;

 void ks(vi& dp,int w,vector< ii >& coin){
    int n = sz(coin);
    dp[0] = 0;
    FOR(1,w,i){
        FOR(0,n-1,j){
            if(i-coin[j].y >=0){
                dp[i] = min(dp[i],dp[i-coin[j].y] + coin[j].x);
            }
        }
    }
 }

 int main(){
    int t;
    cin >>t;
    while(t--){
        int n,v,w,empty,full,wt;
        vector< ii > coin;
        cin >> empty >> full;
        cin >> n;
        FOR(0,n-1,i){
            cin >> v >> w;
            coin.pb(mp(v,w));
        }
        wt = full-empty;

        vi dp(wt+1,INF);
        ks(dp,wt,coin);
        if(dp[wt] != INF){
            cout << "The minimum amount of money in the piggy-bank is " << dp[wt] << "." << endl;
        } else{
            cout << "This is impossible." << endl;
        }

    }



 return 0;
 }

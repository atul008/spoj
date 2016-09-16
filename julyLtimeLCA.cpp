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

 int LCA(vvi& arr,int* vis,int n,int& lca,int r,int u,int v){
    if( r == u || r == v){
        return 1 ;
    }
    vis[r] = 1;
    int flag = 0;
    vi count(0);
    FOR(1,n,i){
        if(arr[r][i] == 1 && (vis[i] == 0) ){
            flag = LCA(arr,vis,n,lca,i,u,v);
        }
        if(flag == 1)
            count.pb(1);
        if(flag == 2) return 2;
        flag = 0;

    }
    if(sz(count) > 1) {
        lca = r;
        return 2;
    }
    return 0;
 }

 int main(){
    int n,x,y;
    cin >> n;
    vvi arr(n+1,vi(n+1,0));
    FOR(1,n-1,i){
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    int q;
    cin >> q;
    int r,u,v,ans;
    int  vis[n+1];
    while(q--){
        cin >> r >> u >> v;
        SET(vis,0);
        vis[0] = 1;
        ans = r;
        LCA(arr,vis,n,ans,r,u,v);
        cout << ans << endl;
    }

 return 0;
 }

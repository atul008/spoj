 #include <map>
 #include <set>
 #include <vector>
 #include <list>
 #include <cmath>
 #include <cstdio>
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
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back
 #define mp make_pair

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;

 bool isPalin(vi& arr,int& all9){
    int n = sz(arr);
    FOR(0,n/2,i){
        if(arr[i] != arr[n-1-i])
            return false;

        if(arr[i] != 9) all9 = 0;
    }
 return true;
 }

 int main(){
    int t;
    vi arr;
    cin >> t;
    while(t--){
        arr.clear();
        string s;
        cin >> s;
        int n = sz(s);
        FOR(0,n-1,i){
            arr.pb(s[i]-'0');
        }
        int all9 = 1;
        int isp = isPalin(arr,all9);
        if( isp && all9 == 1){
            cout << "1";
            FOR(1,n-1,i) cout << "0";
            cout << "1" << endl;

        }else if( isp && all9 == 0){
                int i ,j;
                if(n%2 == 0){
                    i = n/2 -1;
                    j = i+1;
                }else{
                    i = n/2;
                    j = i;
                }
                if(arr[i] == 9){
                    int carry = 1;
                    arr[i] = 0;
                    arr[j] = 0;
                    i--;
                    j++;
                    while(carry && i>=0 && j<= n-1){
                        arr[i] = arr[i] + carry;
                        carry = arr[i]/10;
                        arr[i] = arr[i]%10;
                        arr[j] = arr[i];
                        i--;
                        j++;
                    }
                }else{
                    arr[i] = arr[i] + 1;
                    arr[j] = arr[i];
                }

                tr(arr,it) cout << *it;
                cout << endl;

        }else{
            int i ,j;
            if(n%2 == 0){
                i = n/2 -1;
                j = i+1;
            }else{
                i = n/2;
                j = i;
            }

            while(i>=0 && j<=n-1){
                if(arr[i] != arr[j])
                    break;
                i--;
                j++;
            }
            int flag = 0;
            if(arr[i] < arr[j]) flag = 1;

            while(i>=0 && j<=n-1){
                arr[j] = arr[i];
                i--;
                j++;
            }
            if(flag == 1){
                if(n%2 == 0){
                    i = n/2 -1;
                    j = i+1;
                }else{
                    i = n/2;
                    j = i;
                }
                if(arr[i] == 9){
                        int carry = 1;
                        arr[i] = 0;
                        arr[j] = 0;
                        i--;
                        j++;
                        while(carry && i>=0 && j<= n-1){
                            arr[i] = arr[i] + carry;
                            carry = arr[i]/10;
                            arr[i] = arr[i]%10;
                            arr[j] = arr[i];
                            i--;
                            j++;
                        }
                }else{
                    arr[i] = arr[i] + 1;
                    arr[j] = arr[i];
                    i--;
                    j++;
                }
            }

            tr(arr,it) cout << *it;
            cout << endl;
       }

    }

 return 0;
 }

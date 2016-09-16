 #include <deque>
 #include <iostream>
 #include <algorithm>

 #define sz(a) int((a).size())
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define FOR(a,b,i) for(int i=a; i<=b; i++)
 #define RFOR(a,b,i) for(int i=a; i>=b; i--)
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back

 using namespace std;
 class BigNumber{
    private:
        // 0 for +ve ; 1 for -ve
        int sign;
        deque<int> num;
    public:
        BigNumber (){}
       BigNumber(string s){
            if(s[0] == '-')
                sign = 1;
            else
                sign = 0;
            int len = s.length();
            FOR(0,len-1,i){
                num.pb(s[i]-'0');
            }
        }
        BigNumber(deque<int> s){
            sign = 0;
            int len = sz(s);
            FOR(0,len-1,i){
                num.pb(s[i]);
            }
        }
        void operator =(const BigNumber a ){
            num.clear();
            sign = a.sign;
            FOR(0,sz(a.num)-1,i) num.pb(a.num[i]);
        }
        void disp(){
            if(sign == 1) cout << "-";
            tr(num,it) cout << *it;
        }
    // To multiply bignumber with  a integer
        BigNumber operator * (const int a){
            int m,carry = 0;
            int i = sz(num)-1;
            deque<int> temp;
            while(i>=0){
                m = num[i]*a + carry;
                carry = m/10;
                m %= 10;
                temp.push_front(m);
                i--;
            }
            while(carry > 0){
                temp.push_front(carry%10);
                carry /= 10;
            }
            return BigNumber(temp);
        }

 };

 int main(){
   int t,n;
   cin >> t;
    while(t--){
         cin >> n;
         BigNumber fact("1");
         FOR(2,n,i){
            fact = fact * i;
         }
         fact.disp();
         cout << endl;
   }
 return 0;
 }

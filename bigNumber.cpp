 #include <map>
 #include <set>
 #include <vector>
 #include <list>
 #include <deque>
 #include <queue>
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
 #define RFOR(a,b,i) for(int i=a; i>=b; i--)
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back
 #define mp make_pair

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;
 class BigNumber{
    private:
        // 0 for +ve ; 1 for -ve
        int sign;
        deque<int> num;
    public:
        BigNumber (){}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        BigNumber(deque<int> s){
            sign = 0;
            int len = sz(s);
            FOR(0,len-1,i){
                num.pb(s[i]);
            }
        }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        void operator =(const BigNumber a ){
            num.clear();
            sign = a.sign;
            FOR(0,sz(a.num)-1,i) num.pb(a.num[i]);
        }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        BigNumber operator + (const BigNumber b){

           int i = sz(num),j = sz(b.num);
           deque<int> temp(0);
           i--;
           j--;
           int carry = 0;
           int sum = 0;
           while(i >=0 && j>=0){
                sum = num[i] + b.num[j] + carry;
                carry = sum/10;
                sum %= 10;
                temp.push_front(sum);
                i--;
                j--;
           }
           if(i < 0){
               while(j>=0){
                   sum = b.num[j] + carry;
                   carry = sum/10;
                   sum %=10;
                    temp.push_front(sum);
                    j--;
               }
               if(carry > 0){
                temp.push_front(carry);
                carry = 0;
               }
           }
           if(j < 0){
               while(i>=0){
                   sum = num[i] + carry;
                   carry = sum/10;
                   sum %=10;
                   temp.push_front(sum);
                    i--;
               }
               if(carry > 0){
                temp.push_front(carry);
                carry = 0;
               }
           }
            return BigNumber(temp);
        }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        void disp(){
            if(sign == 1) cout << "-";
            tr(num,it) cout << *it;
        }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        BigNumber operator * (const BigNumber b){
            int iter = 0,n = sz(b.num)-1;
            BigNumber res("0"),temp;

            while(iter <= n){
                temp.num.clear();
                temp = *this * static_cast<int>(b.num[n-iter]);
                FOR(1,iter,j) temp.num.pb(0);
                res = res + temp;
                iter++;
            }
            return res;
        }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        bool operator < (const BigNumber b){
            int sza = sz(num),szb = sz(b.num);
            if(num[0] != '-' && b.num[0] != '-'){
              if(sza < szb)
                    return true;
              else if(sza > szb)
                    return false;
              else
                    {
                        int i = 0;
                        while(i<=sza-1){
                            if(num[i] < b.num[i])
                                return true;
                            else if(num[i] > b.num[i])
                                return false;
                                i++;
                        }
                        return false;
                    }
            }

            if(num[0] == '-' && b.num[0] == '-'){
              if(sza > szb)
                    return true;
              else if(sza < szb)
                    return false;
              else
                    {
                        int i = 0;
                        while(i<=sza-1){
                            if(num[i] > b.num[i])
                                return true;
                            else if(num[i] < b.num[i])
                                return false;
                                i++;
                        }
                        return false;
                    }
            }
            if(num[0] != '-' && b.num[0] == '-') return false;
            if(num[0] == '-' && b.num[0] != '-') return true;
        }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        BigNumber operator -(BigNumber b){
            BigNumber res,temp;
            if(*this < b){
                res.sign = 1;
                temp = b;
                b = *this;
                *this = temp;
            }else{
                res.sign = 0;
            }
            int i = sz(num)-1 , j = sz(b.num)-1;
            int diff,carry = 0 ;
            while(i >= 0 && j >=0){
                diff = num[i] - b.num[j] - carry;
                if(diff >= 0){
                    res.num.push_front(diff);
                    carry = 0;
                }else{
                    diff += 10;
                    carry = 1;
                    res.num.push_front(diff);
                }
                i--;
                j--;
            }
            if(j < 0 && i >=0){
                diff = num[i] - carry;
                carry = 0;
                res.num.push_front(diff);
                i--;
                while(i >=0){
                    res.num.push_front(num[i--]);
                }
            }
            while(res.num[0] == 0){
                res.num.pop_front();
            }
            if(sz(res.num) == 0)
                res.num.pb(0);


            return res;
        }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    BigNumber operator / (const int a){
        int q=0,r=0;
        BigNumber res;
        while(!num.empty()){
            q = q*10 + num[0];
            num.pop_front();
            if(q >= a){
                res.num.pb(q/a);
                q = q%a;
            } else if(!res.num.empty()){
                res.num.pb(0);
            }
        }
    return res;
    }



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 };

 int main(){
   // BigNumber a("1005"),b("25"),c,d;
    //c = a+b;
   /* cout << "d : ";
    d = b* a;
    d.disp();
    cout << endl;
    if(b < a) cout << "a is less than b \n";
    c = a / 25;
    c.disp(); */
    string total,more;
    int c = 10;
    while(c--){
         cin >> total >> more;
         BigNumber a,b,t(total),m(more);
         a = (t + m)/2;
        // a = a/2;
         b = (t - m)/2;
         a.disp();
         cout << endl;
         b.disp();
         cout << endl;
   }
 return 0;
 }

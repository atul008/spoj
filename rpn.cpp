 #include <map>
 #include <set>
 #include <stack>
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

    stack<char> s;
    int t;
    string exp;
    cin >> t;
    while(t--){
        cin >> exp;
        string rpn;
        FOR(0,exp.length()-1,i){
            if(exp[i] >='a' && exp[i] <='z'){
                rpn = rpn + exp[i];
                //rpn.append(exp[i]);
                //cout << "abc" << endl;
            }else if(exp[i] == '('){
                        s.push('(');
                 //       cout << "(" << endl;
            }else if(exp[i] == ')'){
                while(s.top() != '('){
                        rpn += s.top();
                        //rpn.append(s.top());
                        s.pop();
                }
                s.pop();
                //cout << ")" << endl;
            } else {
               // cout << "+-" << endl;
                switch(exp[i]){
                    case '+' :{
                        char t = s.top();
                        if(t == '+' || t == '-' || t == '*' || t == '/' || t == '^'){
                        while(t == '+' || t == '-' || t == '*' || t == '/' || t == '^'){
                            //rpn.append(t);
                            rpn += t;
                            s.pop();
                            t = s.top();
                        }
                        s.pop();
                        } else{
                            s.push(exp[i]);
                        }
                        break;
                    }
                    case '-':{
                        char t = s.top();
                        if( t == '-' || t == '*' || t == '/' || t == '^'){
                        while( t == '-' || t == '*' || t == '/' || t == '^'){
                            //rpn.append(t);
                            rpn += t;
                            s.pop();
                            t = s.top();
                        }
                        s.pop();
                         }else{
                            s.push(exp[i]);
                        }
                        break;

                    }
                    case '*':{
                        char t = s.top();
                        if( t == '*' || t == '/' || t == '^'){
                        while( t == '*' || t == '/' || t == '^'){
                            //rpn.append(t);
                            rpn += t;
                            s.pop();
                            t = s.top();
                        }
                        s.pop();
                        } else{
                            s.push(exp[i]);
                        }
                        break;
                    }
                    case'/':{
                        char t = s.top();
                        if( t == '/' || t == '^'){
                        while( t == '/' || t == '^'){
                            //rpn.append(t);
                            rpn += t;
                            s.pop();
                            t = s.top();
                        }
                        s.pop();
                        } else {
                            s.push(exp[i]);
                        }
                        break;
                    }
                    case '^':{
                        char t = s.top();
                        if(t == '^'){
                        while( t == '^'){
                          //  rpn.append(t);
                            rpn += t;
                            s.pop();
                            t = s.top();
                        }
                        s.pop();
                        } else {
                            s.push('^');
                        }
                        break;
                    }
                }
            }
        }
        cout << rpn << endl;
    }





 return 0;
 }

#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack <char> b;
    string s;
    cin >> s;
    int cnto = 0;
    int cntc = 0;

    if ((s[0] == ')' || s[0] == '}' || s[0] == ']') || (s[s.size() - 1] == '(' || s[s.size() - 1] == '{' || s[s.size() - 1] == '[')){
            cout << "no" << endl;
            return 0;
        }

    for (int i=0; i<s.length(); i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            b.push(s[i]);
            cnto++;
        }else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
            cntc++;
            if (cntc > cnto){
                cout << "no" << endl;
                return 0;
            }
            else if (s[i] == ')' && !b.empty() && b.top() == '('){
                b.pop();
            }
            else if (s[i] == '}' && !b.empty() && b.top() == '{'){
                b.pop();
            }
            else if (s[i] == ']' && !b.empty() && b.top() == '['){
                b.pop();
            }
            else if (b.empty()){
                cout << "no" << endl;
                return 0;
            }
        }
        
    }

    if (b.empty()){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }

    return 0;
}
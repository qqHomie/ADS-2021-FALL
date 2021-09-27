#include <iostream>
#include <queue>

using namespace std;

int main(){

    queue <string> g9;
    queue <string> g10;
    queue <string> g11;

    string s;

    while (getline(cin,s)){
        if (s.substr(0, 1) == "9") {
            g9.push(s.substr(2, s.size() - 2));
        }
        else if(s.substr(0,2) == "10") {
                g10.push(s.substr(3, s.size() - 3));
        }
        else if(s.substr(0,2) == "11"){
            g11.push(s.substr(3, s.size() - 3));
        }
    }


    while(!g9.empty()){
        cout << "9 " << g9.front() << endl;
        g9.pop();
    }

    while(!g10.empty()){
        cout << "10 " << g10.front() << endl;
        g10.pop();
    }

    while(!g11.empty()){
        cout << "11 " << g11.front() << endl;
        g11.pop();
    }

    return 0;
}
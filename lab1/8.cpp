#include <iostream>
#include <deque>

using namespace std;

int main(){

    int n;
    cin >> n;
    int x;
    deque <int> d1;
    deque <int> d2;

    while (n!=0){
        char a;
        cin >> a;
        if (a == '+'){
            cin >> x;
            d1.push_back(x);
        }
        else if (a == '*'){
            cin >> x;
            d1.push_front(x);
        }
        else if (a == '-'){
            cout << d2.front() << endl;
            d2.pop_front();
        }
        if (d1.size() > d2.size()){
            d2.push_back(d1.front());
            d1.pop_front();
        }
        n--;
    }

    return 0;
}
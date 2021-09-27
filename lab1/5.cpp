#include <iostream>
#include <queue>

using namespace std;

int main(){

    queue <int> first;
    queue <int> second;
    int cnt = 0;

    int n;
    for (int i=0; i<5; i++){
        cin >> n;
        first.push(n);
    }
    int m;
    for (int i=0; i<5; i++){
        cin >> m;
        second.push(m);
    }

    while (!first.empty() && !second.empty()){
        int a = first.front();
        int b = second.front();
        first.pop();
        second.pop();

        if (a == 0 && b == 9){
            first.push(a);
            first.push(b);
            cnt++;
        }
        else if (a == 9 && b == 0){
            second.push(a);
            second.push(b);
            cnt++;
        }
        else if (a > b){
            first.push(a);
            first.push(b);
            cnt++;
        }
        else if (a < b){
            second.push(a);
            second.push(b);
            cnt++;
        }

        if (cnt > 1000000){
            cout << "botva" << endl;
            return 0;
        }
    }

    if (first.empty()){
        cout << "second " << cnt << endl;
    }

    else if (second.empty()){
        cout << "first " << cnt << endl;
    }

    return 0;
}
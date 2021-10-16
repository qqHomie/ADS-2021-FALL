#include <iostream>

using namespace std;

int main(){

    int n, x;
    int maxi1 = -10000000;
    int maxi2 = -10000007;
    cin >> n;
    while (n != 0){
        cin >> x;
        if (x > maxi1 && x != maxi2){
            maxi2 = maxi1;
            maxi1 = x;
        }
        else if (x > maxi2 && x < maxi1 && maxi1 != maxi2){
            maxi2 = x;
        }
        n--;
    }
    cout << maxi2 << endl;

    return 0;
}
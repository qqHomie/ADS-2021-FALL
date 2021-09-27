#include <iostream>

using namespace std;

int gcd(int a, int b){
    if (a % b == 0) return b;
    return gcd(b % a, a);
}

int main(){

    int n, m;
    cin >> n >> m;
    cout << gcd(n, m) << endl;

    return 0;
}
#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int a[n];
    int maxi = -1001;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if (a[i] > maxi){
            maxi = a[i];
        } 
    }
    cout << maxi << endl;
    

    return 0;
}
#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int a[n];
    int maxi = -1001;
    int maxindex = -1;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if (a[i] > maxi){
            maxi = a[i];
            maxindex = i + 1;
        } 
    }
    cout << maxindex << endl;

    return 0;
}
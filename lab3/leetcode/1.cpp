#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n = 5;
    vector <int> v;
    vector <pair<int, int>> ans;

    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        ans.push_back(make_pair(x, i));
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (v[0] == ans[j].first && i<=2){
                ans[j].second = 100;
            }
            else if (v[1] == ans[j].first && i<=2){
                ans[j].second = 200;
            }
            else if (v[2] == ans[j].first && i<=2){
                ans[j].second = 300;
            }
            else if(v[i] == ans[j].first && i>2){
                ans[j].second == i + 1;
            }
        }
    }

    for (int i=0;i<n;i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
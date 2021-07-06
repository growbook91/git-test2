#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int arr[13]={-2,-1,10,9,6,7,8,1,2,3,4,5,12};
    vector<int> ve={-2,-1,10,9,6,7,8,1,2,3,4,5,12};
    
    sort(arr, arr+13);
    sort(ve.begin(), ve.end());

    for(auto i : arr){
        cout << i << " ";
    }
    putchar('\n');
    for(auto i : ve){
        cout << i << " ";
    }
    putchar('\n');

    cout << "exist : " << binary_search(arr, arr+13, 4) << endl;
    cout << "exist : " << binary_search(ve.begin(), ve.end(), 5) << endl;

    cout << "lower_bound(0) : " << lower_bound(arr, arr + 13, 0) - arr + 1<< endl;
    cout << "lower_bound(0) : " << lower_bound(ve.begin(), ve.end(), 0) - ve.begin() + 1<< endl;
    cout << "upper_bound(0) : " << upper_bound(arr, arr + 13, 0) - arr + 1<< endl;
    cout << "upper_bound(0) : " << upper_bound(ve.begin(), ve.end(), 0) - ve.begin() + 1<< endl;

    return 0;
}
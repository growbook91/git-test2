#include <iostream>
using namespace std;

int F(int N){
    //base
    if(N == 0 || N == 1)
    return N;

    return F(N-1) + F(N-2);
}

int main(){
    int N;
    cin >> N;
    cout << F(N) << endl;
    return 0;
}
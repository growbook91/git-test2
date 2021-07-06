#include <iostream>
using namespace std; 
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 4, b= 10;
    cout << a << " " << b << endl;
    swap(a,b); 
    cout << a << " " << b << endl;
    return 0;
}
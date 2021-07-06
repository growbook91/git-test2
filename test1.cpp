#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    map<int, int> empty;
    printf("%d\n", empty[32]);

    map<double, int> empty_1;
    printf("%d\n", empty_1[32]);

    map<string, string> empty_2;
    cout << empty_2["a"] << endl;
    
    return 0;
}
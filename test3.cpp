#include <iostream>
#include <limits>

int main(){
    std::cout << "int 타입의 최대 값:  " << std::numeric_limits<int>::max( ) << std::endl;
    std::cout << "int 타입의 최소 값:  " << std::numeric_limits<int>::min( ) << std::endl;
    std::cout << "long long 타입의 최대 값:  " << std::numeric_limits<long long>::max( ) << std::endl;
    std::cout << "long long 타입의 최소 값:  " << std::numeric_limits<long long>::min( ) << std::endl;
    return 0;
}
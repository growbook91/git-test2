#include <iostream>
#include <vector>
using namespace std;
//꿀팁 = 1e6이런 식으로 하면 10의 몇 제곱

int main(){
    //vector선언
    int N = 0, M = 0;
    vector<int> v(1);//사용자의 입력값을 저장...그리고 처음 부분은 0으로 초기화
    unsigned long long count = 0;

    cin >> N >> M;
    int temp = 0;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        v.push_back(temp);
    }
    //psum구하기
    //각 항을 M으로 나누기
    for(int i = 1; i <= N ; i++){
        v[i]=(v[i-1]+v[i])%M;
    }
    
    //같은 숫자의 개수 파악
    vector<long long> left(M);
    for(int i = 0; i < v.size(); i++){
        left[v[i]]++;
    }

    //combination
    for(int i = 0; i < left.size(); i++){
        count += left[i]*(left[i]-1)/2;//어차피 둘 중 하나는 짝수라서 무조건 int다.
    }
    cout << count << endl;
    return 0;
}
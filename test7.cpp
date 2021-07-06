#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int sum = 0;
    
    vector<int> v(N);
    int ans = -1000;
   //일단 총합을 알아야 한다.
   for(int i = 0; i<N; i++){
       cin >> v[i];
       sum += v[i];
   }
   //index를 증가해가면서 잔여물보다 더 작을 때까지 증가
   for(int start = 0; start < N ; start++){
       int psum = 0;
       for(int j = start; j < N ; j++){
            psum += v[j];
            if(psum > sum - psum)
            break;
            ans=max(ans, psum);
        }
   }
   cout << ans <<endl;
   //잔여물보다 커지면 stop하고 prev를 
   //최댓값을 저장
    return 0;
}
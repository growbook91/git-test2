#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    
    //값 받기
    cin >> N >> M;
    vector< vector<int> > arr(N+1, vector<int>(N+1,0));
    vector< vector<int> > psum(N+1, vector<int>(N+1,0));
    vector<int> output(M);
    //array선언
    for(int i = 0 ; i < N; i++){
        arr[i][0]=0;
        arr[0][i]=0;
    }
    putchar('\n');
    for(int i = 1; i <= N; i++){//행
        for(int j = 1; j <= N; j++){//열
            //array 값 받기
            cin >> arr[i][j];
            //psum 구하기
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + arr[i][j];
            // cout << psum[i][j] << " ";
        }
    }
    // for(int i = 1; i <= N; i++){//행
    //     for(int j = 1; j <= N; j++){//열
    //         cout << psum[i][j] << " ";
    //     }
    //     putchar('\n');
    // }
    
    //범위값받기
    int x1, y1, x2, y2;
    for(int i = 0; i < M; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        output[i]=psum[x1-1][y1-1] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x2][y2];
    }
    //계산
    //출력
    for(int i = 0; i < M; i++){
        cout << output[i] << endl;
    }
    return 0;
}

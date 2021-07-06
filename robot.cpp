#include <iostream>
using namespace std;
#define EAST 0
#define NORTH 1
#define WEST 2
#define SOUTH 3

int main(){
    int flag = EAST;
    string command = "";
    int d = 0;
    int N = 0 , M = 0;
    int loc[2]={0,0};//초기위치

    cin >> M >> N;
    for(int i = 0; i< N; i++){
        //명령어 받기
        cin >> command >> d;
        // cout << command << d << endl;
        //움직이기
        //turn
        if(!command.compare("TURN")){
            if(d==0){
                if(flag != SOUTH)
                    flag++;
                else flag = EAST;

            }
            else if(d==1){
                if(flag != EAST)
                flag--;
                else flag = SOUTH;
            }
            else {
                printf("Wrong direction input!\n");
                return 0;
            }
        }
        //move
        else if(!command.compare("MOVE"))
        switch(flag){
            case EAST : loc[0] += d;
                        break;
            case NORTH: loc[1] += d;
                        break;
            case WEST : loc[0] -= d;
                        break;
            case SOUTH: loc[1] -= d;
                        break;
        }
        else {
                printf("Wrong command input!\n");
                return -1;
            }
        //범위 확인
        if(!((0<=loc[0] && loc[0]<=M) && (0<=loc[1] && loc[1]<=M))){
            printf("-1");
            return 0;
        }
    }
    cout << loc[0] << " " << loc[1];
    return 0;
}

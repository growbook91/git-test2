#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#define STUDENT 26;
using namespace std;

// typedef enum{
//     준기, 진하, 예영, 강민, 창현, 인성, 지윤, 민석, 솔희, 승주, 주영, 진우, 서영, 선우, 경민, 예진, 권희, 용한, 소지혜, 유진, 지수, 동현, 이지혜, 현우, 민지, 태찬
// } people;

int main(){
    // cout << "안녕하세요" << endl;
    string people[26] = {"인성", "지윤", "민석", "솔희", "승주", "주영", "진우", "서영", "선우", "경민", "태찬", "준기", "진하", "예영", "강민", "창현", "예진", "권희", "용한", "소지혜", "유진", "지수","동현", "이지혜", "현우", "민지"};
    vector<int> graph[26];
    srand(time(NULL));
    //0부터 10까지는 안겹치게
    //파일을 열때에는 w+로 열자 -> 매번 파일을 새로 쓰게끔
    // FILE* fp = fopen("밥cc.txt", "r");
    //금지목록을 만들어야 하는데..
    
    //while문에 crtl c입력할 때까지 
        //ctrl z누르면 원래대로 돌아가는 걸로
        //이걸 구현하려면 현 graph 상태를 저장하는 걸 만들어야..
    //while안에서는 안되는 수를 제외하고 무작위로 수를 뽑고 /이미 뽑은 것을 제외하는 자료구조는 flag로
    //그래프에 추가 시켜두기
    //즉, 2가지 안되는 경우의 수가 존재 1. 원래 됬던 짝이나 새내기경우 2. 이미 이 프로그램내에서 뽑힌 경우
    char go = 0;
    do{
        int count = 0;
        int flag[26] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };//무작위로 해도 되는지
        cout << "Press Enter to proceed or Press 'ctrl C' to terminate the program\n";
        for(int i = 0 ; i < sizeof(people)/sizeof(people[0]); i++){
            

            //해당flag가 1인지 확인
            if(flag[i]==0) continue;
            //비어있는지 확인
            int rand_num = -1;
            if(graph[i].empty()){
                do{
                    rand_num=rand()%STUDENT;
                }while(rand_num == i || flag[rand_num] == 0);
            }
            else{
                int checkout = 0;
                while(1){
                    rand_num=rand()%STUDENT;
                    for(checkout = 0 ; checkout < graph[i].size(); checkout++){
                        if(graph[i][checkout] == rand_num || i==rand_num || flag[rand_num]==0){
                            break;
                        }
                    }
                    if(checkout == graph[i].size()) break;
                }
                
            }
            //비어있으면 아무거나 
            graph[rand_num].push_back(i);
            graph[i].push_back(rand_num);
            flag[rand_num] = 0;
            flag[i] = 0;
            //출력
            count++;
            cout << count << ')' <<people[i] <<"-"<<people[rand_num]<<endl;
        }
        
    }while((go = getchar()) != EOF);

    // for(int i = 0; i<26; i++){
    //     cout << people[i] << " ";
    // }

    return 0;
}
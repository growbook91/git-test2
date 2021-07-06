#include <iostream>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
typedef struct Node{
    string puzzle;
    struct Node *parent;
} Node;

string state[3] = {"132078564", "370162548", "756342108"};
string final = "123804765";

int compare(string state){
    if(state == final)
        return 1;
    else
        return 0;
}
int find_position(string state)
{
    for(int i = 0; i < state.size(); i++){
        if(state[i] == '0')
            return i;
    }
    return -1;
}
void print(string state){
    for(int i = 0; i < state.size(); i++){
        cout << state[i] << " ";
        if(i % 3 == 2)
            cout << "\n";
    }
    return;
}
string swap_puzzle(string check, int ind, int change_ind){
    char temp = check[ind];
    check[ind] = check[change_ind];
    check[change_ind] = temp;
    return check;
}

int main(){
    int result = 0;
    int isfind = 0;
    Node *newNode = NULL;

    for(int i = 0; i < 3; i++){
        newNode = new Node();
        newNode->puzzle = state[i];
        newNode->parent = NULL;
        cout << "-------------\n";
        cout << i << " puzzle\n";
        set<string> done;
        queue<Node*> q;
        result = 0;
        isfind = 0;

        done.insert(newNode->puzzle);
        q.push(newNode);
        // 같은 level node 검사하기
        while(!q.empty()){
            int size = q.size();
            for(int j = 0; j < size; j++){
                Node *check = q.front();
                q.pop();
                // 만약 완료 됐으면 끝
                if(check->puzzle == final){
                    string *array;
                    cout << "how many move the puzzle? " << result << "\n";
                    for(int level = result + 1; level > 0; level--){
                        Node *temp_Node = check;
                        for(int temp_level = 0; temp_level < level - 1; temp_level++)
                            temp_Node = temp_Node->parent;
                        print(temp_Node->puzzle);
                        cout << "\n";
                    }
                    isfind = 1;
                    break;
                }
                // 0 찾기
                int ind = find_position(check->puzzle);
                int row, col;
                // row값 찾기
                if(ind == 0)
                    row = 0;
                else
                    row = ind / 3;
                // col값 찾기
                if(ind == 0)
                    col = 0;
                else   
                    col = ind % 3;
            
                // 위치 바꾸고 큐에 넣기
                string temp;
                if(ind - 3 >= 0){
                    temp = swap_puzzle(check->puzzle, ind, ind - 3);
                    // 없었던 값이면 set에 넣기
                    if(done.find(temp) == done.end()){
                        newNode = new Node();
                        newNode->puzzle = temp;
                        newNode->parent = check;
                        q.push(newNode);
                        done.insert(newNode->puzzle);
                    }
                }
                if(ind - 1 >= 0 && (ind - 1) / 3 == row){
                    temp = swap_puzzle(check->puzzle, ind, ind - 1);
                    // 없었던 값이면 set에 넣기
                    if(done.find(temp) == done.end()){
                        newNode = new Node();
                        newNode->puzzle = temp;
                        newNode->parent = check;
                        q.push(newNode);
                        done.insert(newNode->puzzle);
                    }
                }
                if(ind + 1 <= 8 && (ind + 1) / 3 == row){
                    temp = swap_puzzle(check->puzzle, ind, ind + 1);
                    // 없었던 값이면 set에 넣기
                    if(done.find(temp) == done.end()){
                        newNode = new Node();
                        newNode->puzzle = temp;
                        newNode->parent = check;
                        q.push(newNode);
                        done.insert(newNode->puzzle);
                    }
                }
                if(ind + 3 <= 8){
                    temp = swap_puzzle(check->puzzle, ind, ind + 3);
                    // 없었던 값이면 set에 넣기
                    if(done.find(temp) == done.end()){
                        newNode = new Node();
                        newNode->puzzle = temp;
                        newNode->parent = check;
                        q.push(newNode);
                        done.insert(newNode->puzzle);
                    }
                }
            }
            //찾은게 있으면 다음 puzzle풀기
            if(isfind == 1)
                break;
            //깊이
            result++;
        }
        if(isfind == 0)
            cout << "there is no path back to the correct state\n";
    }
    cout << "finished\n";

    return 0;
}
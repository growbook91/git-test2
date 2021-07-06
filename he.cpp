#include<iostream>
#include<vector>
#include <queue>
#include <list>
#include <map>
using namespace std;

queue<int *> q;
list<int *> found;//state, key
list<int *> parent;//parent of found list

void createState(int* state){
    //0을 찾아
    
    //경우의 수 분석
    //compare

    //if(새로운 것)
        //queue에 집어넣기
}
int main()
{
    // 	for each vertex u  V – {s}//초기화부분…못해
    // do d[u] = ; π[u] = NIL; 
    // color[s] = GRAY; d[s] = 0; π[s] = NIL; Q=
    // ENQUEUE(Q, s)

    //first state선언
    int state[9] = {1,3,2,0,7,8,5,6,4};
    q.push(state);
    found.push_back(state);
    parent.push_back(NULL);
    // if(!parent.empty()){
    //     cout << 1 << endl;
    // }
    //결론적으로 NULL값을 list에 넣어도 empty가 아님.


    // ENQUEUE(found, s)
    // while Q  //u가 과거이고 v가 현재인듯/u가 현재 탐색하는 node.
    while(!q.empty()){
        // u = DEQUEUE(Q) 
        int *u = q.front();
        q.pop();
        //새롭게 만들 수 있는 state의 경우의 수를 return하는 함수를 만들어야 한다.
            // return void, queue q를 전역변수로 선언해서 접근, 현 state를 parameter로 받아.
        //state를 비교하는 함수도 필요..!
            //find 0
        
        // for each v  Adj[u]
        // if color[v] = WHITE//white인 것을 확인하는 알고리즘이 필요하다. 
        // //새로운 걸 발견하고
        // //if 그게 found에 없고, 정답이 아니라면
        //  then color[v] = GRAY
        // d[v] = d[u] + 1 
        // π[v] = u 
        // ENQUEUE(Q, v)
        // //부모에 대한 정보를 저장
        // //found, q queue에 child에 대한 정보를 저장
        // //반드시 우리가 찾는 노드가 발견될 거라는 것이 가정.
        // color[u] = BLACK//black이 되는 경우는 더 해당 노드가 더 이상 확장하지 못할 떄..!

        // // s: source vertex
        // // π : parent in the tree // d : Distance from s to u

    }
    
	return 0;
}
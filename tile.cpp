#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
 
int main() {
    int LCS_length = 0, max; //LCS length
    int **table; //LCS saved in this table
 
    
    int N;

    //set String
    cin >> N;
    vector <int> str2(N+1);
    for(int i = 0; i < N ; i++){
        cin >> str2[i+1];
    }
    vector<int> str1(str2);
    sort(str2.begin()+1, str2.end());
    // unique의 return값은 유일한 원소들이 끝나고 첫번째 쓰레기 원소가 나오는 곳의 위치
    vector<int>::iterator it = unique(str2.begin()+1,str2.end());
    str2.resize(it - str2.begin() ); // n
    


    int len1, len2;
    len1 = str1.size();
    len2 = str2.size();
 
    table = new int*[len2];
    for (int i = 0; i < len2; i++) {
        table[i] = new int[len1];
    }
 
    for (int i = 0; i < len1; i++) {
        table[0][i] = 0;
    }
 
    //Calculation Table Index and LCS Length
    for (int i = 1; i < len2; i++) {
        max = 0;
        table[i][0] = 0;
        for (int j = 1;j < len1; j++) {
            if (str2[i]== str1[j]){
                max = table[i-1][j - 1] + 1;
                table[i][j] = max;
            }
            else {
                if(table[i][j - 1] > table[i - 1][j])
                    table[i][j] = table[i][j-1];
                else
                    table[i ][j] = table[i-1][j];
            }
        }
        if (LCS_length < max)
            LCS_length = max;
    }
    cout << LCS_length;
 
    return 0;
}


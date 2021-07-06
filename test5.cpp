#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
int MIN = 0;
int n, m;//n이 집의 개수, m이 공유기 개수
vector<int> v;

bool f(int x) {
    //이제 여기에 조건을 확인하는 식을 넣으면 되는 거지??
    //여기서 x는 최소거리이다.
    //근데 최소거리를 허용해주니까....혹시나 그게 넘쳤을 떄에 그 최솟값을 저장해놔야 한다.
    int count = 1;
    int prev = 0;
    MIN = numeric_limits<int>::max();
    for (int i = 1; i < v.size(); ++i) {
        //서로의 차이를 계산
        //최소값을 만족하면 min과 prev, count를 update함.
        int dist = v[i]-v[prev];
        if(dist >= x){
            prev = i;
            count++;
            if(MIN > dist){
                MIN = dist;
                cout << x<<") "<<MIN << endl;
            }
        }
        if(count >= m) return true;
        cout <<"count"<< count << endl;
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int lo = 1, hi = v[v.size()-1]-v[0];
    while (lo + 1 != hi) {
        int mid = (lo + hi)/2;
        if (f(mid)) lo = mid;
        else hi = mid;
    }
    
    printf("%d\n",MIN);
}
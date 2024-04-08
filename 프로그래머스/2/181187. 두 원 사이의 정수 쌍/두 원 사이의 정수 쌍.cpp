#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long cnt = 0;
    
    // 전체
    for(int x=-r2;x<=r2;x++){
        int y = sqrt(pow(r2,2) - pow(x,2));
        cnt += (y*2+1); // 가운데점을 기준으로 
    }
    
    // 안쪽 원 빼기
    for(int x=-r1+1;x<r1;x++){
        int y = sqrt(pow(r1,2) - pow(x,2));
        cnt -= (y*2+1);
        
        // 근데 원점을 기준으로 y축에 있는 원 위에 있는 두 점은 포함시켜야 하므로
        if(pow(x,2)+pow(y,2) == pow(r1,2)){
            cnt += 2;
        }
    }
    
    return cnt;
}
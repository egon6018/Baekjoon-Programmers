#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> routes) {
    int camera = 1; // 기본 카메라 1대
    
    // 일단 routes[i][0]값을 기준으로 오름차순으로 정렬
    sort(routes.begin(), routes.end());
    // for(int i=0;i<routes.size();i++){
    //     cout << routes[i][0] << " " << routes[i][1] << "\n";
    // }
    
    int temp = routes[0][1]; // 0번째 차가 나갈때
    for(auto car : routes){                
        if(temp < car[0]){ //현재 차가 나갈때보다 뒤에 다음 차가 들어온다면          
            camera++;             
            temp = car[1]; // 나가는 지점 update
        }   
        
        if(temp >= car[1]){ // 현재 차보다 다음 차가 먼저 들어오면
            temp = car[1]; // 나가는 지점 update
        }    
    }
    
    return camera;
}
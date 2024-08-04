#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<string> a, vector<string> b){
    return a[1] < b[1]; 
    // 과제를 시작시간 순으로 정렬
    // (비교하려는 시작시간이 2번째 컬럼에 있으니까 a[1]이랑 b[1]을 비교)
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<string,int>> waitTesk; 
    // 진행중인 과제 <과제이름, 과제마치는데 걸리는시간>
    
    sort(plans.begin(), plans.end(), compare);
    // 과제를 시작시간 순으로 정렬
    
    int time = 0;
    
    for(vector<string> v : plans){        
        int newTime = 60*stoi(v[1].substr(0,2)) + stoi(v[1].substr(3,5));
        // 시간을 분으로 바꿔서 비교 (ex) 11:40 => 660+40=670, 12:10 => 720+10=730
        
        while( time < newTime ) {
            if(waitTesk.size() > 0 ){ // 진행중인 과제가 있다면
                waitTesk.back().second--; // 과제 남은시간--
                if(waitTesk.back().second == 0){ 
                    // 가장 최근에 멈춘 과제의 남은 시간이 없어 모두 끝났을경우 
                    answer.push_back(waitTesk.back().first);
                    // 과제를 끝낸 순서대로 answer에 push
                    waitTesk.pop_back();
                    // 과제를 끝냈기에 대기배열에서 pop
                }
            }
            time++;
        }  
        
        // 새로 시작해야하는 과제의 시간이 되면 
        waitTesk.push_back({v[0],stoi(v[2])}); 
        // 과제이름이랑 과제마치는데 걸리는 시간을 대기배열에 push
    }
    
    while(waitTesk.size() > 0){ // 대기중인 과제가 아직 남아있다면
        answer.push_back(waitTesk.back().first); 
        // 최근부터이니까 뒤에 있는 것부터 answer에 push
        waitTesk.pop_back();
    }
    
    return answer;
}
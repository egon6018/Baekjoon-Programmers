#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int,int> t; // <학생번호, 체육복개수>

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 초기세팅
    for(int i=1;i<=n;i++){
        t.insert({i,1});
    }    
    sort(lost.begin(), lost.end()); // 입력값이 학생번호 순서대로 입력 안될 수도 있음
    for(int i=0;i<lost.size();i++){
        t[lost[i]]--;
    }  
    for(int i=0;i<reserve.size();i++){
        t[reserve[i]]++;
    }
    // 여기까지 1:2벌, 2:0벌, 3:2벌, 4:0벌, 5:2벌
        
    for(int i=0;i<lost.size();i++){
        if(t[lost[i]] > 0){ // 만약 도난 당했는데, 여벌 옷을 가지고 있었을 경우
            continue;
        }
        
        if(t[lost[i]-1] > 1){ // 이전학생이 여벌을 가지고 있다면
            t[lost[i]-1]--;
            t[lost[i]]++;
        }
        else if(t[lost[i]+1] > 1){ // 이전학생이 여벌이 없으면 다음학생
            t[lost[i]+1]--;
            t[lost[i]]++;
        }
    }
    
    int answer = 0;
    for(auto it:t){
        if(it.second >= 1){
            answer++;
        }
    }
    return answer;
}
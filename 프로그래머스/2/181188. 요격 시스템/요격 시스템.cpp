#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v; // <e,s>

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    for(int i=0;i<(int)targets.size();i++){
        int s = targets[i][0];
        int e = targets[i][1];
        v.push_back({e,s});
    }
    
    sort(v.begin(),v.end()); // e가 빨리 끝나는 시점부터 오름차순으로
    
    int min_val = -1;
    for(int i=0;i<(int)v.size();i++){
        int e = v[i].first;
        int s = v[i].second;
        
        if(min_val <= s){ // s도 개구간으로 포함안되니까 
            answer++;
            min_val = e;
        }
    }
    
    return answer;
}
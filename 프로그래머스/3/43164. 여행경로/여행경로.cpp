#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define MAX_n 10000
using namespace std;

bool visited[MAX_n];
int ticket_cnt = 0;
bool finish = false;
vector<string> answer;

void DFS(string cur, vector<vector<string>> tickets){
    if(ticket_cnt == (int)tickets.size()){ // 주어진 항공권을 다 사용한 경우
        finish = true;
    }
    answer.push_back(cur);
    
    for(int i=0;i<(int)tickets.size();i++){
        string next_depart = tickets[i][0]; // 다음구간 출발공항
        
        // 방문했는지 행 별로 확인
        if(!visited[i] && next_depart == cur){ 
            // 다음구간 출발공항이 현재 도착공항인데, 아직 방문안한 구간이라면
            visited[i] = true;
            ticket_cnt++;
            
            string next_dest = tickets[i][1]; // 다음구간 도착공항
            DFS(next_dest, tickets);
            
            if(!finish){ // 주어진 항공권을 다 썼는데 만약 이제 길이 없다
                visited[i] = false;
                answer.pop_back();
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {  
    
    // 정렬 먼저 -> 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return하니까
    sort(tickets.begin(), tickets.end());
    
    DFS("ICN", tickets);
        
    return answer;
}
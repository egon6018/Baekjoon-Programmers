#include <string>
#include <vector>
#define MAX_n 200
using namespace std;

vector<int> edges[MAX_n+1];
bool visited[MAX_n];

void DFS(int cur_com){
    for(int i=0;i<(int)edges[cur_com].size();i++){
        int next_com = edges[cur_com][i];
        
        if(!visited[next_com]){
            visited[next_com] = true;
            DFS(next_com);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(computers[i][j]){
                edges[i].push_back(j);                
            }
        }
    }
        
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(i);
            answer++;
        }
    }
    
    return answer;
}
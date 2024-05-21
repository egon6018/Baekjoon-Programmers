#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#define MAX_nm 100
using namespace std;

int dr[4]={0,1,0,-1}; // 동,남,서,북
int dc[4]={1,0,-1,0}; // 동,남,서,북
queue<pair<int,int>> q;
int visited[MAX_nm+1][MAX_nm+1];

bool inRange(int r, int c, int n, int m){
    return (r>0) && (r<=n) && (c>0) && (c<=m);
}

void BFS(int n, int m, vector<vector<int>> maps){
    while(!q.empty()){
        int cur_r, cur_c;
        tie(cur_r, cur_c) = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];
            
            if(!inRange(next_r, next_c, n, m)){
                continue;
            }
            
            if(maps[next_r-1][next_c-1] && !visited[next_r][next_c]){
                visited[next_r][next_c] = visited[cur_r][cur_c] + 1;
                q.push({next_r, next_c});                
            }            
        }
    }
}


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    // nxm
    int n = maps.size();
    int m = maps[0].size();
    
    q.push({1,1});
    BFS(n,m,maps);
    
    if(visited[n][m]){
        answer = visited[n][m] + 1;
    }
    else{
        answer = -1;
    }
    
    return answer;
}
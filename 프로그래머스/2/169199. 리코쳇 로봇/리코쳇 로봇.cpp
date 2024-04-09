#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#define MAX_N 100
using namespace std;

int n,m; // n x m
queue<pair<int,int>> q;
int visited[MAX_N][MAX_N];
int answer = 0;

int dr[4]={0,1,0,-1}; // 동,남,서,북
int dc[4]={1,0,-1,0}; // 동,남,서,북

bool inRange(int cur_r, int cur_c, int n, int m){
    return (cur_r>=0) && (cur_r<n) && (cur_c>=0) && (cur_c<m);
}

void BFS(vector<string> board){
    while(!q.empty()){
        int cur_r, cur_c;
        tie(cur_r, cur_c) = q.front();
        q.pop();
        
        for(int dir=0;dir<4;dir++){
            int next_r = cur_r;
            int next_c = cur_c;
            
            while(true){
                if(!inRange(next_r, next_c, n, m)) { // 벽 만났을때
                    break; 
                }
                if(board[next_r][next_c] == 'D') { // 장애물 만났을 때
                    break; 
                }
                // 벽도 없고 장애물도 없으면 계속 한칸씩 전진(미끄러진다)
                next_r += dr[dir];
                next_c += dc[dir];
            }
            
            // 벽과 장애물을 만난 칸까지 전진한거니까 한칸 빼주기
            next_r -= dr[dir];
            next_c -= dc[dir];
            
            if(board[next_r][next_c] == 'G'){ // 목표지점을 만났다면 종료
                answer = visited[cur_r][cur_c];
                return;
            }
            
            if(visited[next_r][next_c]){ // 이미 방문한 적이 있다면
                continue;
            }
            
            visited[next_r][next_c] = visited[cur_r][cur_c] + 1;
            q.push({next_r, next_c});
        }  
    }
}

int solution(vector<string> board) {
    n = board.size();
    m = board[0].size();
    
    // "."은 빈 공간을, "R"은 로봇의 처음 위치를, "D"는 장애물의 위치를, "G"는 목표지점
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = 0; // 초기화
            if(board[i][j] == 'R') { // 출발점
                q.push({i,j});
                visited[i][j] = 1;
            }
        }
    }
    
    BFS(board);
    
    if(answer == 0){ // 탈출 못한 경우
        return -1;
    }
    else{
        return answer;
    }
}
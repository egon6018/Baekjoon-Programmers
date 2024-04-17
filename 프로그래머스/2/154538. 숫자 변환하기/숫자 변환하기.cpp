#include <string>
#include <vector>
#include <queue>
using namespace std;

int visited[1000001];
queue<int> q;

int solution(int x, int y, int n) {           
    q.push(x);
    while(!q.empty()){
        int cur = q.front();
        q.pop();        
        
        if(cur == y){
            return visited[cur]; // 처음부터 x==y일때
        }
        
        int dir[3]={cur+n, cur*2, cur*3};
        for(int i=0;i<3;i++){
            int next = dir[i];
            if(next>y || visited[next]){ // y를 넘어섰거나, 이미 방문했다면
                continue;
            }
            visited[next] = visited[cur] + 1;
            q.push(next);
        }
        
    }        
    
    return -1; // y로 만들 수 없다면
}
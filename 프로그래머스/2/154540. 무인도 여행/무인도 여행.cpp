#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

int n,m;
int maps_int[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int big_num;

int dr[4]={0,1,0,-1}; // 동,남,서,북
int dc[4]={1,0,-1,0}; // 동,남,서,북

bool inRange(int cur_r, int cur_c){
    return (cur_r>=0) && (cur_r<n) && (cur_c>=0) && (cur_c<m);
}

void DFS(int cur_r, int cur_c){    
    for(int i=0;i<4;i++){
        int next_r = cur_r + dr[i];
        int next_c = cur_c + dc[i];
        
        if(!inRange(next_r, next_c)) continue;
        
        if(maps_int[next_r][next_c] && !visited[next_r][next_c]){
            visited[next_r][next_c] = true;
            big_num += maps_int[next_r][next_c];
            DFS(next_r, next_c);
        }
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    n = maps.size();
    m = maps[0].size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j] == 'X'){
                maps_int[i][j] = 0;
            }
            else{
                maps_int[i][j] = maps[i][j]-'0';
            }
        }
    }
    
    
    bool is_island=false; // 지낼 수 있는 무인도가 없다
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps_int[i][j]){
                is_island=true;
            }           
        }
    }
    if(!is_island){ // 끝까지 탐색했는데 all 0이다 => -1리턴
        answer.push_back(-1);
        return answer;
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && maps_int[i][j]){
                big_num = 0;
                visited[i][j] = true;  
                big_num += maps_int[i][j];              
                DFS(i,j);
                answer.push_back(big_num);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
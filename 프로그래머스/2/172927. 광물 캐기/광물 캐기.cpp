// #include <string>
// #include <vector>

// using namespace std;

// int solution(vector<int> picks, vector<string> minerals) {
//     // 최소한의 피로도
//     // picks: dia, iron, stone 순서로
    
//     // 다이아 -> 철 -> 돌 곡괭이 순서로 캐는게 가장 최선의 방법 아닌가..?
//     // 반례: 피로도가 많이 드는 광물이 뒤에 위치한 경우
    
//     int cnt=0; // 광물 캔 횟수
//     int pick_idx=0;
//     int tired=0; // 피로도
//     for(int i=0;i<(int)minerals.size();i++){
//         if(picks[pick_idx] == 0){ // 해당 곡괭이 없음
//             pick_idx++; // 다음 곡괭이로
//             if(pick_idx > 2){ // 더이상 곡괭이 없으니까 종료
//                 break;
//             }
//             cnt=0; // 광물개수 다시 처음부터  
//         }   
        
//         if(minerals[i] == "diamond"){
//             if(pick_idx == 0){ // 다이아몬드 곡괭이
//                 tired += 1;                
//             } else if(pick_idx == 1){ // 철 곡괭이
//                 tired += 5;
//             } else if(pick_idx == 2){ // 돌 곡괭이
//                 tired += 25;
//             }            
//         } else if(minerals[i] == "iron"){
//             if(pick_idx == 2){ // 돌 곡괭이
//                 tired += 5;
//             } else{ // 다이아, 철 곡괭이
//                 tired += 1;
//             }
//         } else if(minerals[i] == "stone"){
//             tired += 1; 
//         }
        
//         cnt++;
//         if(cnt >= 5){ // 곡괭이 하나 선택해서 광물 5개를 연속으로 캔다
//             picks[pick_idx]--;
//             if(picks[pick_idx] == 0){
//                 pick_idx++;
//                 if(pick_idx > 2){ // 더이상 곡괭이 없으니까 종료
//                     break;
//                 }
//             }            
//             cnt=0;
//         }                      
//     }
            
//     return tired;
// }


#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

map<string, int>MineralList;                //광물들 이름
int AllList[3][3]={{1,1,1},{5,1,1},{25,5,1}}; // 각각 피로도


vector<int>MineralsIntList;

int ListSize=0;
int answer = 1250;

//5 개씩 광물을 캔다....
//곡갱이의 갯수 picks   >> [다이아곡갱이 갯수, 철곡갯수, 돌곡갯수]
// 광물들의 순서 minerals   >> [순서~~~]
// 최소의 피로도는?


// >>> dfs로 찾기 가능?

void dfs(vector<int> &picks, int location,int sum){ // 곡갱이들, 현재 위치
    int sumList[3]={0,}; // 피로도 저장
    int savePoint=0;
    
    if(ListSize<=location || picks[0]+picks[1]+picks[2]==0){// 끝까지가거나 곡갱이다씀
        
        answer=min(answer,sum);
        return;
    }
    
    
    for(int i=location;i<location+5;i++){
        
        if(i>=ListSize){
            savePoint=i;
            break;
        }
        sumList[0]+=AllList[0][MineralsIntList[i]];
        sumList[1]+=AllList[1][MineralsIntList[i]];
        sumList[2]+=AllList[2][MineralsIntList[i]];  // 각각의 곡갱이로 일을한것!
        
        savePoint=i;
    }
    
    
    
    for(int i=0;i<3;i++){//각각 출발
        if(picks[i]!=0){
            picks[i]-=1;
            dfs(picks,savePoint+1,sum+sumList[i]);
            picks[i]+=1;
        }
    }
    
    
}

int solution(vector<int> picks, vector<string> minerals) {
    
    
    MineralList["diamond"]=0; //단어 처리
    MineralList["iron"]=1;
    MineralList["stone"]=2;
    
    ListSize=minerals.size();
    
    //5개씩 나눠야되네!
    //그럼 5개씩 해서 해결피로도 구하면 되는거 아닌감?
    
    
    for(string i : minerals){
        MineralsIntList.push_back(MineralList[i]);
    }
    
    
    
    dfs(picks,0,0);
    
    
    return answer;
}

#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> mineral_idx; // <광물들 이름, 이름을 0,1,2로 설정>
int tired[3][3] = {{1,1,1}, {5,1,1}, {25,5,1}}; // 각 곡괭이별 피로도
int mineral_size; // 미네랄 리스트 개수
vector<int> mineral_int_list; // 주어진 minerals를 0,1,2로 변경(mineral_idx)하여 다시 저장

int answer = 1250; // 될 수 있는 최고피로도: 25*50

void DFS(vector<int> &picks, int cur, int tire_sum){ // cur:현재위치, tire_sum: 현재까지 쌓인 피로도
    
    int pick_tire[3]={0,}; // 곡괭이별 피로도 저장
    int save_point=0; 
    
    if(mineral_size<=cur || picks[0]+picks[1]+picks[2]==0){
        // 광물들을 다 캤거나, 모든 곡괭이가 더이상 남아있지 않다면 종료
        answer = min(answer, tire_sum);
        return;
    }
    
    for(int i=cur;i<cur+5;i++){ // 한 곡괭이별 광물 5개씩
        if(i>=mineral_size){ // 더이상 광물이 없으면
            save_point=i;
            break;
        }
        
        // 각 곡괭이별 피로도 저장
        pick_tire[0] += tired[0][mineral_int_list[i]];
        pick_tire[1] += tired[1][mineral_int_list[i]];
        pick_tire[2] += tired[2][mineral_int_list[i]];
        
        save_point=i;
    }
    
    for(int i=0;i<=2;i++){
        if(picks[i] != 0){
            picks[i] -= 1;
            DFS(picks, save_point+1, tire_sum+pick_tire[i]);
            picks[i] += 1; // 다음 케이스를 위해서
        }
    }    
}


int solution(vector<int> picks, vector<string> minerals) {
    // 최소한의 피로도
    // picks: dia, iron, stone 순서로
    
    // 다이아 -> 철 -> 돌 곡괭이 순서로 캐는게 가장 최선의 방법 아닌가..?
    // 반례: 피로도가 많이 드는 광물이 뒤에 위치한 경우
    
    mineral_idx["diamond"] = 0;
    mineral_idx["iron"] = 1;
    mineral_idx["stone"] = 2;
    
    mineral_size = minerals.size();
    
    for(string name: minerals){
        mineral_int_list.push_back(mineral_idx[name]);
    }
    
    DFS(picks, 0, 0);
    
    return answer;
    
    
    
// ----------------------------------------------------------    
//    int cnt=0; // 광물 캔 횟수
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
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int i,j,k;
    for(int cmd=0;cmd<(int)commands.size();cmd++){
        i = commands[cmd][0];
        j = commands[cmd][1];
        k = commands[cmd][2];
        
         // i번째부터 j번까지 추출  
        vector<int> out;
        for(int idx=i;idx<=j;idx++){
            out.push_back(array[idx-1]);
        }    
        // 정렬
        sort(out.begin(), out.end());      
    
        for(int idx=0;idx<(int)out.size();idx++){
            if(idx == k-1){
                answer.push_back(out[idx]);
                break;
            }
        }
    }
    
    return answer;
}
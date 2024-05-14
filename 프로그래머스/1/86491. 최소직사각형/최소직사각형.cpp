#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 10000

int max_first[MAX_N][MAX_N];

int solution(vector<vector<int>> sizes) {
    for(int i=0;i<sizes.size();i++){
        int max_val=0,min_val;
        max_val=max(max_val,sizes[i][0]);
        max_val=max(max_val,sizes[i][1]);
        
        if(max_val==sizes[i][0]){
            min_val=sizes[i][1];
        }
        else if(max_val==sizes[i][1]){
            min_val=sizes[i][0];
        }
        
        // w,h 둘중에 큰수를 왼쪽에
        sizes[i][0]=max_val;
        sizes[i][1]=min_val;
    }
    
    int max_w=0, max_h=0;
    for(int i=0;i<sizes.size();i++){        
        max_w = max(max_w, sizes[i][0]);
        max_h = max(max_h, sizes[i][1]);
    }
    
    return max_w*max_h;    
}
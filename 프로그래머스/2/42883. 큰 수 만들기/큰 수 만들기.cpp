#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    // 투포인터
    
    int start = 0;       
    int cnt = 0;
    int remain = number.size() - k;
    
    for(int i=0;i<remain;i++) {
        // 처음에는 시작지점이 최댓값이니까
        char max_num = number[start]; 
        int max_idx = start; 
        
        for(int j=start;j<=k+i;j++) { // start부터 k개
            if(max_num < number[j]) { 
                // 더 큰 값이 나오면 최댓값이랑 그때의 인덱스를 다시 설정
                max_num = number[j];
                max_idx = j;
            }
        }
        start = max_idx + 1; // 그 다음 시작지점은 최댓값인덱스 다음부터 찾으면 되니까
        answer += max_num;
    }
    
    return answer;
}
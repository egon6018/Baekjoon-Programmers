#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    // answer[0] = answer[1] = 0으로 초기화
    
    // 투포인터로 접근
    int s = 0; // 시작인덱스
    int e = 0; // 끝인덱스
    int sum = sequence[0]; // 첫번째 값으로 초기화
    int sublen = sequence.size() + 1; // 부분수열의 길이 초기화
    
    while(s<=e && e<sequence.size()){
        if(sum < k){
            e++;
            sum += sequence[e];
        }else if(sum == k){
            if(e-s+1 < sublen){ // 현재 부분수열길이값보다 작다면
                sublen = e-s+1;
                answer[0] = s;
                answer[1] = e;
            }else if(e-s+1 == sublen){ // 부분수열길이가 같다면 작은 인덱스부터
                if(answer[0] > s){
                    answer[0] = s;
                    answer[1] = e;
                }                
            }
            
            sum -= sequence[s]; // 또 있나 찾기 위해 다음 케이스로 이동 -> 가장 앞에껄 뺀다
            s++;
        }else{ // sum > k
            sum -= sequence[s]; // 가장 앞에껄 뺀다
            s++;
        }
    }
    
    

    return answer;
}
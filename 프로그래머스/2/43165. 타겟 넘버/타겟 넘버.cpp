#include <string>
#include <vector>
using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int idx){
    if(idx == numbers.size()){
        if(sum == target){
            answer++;
        }
        return;
    }
    
    // 더하거나 빼거나
    dfs(numbers, target, sum+numbers[idx], idx+1);
    dfs(numbers, target, sum-numbers[idx], idx+1);
}


int solution(vector<int> numbers, int target) {
    // 백트래킹인거 같은데
    dfs(numbers, target, 0, 0);            

    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    // 최소값끼리 또 묶기에는 예외상황 발생 가능 -> 최소값+최대값
    
    // 50 50 70 80
    int idx = 0;
    while(idx < people.size()){
        int back = people.back(); 
        people.pop_back();
        
        if(people[idx] + back <= limit){ 
            answer++; 
            idx++; // 그 다음 최솟값
        }
        else { 
            // limit를 넘어서면 그냥 몸무게 최대값의 사람 한명만 구명보트로 구출하면 되니까
            answer++;
        }
    }
    
    return answer;
}
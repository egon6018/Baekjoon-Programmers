#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size()); // answer의 크기를 numbers.size()로 미리 초기화
    
    // 자신보다 뒤에 있는 숫자 중, 자신보다 크면서 가장 가까이 있는 수 => 뒷 큰수
    
    // 뒤에서부터 접근해보자! => 당연히 맨 뒤에 있는 숫자는 뒤에 아무것도 없으니까 -1이 들어갈 것!
    stack<int> temp;
    for(int i=numbers.size()-1;i>=0;i--){
        while(true){            
            if(temp.empty()){ // 스택이 비어있으면 더 큰수가 없다는 뜻 
                answer[i] = -1;
                break;
            }
            
            if(temp.top() > numbers[i]){
                answer[i] = temp.top();
                break;
            }            
            temp.pop(); // 스택에 숫자가 있는데 나보다 큰수가 아니면 pop
        }
        
        temp.push(numbers[i]);
    }
    
    
    //----------------------------시간초과---------------------------------
    // int cur_idx=0; // 앞부터 시작
    // while(cur_idx < (int)numbers.size()){
    //     bool is_exist = false; // 자신보다 뒤에 있으면서 큰 수가 존재하는가
    //     for(int i=cur_idx+1;i<(int)numbers.size();i++){
    //         if(numbers[cur_idx] < numbers[i]){
    //             answer.push_back(numbers[i]);
    //             is_exist = true;
    //             break;
    //         }
    //     }
    //     if(!is_exist){
    //         answer.push_back(-1);
    //     }
    //     cur_idx++;
    // }
    
    
    return answer;
}
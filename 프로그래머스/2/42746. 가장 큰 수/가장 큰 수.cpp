#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b){ // 6이랑 10일때
    return a+b > b+a; // 610 > 106
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> temp;
    for(auto num:numbers){
        temp.push_back(to_string(num)); // 숫자->문자열로
    }
    
    sort(temp.begin(), temp.end(), cmp); // 문자열로 비교하여 내림차순으로    
        
    if (temp.at(0) == "0") { // 처음숫자가 0이라면 0을 리턴
        return "0";
    }        
    
    for(auto num:temp){
        answer += num;
    }    
    return answer;
}
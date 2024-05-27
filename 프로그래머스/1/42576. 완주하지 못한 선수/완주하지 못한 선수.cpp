#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string,int> p; // <참가자이름, 일단 참가했으면 1> 만약 동명이인이 있다면 2가 될 것임 => 나중에 완주자들은 0이 될 것임

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(int i=0;i<(int)participant.size();i++){
        if(p.find(participant[i]) != p.end()){ 
            // 만약 이미 참가자명단에 있다면 (동명이인)
            p[participant[i]]++;    
        }
        else{
            p.insert({participant[i], 1});
        }                
    }
    
    for(int i=0;i<(int)completion.size();i++){
        if(p.find(completion[i]) != p.end()){
            p[completion[i]]--;
        }
    }
    
    for(auto it:p){
        if(it.second > 0){
            // cout << it.first << " ";           
            
            // answer.push_back(it.first);
            // 위는 에러나는 이유: push_back 함수는 문자열 끝에 단일 문자를 추가하는 함수. 즉, string값을 push_back하는게 아니라 char값을 push_back함
            
            answer += it.first;
        }
    }
    
    return answer;
}
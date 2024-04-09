#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 약간 아리송한 문제

int reservate[25][61];

int solution(vector<vector<string>> book_time) {
    // book_time[i]는 ["HH:MM", "HH:MM"] 형태
    
    for(int i=0;i<(int)book_time.size();i++){
        int start_h = stoi(book_time[i][0].substr(0,2));
        int start_m = stoi(book_time[i][0].substr(3,2));
        int end_h = stoi(book_time[i][1].substr(0,2));
        int end_m = stoi(book_time[i][1].substr(3,2));
        end_m += 10; // 퇴실시간을 기준으로 10분간 청소한다고 했으니까
        
        if(end_m > 59){ // 만약 59분을 넘어가면 분->시
            end_h++;
            end_m -= 60;
        }
        
        for(int j=start_h;j<=end_h;j++) {
            for(int k=0;k<60;k++) {
                if(j == start_h) { // 시작시간일때
                    if(k < start_m)
                        continue;
                    
                }
                if(j == end_h) { // 끝시간일때
                    if(k >= end_m)
                        break;
                    
                }
                reservate[j][k]++; // 예약가능
            }
        }
    }
    
    int answer = 0;
    
    for(int i=0; i<24; i++) {
        for(int j=0; j<60; j++) {
            if(reservate[i][j] > answer)
                answer = reservate[i][j];
        }
    }
    
    return answer;
}
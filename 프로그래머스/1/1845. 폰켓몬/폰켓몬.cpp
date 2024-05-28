#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<int> pokemon;

int solution(vector<int> nums)
{
    
    int choice_cnt = (int)nums.size()/2;
    
    sort(nums.begin(), nums.end()); // 두번째 예제인 경우 [2,2,3,3,3,4]
    
    for(int i=0;i<(int)nums.size();i++){
        pokemon.insert(nums[i]); // [2,3,4]만 들어가게 될 것임
    }
    
    int cnt = 0;
    bool can_return = false;
    for(auto it:pokemon){
        if(cnt == choice_cnt){ // 포켓몬을 다 선택했다면
            can_return = true;
            return cnt;
        }
        cnt++;
    }
    
    if(!can_return){ 
        // return안하고 여기까지 왔다는 거는 
        //선택해야 하는 포켓몬 수보다 포켓몬 종료의 수가 더 적다는 뜻이니까
        return pokemon.size();
    }   
}
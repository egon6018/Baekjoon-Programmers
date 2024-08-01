# 물고기 종류 별로 가장 큰 물고기의 ID, 물고기 이름, 길이를 출력하는 SQL 문을 작성해주세요.
# 물고기의 ID 컬럼명은 ID, 이름 컬럼명은 FISH_NAME, 길이 컬럼명은 LENGTH로 해주세요.
# 결과는 물고기의 ID에 대해 오름차순 정렬해주세요.
# 단, 물고기 종류별 가장 큰 물고기는 1마리만 있으며 10cm 이하의 물고기가 가장 큰 경우는 없습니다.

select ID, FISH_NAME, LENGTH
from fish_info f inner join fish_name_info n
on f.fish_type = n.fish_type
where (f.fish_type, length) in ( select fish_type, max(length)
                              from fish_info
                              group by fish_type )
order by id asc;

## 아래처럼 하면 안되는 이유
## fish_type별로 가장 큰 물고기 한마리씩 여러row줄이 리턴될 것이기 때문에 에러남
## 따라서 fish_type, length 같이 묶어서 조건을 걸어야 함
## 하나의 row씩만 나오도록 (한 fish_type당 가장 큰 길이 하나)
# where length = ( select max(length)
#                  from fish_info
#                  group by fish_type )
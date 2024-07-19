# FISH_INFO 테이블에서 2021년도에 잡은 물고기 수를 출력하는 SQL 문을 작성해주세요.
# 이 때 컬럼명은 'FISH_COUNT' 로 지정해주세요.

select count(*) as FISH_COUNT
from fish_info
where time like '2021%';

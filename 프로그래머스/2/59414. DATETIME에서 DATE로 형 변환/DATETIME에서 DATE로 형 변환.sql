# ANIMAL_INS 테이블에 등록된 모든 레코드에 대해, 
# 각 동물의 아이디와 이름, 들어온 날짜를 조회하는 SQL문을 작성해주세요. 
# 이때 결과는 아이디 순으로 조회해야 합니다.

select ANIMAL_ID, NAME, substring(datetime, 1,10) as '날짜'
from animal_ins
order by animal_id;
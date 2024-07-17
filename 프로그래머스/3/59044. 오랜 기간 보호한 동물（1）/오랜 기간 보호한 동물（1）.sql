# 아직 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 이름과 
# 보호 시작일을 조회하는 SQL문을 작성해주세요. 
# 이때 결과는 보호 시작일 순으로 조회해야 합니다.


select i.NAME, i.DATETIME
from animal_ins i left join animal_outs o
on i.animal_id = o.animal_id
where o.animal_id is null
-- 아직 입양을 못갔으니까 ins테이블에만 있고, outs테이블에는 없을것
order by i.datetime
limit 3; -- 상위 3개의 데이터 추출







# -- 코드를 입력하세요
# SELECT I.NAME, I.DATETIME
# FROM ANIMAL_INS I LEFT OUTER JOIN ANIMAL_OUTS O
# ON I.ANIMAL_ID = O.ANIMAL_ID
# WHERE O.ANIMAL_ID IS NULL
# ORDER BY I.DATETIME
# LIMIT 3;
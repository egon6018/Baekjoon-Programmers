# 입양을 간 기록은 있는데, 보호소에 들어온 기록이 없는 동물의 ID와 이름을 ID 순으로 조회하는 SQL문을 작성해주세요.

select o.ANIMAL_ID, o.NAME
from animal_ins i right join animal_outs o
-- 입양을 간 기록은 있는데(outs에는 있는데), 보호소에 들어온 기록은 없는(ins에는 없는) 
on i.animal_id = o.animal_id
where i.animal_id is null
order by o.animal_id;










# -- 코드를 입력하세요
# SELECT O.ANIMAL_ID, O.NAME
# FROM ANIMAL_INS I RIGHT OUTER JOIN ANIMAL_OUTS O
# ON I.ANIMAL_ID = O.ANIMAL_ID
# WHERE I.ANIMAL_ID IS NULL
# ORDER BY O.ANIMAL_ID;
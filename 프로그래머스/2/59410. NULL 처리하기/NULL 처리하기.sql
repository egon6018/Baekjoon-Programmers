select ANIMAL_TYPE, ifnull(name, "No name") as NAME, SEX_UPON_INTAKE
from animal_ins
order by animal_id;












# -- 코드를 입력하세요
# SELECT ANIMAL_TYPE, IFNULL(NAME,"No name"), SEX_UPON_INTAKE
# FROM ANIMAL_INS
# ORDER BY ANIMAL_ID ASC;
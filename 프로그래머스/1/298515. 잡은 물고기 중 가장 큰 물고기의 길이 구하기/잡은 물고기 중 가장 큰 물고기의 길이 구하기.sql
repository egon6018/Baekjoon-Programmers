# FISH_INFO 테이블에서 잡은 물고기 중 가장 큰 물고기의 길이를 'cm' 를 붙여 출력하는 SQL 문을 작성해주세요.
# 이 때 컬럼명은 'MAX_LENGTH' 로 지정해주세요.

## 문자열을 이어붙일때에는 concat함수!
select concat(max(length),'cm') as MAX_LENGTH
from fish_info;
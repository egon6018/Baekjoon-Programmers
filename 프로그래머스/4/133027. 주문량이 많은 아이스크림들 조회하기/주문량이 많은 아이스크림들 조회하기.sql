select F.flavor as FLAVOR
from first_half F inner join july J
on F.flavor = J.flavor
group by F.flavor
order by sum(F.total_order)+sum(J.total_order) desc 
-- 상반기 아이스크림 총주문량+7월 아이스크림 총주문량 더한값이 큰 순서대로
limit 3; 
-- 상위 3개의 맛만 조회







# -- 코드를 입력하세요
# SELECT J.FLAVOR
# FROM FIRST_HALF F INNER JOIN JULY J
# ON F.FLAVOR = J.FLAVOR
# GROUP BY F.FLAVOR
# ORDER BY SUM(F.TOTAL_ORDER)+SUM(J.TOTAL_ORDER) DESC
# LIMIT 3;
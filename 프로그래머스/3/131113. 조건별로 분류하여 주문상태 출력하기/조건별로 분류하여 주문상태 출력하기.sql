# FOOD_ORDER 테이블에서 
# 2022년 5월 1일을 기준으로 주문 ID, 제품 ID, 출고일자, 출고여부를 조회하는 SQL문을 작성해주세요. 
# 출고여부는 2022년 5월 1일까지 출고완료로 이 후 날짜는 출고 대기로 미정이면 출고미정으로 출력해주시고, 결과는 주문 ID를 기준으로 오름차순 정렬해주세요.


select ORDER_ID, PRODUCT_ID, substring(OUT_DATE,1,10),
    case
        when date_format(out_date, '%Y-%m-%d') <= '2022-05-01' then '출고완료'
        when out_date is null then '출고미정'
    else '출고대기'
    end as 출고여부
from food_order
order by order_id;










# -- 코드를 입력하세요
# SELECT ORDER_ID, PRODUCT_ID, SUBSTRING(OUT_DATE, 1, 10), 
#         CASE
#             WHEN (MONTH(OUT_DATE) < '05') or (MONTH(OUT_DATE) <= '05' and DAY(OUT_DATE) <= '01') THEN '출고완료'
#             WHEN (MONTH(OUT_DATE) > '05') or (MONTH(OUT_DATE) >= '05' and DAY(OUT_DATE) > '01') THEN '출고대기'
#             WHEN OUT_DATE IS NULL THEN '출고미정'
#         END AS 출고여부
# FROM FOOD_ORDER
# ORDER BY ORDER_ID;
# FOOD_PRODUCT 테이블에서 가격이 제일 비싼 식품의 식품 ID, 식품 이름, 식품 코드, 식품분류, 식품 가격을 조회하는 SQL문을 작성해주세요.

select PRODUCT_ID, PRODUCT_NAME, PRODUCT_CD, CATEGORY, PRICE
from food_product
where price = ( select max(price)
                from food_product )








# -- 코드를 입력하세요
# SELECT *
# FROM FOOD_PRODUCT
# WHERE PRICE = (SELECT MAX(PRICE)
#             FROM FOOD_PRODUCT
#             );
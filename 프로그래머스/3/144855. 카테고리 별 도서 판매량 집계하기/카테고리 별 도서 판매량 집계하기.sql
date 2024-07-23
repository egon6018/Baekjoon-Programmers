# 2022년 1월의 카테고리 별 도서 판매량을 합산하고, 카테고리(CATEGORY), 총 판매량(TOTAL_SALES) 리스트를 출력하는 SQL문을 작성해주세요.
# 결과는 카테고리명을 기준으로 오름차순 정렬해주세요.

select CATEGORY, sum(sales) as TOTAL_SALES
from book inner join book_sales
on book.book_id = book_sales.book_id
where date_format(sales_date, '%Y-%m') = '2022-01'
group by category
order by category;
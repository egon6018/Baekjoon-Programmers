# 2022년 1월의 도서 판매 데이터를 기준으로 저자 별,카테고리 별 매출액(TOTAL_SALES = 판매량 * 판매가) 을 구하여, 저자 ID(AUTHOR_ID),저자명(AUTHOR_NAME),카테고리(CATEGORY),매출액(SALES) 리스트를 출력하는 SQL문을 작성해주세요.
# 결과는 저자 ID를 오름차순으로, 저자 ID가 같다면 카테고리를 내림차순 정렬해주세요.

select book.AUTHOR_ID, author.AUTHOR_NAME, book.CATEGORY, sum(book_sales.sales*book.price) as TOTAL_SALES
from book 
inner join author
on book.author_id = author.author_id
inner join book_sales
on book.book_id = book_sales.book_id
where date_format(book_sales.sales_date, "%Y-%m") = '2022-01'
group by book.author_id, book.category
order by book.author_id asc, book.category desc;
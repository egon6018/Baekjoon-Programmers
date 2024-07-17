# '경제' 카테고리에 속하는 도서들의 도서 ID(BOOK_ID), 저자명(AUTHOR_NAME), 출판일(PUBLISHED_DATE) 리스트를 출력하는 SQL문을 작성해주세요.
# 결과는 출판일을 기준으로 오름차순 정렬해주세요.

select book.BOOK_ID, author.AUTHOR_NAME, substring(book.PUBLISHED_DATE,1,10) as PUBLISHED_DATE
from book inner join author
on book.author_id = author.author_id
where book.category = '경제'
order by book.published_date; 











# -- 코드를 입력하세요
# SELECT B.BOOK_ID, A.AUTHOR_NAME, SUBSTRING(B.PUBLISHED_DATE, 1, 10) AS PUBLISHED_DATE
# FROM BOOK B INNER JOIN AUTHOR A
# ON B.AUTHOR_ID = A.AUTHOR_ID
# WHERE B.CATEGORY = '경제'
# ORDER BY B.PUBLISHED_DATE;
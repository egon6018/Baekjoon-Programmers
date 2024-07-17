# USED_GOODS_BOARD와 USED_GOODS_USER 테이블에서 
# 중고 거래 게시물을 3건 이상 등록한 사용자의 사용자 ID, 닉네임, 전체주소, 전화번호를 조회하는 SQL문을 작성해주세요. 
# 이때, 전체 주소는 시, 도로명 주소, 상세 주소가 함께 출력되도록 해주시고, 전화번호의 경우 xxx-xxxx-xxxx 같은 형태로 하이픈 문자열(-)을 삽입하여 출력해주세요. 
# 결과는 회원 ID를 기준으로 내림차순 정렬해주세요.

select u.USER_ID, u.NICKNAME, 
        concat(u.city,' ',u.street_address1,' ',u.street_address2) as '전체주소',
        concat(substring(u.tlno,1,3),'-',substring(u.tlno,4,4),'-',substring(u.tlno,8,4)) as '전화번호'
        -- 문자열을 합칠때에는 concat함수!!
from used_goods_board b inner join used_goods_user u
on b.writer_id = u.user_id
group by b.writer_id
having count(*) >= 3
-- where count(b.board_id) >= 3 => 사용불가! 
-- 집계함수는 group by와 함께 사용되며 having절에서 사용가능!
order by u.user_id desc;









# -- 코드를 입력하세요
# SELECT U.USER_ID, U.NICKNAME, CONCAT_ws(' ', U.CITY, U.STREET_ADDRESS1, U.STREET_ADDRESS2) AS 전체주소, CONCAT(SUBSTRING(U.TLNO, 1, 3), '-', SUBSTRING(U.TLNO, 4,4), '-', SUBSTRING(U.TLNO, 8,4)) AS 전화번호
# FROM USED_GOODS_BOARD B INNER JOIN USED_GOODS_USER U
# ON B.WRITER_ID = U.USER_ID
# GROUP BY B.WRITER_ID
# HAVING COUNT(B.WRITER_ID) >= 3
# ORDER BY U.USER_ID DESC;
# MEMBER_PROFILE와 REST_REVIEW 테이블에서 리뷰를 가장 많이 작성한 회원의 리뷰들을 조회하는 SQL문을 작성해주세요. 
# 회원 이름, 리뷰 텍스트, 리뷰 작성일이 출력되도록 작성해주시고, 
# 결과는 리뷰 작성일을 기준으로 오름차순, 리뷰 작성일이 같다면 리뷰 텍스트를 기준으로 오름차순 정렬해주세요.

select m.MEMBER_NAME, r.REVIEW_TEXT, substring(r.REVIEW_DATE,1,10) as REVIEW_DATE
from member_profile m inner join rest_review r
on m.member_id = r.member_id
where m.member_id = ( select member_id 
                      from rest_review
                      group by member_id
                      order by count(*) desc limit 1 )
-- 리뷰를 제일 많이 작성한 회원을 찾아주기 위해 => 서브쿼리 이용, 
-- member_id별로 그룹지어서 개수를 세서 내림차순으로 정렬한 다음 상위 멤버 한명만 뽑아낸다
order by r.review_date, r.review_text;
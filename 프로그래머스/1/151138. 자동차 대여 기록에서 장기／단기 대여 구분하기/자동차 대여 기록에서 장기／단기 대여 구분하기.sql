# CAR_RENTAL_COMPANY_RENTAL_HISTORY 테이블에서 
# 대여 시작일이 2022년 9월에 속하는 대여 기록에 대해서 대여 기간이 30일 이상이면 '장기 대여' 그렇지 않으면 '단기 대여' 로 표시하는 컬럼(컬럼명: RENT_TYPE)을 추가하여 대여기록을 출력하는 SQL문을 작성해주세요. 
# 결과는 대여 기록 ID를 기준으로 내림차순 정렬해주세요.

select HISTORY_ID, CAR_ID, substring(START_DATE,1,10) as START_DATE, substring(END_DATE,1,10) as END_DATE, 
    case 
        when datediff(end_date,start_date) + 1 >= 30 then '장기 대여'
        -- datediff(날짜1, 날짜2) => 날짜1 - 날짜2
        -- +1을 하는 이유는 2022-09-01~2022-09-30인 경우 1일부터 30일이니까 30일인건데
        -- datediff를 하면 30-1=29가 되니까 꼭 +1해줘야 함!!        
        else '단기 대여'
    end as RENT_TYPE
from car_rental_company_rental_history 
where date_format(start_date, '%Y-%m') = '2022-09'
order by history_id desc;
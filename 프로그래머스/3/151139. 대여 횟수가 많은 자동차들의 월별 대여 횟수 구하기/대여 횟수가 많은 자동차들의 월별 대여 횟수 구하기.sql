# CAR_RENTAL_COMPANY_RENTAL_HISTORY 테이블에서 
# 대여 시작일을 기준으로 2022년 8월부터 2022년 10월까지 
# 총 대여 횟수가 5회 이상인 자동차들에 대해서 
# 해당 기간 동안의 월별 자동차 ID 별 총 대여 횟수(컬럼명: RECORDS) 리스트를 출력하는 SQL문을 작성해주세요. 
# 결과는 월을 기준으로 오름차순 정렬하고, 
# 월이 같다면 자동차 ID를 기준으로 내림차순 정렬해주세요. 
# 특정 월의 총 대여 횟수가 0인 경우에는 결과에서 제외해주세요.

select month(start_date) as MONTH, CAR_ID, count(history_id) as RECORDS
# '월'만 출력해야되니까 month()
from car_rental_company_rental_history
where start_date >= "2022-08-01" and start_date < "2022-11-01"
      and car_id in ( select car_id # 리스트 출력
                      from car_rental_company_rental_history
                      where start_date >= "2022-08-01" and start_date < "2022-11-01"
                      group by car_id
                      having count(history_id) >= 5 # 총 대여횟수가 5회 이상인 것들
                    )
group by month, car_id 
# 월별, 자동차ID별 
having records > 0 
# 총 대여횟수가 0인 경우는 결과에서 제외. 대여횟수가 최소 한번 이상인거를 출력
order by month asc, car_id desc;
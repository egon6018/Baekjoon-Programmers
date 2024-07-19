# AIR_POLLUTION 테이블에서 수원 지역의 연도 별 평균 미세먼지 오염도와 평균 초미세먼지 오염도를 조회하는 SQL문을 작성해주세요. 
# 이때, 평균 미세먼지 오염도와 평균 초미세먼지 오염도의 컬럼명은 각각 PM10, PM2.5로 해 주시고, 값은 소수 셋째 자리에서 반올림해주세요.
# 결과는 연도를 기준으로 오름차순 정렬해주세요.

select year(ym) as 'YEAR', 
-- substring(ym,1,4)로 하면 틀림 => 이유는 이렇게하면 string으로 반환되니깐
-- year(ym)으로 해야 number로 반환됨
       round(avg(pm_val1), 2) as 'PM10', round(avg(pm_val2), 2) as 'PM2.5'
from air_pollution 
where location2 = '수원' 
group by year 
order by year;











# select year(ym) as YEAR, round(avg(pm_val1),2) as PM10, round(avg(pm_val2),2) as 'PM2.5'
# from air_pollution
# where location2 = '수원'
# group by year(ym)
# order by year(ym);
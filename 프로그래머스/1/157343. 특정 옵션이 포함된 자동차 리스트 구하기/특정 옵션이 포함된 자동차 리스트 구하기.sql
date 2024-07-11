select *
from car_rental_company_car
where options like '%네비게이션%' # '네비게이션'옵션이 포함된
order by car_id desc;
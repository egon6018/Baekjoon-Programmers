select 
    case
        when date_format(differentiation_date, '%m') in ('01', '02', '03') then '1Q'
        when date_format(differentiation_date, '%m') in ('04', '05', '06') then '2Q'
        when date_format(differentiation_date, '%m') in ('07', '08', '09') then '3Q'
        when date_format(differentiation_date, '%m') in ('10', '11', '12') then '4Q'
    end as QUARTER,
    count(*) as ECOLI_COUNT
from ecoli_data
group by QUARTER
order by QUARTER
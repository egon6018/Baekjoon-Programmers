select ed2.id as ID, ed2.genotype as GENOTYPE, ed1.genotype as PARENT_GENOTYPE
from ecoli_data ed1 inner join ecoli_data ed2 -- ed1:부모, ed2:자식
on ed1.id = ed2.parent_id
where ed1.genotype & ed2.genotype = ed1.genotype -- 2진수이므로 비트연산
order by ed2.id;

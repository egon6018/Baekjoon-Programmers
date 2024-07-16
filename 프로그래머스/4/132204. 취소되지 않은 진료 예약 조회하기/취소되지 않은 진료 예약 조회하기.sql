# PATIENT, DOCTOR 그리고 APPOINTMENT 테이블에서 
# 2022년 4월 13일 취소되지 않은 흉부외과(CS) 진료 예약 내역을 조회하는 SQL문을 작성해주세요. 진료예약번호, 환자이름, 환자번호, 진료과코드, 의사이름, 진료예약일시 항목이 출력되도록 작성해주세요. 결과는 진료예약일시를 기준으로 오름차순 정렬해주세요.

select a.APNT_NO, p.PT_NAME, p.PT_NO, a.MCDP_CD, d.DR_NAME, a.APNT_YMD
from appointment a 
inner join patient p on a.pt_no = p.pt_no
inner join doctor d on a.mddr_id = d.dr_id
where date_format(a.apnt_ymd, '%Y-%m-%d') = '2022-04-13' 
and a.mcdp_cd = 'CS'
and a.apnt_cncl_yn = 'N'
order by a.apnt_ymd;




# SELECT AP.APNT_NO, P.PT_NAME, AP.PT_NO, AP.MCDP_CD, D.DR_NAME, AP.APNT_YMD
# FROM APPOINTMENT AP 
# JOIN DOCTOR D ON D.DR_ID = AP.MDDR_ID
# JOIN PATIENT P ON P.PT_NO = AP.PT_NO
# WHERE AP.APNT_CNCL_YMD IS NULL AND AP.MCDP_CD = 'CS' AND AP.APNT_YMD LIKE '2022-04-13%'
# ORDER BY AP.APNT_YMD
select board_id, writer_id, title, price,
    case
        when status = 'SALE' then '판매중'
        when status = 'RESERVED' then '예약중'
        when status = 'DONE' then '거래완료'
    end as status
from used_goods_board
where created_date = '2022-10-05'
order by board_id desc;







# -- 코드를 입력하세요
# SELECT B.BOARD_ID, B.WRITER_ID, B.TITLE, B.PRICE,
#         CASE
#             WHEN B.STATUS = 'SALE' THEN '판매중'
#             WHEN B.STATUS = 'RESERVED' THEN '예약중'
#             WHEN B.STATUS = 'DONE' THEN '거래완료'
#         END AS STATUS
# FROM USED_GOODS_BOARD B
# WHERE DATE_FORMAT(CREATED_DATE, '%y-%m-%d') = '22-10-05'
# ORDER BY B.BOARD_ID DESC;
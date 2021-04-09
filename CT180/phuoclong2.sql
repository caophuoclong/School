--3

select * 
from ktrucsu
where hoten_kts like '%le%'
and nams_kts = 1956;

-- 4
select * from cgtrinh;
select cg.ten_ctr, cg.ngay_bd from
cgtrinh cg
WHERE to_date(cg.ngay_bd,'mon-dd-yyyy') between to_date('09-01-1994','mm-dd-yyyy') and to_date('10-20-1994','mm-dd-yyyy')
;

-- 5

select ten_ctr, diachi_ctr from cgtrinh
where ten_thau = 'cty xd so 6'
;

-- 6

select distinct ct.ten_thau, ct.dchi_thau
from chuthau ct join cgtrinh cg on ct.ten_thau = cg.ten_thau join thietke tk on cg.stt_ctr = tk.stt_ctr
where tinh_thanh = 'can tho' and tk.hoten_kts = 'le kim dung';

-- 7
SELECT KTS.HOTEN_KTS, KTS.NOI_TN 
FROM KTRUCSU KTS JOIN THIETKE TK ON KTS.HOTEN_KTS = TK.HOTEN_KTS JOIN CGTRINH CG ON TK.STT_CTR = CG.STT_CTR
WHERE CG.TEN_CTR = 'khach san quoc te' and cg.tinh_thanh = 'can tho';

--8
SELECT CN.HOTEN_CN, CN.NAMS_CN, CN.NAM_VAO_N
FROM CONGNHAN CN JOIN THAMGIA TG ON TG.HOTEN_CN = CN.HOTEN_CN JOIN CGTRINH CG ON CG.STT_CTR=TG.STT_CTR
WHERE (CN.CH_MON = 'han' or CN.CH_MON = 'dien') and TEN_THAU = 'le van son';

-- 9
select * from cgtrinh;
select * from thamgia;
select cn.hoten_cn, tg.ngay_tgia, tg.so_ngay
from congnhan cn join thamgia tg on cn.hoten_cn=tg.hoten_cn join cgtrinh cg on cg.stt_ctr=tg.stt_ctr
where cg.ten_ctr='khach san quoc te' and cg.tinh_thanh = 'can tho'
and tg.ngay_tgia >= 'dec-15-1994' and tg.so_ngay <= 16 ;


-- 10
select cg.ten_ctr, cg.diachi_ctr, tg.ngay_tgia
from cgtrinh cg join thamgia tg on cg.stt_ctr=tg.stt_ctr join congnhan cn on cn.hoten_cn=tg.hoten_cn
where cn.hoten_cn = 'nguyen hong van' and tg.ngay_tgia + tg.so_ngay >= to_date('18-12-1994','dd-mm-yyyy');


-- 11
select * from thietke;
select kts.hoten_kts, kts.nams_kts
from ktrucsu kts join thietke tk on kts.hoten_kts = tk.hoten_kts join cgtrinh cg on cg.stt_ctr = tk.stt_ctr
where kts.noi_tn = 'tp hcm' and cg.kinh_phi > 400;


--12
select tk.hoten,ten_ctr from cgtrinh cg join thietke tk on tk.stt_ctr=cg.stt_ctr;
select tk.hoten_kts
from thietke tk join cgtrinh cg on cg.stt_ctr=tk.stt_ctr
where cg.ten_thau like 'le van son' 
intersect 
select tk.hoten_kts  
from thietke tk join cgtrinh cg on cg.stt_ctr=tk.stt_ctr
where cg.ten_thau like 'cty xd so 6';

-- 13
select * from cgtrinh;
select cg.ten_ctr, cg.diachi_ctr, cg.kinh_phi from cgtrinh cg
where cg.kinh_phi = (select max(cg.kinh_phi) 
from cgtrinh cg)
;
-- 14

select kts.hoten_kts, kts.nams_kts from ktrucsu kts
where kts.nams_kts = (select max(kts.nams_kts) from ktrucsu kts);

-- 15
select * from cgtrinh;
select * from thamgia;
select * from cgtrinh cg join thamgia tg on cg.stt_ctr=tg.stt_ctr;
select * from cgtrinh cg join thamgia cn on cg.stt_ctr=cn.stt_ctr;

select tg.hoten_cn, cg.tinh_thanh
from thamgia tg join cgtrinh cg on tg.stt_ctr=cg.stt_ctr
where cg.tinh_thanh='can tho'; 
select tg.hoten_cn, cg.tinh_thanh from thamgia tg join cgtrinh cg on tg.stt_ctr=cg.stt_ctr;
minus
(
select tg.hoten_cn, cg.tinh_thanh
from thamgia tg join cgtrinh cg on tg.stt_ctr=cg.stt_ctr
where cg.tinh_thanh='vinh long');
select tg.hoten_cn, cg.tinh_thanh
from thamgia tg join cgtrinh cg on tg.stt_ctr=cg.stt_ctr
where cg.tinh_thanh='vinh long';

-- 20

select cg.ten_ctr, count(*) from cgtrinh cg join thamgia tg on cg.stt_ctr=tg.stt_ctr join congnhan cn on cn.hoten_cn=tg.hoten_cn group by cg.ten_ctr;











































































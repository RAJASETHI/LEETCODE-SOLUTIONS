# Write your MySQL query statement below
select product_id,product_name  from(select p.product_id,p.product_name,s.sale_date  from Product  as p inner join Sales  as s on s.product_id=p.product_id group by s.product_id having min(sale_date) Between 
"2019-01-01" and "2019-03-31" and max(s.sale_date) Between 
"2019-01-01" and "2019-03-31")as T;
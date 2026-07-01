# Write your MySQL query statement below
select p.product_name , pp.year ,pp.price from Product p
join Sales pp
on p.product_id=pp.product_id
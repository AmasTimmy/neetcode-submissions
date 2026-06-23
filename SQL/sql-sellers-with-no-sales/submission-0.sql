SELECT s.seller_name from seller s
WHERE s.seller_id NOT IN (
    SELECT o.seller_id FROM orders o
    WHERE o.sale_date BETWEEN '2020-01-01' AND '2020-12-31'
)
ORDER BY s.seller_name ASC
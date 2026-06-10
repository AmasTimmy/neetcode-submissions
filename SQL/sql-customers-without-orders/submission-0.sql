-- Write your query below
SELECT c.name from customers c
LEFT JOIN orders o on c.id = o.customer_id
where o.customer_id is NULL
🔹 1. UNION – Combine and Remove Duplicates

Use Case: When combining data from multiple sources and you want only unique records.

SELECT email FROM customers
UNION
SELECT email FROM newsletter_subscribers;

Result: All unique emails from both sources.

📝 Note: Slower than UNION ALL because it removes duplicates.
🔹 2. UNION ALL – Combine and Keep All

Use Case: When performance matters and duplicates are acceptable or expected.

SELECT product_id FROM online_orders
UNION ALL
SELECT product_id FROM store_orders;

Result: All product IDs from both sources, duplicates included.

✅ Faster than UNION.
🔹 3. JOINs (INNER, LEFT, etc.) – Combine Based on Relationship

Use Case: When you need to merge rows from two or more tables based on a common column.

SELECT o.order_id, c.name, o.total
FROM orders o
INNER JOIN customers c ON o.customer_id = c.customer_id;

Result: Orders matched with customer names.

📝 Joins are great for data enrichment.
🔹 4. Subqueries – Use Query Inside a Query

Use Case: When you need a temporary dataset for filtering, transformation, or lookups.

SELECT name FROM products
WHERE product_id IN (
    SELECT product_id FROM order_items WHERE quantity > 10
);

Result: Products that were ordered in quantities greater than 10.
🔹 5. CTEs (Common Table Expressions) – Clean, Modular Query Building

Use Case: When you want readable, step-by-step queries, often for analytics.

WITH high_spenders AS (
    SELECT customer_id, SUM(total) AS total_spent
    FROM orders
    GROUP BY customer_id
    HAVING SUM(total) > 1000
)
SELECT c.name, h.total_spent
FROM high_spenders h
JOIN customers c ON h.customer_id = c.customer_id;

Result: Names of customers who spent more than $1000.


????
✅ Easier to maintain and optimize.
🔹 6. Materialized Views or Pre-aggregated Tables (advanced optimization)

Use Case: When you run heavy analytics repeatedly and want faster query execution.

-- Create a materialized view for monthly sales
CREATE MATERIALIZED VIEW monthly_sales AS
SELECT product_id, toStartOfMonth(order_date) AS month, SUM(total) AS total_sales
FROM orders
GROUP BY product_id, month;

Now instead of querying the big orders table each time, you query the smaller monthly_sales.

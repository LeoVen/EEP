-- 1 --
SELECT * FROM Products;

-- 2 --
SELECT
	ProductName,
	UnitPrice,
	UnitsInStock
FROM Products;

-- 3 --
SELECT *
FROM Products
ORDER BY ProductName ASC;

-- 4 --
SELECT *
FROM Products
WHERE UnitPrice < 10;

-- 5 --
SELECT *
FROM Products
WHERE
	UnitPrice > 5 AND
	UnitsInStock = 0
ORDER BY ProductName ASC;

-- 6 --
SELECT *
FROM Products
WHERE ProductName LIKE 'M%'
ORDER BY ProductName;

-- 7 --
SELECT
	p.ProductName,
	p.UnitPrice,
	c.CategoryName
FROM Products p
	INNER JOIN Categories c
		ON p.CategoryID = c.CategoryID
ORDER BY
	p.UnitPrice DESC,
	p.ProductName ASC;

-- 8 --
SELECT
	p.ProductName,
	p.UnitPrice,
	c.CategoryName,
	s.CompanyName
FROM Products p
	INNER JOIN Categories c
		ON p.CategoryID = c.CategoryID
	INNER JOIN Suppliers s
		ON p.SupplierID = s.SupplierID
ORDER BY p.UnitPrice DESC;

-- 9 --
SELECT
	c.CategoryID,
	c.CategoryName,
	COUNT(*) as Total
FROM Products p
	INNER JOIN Categories c
		ON (c.CategoryID = p.CategoryID)
GROUP BY
	c.CategoryID,
	c.CategoryName;

SELECT
	c.CategoryId,
	c.CategoryName,
	(SELECT COUNT(*)
		FROM Products p
		WHERE p.CategoryID = c.CategoryID
	) as Total
FROM Categories c;

-- 10 --
SELECT
	c.CategoryID,
	c.CategoryName,
	AVG(p.UnitPrice) as Average
FROM Products p
	INNER JOIN Categories c
		ON (c.CategoryID = p.CategoryID)
GROUP BY
	c.CategoryID,
	c.CategoryName;

-- 11 --
SELECT
	c.CategoryID,
	c.CategoryName,
	COUNT(*) as Total
FROM Products p
INNER JOIN Categories c
	ON (c.CategoryID = p.CategoryID)
GROUP BY
	c.CategoryID,
	c.CategoryName
HAVING COUNT(*) > 10;

-- 12 --

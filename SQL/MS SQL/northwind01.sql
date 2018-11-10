/**
 * @file northwind01.sql
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 *
 * @date 20/10/2018	
 */

-- ////////////////////////////////////////////////////////////////////////////
SELECT * FROM Products
WHERE CategoryID = 2 and SupplierID = 3;
-- ////////////////////////////////////////////////////////////////////////////

-- ////////////////////////////////////////////////////////////////////////////
SELECT * from Products WHERE CategoryID = 2 ORDER BY ProductName;
-- ////////////////////////////////////////////////////////////////////////////

-- ////////////////////////////////////////////////////////////////////////////
SELECT COUNT(*) FROM Products;
-- ////////////////////////////////////////////////////////////////////////////

-- ////////////////////////////////////////////////////////////////////////////
SELECT MAX(UnitPrice) as "Max", MIN(UnitPrice) as "Min"
FROM Products
WHERE CategoryID = 2;
-- ////////////////////////////////////////////////////////////////////////////

-- ////////////////////////////////////////////////////////////////////////////
SELECT SUM(UnitPrice)
FROM Products;
-- ////////////////////////////////////////////////////////////////////////////

-- ////////////////////////////////////////////////////////////////////////////
SELECT
	CategoryID,
	ProductName,
	UnitPrice,
	UnitsInStock,
	(UnitPrice * UnitsInStock)
		as TotalStockPrice
FROM Products
ORDER BY UnitsInStock DESC;
-- ////////////////////////////////////////////////////////////////////////////

-- ////////////////////////////////////////////////////////////////////////////
SELECT
	CategoryID,
	COUNT(*) as Total
FROM Products
GROUP BY CategoryID;
-- ////////////////////////////////////////////////////////////////////////////

-- ////////////////////////////////////////////////////////////////////////////
SELECT
	CategoryID,
	COUNT(*)
		as Total,
	MAX(UnitPrice)
		as MaximumPrice
FROM Products
GROUP BY CategoryID;
-- ////////////////////////////////////////////////////////////////////////////

/**
 * @file northwind02.sql
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 *
 * @date 10/11/2018	
 */

-- ////////////////////////////////////////////////////////////////////////////
SELECT ProductName, CategoryName, CompanyName
FROM Products,
	 Categories,
	 Suppliers
WHERE products.CategoryID = Categories.CategoryID
	  AND Products.SupplierID = Suppliers.SupplierID;

SELECT ProductName, CategoryName
FROM Products
	INNER JOIN Categories on Products.CategoryID = Categories.CategoryID
	INNER JOIN Suppliers on Products.SupplierID = Suppliers.SupplierID;
-- ////////////////////////////////////////////////////////////////////////////

-- ////////////////////////////////////////////////////////////////////////////
SELECT p.ProductID, o.OrderID
FROM Products p
	LEFT JOIN [Order Details] o
	ON p.ProductID = o.ProductID;

SELECT MAX(o.UnitPrice)
FROM [Order Details] o
WHERE o.ProductID = 25;
-- ////////////////////////////////////////////////////////////////////////////

-- ////////////////////////////////////////////////////////////////////////////
SELECT ProductId,
	   ProductName,
	   UnitPrice,
	   (
	   SELECT MAX(o.UnitPrice)
	   FROM [Order Details] o
	   WHERE o.ProductID = p.ProductId
	   ) as MaxUnitPrice
FROM Products p;
-- ////////////////////////////////////////////////////////////////////////////

-- ////////////////////////////////////////////////////////////////////////////
SELECT o.ProductId, 
	   MAX(o.UnitPrice) as MaxUnitPrice
FROM [Order Details] o
GROUP BY o.ProductID;
-- ////////////////////////////////////////////////////////////////////////////

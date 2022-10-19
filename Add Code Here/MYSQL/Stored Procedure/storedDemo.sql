--The following SQL statement creates a stored procedure named "SelectAllCustomers" that selects all records from the "Customers" table:

CREATE PROCEDURE SelectAllCustomers
AS
SELECT * FROM Customers
GO;

-- Execute the stored procedure above as follows:

EXEC SelectAllCustomers;

-- Stored Procedure With One Parameter: The following SQL statement creates a stored procedure that selects Customers from a particular City from the "Customers" table:

CREATE PROCEDURE SelectAllCustomers @City nvarchar(30)
AS
SELECT * FROM Customers WHERE City = @City
GO;

--Execute the stored procedure above as follows:

EXEC SelectAllCustomers @City = 'London';

--Stored Procedure With Multiple Parameters : Setting up multiple parameters is very easy. Just list each parameter and the data type separated by a comma as shown below.

--The following SQL statement creates a stored procedure that selects Customers from a particular City with a particular PostalCode from the "Customers" table:

CREATE PROCEDURE SelectAllCustomers @City nvarchar(30), @PostalCode nvarchar(10)
AS
SELECT * FROM Customers WHERE City = @City AND PostalCode = @PostalCode
GO;

--Execute the stored procedure above as follows:

EXEC SelectAllCustomers @City = 'London', @PostalCode = 'WA1 1DP';

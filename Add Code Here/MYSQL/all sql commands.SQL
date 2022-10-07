-- SQL SELECT Statement
    SELECT column1, column2, ...
    FROM table_name;

    SELECT * FROM table_name;
    SELECT CustomerName, City FROM Customers;

-- SQL SELECT DISTINCT Statement
    SELECT DISTINCT column1, column2, ...
    FROM table_name;

    SELECT DISTINCT Country FROM Customers;

    SELECT COUNT(DISTINCT Country) FROM Customers;

-- SQL WHERE Clause
    SELECT column1, column2, ...
    FROM table_name
    WHERE condition;
    -- (==, > , < , >= , <= , <> , BETWEEN , LIKE , IN)

    SELECT * FROM Customers
    WHERE Country='Mexico';

    WHERE CustomerID=1;

    WHERE Price BETWEEN 50 AND 60;

    WHERE Contry LIKE 's%'

    WHERE City IN ('Paris','London');

-- The SQL AND, OR and NOT Operators
    SELECT column1, column2, ...
    FROM table_name
    WHERE condition1 AND condition2 AND condition3 ...;
    WHERE condition1 OR condition2 OR condition3 ...;
    WHERE NOT condition;

    SELECT * FROM Customers
    WHERE Country='Germany' AND City='Berlin';

    WHERE City='Berlin' OR City='München';

    WHERE Country='Germany' OR Country='Spain';

    WHERE NOT Country='Germany';

    WHERE Country='Germany' AND (City='Berlin' OR City='München');

    WHERE NOT Country='Germany' AND NOT Country='USA';

-- SQL ORDER BY Keyword
    SELECT * FROM Customers
    ORDER BY Country;

    ORDER BY Country DESC;

    ORDER BY Country, CustomerName;

    ORDER BY Country ASC, CustomerName DESC;

-- SQL INSERT INTO Statement
    INSERT INTO table_name (column1, column2, column3, ...)
    VALUES (value1, value2, value3, ...);

    INSERT INTO table_name
    VALUES (value1, value2, value3, ...);

    INSERT INTO Customers (CustomerName, ContactName, Address, City, PostalCode, Country)
    VALUES ('Cardinal', 'Tom B. Erichsen', 'Skagen 21', 'Stavanger', '4006', 'Norway');

    INSERT INTO Customers (CustomerName, City, Country)
    VALUES ('Cardinal', 'Stavanger', 'Norway');

-- SQL NULL Values
    SELECT column_names
    FROM table_name
    WHERE column_name IS NULL;

    WHERE column_name IS NOT NULL;

    SELECT CustomerName, ContactName, Address
    FROM Customers
    WHERE Address IS NULL;

    WHERE Address IS NOT NULL;

-- SQL UPDATE Statement
    UPDATE table_name
    SET column1 = value1, column2 = value2, ...
    WHERE condition;

    UPDATE Customers
    SET ContactName = 'Alfred Schmidt', City= 'Frankfurt'
    WHERE CustomerID = 1;

    SET ContactName='Juan'
    WHERE Country='Mexico';

    -- Be careful when updating records. If you omit the WHERE clause, ALL records will be updated!
    UPDATE Customers
    SET ContactName='Juan';

-- SQL DELETE Statement
    DELETE FROM table_name WHERE condition;

    DELETE FROM Customers WHERE CustomerName='Alfreds Futterkiste';
    -- The following SQL statement deletes all rows in the "Customers" table, without deleting the table:
    DELETE FROM table_name;

-- SQL TOP, LIMIT, FETCH FIRST or ROWNUM Clause
    SELECT TOP number|percent column_name(s)
    FROM table_name
    WHERE condition;

    SELECT column_name(s)
    FROM table_name
    WHERE condition
    LIMIT number;

    SELECT column_name(s)
    FROM table_name
    ORDER BY column_name(s)
    FETCH FIRST number ROWS ONLY;

    SELECT column_name(s)
    FROM table_name
    WHERE ROWNUM <= number;

    SELECT TOP 3 * FROM Customers;

    SELECT * FROM Customers
    LIMIT 3;

    SELECT * FROM Customers
    FETCH FIRST 3 ROWS ONLY;

    SELECT TOP 50 PERCENT * FROM Customers;

    SELECT * FROM Customers
    FETCH FIRST 50 PERCENT ROWS ONLY;

    SELECT TOP 3 * FROM Customers
    WHERE Country='Germany';

    SELECT * FROM Customers
    WHERE Country='Germany'
    LIMIT 3;

    SELECT * FROM Customers
    WHERE Country='Germany'
    FETCH FIRST 3 ROWS ONLY;

-- SQL MIN() and MAX() Functions
    SELECT MIN(column_name)       |  SELECT MAX(column_name)
    FROM table_name               |  FROM table_name
    WHERE condition;              |  WHERE condition;

    SELECT MIN(Price) AS SmallestPrice   |  SELECT MAX(Price) AS LargestPrice
    FROM Products;                       |  FROM Products;

-- SQL COUNT(), AVG() and SUM() Functions
    SELECT COUNT(column_name) |  SELECT AVG(column_name)  |  SELECT SUM(column_name)
    FROM table_name           |  FROM table_name          |  FROM table_name
    WHERE condition;          |  WHERE condition;         |  WHERE condition;

    SELECT COUNT(ProductID) | SELECT AVG(Price)  | SELECT SUM(Quantity)
    FROM Products;          | FROM Products;     | FROM OrderDetails;
   
-- The SQL LIKE Operator
    SELECT column1, column2, ...
    FROM table_name
    WHERE columnN LIKE pattern;

    LIKE  |   Operator	             |   Description
    WHERE | CustomerName LIKE 'a%'	 |  Finds any values that start with "a"
    WHERE | CustomerName LIKE '%a'	 |  Finds any values that end with "a"
    WHERE | CustomerName LIKE '%or%' | 	Finds any values that have "or" in any position
    WHERE | CustomerName LIKE '_r%'	 |  Finds any values that have "r" in the second position
    WHERE | CustomerName LIKE 'a_%'	 |  Finds any values that start with "a" and are at least 2 characters in length
    WHERE | CustomerName LIKE 'a__%' | 	Finds any values that start with "a" and are at least 3 characters in length
    WHERE | ContactName LIKE 'a%o'	 |  Finds any values that start with "a" and ends with "o"

    SELECT * FROM Customers
    WHERE CustomerName LIKE 'a%';

    WHERE CustomerName LIKE '%a';

    WHERE CustomerName LIKE '%or%';

    WHERE CustomerName LIKE '_r%';

    WHERE CustomerName LIKE 'a__%';

    WHERE ContactName LIKE 'a%o';

    WHERE CustomerName NOT LIKE 'a%';

-- SQL Wildcards
    Symbol	| Description                                                |	Example
    * , %	| Represents zero or more characters                         |  bl*,bl% finds bl, black, blue, and blob
    ? , _	| Represents a single character                              |	h?t,h_t finds hot, hat, and hit
    []	    | Represents any single character within the brackets        |  h[oa]t finds hot and hat, but not hit
    ! , ^	| Represents any character not in the brackets               |  h[!oa]t(h[^oa]t) finds hit, but not hot and hat
    -	    | Represents any single character within the specified range |  c[a-b]t finds cat and cbt
    #	    | Represents any single numeric character                    |  2#5 finds 205, 215, 225, 235, 245, 255, 265, 275, 285, and 295

    SELECT * FROM Customers
    WHERE City LIKE 'ber%';

    WHERE City LIKE '%es%';

    WHERE City LIKE '_ondon';

    WHERE City LIKE 'L_n_on';

    WHERE City LIKE '[bsp]%';

    WHERE City LIKE '[a-c]%';

    WHERE City LIKE '[!bsp]%';

    WHERE City NOT LIKE '[bsp]%';

-- SQL IN Operator
    SELECT column_name(s)                       |  SELECT column_name(s)       
    FROM table_name                             |  FROM table_name
    WHERE column_name IN (value1, value2, ...); |  WHERE column_name IN (SELECT STATEMENT);                            

    SELECT * FROM Customers
    WHERE Country IN ('Germany', 'France', 'UK');
    WHERE Country NOT IN ('Germany', 'France', 'UK');
    WHERE Country IN (SELECT Country FROM Suppliers);

-- SQL BETWEEN Operator
    SELECT column_name(s)
    FROM table_name
    WHERE column_name BETWEEN value1 AND value2;

    SELECT * FROM Products          |  SELECT * FROM Products   
    WHERE Price BETWEEN 10 AND 20;  |  WHERE Price NOT BETWEEN 10 AND 20;

    SELECT * FROM Products
    WHERE Price BETWEEN 10 AND 20
    AND CategoryID NOT IN (1,2,3);

    SELECT * FROM Products
    WHERE ProductName BETWEEN 'Carnarvon Tigers' AND 'Mozzarella di Giovanni'
    ORDER BY ProductName;

    SELECT * FROM Products
    WHERE ProductName BETWEEN "Carnarvon Tigers" AND "Chef Anton's Cajun Seasoning"
    ORDER BY ProductName;

    SELECT * FROM Products
    WHERE ProductName NOT BETWEEN 'Carnarvon Tigers' AND 'Mozzarella di Giovanni'
    ORDER BY ProductName;

    SELECT * FROM Orders
    WHERE OrderDate BETWEEN #07/01/1996# AND #07/31/1996#;

    SELECT * FROM Orders
    WHERE OrderDate BETWEEN '1996-07-01' AND '1996-07-31';

-- SQL Aliases
    SELECT column_name AS alias_name  |  SELECT column_name(s)
    FROM table_name;                  |  FROM table_name AS alias_name;

    SELECT CustomerID AS ID, CustomerName AS Customer
    FROM Customers;

    -- It requires double quotation marks or square brackets if the alias name contains spaces:
    SELECT CustomerName AS Customer, ContactName AS [Contact Person]
    FROM Customers;
    -- The following SQL statement creates an alias named "Address" that combine four columns (Address, PostalCode, City and Country):
    SELECT CustomerName, Address + ', ' + PostalCode + ' ' + City + ', ' + Country AS Address
    FROM Customers;

    SELECT CustomerName, CONCAT(Address,', ',PostalCode,', ',City,', ',Country) AS Address
    FROM Customers;

    SELECT o.OrderID, o.OrderDate, c.CustomerName
    FROM Customers AS c, Orders AS o
    WHERE c.CustomerName='Around the Horn' AND c.CustomerID=o.CustomerID;

    SELECT Orders.OrderID, Orders.OrderDate, Customers.CustomerName
    FROM Customers, Orders
    WHERE Customers.CustomerName='Around the Horn' AND Customers.CustomerID=Orders.CustomerID;

-- SQL Joins
    SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate
    FROM Orders
    INNER JOIN Customers ON Orders.CustomerID=Customers.CustomerID;

        (INNER) JOIN:  Returns records that have matching values in both tables
    LEFT (OUTER) JOIN:  Returns all records from the left table, and the matched records from the right table
    RIGHT (OUTER) JOIN:  Returns all records from the right table, and the matched records from the left table
    FULL (OUTER) JOIN:  Returns all records when there is a match in either left or right table

    SELECT Orders.OrderID, Customers.CustomerName
    FROM Orders
    INNER JOIN Customers ON Orders.CustomerID = Customers.CustomerID;

    --inner join
        SELECT Orders.OrderID, Customers.CustomerName, Shippers.ShipperName
        FROM ((Orders
        INNER JOIN Customers ON Orders.CustomerID = Customers.CustomerID)
        INNER JOIN Shippers ON Orders.ShipperID = Shippers.ShipperID);

    --left join
        SELECT Customers.CustomerName, Orders.OrderID
        FROM Customers
        LEFT JOIN Orders ON Customers.CustomerID = Orders.CustomerID
        ORDER BY Customers.CustomerName;

    --right join
        SELECT Orders.OrderID, Employees.LastName, Employees.FirstName
        FROM Orders
        RIGHT JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID
        ORDER BY Orders.OrderID;

    --outer join
        SELECT Customers.CustomerName, Orders.OrderID
        FROM Customers
        FULL OUTER JOIN Orders ON Customers.CustomerID=Orders.CustomerID
        ORDER BY Customers.CustomerName;

    --self join
        SELECT A.CustomerName AS CustomerName1, B.CustomerName AS CustomerName2, A.City
        FROM Customers A, Customers B
        WHERE A.CustomerID <> B.CustomerID
        AND A.City = B.City
        ORDER BY A.City;

-- SQL UNION Operator
    SELECT column_name(s) FROM table1    | SELECT column_name(s) FROM table1
    UNION                                | UNION ALL
    SELECT column_name(s) FROM table2;   | SELECT column_name(s) FROM table2; 

    SELECT City FROM Customers           | SELECT City FROM Customers
    UNION                                | UNION ALL
    SELECT City FROM Suppliers           | SELECT City FROM Suppliers
    ORDER BY City;                       | ORDER BY City;

    SELECT City, Country FROM Customers  | SELECT City, Country FROM Customers
    WHERE Country='Germany'              | WHERE Country='Germany'
    UNION                                | UNION ALL
    SELECT City, Country FROM Suppliers  | SELECT City, Country FROM Suppliers
    WHERE Country='Germany'              | WHERE Country='Germany'
    ORDER BY City;                       | ORDER BY City;

-- SQL GROUP BY Statement
    SELECT column_name(s)
    FROM table_name
    WHERE condition
    GROUP BY column_name(s)
    ORDER BY column_name(s);

    SELECT COUNT(CustomerID), Country
    FROM Customers
    GROUP BY Country;

    ORDER BY COUNT(CustomerID) DESC;

    SELECT Shippers.ShipperName, COUNT(Orders.OrderID) AS NumberOfOrders FROM Orders
    LEFT JOIN Shippers ON Orders.ShipperID = Shippers.ShipperID
    GROUP BY ShipperName;

-- SQL HAVING Clause
    SELECT column_name(s)
    FROM table_name
    WHERE condition
    GROUP BY column_name(s)
    HAVING condition
    ORDER BY column_name(s);

    SELECT COUNT(CustomerID), Country
    FROM Customers
    GROUP BY Country
    HAVING COUNT(CustomerID) > 5;

    ORDER BY COUNT(CustomerID) DESC;

    SELECT Employees.LastName, COUNT(Orders.OrderID) AS NumberOfOrders
    FROM (Orders
    INNER JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID)
    GROUP BY LastName
    HAVING COUNT(Orders.OrderID) > 10;

-- SQL EXISTS Operator
    SELECT column_name(s)
    FROM table_name
    WHERE EXISTS
    (SELECT column_name FROM table_name WHERE condition);

    SELECT SupplierName
    FROM Suppliers
    WHERE EXISTS (SELECT ProductName FROM Products WHERE Products.SupplierID = Suppliers.supplierID AND Price < 20);

    SELECT SupplierName
    FROM Suppliers
    WHERE EXISTS (SELECT ProductName FROM Products WHERE Products.SupplierID = Suppliers.supplierID AND Price = 22);

-- SQL ANY and ALL Operators

    SELECT column_name(s)           | SELECT column_name(s)                                           
    FROM table_name                 | FROM table_name                                         
    WHERE column_name operator ANY  | WHERE column_name operator ALL                                          
      (SELECT column_name           |   (SELECT column_name                                     
      FROM table_name               |   FROM table_name                                           
      WHERE condition);             |   WHERE condition);                                         

    
    SELECT ProductName       | SELECT ProductName        |  SELECT ProductName                                      
    FROM Products            | FROM Products             |  FROM Products                                    
    WHERE ProductID = ANY    | WHERE ProductID = ANY     |  WHERE ProductID = ANY                                    
      (SELECT ProductID      |   (SELECT ProductID       |    (SELECT ProductID                                    
      FROM OrderDetails      |   FROM OrderDetails       |    FROM OrderDetails                                    
      WHERE Quantity = 10);  |   WHERE Quantity > 99);   |    WHERE Quantity > 1000);                                  

    SELECT ALL ProductName   | SELECT ProductName                                          
    FROM Products            | FROM Products                       
    WHERE TRUE;              | WHERE ProductID = ALL           
                             |  (SELECT ProductID       
                             |  FROM OrderDetails           
                             |   WHERE Quantity = 10);   
                             |            

-- SQL SELECT INTO Statement  
    SELECT *
    INTO newtable [IN externaldb]
    FROM oldtable
    WHERE condition;                       

    SELECT column1, column2, column3, ...
    INTO newtable [IN externaldb]
    FROM oldtable
    WHERE condition;

    SELECT * INTO CustomersBackup2017
    FROM Customers;

    SELECT * INTO CustomersBackup2017 IN 'Backup.mdb'
    FROM Customers;

    SELECT CustomerName, ContactName INTO CustomersBackup2017
    FROM Customers;

    SELECT * INTO CustomersGermany
    FROM Customers
    WHERE Country = 'Germany';

    SELECT Customers.CustomerName, Orders.OrderID
    INTO CustomersOrderBackup2017
    FROM Customers
    LEFT JOIN Orders ON Customers.CustomerID = Orders.CustomerID;

    SELECT * INTO newtable
    FROM oldtable
    WHERE 1 = 0;

-- SQL INSERT INTO SELECT Statement
    INSERT INTO table2
    SELECT * FROM table1
    WHERE condition;

    INSERT INTO table2 (column1, column2, column3, ...)
    SELECT column1, column2, column3, ...
    FROM table1
    WHERE condition;

    INSERT INTO Customers (CustomerName, City, Country)
    SELECT SupplierName, City, Country FROM Suppliers;

    INSERT INTO Customers (CustomerName, ContactName, Address, City, PostalCode, Country)
    SELECT SupplierName, ContactName, Address, City, PostalCode, Country FROM Suppliers;

    INSERT INTO Customers (CustomerName, City, Country)
    SELECT SupplierName, City, Country FROM Suppliers
    WHERE Country='Germany';

-- SQL CASE Expression
    CASE
        WHEN condition1 THEN result1
        WHEN condition2 THEN result2
        WHEN conditionN THEN resultN
        ELSE result
    END;

    SELECT OrderID, Quantity,
    CASE
        WHEN Quantity > 30 THEN 'The quantity is greater than 30'
        WHEN Quantity = 30 THEN 'The quantity is 30'
        ELSE 'The quantity is under 30'
    END AS QuantityText
    FROM OrderDetails;

    SELECT CustomerName, City, Country
    FROM Customers
    ORDER BY
    (CASE
        WHEN City IS NULL THEN Country
        ELSE City
    END);

-- SQL IFNULL(), ISNULL(), COALESCE(), and NVL()
    SELECT ProductName, UnitPrice * (UnitsInStock + UnitsOnOrder)
    FROM Products;

    -- MySQL
        SELECT ProductName, UnitPrice * (UnitsInStock + IFNULL(UnitsOnOrder, 0))
        FROM Products;

        SELECT ProductName, UnitPrice * (UnitsInStock + COALESCE(UnitsOnOrder, 0))
        FROM Products;

    -- SQL Server
        SELECT ProductName, UnitPrice * (UnitsInStock + IIF(IsNull(UnitsOnOrder), 0, UnitsOnOrder))
        FROM Products;

        SELECT ProductName, UnitPrice * (UnitsInStock + COALESCE(UnitsOnOrder, 0))
        FROM Products;

    -- MS Access
        SELECT ProductName, UnitPrice * (UnitsInStock + IIF(IsNull(UnitsOnOrder), 0, UnitsOnOrder))
        FROM Products;

    -- Oracle
        SELECT ProductName, UnitPrice * (UnitsInStock + NVL(UnitsOnOrder, 0))
        FROM Products;

        SELECT ProductName, UnitPrice * (UnitsInStock + COALESCE(UnitsOnOrder, 0))
        FROM Products;

-- SQL Stored Procedures for SQL Server
    CREATE PROCEDURE procedure_name |  CREATE PROCEDURE SelectAllCustomers @City nvarchar(30)                                       
    AS                              |  AS                                                               
    sql_statement                   |  SELECT * FROM Customers WHERE City = @City                                   
    GO;                             |  GO;                                                              

    EXEC procedure_name;            |  EXEC SelectAllCustomers @City = 'London';


    CREATE PROCEDURE SelectAllCustomers @City nvarchar(30), @PostalCode nvarchar(10)
    AS
    SELECT * FROM Customers WHERE City = @City AND PostalCode = @PostalCode
    GO;     

    EXEC SelectAllCustomers @City = 'London', @PostalCode = 'WA1 1DP';  

-- SQL Comments
    SINGLE LINE COMMENT(--)
    MULTI LINE COMMENT (/* ...  */)

-- SQL Operators
    -- Arithmetic Operators
    Operator  |	Description 
    +	      |  Add	
    -	      |  Subtract	
    *	      |  Multiply	
    /	      |  Divide	
    %	      |  Modulo
    -- Bitwise Operators
    Operator  |   Description
    &	      | Bitwise AND
    |	      | Bitwise OR
    ^	      | Bitwise exclusive OR
    
    -- Logical Operators
    Operator |                     Description	
    ALL	     | TRUE if all of the subquery values meet the condition	
    AND	     | TRUE if all the conditions separated by AND is TRUE	
    ANY	     | TRUE if any of the subquery values meet the condition	
    BETWEEN	 | TRUE if the operand is within the range of comparisons	
    EXISTS	 | TRUE if the subquery returns one or more records	
    IN	     | TRUE if the operand is equal to one of a list of expressions	
    LIKE	 | TRUE if the operand matches a pattern	
    NOT	     | Displays a record if the condition(s) is NOT TRUE	
    OR	     | TRUE if any of the conditions separated by OR is TRUE	
    SOME	 | TRUE if any of the subquery values meet the condition


___________________________________________________________________________________________________________


-- SQL CREATE DATABASE Statement
    CREATE DATABASE databasename;

    CREATE DATABASE testDB;
    SHOW DATABASES;

-- SQL DROP DATABASE Statement
    DROP DATABASE databasename;
    DROP DATABASE testDB;

-- SQL BACKUP DATABASE for SQL Server
    BACKUP DATABASE databasename
    TO DISK = 'filepath';

    BACKUP DATABASE databasename  |  BACKUP DATABASE testDB                        
    TO DISK = 'filepath'          |  TO DISK = 'D:\backups\testDB.bak';    
    WITH DIFFERENTIAL;                 

-- SQL CREATE TABLE Statement
    CREATE TABLE table_name (
        column1 datatype,
        column2 datatype,
        column3 datatype,
    ....
    );           

    CREATE TABLE Persons (        |   CREATE TABLE TestTable AS                              
        PersonID int,             |   SELECT customername, contactname                  
        LastName varchar(255),    |   FROM customers;                                            
        FirstName varchar(255),   |                              
        Address varchar(255),     |                            
        City varchar(255)         |                        
    );

-- SQL DROP TABLE Statement
    DROP TABLE table_name;   
    -- Be careful before dropping a table. Deleting a table will result in loss of complete information stored in the table!
    DROP TABLE Shippers;
    -- The TRUNCATE TABLE statement is used to delete the data inside a table, but not the table itself.
    TRUNCATE TABLE table_name;

-- SQL ALTER TABLE Statement
    ALTER TABLE table_name     |  ALTER TABLE table_name            
    ADD column_name datatype;  |  DROP COLUMN column_name;                
                            |
    ALTER TABLE Customers      |  ALTER TABLE Customers       
    ADD Email varchar(255);    |  DROP COLUMN Email;         

    ALTER TABLE Persons                      
    ALTER COLUMN DateOfBirth year;                 
  
-- SQL Constraints
        NOT NULL -     Ensures that a column cannot have a NULL value
        UNIQUE -       Ensures that all values in a column are different
        PRIMARY KEY -  A combination of a NOT NULL and UNIQUE. Uniquely identifies each row in a table
        FOREIGN KEY -  Prevents actions that would destroy links between tables
        CHECK -        Ensures that the values in a column satisfies a specific condition
        DEFAULT -      Sets a default value for a column if no value is specified
        CREATE INDEX - Used to create and retrieve data from the database very quickly

    -- NOT NULL
        CREATE TABLE Persons (
            ID int NOT NULL,
            LastName varchar(255) NOT NULL,
            FirstName varchar(255) NOT NULL,
            Age int
        );

    -- UNIQUE
        CREATE TABLE Persons (
            ID int NOT NULL UNIQUE,
            LastName varchar(255) NOT NULL,
            FirstName varchar(255),
            Age int
        );

    -- PRIMARY KEY
        CREATE TABLE Persons (
            ID int NOT NULL,
            LastName varchar(255) NOT NULL,
            FirstName varchar(255),
            Age int,
            PRIMARY KEY (ID)
        );

    -- FOREIGN KEY
        CREATE TABLE Orders (
            OrderID int NOT NULL,
            OrderNumber int NOT NULL,
            PersonID int,
            PRIMARY KEY (OrderID),
            FOREIGN KEY (PersonID) REFERENCES Persons(PersonID)
        );

    -- CHECK
        CREATE TABLE Persons (
            ID int NOT NULL,
            LastName varchar(255) NOT NULL,
            FirstName varchar(255),
            Age int,
            CHECK (Age>=18)
        );

    -- DEFAULT
        CREATE TABLE Persons (
            ID int NOT NULL,
            LastName varchar(255) NOT NULL,
            FirstName varchar(255),
            Age int,
            City varchar(255) DEFAULT 'Sandnes'
        );

    -- CREATE INDEX
        CREATE INDEX index_name
        ON table_name (column1, column2, ...);

        CREATE INDEX idx_pname
        ON Persons (LastName, FirstName);

-- SQL AUTO INCREMENT Field
    CREATE TABLE Persons (                    |  CREATE TABLE Persons (                                 
        Personid int NOT NULL AUTO_INCREMENT, |      Personid int NOT NULL AUTO_INCREMENT = 100,                                                           
        LastName varchar(255) NOT NULL,       |      LastName varchar(255) NOT NULL,                                                           
        FirstName varchar(255),               |      FirstName varchar(255),                                                           
        Age int,                              |      Age int,                                                           
        PRIMARY KEY (Personid)                |      PRIMARY KEY (Personid)                                                           
    );                                        |  );        

-- SQL Working With Dates
    DATE -      format: YYYY-MM-DD
    DATETIME -  format: YYYY-MM-DD HH:MI:SS
    TIMESTAMP - format: YYYY-MM-DD HH:MI:SS
    YEAR -      format: YYYY or YY

    SELECT * FROM Orders WHERE OrderDate='2008-11-11'

-- SQL Views
    CREATE VIEW view_name AS
    SELECT column1, column2, ...
    FROM table_name
    WHERE condition;

    CREATE VIEW [Brazil Customers] AS
    SELECT CustomerName, ContactName
    FROM Customers
    WHERE Country = 'Brazil';

    -- DROP VIEW view_name;
    DROP VIEW [Brazil Customers];









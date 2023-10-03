SELECT ROUND(SUM(tiv_2016),2) as tiv_2016 
FROM Insurance 
WHERE tiv_2015 IN
  (SELECT tiv_2015 
  FROM Insurance 
  GROUP BY tiv_2015
  HAVING COUNT(tiv_2015) > 1)
AND NOT (lat,lon) IN 
  (
    SELECT lat,lon
    FROM Insurance
    GROUP BY lat,lon
    HAVING COUNT(1) > 1
  )
SELECT dept.departmentname, employee_summary.count_employees
FROM (SELECT count(DISTINCT employeeid) AS "count_employees",departmentid
FROM employees GROUP BY departmentid) AS employee_summary
INNER JOIN
department as dept
ON dept.departmentid::varchar = employee_summary.departmentid
ORDER BY employee_summary.count_employees DESC;
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N - 1;
  RETURN (
      select DISTINCT salary from Employee
      order by salary desc limit n, 1
  );
END
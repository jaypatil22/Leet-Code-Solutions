# Write your MySQL query statement below
SELECT DISTINCT(a.Email) FROM Person as a JOIN Person as b where a.id != b.id and a.Email = b.Email;
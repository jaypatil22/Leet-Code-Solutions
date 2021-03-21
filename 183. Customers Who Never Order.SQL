# Write your MySQL query statement below
select  c.Name as Customers from Customers c where c.Id<> All(select o.CustomerId from Orders o);
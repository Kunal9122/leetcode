select name as Customers
from Orders o
right join Customers c on c.id = o.customerId
where customerId is null
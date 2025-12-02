
with B as(
    select users_id from Users where banned = 'Yes'
),
A as (
    select t.* from Trips t where client_id not in (select users_id from B) and driver_id not in (select users_id from B) and t.request_at between "2013-10-01" and "2013-10-03"
)

select request_at as Day, round(sum(status like "cancelled%")/count(*), 2) as "Cancellation Rate" from A group by request_at having count(*)>=1
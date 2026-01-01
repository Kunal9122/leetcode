# Write your MySQL query statement below
select distinct l.book_id, title, author, genre,publication_year, total_copies as current_borrowers
from library_books l
join borrowing_records using(book_id)
where return_date is null
group by 1
having count(*)=total_copies
order by 6 desc, 2


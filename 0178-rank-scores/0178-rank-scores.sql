# Write your MySQL query statement below
SELECT SCORE,
    DENSE_RANK() over( ORDER BY SCORE DESC) AS `rank`
    from Scores;

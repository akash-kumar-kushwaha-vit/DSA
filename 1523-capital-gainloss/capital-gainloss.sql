# Write your MySQL query statement below
select stock_name ,SUM(
    case 
     when operation='Buy' then -price
     when operation='Sell' then price
    end
)as capital_gain_loss 
from Stocks 
group by stock_name;

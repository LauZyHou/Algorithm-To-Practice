select
    id,
    sum(case D.month when 'Jan' then D.revenue else null end) as 'Jan_Revenue',
    sum(case D.month when 'Feb' then D.revenue else null end) as 'Feb_Revenue',
    sum(case D.month when 'Mar' then D.revenue else null end) as 'Mar_Revenue',
    sum(case D.month when 'Apr' then D.revenue else null end) as 'Apr_Revenue',
    sum(case D.month when 'May' then D.revenue else null end) as 'May_Revenue',
    sum(case D.month when 'Jun' then D.revenue else null end) as 'Jun_Revenue',
    sum(case D.month when 'Jul' then D.revenue else null end) as 'Jul_Revenue',
    sum(case D.month when 'Aug' then D.revenue else null end) as 'Aug_Revenue',
    sum(case D.month when 'Sep' then D.revenue else null end) as 'Sep_Revenue',
    sum(case D.month when 'Oct' then D.revenue else null end) as 'Oct_Revenue',
    sum(case D.month when 'Nov' then D.revenue else null end) as 'Nov_Revenue',
    sum(case D.month when 'Dec' then D.revenue else null end) as 'Dec_Revenue'
from Department as D
group by D.id
import calendar
import datetime

# Get the current year
current_year = datetime.date.today().year

# Create a TextCalendar for the current year
cal = calendar.TextCalendar(calendar.SUNDAY)

# Generate and display the calendar for the entire year
for month in range(1, 13):
    print(cal.formatmonth(current_year, month))

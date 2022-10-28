import calendar
year = int(input("Enter the year for the calendar: "))
month = int(input("Enter the month for the calendar, 1-12: "))

calendar.setfirstweekday(calendar.SUNDAY)
myCal = calendar.month(year,month)
print(myCal)

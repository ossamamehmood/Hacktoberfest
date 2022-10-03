#program to calculate date after given date

year = int(input("Input a year: "))

if year<0:
    print("The year cannot be negative")
elif (year % 400 == 0):
    leap_year = True
elif (year % 100 == 0):
    leap_year = False
elif (year % 4 == 0):
    leap_year = True
else:
    leap_year = False

month = int(input("Input a month [1-12]: "))
if month>12 or month<1:
    print("Invalid month")
    exit()
elif month in (1, 3, 5, 7, 8, 10, 12):
    month_length = 31
elif month == 2:
    if leap_year:
        month_length = 29
    else:
        month_length = 28
else:
    month_length = 30

day = int(input("Input a day [1-31]: "))
if day>month_length or day<1:
    print("Invalid day")
    exit()
elif day < month_length:
    day += 1
else:
   day = 1
   month += 1

print("The next date is [dd-mm-yyyy] %d-%d-%d." % (day, month, year))
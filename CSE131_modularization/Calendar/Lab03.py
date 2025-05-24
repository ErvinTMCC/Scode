# 1. Name:
#      Ervin Martinez
# 2. Assignment Name:
#      Lab 03 : Calendar Program
# 3. Assignment Description:
#      The Calendar Program prompts user for a month and year that that they would 
#      like to see a calender displayed for. The program will calculate the number of
#      days since the start of the Gregorian calendar(Jan. 1753) to the desired calendar
#      month. Then get current months number of days, calculate the offset, and display 
#      the requested months calendar for the given year. 
# 4. What was the hardest part? Be as specific as possible.
#      It was something simple but it took me a bit to see what I had over-looked. I was
#      calculating the sum of all days including the users desired month, instead of the
#      sum up to the month. My first method was calculating the offset for the next month,
#      not as the later which was the requested month's offset.
# 5. How long did it take for you to complete the assignment?
#      It took about 4 hrs.


def display_table(dow, num_days):
    '''Display a calendar table'''
    assert(type(num_days) == type(dow) == type(0))
    assert(0 <= dow <= 6)
    assert(28 <= num_days <= 31)

    # Display a nice table header
    print("  Su  Mo  Tu  We  Th  Fr  Sa")

    # Indent for the first day of the week
    for indent in range(dow):
        print("    ", end='')

    # Display the days of the month
    for dom in range(1, num_days + 1):
        print(repr(dom).rjust(4), end='')
        dow += 1
        # Newline after Saturdays
        if dow % 7 == 0:
            print("") # newline

    # We must end with a newline
    if dow % 7 != 0:
        print("") # newline

#Prompt user for desired Calendar month.
def prompt_month():
    try:
        month = int(input("Enter the month number: "))

        #Check if month is valid.
        if(month > 12 or month <= 0):
            print("Invalid: can only be a value from 1 - 12, please try again.")
            return prompt_month()
        else:
            return month
    except:
        print("Error: Please try again.")
        return prompt_month()
    
#Prompt user for desired Calendar year.
def prompt_year():
    try:
        year = int(input("Enter year: "))

        #Check if year is valid.
        if(year >= 1753):
            return year
        else:
            print("Invalid: Can only be a value greater than 1753, please try again.")
            return prompt_year()
    except:
        print("Error: Please try again.")
        return prompt_year()

#Calculate number of days in a given month.
def days_in_month(isleap, month):
    assert (month <= 12 and month > 0)

    #find given month return days in that month.
    match month:
        case 1 | 3 | 5 | 7 | 8 | 10 | 12:
            return 31
        case 4 | 6| 9| 11:
            return 30
        case 2:
            #Check if Leap Year for Feb.
            if isleap:
                return 29
            else:
                return 28

#Determin if year is leap year.
def is_leap_yr(year):
    assert(year >= 1753)

    #Check if year is divisable by 4.
    if(not(year%4)):
        #Check if Month is Centurian and not divisable by 400.
        if(not(year%100) and (year%400)):
            return False
        #Meets all critiria for a Leap Year.
        else:
            return True
    else:
        return False

def number_days_since_1753(year, month):
    assert(type(year) == type(month) == type(0))
    assert(year >= 1753)
    assert(month <= 12 and month > 0)

    #Number of days since 1753 accumulator.
    total_days = 0

    #Total days for years since 1753 to requested year
    for iYear in range(1753, year, 1):
        #Check if year is Leap Year.
        if is_leap_yr(iYear):
            total_days += 366
        else:
            total_days += 365
    
    #Total days for months in requested year up to requested month, summed to previous sum total.
    for iMonth in range(1, month, 1):
        # Get number of days in the month.
        total_days += days_in_month(is_leap_yr(year), iMonth)

    #Return total days since Jan 1753
    return total_days

def calc_offset(total_days):
    assert(total_days >= 0)
    assert(type(total_days) == type(0))

    #Return the calculated offset.
    return (1 + total_days) % 7

def main():
    #Prompt user for month and year
    month = prompt_month()
    year = prompt_year()
    
    # #Get number of days since Jan 1753 and Months days.
    total_days = number_days_since_1753(year, month)

    # #Get number of days in requested month, from offset and month
    mth_days = days_in_month(is_leap_yr(year), month)

    # #Output Calendar
    display_table(calc_offset(total_days), mth_days)

if __name__ == "__main__":
    main()
/***********************************************************************
* Program:
*    Project 2, Calendar  
*    Brother Comeau, CS124
* Author:
*    Ben Wright
* Summary: 
*    This program display's a calendar that starts from 1753 and goes up
*    to any year after that. It will even determine when it is a leap
*    year.
*    Estimated:  5.0 hrs   
*    Actual:     7.0 hrs
*      I would say that the hardest part was trying getting the offset
*      function to work. The same thing with the leap year function, it
*      at first wasn't counting the extra day of the year when it was
*      a leap year
************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/***************************************************************
 * The function get month prompts the user for the month number.
 ***************************************************************/
int getMonth()
{
   int month;
   cout << "Enter a month number: ";
   cin >> month;
   while (!(month >= 1 && month <= 12))
   {
      cout << "Month must be between 1 and 12." << endl;
      cout << "Enter a month number: ";
      cin >> month;
   }
   return month;
}

/*************************************************************
 * The function get year prompts the user for the year number.
 *************************************************************/
int getYear()
{
   int year;
   cout << "Enter year: ";
   cin >> year;
   while (!(year >= 1753))
   {
      cout << "Year must be 1753 or later." << endl;
      cout << "Enter year: ";
      cin >> year;
   }
   return year; 
}

/**********************************************************************
 * The function compute leap year determines whether the year is a
 * leap year.
 ***********************************************************************/
bool computeLeapYear(int year)// is leapyear or not?
{
   if (year % 4 != 0)
      return false;
   else if (year % 100 != 0)
      return true;
   else if (year % 400 != 0)
      return false;
   else
      return true;
}

/**********************************************************************
 * The function computeNumDaysMonth determines the number of days that
 * each month should have within the given year.
 ***********************************************************************/
int computeNumDaysMonth(int month, int year)
{
   if (month == 1 || month == 3 || month == 5 || month == 7
       || month == 8 || month == 10 || month == 12)
      return 31;
   if (month == 4 || month == 6 || month == 9 || month == 11)
      return 30;
   if (month == 2)
   {
      if (computeLeapYear(year))
         return 29;
      else
         return 28;
   }
   return false;
}

/**********************************************************************
 * The function numDaysInYear determines the number of days each year
 * should have.
 ***********************************************************************/
int numDaysInYear(int year)
{
   if (computeLeapYear(year))
      return 366;
   else
      return 365;
}

/*****************************************************************
 * The function computeOffSet counts the days from January 1753
 * to the time the user inputs.
 *****************************************************************/
int computeOffSet(int month, int year)
{
   int numDays = 0; 

   for (int yearCount = 1753; yearCount < year; yearCount++)
      numDays += numDaysInYear(yearCount);
   
   for (int monthCount = 1; monthCount < month; monthCount++)
      numDays += computeNumDaysMonth(monthCount, year);
   
   return numDays % 7;
}

/**********************************************************************
 * The function display table will display the calendar on the screen.
 ***********************************************************************/
void displayTable(int offset, int numDays, int month, int year)
{
   offset = (offset + 1) % 7;

   cout << ", " << year << endl;
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   cout << setw((4 * offset)) << "";
   
   for (int day = 1; day <= numDays; day++)
   {
      cout << setw(4) << day;
      offset++;

      if (offset % 7 == 0 || numDays == day)         
         cout << endl;
   }
}

void checkMonth(int month, int number, string name)
{
   if (month == number)
      cout << name;
}
/**********************************************************************
 * The function display header will display the name of a month the
 * user inputs a number 1-12.
 ***********************************************************************/
void checkMonth(int month)
{
   checkMonth(month, 1, "January");
   checkMonth(month, 2, "February");
   checkMonth(month, 3, "March");
   checkMonth(month, 4, "April");
   checkMonth(month, 5, "May");
   checkMonth(month, 6, "June");
   checkMonth(month, 7, "July");
   checkMonth(month, 8, "August");
   checkMonth(month, 9, "September");
   checkMonth(month, 10, "October");
   checkMonth(month, 11, "November");
   checkMonth(month, 12, "December");
}

/**********************************************************************
 * The function display will call the display header and display table
 * functions.
 ***********************************************************************/
void display(int month, int year, int numDays, int offset)
{
   checkMonth(month);
   displayTable(offset, numDays, month, year);
}

/**********************************************************************
 * The function main will call the functions listed in the program and
 * display them on the screen.
 ***********************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();
   int numDays = computeNumDaysMonth(month, year);
   int leapyear = computeLeapYear(year);
   int offset = computeOffSet(month, year);
   cout << endl;
   display(month, year, numDays, offset);
   return 0;
}
      

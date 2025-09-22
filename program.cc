#include <iostream>
#include <cmath>
using namespace std;

// This c++ program was written by Alec Schoep and Thomas Cunningham.
// alecthomas.cc
// Compilers and editors used: g++ and gedit
// Last edit 22/09/2025


int main() {
    srand(42);
    
    cout << "Creators: Alec Schoep (s4924231) & Thomas Cunningham (s)" << endl;
    cout << "Year of arrival: 2025" << endl;
    cout << "Field of study: Computer Science" << endl;
    cout << "Assignment: 1" << endl;
    cout << "Creation date: 19/9/2025" << endl;
    cout << "This program will test you, to see if you are eligible to be studying on a university." << endl;

    int Day, Month, Year;
    int HardCodedDateDay = 22;
    int HardCodedDateMonth = 9;
    int HardCodedDateYear = 2025;

    // Ask the user for their date of birth
    cout << "Enter your birth of day(day month year) :";
    cin >> Day >> Month >> Year;

    int YearsOld = HardCodedDateYear - Year;
    int MonthsOld = 0;
    int MonthValue = 0;
    int YearValue = 0;

    // if statement for if the year is negative or its in the future.
    if (Year < 0 || Year > HardCodedDateYear || Month < 1 || Month > 12) {
        cout << "You cant use this date, because its invalid." << endl;
        return 1;
    }

    // Check if the input date exists and is valid.
    int DaysInMonth = 31;
    if (Month == 4 || Month == 6 || Month == 9 || Month == 11) {
        DaysInMonth = 30;
    }
    else if (Month == 2) {
        if ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0))
            DaysInMonth = 29;
        else
            DaysInMonth = 28;
    }

    // Check if the day input value is valid or not.
    if (Day < 1 || Day > DaysInMonth) {
        cout << "You cant use this date, because its invalid." << endl;
        return 1;
    }

    // If statement for if you are too young or too old.
    if (HardCodedDateYear - Year < 10 || (HardCodedDateYear - Year == 10 && (Month > HardCodedDateMonth || (Month == HardCodedDateMonth && Day > HardCodedDateDay))) || HardCodedDateYear - Year > 100 || (HardCodedDateYear - Year == 100 && (Month < HardCodedDateMonth || (Month == HardCodedDateMonth && Day < HardCodedDateDay))))
    {
        return 1;
    }


    // Year and month difference.
    if (Month > HardCodedDateMonth || (Month == HardCodedDateMonth && Day > HardCodedDateDay)) {
        YearsOld = YearsOld - 1;
        MonthValue = (12 - (Month - HardCodedDateMonth));
        YearValue = YearsOld;
    }
    else if (Month < HardCodedDateMonth || (Month == HardCodedDateMonth && Day <= HardCodedDateDay)) {
        MonthValue = HardCodedDateMonth - Month;
        YearValue = YearsOld;
    }

    MonthsOld = YearsOld * 12 + MonthValue;

    // Weekday calculation.
    int DaysSince1900 = (Year - 1900) * 365;

    int LeapDaysBefore = (Year - 1) / 4 - (Year - 1) / 100 + (Year - 1) / 400;
    int LeapDaysStart = 1899 / 4 - 1899 / 100 + 1899 / 400;
    DaysSince1900 = DaysSince1900 + (LeapDaysBefore - LeapDaysStart);

    if (Month > 1) DaysSince1900 = DaysSince1900 + 31;
    if (Month > 2) {
        if ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0))
            DaysSince1900 = DaysSince1900 + 29;
        else
            DaysSince1900 = DaysSince1900 + 28;
    }
    if (Month > 3) DaysSince1900 = DaysSince1900 + 31;
    if (Month > 4) DaysSince1900 = DaysSince1900 + 30;
    if (Month > 5) DaysSince1900 = DaysSince1900 + 31;
    if (Month > 6) DaysSince1900 = DaysSince1900 + 30;
    if (Month > 7) DaysSince1900 = DaysSince1900 + 31;
    if (Month > 8) DaysSince1900 = DaysSince1900 + 31;
    if (Month > 9) DaysSince1900 = DaysSince1900 + 30;
    if (Month > 10) DaysSince1900 = DaysSince1900 + 31;
    if (Month > 11) DaysSince1900 = DaysSince1900 + 30;

    DaysSince1900 = DaysSince1900 + Day;

    int WeekDayNumber = DaysSince1900 % 7;
    string WeekDay;

    if (WeekDayNumber == 0) WeekDay = "sunday";
    if (WeekDayNumber == 1) WeekDay = "monday";
    if (WeekDayNumber == 2) WeekDay = "tuesday";
    if (WeekDayNumber == 3) WeekDay = "wednesday";
    if (WeekDayNumber == 4) WeekDay = "thursday";
    if (WeekDayNumber == 5) WeekDay = "friday";
    if (WeekDayNumber == 6) WeekDay = "saturday";

    // print to the screen.
    cout << "You are " << YearValue << " years and " << MonthValue << " months old (" << MonthsOld << " months). " << "You were born on a " << WeekDay << "." << endl;

    // Ask for the first letter of the day.
    char FirstLetter;
    char SecondLetter = ' ';

    cout << "Enter the first letter of the day you were born:";
    cin >> FirstLetter;

    if (FirstLetter == 't') {
        cout << "Enter a second letter:";
        cin >> SecondLetter;
    }

    if (FirstLetter == WeekDay[0]) {
        if (WeekDay == "tuesday" && SecondLetter == 'u') {
            cout << "That is correct." << endl;
        }
        else if (WeekDay == "thursday" && SecondLetter == 'h') {
            cout << "That is correct." << endl;
        }
        else if (WeekDay != "tuesday" && WeekDay != "thursday") {
            cout << "That is correct." << endl;
        }
        else {
            return 1;
        }
    }


    // Start with the abc formula.


    return 0;
}

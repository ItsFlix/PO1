#include <iostream>
using namespace std;

int main() {

    int Day, Month, Year;
    int HardCodedDateDay = 22;
    int HardCodedDateMonth = 9;
    int HardCodedDateYear = 2025;

    // Example hardcoded birthday
    //Day = 15;
    //Month = 8;
    //Year = 2006;
    Day = 21;
    Month = 9;
    Year = 1925;

    int YearsOld = HardCodedDateYear - Year;
    int MonthsOld = 0;
    int MonthValue = 0;
    int YearValue = 0;

    // If statement for if you are too young or too old.
    if (HardCodedDateYear - Year < 10 || (HardCodedDateYear - Year == 10 && (Month > HardCodedDateMonth || (Month == HardCodedDateMonth && Day > HardCodedDateDay))) || HardCodedDateYear - Year > 100 || (HardCodedDateYear - Year == 100 && (Month < HardCodedDateMonth || (Month == HardCodedDateMonth && Day < HardCodedDateDay))))
    {
        return 1;
    }


    // Work out year and month difference
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

    // Weekday calculation (day counting method, no loops)
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

    int WeekDayNumber = (1 + DaysSince1900) % 7; // 1 Jan 1900 = Monday

    string WeekDay;
    if (WeekDayNumber == 0) WeekDay = "Sunday";
    if (WeekDayNumber == 1) WeekDay = "Monday";
    if (WeekDayNumber == 2) WeekDay = "Tuesday";
    if (WeekDayNumber == 3) WeekDay = "Wednesday";
    if (WeekDayNumber == 4) WeekDay = "Thursday";
    if (WeekDayNumber == 5) WeekDay = "Friday";
    if (WeekDayNumber == 6) WeekDay = "Saturday";

    // Single output
    cout << "You are " << YearValue << " years and " << MonthValue
        << " months old (" << MonthsOld << " months). "
        << "You were born on a " << WeekDay << "." << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {


    int Day, Month, Year;
    int HardCodedDateDay = 22;
    int HardCodedDateMonth = 9;
    int HardCodedDateYear = 2025;

    //cout << "Enter your birth date (day month year): ";
    //cin >> Day >> Month >> Year;

    //cout << "Date of birth: " << Day << "/" << Month << "/" << Year << endl;


    Day = 15, Month = 9, Year = 2006;

    int MonthsOld{};
    int YearsOld;

    int MonthValue{};
    int YearValue;

    YearsOld = HardCodedDateYear - Year;

    if (Month > HardCodedDateMonth) {
        cout << "rrrrrrrrrrrrrrr" << endl;
        //MonthsOld = ((YearsOld - 1) * 12) + Month;
        MonthsOld = ((YearsOld - 1) * 12) + HardCodedDateMonth;
        MonthValue = 12 - Month;
        YearValue = YearsOld - 1;
    }

    if (Month < HardCodedDateMonth) { // 8 <= 9 t
        
        //cout << YearsOld << endl;

        MonthsOld = ((YearsOld - 1) * 12) + HardCodedDateMonth;
        MonthValue = HardCodedDateMonth - Month;
        YearValue = YearsOld;
        //cout << MonthsOld << endl;

        //cout << "You are " << YearsOld << " years old and " << HardCodedDateMonth - Month << " Months old (" << MonthsOld << " Months)";
    }
    /*else {*/

        // 9 < 9 f 9 >=
        if (Month == HardCodedDateMonth) {
            
            //month = 9
            if (Day >= HardCodedDateDay) { // 15 >= 22 f
                MonthsOld = ((YearsOld) * 12);
                YearValue = YearsOld;
                MonthValue = HardCodedDateMonth;
            }
            else
            {
                MonthsOld = ((YearsOld - 1) * 12) + HardCodedDateMonth;
                YearValue = YearsOld - 1;
                MonthValue = HardCodedDateMonth;
            }
        }


    //}

    //cout << "You are " << YearsOld << " years old and " << HardCodedDateMonth - Month << " Months old (" << MonthsOld << " Months)";
        cout << "You are " << YearValue << " years old and " << MonthValue << " Months old (" << MonthsOld << " Months)";


    return 0;
}

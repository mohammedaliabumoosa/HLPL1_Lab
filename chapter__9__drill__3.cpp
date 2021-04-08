#include"std_lib_facilities.h"

class Date{
    int y, m, d;
public:
    Date(int y, int m, int d);
    void add_day(int n);
    int month(){return m;};
    int day(){return d;};
    int year(){return y;};
};

Date::Date (int yy, int mm, int dd) {
    if(yy < 0 || dd < 0 || dd > 31 || mm < 1 || mm > 12) error("invalid date!");
    y = yy;
    m = mm;
    d = dd;
}

void Date::add_day(int n) {
    d += n;
    for (;d > 31;)
    {
        d -= 31;
        ++m;
    }
    for (;m > 12;)
    {
        m -= 12;
        ++y;
    }
    for (;d < 1;)
    {
        d += 31;
        --m;
    }
    for (;m < 1;)
    {
        m += 12;
        --y;
    }
}

ostream& operator<<(ostream& os, Date& dd)
{
    return os << dd.year() << ' ' 
              << dd.month() << ' ' 
              << dd.day();
}

int main() {
    Date today{1978, 6, 25};
    Date tommorow {today};
    tommorow.add_day(1);
    cout << today << endl;
    cout << tommorow << endl;
    //Date t_1{2004, 13, -5}; "invalid date!"
    /*
    Date t_2{2021, 12, 31};
    t_2.add_day(32);
    cout << t_2 << endl;
    output "2022 2 1"
    */
    return 0;
}

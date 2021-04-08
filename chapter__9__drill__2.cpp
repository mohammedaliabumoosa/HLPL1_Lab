#include"std_lib_facilities.h"

struct Date{
    int y, m, d;
    Date(int y, int m, int d);
    void add_day(int n);
};

Date::Date (int yy, int mm, int dd) {
    if(yy < 0 || dd < 0 || dd > 31 || mm < 1 || mm > 12) error("invalid date!");
    y = yy;
    m = mm;
    d = dd;
}

void Date::add_day(int n) {
    d += n;
    if (d > 31)
    {
        d -= 31;
        ++m;
    }
    if (m > 12)
    {
        m -= 12;
        ++y;
    }
    if (d < 1)
    {
        d += 31;
        --m;
    }
    if (m < 1)
    {
        m += 12;
        --y;
    }
}

ostream& operator<<(ostream& os, Date& dd)
{
    return os << dd.y << ' ' 
              << dd.m << ' ' 
              << dd.d;
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
    t_2.add_day(1);
    cout << t_2 << endl;
    output "2022 1 1"
    */
    return 0;
}

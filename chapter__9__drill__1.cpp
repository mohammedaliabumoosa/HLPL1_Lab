#include"Header.h"

struct Date{
    int y;
    int m;
    int d;
};

void init_day(Date& dd, int y, int m, int d) {
    if(y < 0 || d < 0 || d > 31 || m < 1 || m > 12) error("invalid date!");
    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n) {
    dd.d += n;
    if (dd.d > 31)
    {
        dd.d -= 31;
        ++dd.m;
    }
    if (dd.m > 12)
    {
        dd.m -= 12;
        ++dd.y;
    }
    if (dd.d < 1)
    {
        dd.d += 31;
        --dd.m;
    }
    if (dd.m < 1)
    {
        dd.m += 12;
        --dd.y;
    }
}

ostream& operator<<(ostream& os, Date& dd)
{
    return os << dd.y << ' ' 
              << dd.m << ' ' 
              << dd.d;
}

int main() {
    Date today;
    init_day(today, 1978, 6, 25);
    Date tommorow {today};
    add_day(tommorow, 1);
    cout << today << endl;
    cout << tommorow << endl;
    Date t_1;
    Date t_2;
    //init_day(t_1, 2021, 13, -8); "invalid date!"
    /*init_day(t_2, 2021, 12, 31);
    add_day(t_2,1);
    cout << t_2 << endl;
    output "2022 1 1"*/
    return 0;
}

#include"Header.h"

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> months {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)-1];
}

class Date{
    int y, d;
    Month m;
public:
    Date(int y, Month m, int d);
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
    Month month() const {return m;};
    int day() const {return d;};
    int year() const {return y;};
};

Date::Date (int yy, Month mm, int dd) {
    if(yy < 0 || dd < 0 || dd > 31 || int(mm) < 1 || int(mm) > 12) error("invalid date!");
    y = yy;
    m = mm;
    d = dd;
}

void Date::add_day(int n) {
    d += n;
    int im = int(m);
    for (;d > 31;)
    {
        d -= 31;
        ++im;
    }
    for (;im > 12;)
    {
        im -= 12;
        ++y;
    }
    for (;d < 1;)
    {
        d += 31;
        --im;
    }
    for (;im < 1;)
    {
        im += 12;
        --y;
    }
    m = Month(im);
}

void Date::add_month(int n) {
    int im = int(m);
    im += n;
    for (;im > 12;)
    {
        im -= 12;
        ++y;
    }
    for (;im < 1;)
    {
        im += 12;
        --y;
    }
    m = Month(im);
}

void Date::add_year(int n) {
    y += n;
}

ostream& operator<<(ostream& os, Date& dd)
{
    return os << dd.year() << ' ' 
              << dd.month() << ' ' 
              << dd.day();
}

int main() {
    Date today{1978, Month::jun, 25};
    Date tommorow {today};
    tommorow.add_day(1);
    //today.add_month(37); output "1981 July 25"
    cout << today << endl;
    cout << tommorow << endl;
    //Date t_1{2004, 13, -8}; wont pass the compiler 
    /*
    Date t_2{2021, Month::dec, 31};
    t_2.add_day(1);
    cout << t_2 << endl;
    output "2022 January 1"
    */
    return 0;
}

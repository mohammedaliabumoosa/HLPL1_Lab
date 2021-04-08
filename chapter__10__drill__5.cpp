#include"std_lib_facilities.h"

struct Point {
    double x,y;
    Point():x{0}, y{0} {}
    Point(double x, double y);
};

Point::Point(double xx, double yy)
{
    x = xx;
    y = yy;
}

istream& operator>>(istream& is, Point& p){
    double x, y;
    char ch1, ch2, ch3;
	is >> ch1 >> x >> ch2 >> y >> ch3;


	if(is && ch1 == '(' && ch2 == ',' && ch3 == ')')
	{
		p = Point(x, y);
	}
    else 
    {
        is.clear(ios_base::failbit);
    }
	
    return is;
}

void output_to_file(vector<Point>& ps){
    ofstream ost {"mydata.txt"};
    for (int i = 0; i < ps.size(); i++)
        ost << '(' << ps[i].x << "," << ps[i].y << ')' << endl;
    ost.close();
}

void input_from_file(vector<Point>& ps){
    ifstream ist{"mydata.txt"};
    double x, y;
    char ch1, ch2, ch3;
    Point p;

	while(ist >> ch1 >> x >> ch2 >> y >> ch3)
	{
		p = Point(x, y);
        ps.push_back(p);
	}
}

int main(){
    vector<Point>original_points;
    vector<Point>processed_points;
    cout << "enter 7 points in format (x,y)" << endl;
    Point p;
    for (;original_points.size() < 3;)
    {
        if(cin >> p)
        {
            original_points.push_back(p);
        }
        else 
        {
            cout << "did you type in the specific formart (x,y)?" << endl;
            cin.clear();
        }
    }
    cout << endl;
    
    for (int i = 0; i < original_points.size(); i++)
        cout << '(' << original_points[i].x << "," << original_points[i].y << ')' 
             << endl << endl;

    output_to_file(original_points);

    input_from_file(processed_points);

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class clock_time {
    public:
        clock_time();
        clock_time(int h,int m, int s);
        void set_time(int h,int m, int s);
        int get_hour();
        int get_minute();
        int get_second();
        int get_total_seconds();
        
       friend clock_time operator+(clock_time c,clock_time d){
           return clock_time(c.get_hour()+d.get_hour(),c.get_minute()+d.get_minute(),c.get_second()+d.get_second());
       }
       
       friend bool operator!=(clock_time c,clock_time d){
           return c._seconds != d._seconds;
       }
       
       friend bool operator==(clock_time c,clock_time d){
           return c._seconds == d._seconds;
       }

    private:
        int _seconds;
    
};

string to_string(clock_time& c);
std::ostream& operator<<(ostream& out, clock_time& c);


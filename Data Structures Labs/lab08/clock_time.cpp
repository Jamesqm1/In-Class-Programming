#include "clock_time.h"
#include <stdio.h>





clock_time::clock_time(){
    _seconds =0;
}

clock_time::clock_time(int h,int m, int s){
    set_time(h,m,s);
}

void clock_time::set_time(int h,int m, int s){
    _seconds = (3600 * h + 60* m + s)%86400;
}

int clock_time::get_hour(){
    return _seconds/3600;
}

int clock_time::get_minute(){
    return (_seconds%3600)/60;
}

int clock_time::get_second(){
    return _seconds%60;
}

int clock_time::get_total_seconds(){
    return _seconds;
}

string to_string(clock_time& c){
    string output="";
    int h,m,s;
    h = c.get_hour();
    m = c.get_minute();
    s = c.get_second();
    output+=std::to_string(h)+":";
    if(m<10){
        output+="0"+std::to_string(m)+":";
    }
    else{
        output+=std::to_string(m)+":";
    }
    if(s<10){
        output+="0"+std::to_string(s);
    }
    else{
        output+=std::to_string(s);
    }
    return output;
}

std::ostream& operator<<(ostream& out,clock_time& c){
    out << to_string(c);
    return out;
}



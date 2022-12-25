//
// Created by Younes Lahrichi on 10/14/21.
//

#include "timespan.h"
#include <cmath>

//this is the << operator method 
ostream &operator<<(ostream &out, const TimeSpan &ts) {
//this is the initialization of local variables to help with calculations and conditions
  int hoursTemp;
  int minutesTemp;
  int secondsTemp;
//this checks if the time being passed into it is negative
  if (ts.getHour() < 0 || ts.getMinute() < 0 || ts.getSecond() < 0) {
//this changes the local temp variables to positive so they can be printed and formatted correctly
    hoursTemp = ts.getHour() * -1;
    minutesTemp = ts.getMinute() * -1;
    secondsTemp = ts.getSecond() * -1;
//this if checks if the minutes and the seconds at between 0 - 10 so that it can print a 0 infront of the minutes and seconds values
//this is done for the formatting of the output
    if (minutesTemp < 10 && minutesTemp >= 0 && secondsTemp < 10 && secondsTemp >= 0) {
      out << "-" << hoursTemp << ":" << "0" << minutesTemp << ":" << "0" << secondsTemp;
    }
//this if checks if only the minutes are between 0 - 10 so that it can print a 0 in front of the minutes value
//this is done for the formatting of the output
    else if(minutesTemp < 10 && minutesTemp >= 0){
      out << "-" << hoursTemp << ":" << "0" << minutesTemp << ":" << secondsTemp;
    }
//this if checks if only the minutes are between 0 - 10 so that it can print a 0 in front of the seconds value
//this is done for the formatting of the output
    else if (secondsTemp < 10 && secondsTemp >= 0) {
      out << "-" << hoursTemp << ":" << minutesTemp << ":" << "0" << secondsTemp;
    }
//this just else means that neither of the minuets or seconds value are between 0 - 10
//it just prints a - infront of the time for the correct formatting
    else {out << "-" << hoursTemp << ":" << minutesTemp << ":" << secondsTemp;}

    return out;
  }
//this if checks if the minutes are between 0 - 10 so that it can print a 0 infront of the minutes and seconds values
//this is done for the formatting of the output
  if(ts.getMinute() < 10 && ts.getMinute() >= 0 && ts.getSecond() < 10 && ts.getSecond() >= 0){
    out << ts.getHour() << ":" << "0" << ts.getMinute() << ":" << "0" << ts.getSecond();
  }
//this if checks if only the minutes are between 0 - 10 so that it can print a 0 in front of the minutes value
//this is done for the formatting of the output
  else if(ts.getMinute() <= 10 && ts.getMinute() >= 0){
    out << ts.getHour() << ":" << "0" << ts.getMinute() << ":" << ts.getSecond();
  }
//this if checks if only the minutes are between 0 - 10 so that it can print a 0 in front of the seconds value
//this is done for the formatting of the output
  else if(ts.getSecond() <= 10 && ts.getSecond() >= 0){
    out << ts.getHour() << ":" << ts.getMinute() << ":" << "0" << ts.getSecond();
  }
//this else just prints out the values as they are
//if it gets to this else than it means that format is correct as is and doesnt need any changes
  else{
    out << ts.getHour() << ":" << ts.getMinute() << ":" << ts.getSecond();
  }
  
  return out;
}

//this is the constructor
TimeSpan::TimeSpan(double hour, double minute, double second) {
  fix(hour, minute, second);
}

//this is the method that fixes the time into the best format
//it converts all the hours to seconds and all the minutes to seconds
//then it sets the hours to as many possible sets of 3600 seconds and subract that from the total number of seconds
//then it sets minutes to as man possible sets of 60 seconds and substracts that from the total number of seconds
//lastly it sets the seconds to the remainder of all those calculations
void TimeSpan::fix(double hour, double minute, double second){
  seconds = second + (hour * 60 * 60) + (minute * 60);
  hours = seconds / 3600;
  seconds = fmod(seconds, 3600);
  minutes = seconds / 60;
  seconds = fmod(seconds, 60);
}

// hour component
//this gets the number of hours that are passed and returns that value
int TimeSpan::getHour() const {
  return hours;
}

// minute component
//this gets the number of minutes that are passed and returns that value
int TimeSpan::getMinute() const { 
  return minutes; 
}

// second component
//this gets the number of seconds that are passed and returns that value
int TimeSpan::getSecond() const { 
  return seconds; 
}

// true if timespan is 0 or larger
bool TimeSpan::isPositive() const { 
//this checks if all the values are greater than or equal to 0
//returns true if they are or false if they arent
  if (seconds >= 0 && minutes >= 0 && hours >= 0){
    return true;
  }
  return false;
}

//this is the operator overload + method (addition)
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
//returns the sum of two different timesspans's
  TimeSpan tsSum(hours + ts.getHour(), minutes + ts.getMinute(), seconds + ts.getSecond());
  return tsSum;
}

//this is the operator overload - method (subtraction)
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
//returns the differece of two different timesspans's
  TimeSpan tsSub(hours - ts.getHour(), minutes - ts.getMinute(), seconds - ts.getSecond());
  return tsSub;
}

//this is the operator overload * method (multiplication)
TimeSpan TimeSpan::operator*(unsigned int number) const {
//returns the product of a timespan and an unsigned integer
  TimeSpan tsLarge(hours * number, minutes * number, seconds * number);
  return tsLarge;
}

//this is the operator overload += method (plus equals)
TimeSpan TimeSpan::operator+=(const TimeSpan &ts){
//this returns the value equal to that value and a passed through TimeSpan
  *this = *this + ts;
  return *this;
}

//this is the operator overload -= method (minus equals)
TimeSpan TimeSpan::operator-=(const TimeSpan &ts){
//this returns the value of the difference of a value and a passed through TimeSpan
  *this = *this - ts;
  return *this;
}

//this is the operator overload == method (is equals)
bool TimeSpan::operator==(const TimeSpan &ts) const { 
//this returns true if two timespan's have the same hours, minutes, and seconds
//this returns false if they do not have the same hours, minutes, and seconds
  if(hours == ts.getHour() && minutes == ts.getMinute() && seconds == ts.getSecond()){
    return true; 
  }
  return false;
}

//this is the operator overload != method (is not equals)
bool TimeSpan::operator!=(const TimeSpan &ts) const { 
//this returns true if two timespan's do not have the same hours, minutes, and seconds
//this returns false if they do have the same hours, minutes, and seconds
  if(hours != ts.getHour() && minutes != ts.getMinute() && seconds != ts.getSecond()){
    return true; 
  }
  return false;
}

//this is the operator overload > method (greater than)
bool TimeSpan::operator>(const TimeSpan &ts) const {
//this converts both of the times in question into seconds
//then it compares the two numbers of seconds
//if time1 (the first number of total seconds) is greater than time2 (the second number of total seconds) then it returns true
//if time1 (the first number of total seconds) is less than or equal to time2 (the second number of total seconds) then it returns false
  int time1 = (hours * 3600) + (minutes * 60) + (seconds);
  int time2 = (ts.getHour() * 3600) + (ts.getMinute() * 60) + (ts.getSecond());

  if(time1 > time2){
    return true; 
  }
  return false;
}

//this is the operator overload < method (less than)
bool TimeSpan::operator<(const TimeSpan &ts) const { 
//this converts both of the times in question into seconds
//then it compares the two numbers of seconds
//if time1 (the first number of total seconds) is less than time2 (the second number of total seconds) then it returns true
//if time1 (the first number of total seconds) is greater than or equal to time2 (the second number of total seconds) then it returns false
  int time1 = (hours * 3600) + (minutes * 60) + (seconds);
  int time2 = (ts.getHour() * 3600) + (ts.getMinute() * 60) + (ts.getSecond());
  if(time1 < time2){
    return true; 
  }
  return false;
}

//this is the operator overload <= method (less than or equal to)
bool TimeSpan::operator<=(const TimeSpan &ts) const {
//this converts both of the times in question into seconds
//then it compares the two numbers of seconds
//if time1 (the first number of total seconds) is less than or equal to time2 (the second number of total seconds) then it returns true
//if time1 (the first number of total seconds) is greater than time2 (the second number of total seconds) then it returns false
  int time1 = (hours * 3600) + (minutes * 60) + (seconds);
  int time2 = (ts.getHour() * 3600) + (ts.getMinute() * 60) + (ts.getSecond());
  if(time1 <= time2){
    return true; 
  }
  return false;
}

//this is the operator overload > method (greater than)
bool TimeSpan::operator>=(const TimeSpan &ts) const { 
//this converts both of the times in question into seconds
//then it compares the two numbers of seconds
//if time1 (the first number of total seconds) is greater than or equal to time2 (the second number of total seconds) then it returns true
//if time1 (the first number of total seconds) is less than time2 (the second number of total seconds) then it returns false
  int time1 = (hours * 3600) + (minutes * 60) + (seconds);
  int time2 = (ts.getHour() * 3600) + (ts.getMinute() * 60) + (ts.getSecond());
  if(time1 >= time2){
    return true; 
  }
  return false;
}
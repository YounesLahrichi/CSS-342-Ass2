//
// Created by Younes Lahrichi on 10/14/21.
//

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

//this is the intialization of my class
class TimeSpan {

  //this is the initialization of the oeprator overload of <<
  friend ostream &operator<<(ostream &out, const TimeSpan &ts);

public:

  //this is the initialization of the constructer
  explicit TimeSpan(double hour = 0, double minute = 0, double second = 0);

  //this is the initialization of the method that puts the time into the correct format
  void fix(double hour, double minute, double second);

  //this is the initialization of the oeprator overload of + (addition)
  TimeSpan operator+(const TimeSpan &ts) const;

  //this is the initialization of the oeprator overload of - (subtraction)
  TimeSpan operator-(const TimeSpan &ts) const;

  //this is the initialization of the oeprator overload of == (equality)
  bool operator==(const TimeSpan &ts) const;

  //this is the initialization of the oeprator overload of != (checks if not equal)
  bool operator!=(const TimeSpan &ts) const;

  //this is the initialization of the oeprator overload of * (multiplication)
  TimeSpan operator*(unsigned int number) const;

  //this is the initialization of the oeprator overload of += (addition equals)
  TimeSpan operator+=(const TimeSpan &ts);

  //this is the initialization of the oeprator overload of -= (subtraction equals)
  TimeSpan operator-=(const TimeSpan &ts);

  //this is the initialization of the oeprator overload of < (less than)
  bool operator<(const TimeSpan &ts) const;

  //this is the initialization of the oeprator overload of > (greater than)
  bool operator>(const TimeSpan &ts) const;

  //this is the initialization of the oeprator overload of <= (less than or equal to)
  bool operator<=(const TimeSpan &ts) const;

  //this is the initialization of the oeprator overload of >= (greater than or equal to)
  bool operator>=(const TimeSpan &ts) const;

  // this is the initialization of the method that gets the hour component of timespan
  int getHour() const;

  //this is the initialization of the method that gets the minute component of timespan
  int getMinute() const;

  //this is the initialization of the method that gets the second component of timespan
  int getSecond() const;

  // this is the intialization of the method that returns true if timespan is 0 or larger
  bool isPositive() const;

private:
  //intialization of variables that hold the time that is passed into the program
  //hours variable
  int hours;
  //minutes variable
  int minutes;
  //seconds variable
  int seconds;
};

#endif // ASS2_TIMESPAN_H
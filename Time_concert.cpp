/* The Time class with attributes (declared private) consists of the four integers (of type int) days, hours, minutes and seconds.
The class constructor initializes an object with the declarations. The constructor must ensure that the assigned values are valid: 
seconds and minutes cannot be greater than 59 or less than 0 and hours cannot be greater than 24 or less than 0. When the assigned value exceeds the limit (e.g.
seconds = 130) the manufacturer converts the time using the higher unit (2 minutes 10 seconds in the previous example).
The mutators will have to ensure that the assigned values are valid. */

#include <iostream>

using namespace std;

class Time {
private:
	int second, minute, hour, day;

public:
	Time() {
		setDay(0);
		setHour(0);
		setMinute(0);
		setSecond(0);
	}

	Time(int second) {
		setDay(0);
		setHour(0);
		setMinute(0);
		setSecond(second);
	}

	Time(int second, int minute) {
		setDay(0);
		setHour(0);
		setMinute(minute);
		setSecond(second);
	}

	Time(int second, int minute, int hour) {
		setDay(0);
		setHour(hour);
		setMinute(minute);
		setSecond(second);
	}

	Time(int second, int minute, int hour, int day) {
		setDay(day);
		setHour(hour);
		setMinute(minute);
		setSecond(second);
	}

	void setSecond(int second) { /* converts excess seconds to minutes  */
		if (second > 59) {
			this->second = second % 60;
			setMinute(getMinute() + (int) second / 60);
		} else if (second < 0) {
			this->second = 0;
		} else {
			this->second = second;
		}

	}

	void setMinute(int minute) { /* same with minutes and hours*/
		if (minute > 59) {
			this->minute = minute % 60;
			setHour(getHour() + (int) minute / 60);
		} else if (minute < 0) {
			this->minute = 0;
		} else {
			this->minute = minute;
		}
	}

	void setHour(int hour) { /* hours and days */
		if (hour > 23) {
			this->hour = hour % 24;
			setDay(getDay() + (int) hour / 24);
		} else if (hour < 0) {
			this->hour = 0;
		} else {
			this->hour = hour;
		}
	}

	void setDay(int day) {
		this->day = day;
	}

	int getSecond() {
		return second;
	}

	int getMinute() {
		return minute;
	}

	int getHour() {
		return hour;
	}

	int getDay() {
		return day;
	}

	bool operator==(Time &time) { /* overload comparison */
		return time.getSecond() == getSecond()
				&& time.getMinute() == getMinute()
				&& time.getHour() == getHour() && time.getDay() == getDay();
	}

	Time operator+(Time &time) { /* same addition */
		return Time(time.getSecond() + getSecond(),
				time.getMinute() + getMinute(), time.getHour() + getHour(),
				time.getDay() + getDay());
	}

	Time operator-(Time &time) { /* soustraction */
		return Time(time.getSecond() - getSecond(),
				time.getMinute() - getMinute(), time.getHour() - getHour(),
				time.getDay() - getDay());
	}

	void show() {
		cout << "Seconds = " << getSecond() << " Minutes = " << getMinute()
				<< " Hours = " << getHour() << " Days = " << getDay() << endl;
	}
};

int main() {
	Time t1;
	Time t2(1);
	Time t3(1, 2);
	Time t4(1, 2, 3);
	Time t5(1, 2, 3, 4);
	Time *t6 = new Time(745, 56, 8, 1); /* test the conversion */

	t1.show();
	t2.show();
	t5.show();
	t6->show();
}

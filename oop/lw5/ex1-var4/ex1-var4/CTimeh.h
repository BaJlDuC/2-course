#pragma once

const int HOURS_LIMIT = 24;
const int MINUTES_LIMIT = 60;
const int SECONDS_LIMIT = 60;

class CTime
{
protected:
	unsigned hoursProtected, minutesProtected, secondsProtected, timeStampProtected;
public:
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);
	CTime(unsigned timeStamp = 0); //инициализация времени секундами после полуночи

	unsigned GetHours() const;
	unsigned GetMinutes() const;
	unsigned GetSeconds() const;

	CTime friend operator +(CTime &time1, CTime &time2);
	CTime friend operator -(CTime &time1, CTime &time2);
	CTime friend operator ++(CTime &time, int);
	CTime friend operator --(CTime &time, int);

	CTime friend operator *(CTime &time1, const unsigned &number);
	CTime friend operator *(const unsigned &number, CTime &time1);

	int friend operator /(CTime &time1, CTime &time2);
	CTime friend operator /(CTime &time1, const unsigned &number);

	bool friend operator==(CTime &time1, CTime &time2);
	bool friend operator!=(CTime &time1, CTime &time2);
	bool friend operator>(CTime &time1, CTime &time2);
	bool friend operator<(CTime &time1, CTime &time2);
	bool friend operator>=(CTime &time1, CTime &time2);
	bool friend operator<=(CTime &time1, CTime &time2);

	bool isValid() const;
};

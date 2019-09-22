#include "CTimeh.h"
#include "pch.h"
#include <stdexcept>
#include <iostream>

using namespace std;

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	hoursProtected = hours;
	minutesProtected = minutes;
	secondsProtected = seconds;
}

CTime::CTime(unsigned timeStamp)
{
	timeStampProtected = timeStamp;
}

unsigned CTime::GetHours() const
{
	return hoursProtected;
}

unsigned CTime::GetMinutes() const
{
	return minutesProtected;
}

unsigned CTime::GetSeconds() const
{
	return secondsProtected;
}

bool CTime::isValid() const
{
	if ((hoursProtected >= HOURS_LIMIT) || (minutesProtected >= MINUTES_LIMIT) || (secondsProtected >= MINUTES_LIMIT))
	{
		return false;
	}
	return true;
}
//----------------------------------------------------------------------------------------
CTime operator +(CTime &time1, CTime &time2)
{
	unsigned sumHours = 0, sumMinutes = 0, sumSeconds = 0;
	if ((time1.GetSeconds() + time2.GetSeconds()) >= SECONDS_LIMIT)
	{
		sumSeconds = (time1.GetSeconds() + time2.GetSeconds()) - SECONDS_LIMIT;
		sumMinutes++;
	}
	else
	{
		sumSeconds = time1.GetSeconds() + time2.GetSeconds();
	}
	if ((time1.GetMinutes() + time2.GetMinutes()) >= MINUTES_LIMIT)
	{
		sumMinutes += (time1.GetMinutes() + time2.GetMinutes()) - MINUTES_LIMIT;
		sumHours++;
	}
	else
	{
		sumMinutes += time1.GetMinutes() + time2.GetMinutes();
	}
	if ((time1.GetHours() + time2.GetHours()) >= HOURS_LIMIT)
	{
		sumHours += (time1.GetHours() + time2.GetHours()) - HOURS_LIMIT;
	}
	else
	{
		sumHours += time1.GetHours() + time2.GetHours();
	}
	CTime sum(sumHours, sumMinutes, sumSeconds);

	return sum;
}

CTime operator -(CTime &time1, CTime &time2)
{
	unsigned resultHours = 0, resultMinutes = 0, resultSeconds = 0;
	bool decrementNextValue = false;
	if (time1.GetSeconds() < time2.GetSeconds())
	{
		resultSeconds = SECONDS_LIMIT - (time2.GetSeconds() - time1.GetSeconds());
		decrementNextValue = true;
	}
	else
	{
		resultSeconds = time1.GetSeconds() - time2.GetSeconds();
	}
	if (time1.GetMinutes() < time2.GetMinutes())
	{
		if (decrementNextValue == true)
		{
			resultMinutes = MINUTES_LIMIT - (time2.GetMinutes() - time1.GetMinutes());
			resultMinutes--;
		}
		else
		{
			resultMinutes = MINUTES_LIMIT - (time2.GetMinutes() - time1.GetMinutes());
			decrementNextValue = true;
		}
	}
	else if (decrementNextValue == true)
	{
		if ((time1.GetMinutes() == 0) && (time2.GetMinutes() == 0)) //beg
		{
			resultMinutes = MINUTES_LIMIT - (time2.GetMinutes() - time1.GetMinutes());
			resultMinutes--;
		}
		else
		{
			resultMinutes = time1.GetMinutes() - time2.GetMinutes();
			resultMinutes--;
			decrementNextValue = false;
		} // end
	}
	else
	{
		resultMinutes = time1.GetMinutes() - time2.GetMinutes();
	}
	if (time1.GetHours() < time2.GetHours())
	{
		if (decrementNextValue == true)
		{
			resultHours = HOURS_LIMIT - (time2.GetHours() - time1.GetHours());
			resultHours--;
		}
		else
		{
			resultHours = HOURS_LIMIT - (time2.GetHours() - time1.GetHours());
		}
	}
	else if (decrementNextValue == true)
	{
		resultHours = time1.GetHours() - time2.GetHours();
		resultHours--;
	}
	else
	{
		resultHours = time1.GetHours() - time2.GetHours();
	}

	CTime result(resultHours, resultMinutes, resultSeconds);
	
	return result;
}

CTime operator++(CTime &time, int)
{
	unsigned newSeconds = time.GetSeconds();
	unsigned newMinutes = time.GetMinutes();
	unsigned newHours = time.GetHours();
	if (newSeconds == SECONDS_LIMIT - 1)
	{
		newSeconds = 0;
		newMinutes++;
	}
	else
	{
		newSeconds++;
	}
	if (newMinutes == MINUTES_LIMIT)
	{
		newMinutes = 0;
		newHours++;
	}
	if (newHours == HOURS_LIMIT)
	{
		newHours = 0;
	}
	CTime newTime(newHours, newMinutes, newSeconds);
	return newTime;
}

CTime operator--(CTime &time, int)
{
	unsigned newSeconds = time.GetSeconds();
	unsigned newMinutes = time.GetMinutes();
	unsigned newHours = time.GetHours();
	bool decrementNextValue = false;

	if (newSeconds == 0)
	{
		newSeconds = SECONDS_LIMIT - 1;
		decrementNextValue = true;
	}
	else
	{
		newSeconds--;
	}
	if ((newMinutes == 0) && (decrementNextValue == true))
	{
        newMinutes = MINUTES_LIMIT - 1;
	}
	else if (decrementNextValue == true)
	{
	    newMinutes--;
	    decrementNextValue = false;
	}
	if ((newHours == 0) && (decrementNextValue == true))
	{
		newHours = HOURS_LIMIT - 1;
	}
	else if (decrementNextValue == true)
	{
		newHours--;
	}

	CTime newTime(newHours, newMinutes, newSeconds);
	return newTime;
}

CTime operator *(CTime &time1, const unsigned &factor)
{
	unsigned resultHours = 0, resultMinutes = 0, resultSeconds = 0, resultCopy = 0;
	resultSeconds = time1.GetSeconds() * factor;
	resultCopy = resultSeconds;
	if (resultSeconds >= SECONDS_LIMIT)
	{
		resultSeconds = resultSeconds % SECONDS_LIMIT;
		resultMinutes += resultCopy / MINUTES_LIMIT;
	}
	resultMinutes += time1.GetMinutes() * factor;
	resultCopy = resultMinutes;
	if (resultMinutes >= MINUTES_LIMIT)
	{
		resultMinutes = resultMinutes % MINUTES_LIMIT;
		resultHours += resultCopy / MINUTES_LIMIT;
	}
	resultHours += time1.GetHours() * factor;
	if (resultHours >= HOURS_LIMIT)
	{
		resultHours = resultHours % HOURS_LIMIT;
	}
	CTime result(resultHours, resultMinutes, resultSeconds);

	return result;
}

CTime operator *(const unsigned &factor, CTime &time1)
{
	unsigned resultHours = 0, resultMinutes = 0, resultSeconds = 0, resultCopy = 0;
	resultSeconds = time1.GetSeconds() * factor;
	resultCopy = resultSeconds;
	if (resultSeconds >= SECONDS_LIMIT)
	{
		resultSeconds = resultSeconds % SECONDS_LIMIT;
		resultMinutes += resultCopy / MINUTES_LIMIT;
	}
	resultMinutes += time1.GetMinutes() * factor;
	resultCopy = resultMinutes;
	if (resultMinutes >= MINUTES_LIMIT)
	{
		resultMinutes = resultMinutes % MINUTES_LIMIT;
		resultHours += resultCopy / MINUTES_LIMIT;
	}
	resultHours += time1.GetHours() * factor;
	if (resultHours >= HOURS_LIMIT)
	{
		resultHours = resultHours % HOURS_LIMIT;
	}
	CTime result(resultHours, resultMinutes, resultSeconds);

	return result;
}

int operator /(CTime &time1, CTime &time2)
{
	unsigned result = 0, secondsInTime1 = 0, secondsInTime2 = 0;
	secondsInTime1 = time1.GetSeconds() + time1.GetMinutes() * SECONDS_LIMIT + time1.GetHours() * MINUTES_LIMIT * SECONDS_LIMIT;
	secondsInTime2 = time2.GetSeconds() + time2.GetMinutes() * SECONDS_LIMIT + time2.GetHours() * MINUTES_LIMIT * SECONDS_LIMIT;
	if (secondsInTime2 == 0)
	{
		throw runtime_error("Division by zero");
	}
   
	result = secondsInTime1 / secondsInTime2;
	return result;
} 

CTime operator /(CTime &time1, const unsigned &divisor)
{
	unsigned resultHours = 0, resultMinutes = 0, resultSeconds = 0, secondsAfterDivision = 0, secondsInTime1 = 0;
	secondsInTime1 = time1.GetSeconds() + time1.GetMinutes() * SECONDS_LIMIT + time1.GetHours() * MINUTES_LIMIT * SECONDS_LIMIT;
	if (divisor == 0)
	{
		throw runtime_error("Division by zero");
	}
	secondsAfterDivision = secondsInTime1 / divisor;
	resultSeconds = secondsAfterDivision % SECONDS_LIMIT;
	resultMinutes = secondsAfterDivision / SECONDS_LIMIT;
	if (resultMinutes >= MINUTES_LIMIT)
	{
		resultMinutes %= MINUTES_LIMIT;
		resultHours = resultMinutes / MINUTES_LIMIT;
	}
	resultHours += secondsAfterDivision / SECONDS_LIMIT / MINUTES_LIMIT;

	CTime result(resultHours, resultMinutes, resultSeconds);

	return result;
}
//-------------------------------------------------------------------------------------
bool operator ==(CTime &time1, CTime &time2)
{
	if ((time1.GetHours() != time2.GetHours()) ||
		(time1.GetMinutes() != time2.GetMinutes()) ||
		(time1.GetSeconds() != time2.GetSeconds()))
	{
		return false;
	}
	return true;
}

bool operator !=(CTime &time1, CTime &time2)
{
	if ((time1.GetHours() == time2.GetHours()) &&
		(time1.GetMinutes() == time2.GetMinutes()) &&
		(time1.GetSeconds() == time2.GetSeconds()))
	{
		return false;
	}
	return true;
}

bool operator >(CTime &time1, CTime &time2)
{
	int secondsInTime1 = 0, secondsInTime2 = 0;
	secondsInTime1 = time1.GetSeconds() + time1.GetMinutes() * SECONDS_LIMIT + time1.GetHours() * MINUTES_LIMIT * SECONDS_LIMIT;
	secondsInTime2 = time2.GetSeconds() + time2.GetMinutes() * SECONDS_LIMIT + time2.GetHours() * MINUTES_LIMIT * SECONDS_LIMIT;
	if (secondsInTime1 < secondsInTime2)
	{
		return false;
	}
	return true;
}

bool operator <(CTime &time1, CTime &time2)
{
	int secondsInTime1 = 0, secondsInTime2 = 0;
	secondsInTime1 = time1.GetSeconds() + time1.GetMinutes() * SECONDS_LIMIT + time1.GetHours() * MINUTES_LIMIT * SECONDS_LIMIT;
	secondsInTime2 = time2.GetSeconds() + time2.GetMinutes() * SECONDS_LIMIT + time2.GetHours() * MINUTES_LIMIT * SECONDS_LIMIT;

	if (secondsInTime1 > secondsInTime2)
	{
		return false;
	}
	return true;
}

bool operator >=(CTime &time1, CTime &time2)
{
	int secondsInTime1 = 0, secondsInTime2 = 0;
	secondsInTime1 = time1.GetSeconds() + time1.GetMinutes() * SECONDS_LIMIT + time1.GetHours() * MINUTES_LIMIT * SECONDS_LIMIT;
	secondsInTime2 = time2.GetSeconds() + time2.GetMinutes() * SECONDS_LIMIT + time2.GetHours() * MINUTES_LIMIT * SECONDS_LIMIT;

	if (secondsInTime1 < secondsInTime2)
	{
		return false;
	}
	if (secondsInTime1 == secondsInTime2)
	{
		return true;
	}
	return true;
}

bool operator <=(CTime &time1, CTime &time2)
{
	int secondsInTime1 = 0, secondsInTime2 = 0;
	secondsInTime1 = time1.GetSeconds() + time1.GetMinutes() * SECONDS_LIMIT + time1.GetHours() * MINUTES_LIMIT * SECONDS_LIMIT;
	secondsInTime2 = time2.GetSeconds() + time2.GetMinutes() * SECONDS_LIMIT + time2.GetHours() * MINUTES_LIMIT * SECONDS_LIMIT;

	if (secondsInTime1 > secondsInTime2)
	{
		return false;
	}
	if (secondsInTime1 == secondsInTime2)
	{
		return true;
	}
	return true;
}
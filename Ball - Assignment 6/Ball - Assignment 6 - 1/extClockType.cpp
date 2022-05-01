#include "extClockType.h"

void extClockType::printTimeZone()
{
	cout << timeZone;
}

void extClockType::timeZoner(int a)
{
	switch (a)
	{
	case 1:
		timeZone = " UTC-12:00, Y";
		break;
	case 2:
		timeZone = " UTC-11:00, X";
		break;
	case 3:
		timeZone = " UTC-10:00, W";
		break;
	case 4:
		timeZone = " UTC-09:30, V†";
		break;
	case 5:
		timeZone = " UTC-09:00, V";
		break;
	case 6:
		timeZone = " UTC-08:00, U";
		break;
	case 7:
		timeZone = " UTC-07:00, T";
		break;
	case 8:
		timeZone = " UTC-06:00, S";
		break;
	case 9:
		timeZone = " UTC-05:00, R";
		break;
	case 10:
		timeZone = " UTC-04:00, Q";
		break;
	case 11:
		timeZone = " UTC-03:30, P†";
		break;
	case 12:
		timeZone = " UTC-03:00, P";
		break;
	case 13:
		timeZone = " UTC-02:00, O";
		break;
	case 14:
		timeZone = " UTC-01:00, N";
		break;
	case 15:
		timeZone = " UTC±00:00, Z";
		break;
	case 16:
		timeZone = " UTC+01:00, A";
		break;
	case 17:
		timeZone = " UTC+02:00, B";
		break;
	case 18:
		timeZone = " UTC+03:00, C";
		break;
	case 19:
		timeZone = " UTC+03:30, C†";
		break;
	case 20:
		timeZone = " UTC+04:00, D";
		break;
	case 21:
		timeZone = " UTC+04:30, D†";
		break;
	case 22:
		timeZone = " UTC+05 00, E";
		break;
	case 23:
		timeZone = " UTC+05:30, E†";
		break;
	case 24:
		timeZone = " UTC+05:45, E*";
		break;
	case 25:
		timeZone = " UTC+06:00, F";
		break;
	case 26:
		timeZone = " UTC+06:30, F†";
		break;
	case 27:
		timeZone = " UTC+07:00, G";
		break;
	case 28:
		timeZone = " UTC+08:00, H";
		break;
	case 29:
		timeZone = " UTC+08:45, H*";
		break;
	case 30:
		timeZone = " UTC+09:00, I";
		break;
	case 31:
		timeZone = " UTC+09:30, I†";
		break;
	case 32:
		timeZone = " UTC+10:00, K";
		break;
	case 33:
		timeZone = " UTC+10:30, K†";
		break;
	case 34:
		timeZone = " UTC+11:00, L";
		break;
	case 35:
		timeZone = " UTC+12:00, M";
		break;
	case 36:
		timeZone = " UTC+12:45, M*";
		break;
	case 37:
		timeZone = " UTC+13:00, M†";
		break;
	case 38:
		timeZone = " UTC+14:00, M†";
		break;
	default:
		timeZone = " UTC±00:00, Z";
	}
}

extClockType::extClockType(int hours, int minutes, int seconds, int timeZone)
{
	setTime(hours, minutes, seconds);

	timeZoner(timeZone);


}

extClockType::extClockType()
{
	setTime(0, 0, 0);
	timeZoner(0);

}
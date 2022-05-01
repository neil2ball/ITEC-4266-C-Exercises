#pragma once
#include "clockType.h"

class extClockType :
    public clockType
{
	string timeZone;

    public:

		void printTimeZone();
		void timeZoner(int a);

        extClockType(int hours, int minutes, int seconds, int timeZone);

        extClockType();


    private:

		int timeZones;

};


// Saw this problem on the internet and thought it would be fun to tackle. Took me about 20 minutes.
// My first solution was a complete mess, so I redid it in a way that was vastly more condensed.

// Problem: create an program that returns the smallest angle between the two hands of a clock for any given time.

#include "stdafx.h"
#include <iostream>

using namespace std;

double RetrieveDifferenceAngle(double time);

int main()
{
	double time;

	// Add some exquisite user interface
	cout << "Please enter the time in 24 hour format (e.g. 601 or 2213)...\n";
	cin >> time;

	double differenceAngle = RetrieveDifferenceAngle(time);

	cout << differenceAngle << " is the smaller angle between the two hands.\n";

	system("pause");
}

double RetrieveDifferenceAngle(double time) 
{
	double minuteAngle = fmod(time, 100); // Get the minutes out of 24 hour
	minuteAngle *= 6; // Every minute is 6 degrees

	double hourAngle = fmod((time - fmod(time, 100)) / 100, 12); // Remove minutes and convert 24 hour time to 12 hour; could be a little prettier
	hourAngle *= 30; // Every hour is 30 degrees

	// hourAngle has some special changes to be made based on how many minutes have passed

	hourAngle += minuteAngle * 2.5 / 30; // Every 30 degrees of the minute hand makes the hour hand go 2.5;

	double differenceAngle = abs(minuteAngle - hourAngle); // Absolute difference just in case the minute hand is behind the hour hand

	if (differenceAngle > 180)
		differenceAngle = 360 - differenceAngle; // We want the smallest angle of the two

	return differenceAngle;
}

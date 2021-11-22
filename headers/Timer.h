// (c) Marco Gilardi, 2017
#pragma once

#include <ctime>

class Timer
{
protected:
	virtual ~Timer() {};
	virtual void startTimer() = 0;
	virtual double getTime() = 0;
	virtual void resetTimer() = 0;

};

class LowResTimer : public Timer
{
private:
	clock_t timer;
	// timer
public:
	virtual ~LowResTimer() {}
	LowResTimer();
	void startTimer();
	double getTime();
	void resetTimer();
};

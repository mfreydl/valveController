/*
 * Tasking.h   -  Library for declaring scheduled tasks
 * Created by Mark C Freydl, 15 October 2017
 * Released into the public domain
 */
#ifndef Tasking_h
#define Tasking_h

#include "Arduino.h"

class Task
{
  protected:
    long startedAt;

  public:
    long startAt;
    Task();
    Task(long startMillis);
    void execute();
    Task getNext();
};


class LedTask : public Task
{
  public:
    int ledPin;
    int durationToKeep;
    int targetState;
    LedTask(long startMillis,int pin, int state, int duration); //:Task(startMillis);
    void execute(); //:Task::execute();
    Task getNext(); //:Task::getNext();
};


//class LedOffTask : public Task
//{
//  public:
//    int ledPin;
//    int durationToKeep;
//    int targetState;
//    LedOffTask(long startMillis,int ledPin, int duration);
//    void execute();
//    Task getNext();
//};

#endif

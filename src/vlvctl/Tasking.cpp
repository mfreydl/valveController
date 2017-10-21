#include "Arduino.h"
#include "Tasking.h"

Task::Task() { };
Task::Task(long ms)
{
  startAt = ms;
};

void Task::execute()
{
  startedAt = millis();
};


Task Task::getNext()
{
};


LedTask::LedTask(long ms, int pin, int state, int dur):Task(ms), ledPin(pin), targetState(state), durationToKeep(dur)
{
//  startAt = ms;
//  ledPin = pin;
//  durationToKeep = dur;
//  targetState = state;
};

void LedTask::execute()
{
  startedAt = millis();  // TODO: call for this from the base...
  digitalWrite(ledPin, targetState);
};

Task LedTask::getNext()
{
  //int nxState = (targetState == HIGH) ? LOW : HIGH;
  LedTask *nx = new LedTask(startAt + durationToKeep, ledPin, (targetState == HIGH) ? LOW : HIGH, 250);
  return nx;
};


//
//LedOffTask::LedOffTask(long ms, int pin, int dur):Task(ms)
//{
//  startAt = ms;
//  ledPin = pin;
//  durationToKeep = dur;
//};
//
//LedOnTask::execute()
//{
//  startedAt = millis();  // TODO: call for this from the base...
//  digitalWrite(ledPin, LOW);
//};
//
//Task LedOffTask::getNext()
//{
//  LedOnTask *nx = new LedOnTask(startAt + durationToKeep, ledPin, 100);
//  return nx;
//};


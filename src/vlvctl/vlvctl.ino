#include "Tasking.h"


int _ledPin = 13;


int _durationOn = 500; // milliseconds
int _durationOff = 100; // milliseconds

Task _nextTasks[1] = { }; // = { new Task(millis()) };


void setup() {
  // put your setup code here, to run once:
  pinMode(_ledPin, OUTPUT);

  Task bill = new LedTask(millis(), _ledPin, HIGH, _durationOn);

  _nextTasks[0] = bill;
}


void loop() {

  // ok, it's x-o'clock...
  long now = millis();

  // Who's next task is overdue?
  for (int i=0; i < sizeof(_nextTasks); i++)
  {
    Task task = _nextTasks[i];
    if (task.startAt < now)
    {
      task.execute();
      Task nxTask = task.getNext();
      _nextTasks[i] = nxTask;
    }
  }


  //  digitalWrite(_ledPin, HIGH);
  //  delay(100);
  //  digitalWrite(_ledPin, LOW);
  //  delay(100);

}




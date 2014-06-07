WiredHubsanController
=====================

To control a Hubsan X4 using the built in controller, an Arduino can be hardwired into it to read the values
from the control sticks, modify them, and feed them back into the controller for broadcasting to the X4

1) Open the controller for the X4
2) Carefully expose the copper traces for all four potentiometers connected to each axis of the control sticks
3) wire that signal into the Arduinos input pins
4) Modify the signal as you see fit and send it back out through the arduinos output pins
5) use an appropriate rc filter to smooth the PWM signal genrated by the arduino
6) feed that smoothed signal back into the handset from where you originally spliced it out.

7) Enjoy a computer controlled quad copter!

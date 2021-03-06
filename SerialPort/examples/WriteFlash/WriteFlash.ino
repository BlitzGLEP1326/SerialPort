// Test write() time for a flash string.
#include <SerialPort.h>

SerialPort<0, 0, 32> port;

void setup(void) {
  port.begin(9600);
  
  for (int route = 0; route < 11; route++) {
    uint32_t start = micros();
    port.writeln(F("Selecting passenger route x"));
    uint32_t stop = micros();
    port.write(F("Message time: "));
    port.print(stop - start, DEC);
    port.writeln(F(" us"));
    delay(400);
  }
  port.println(F("Done!"));
}
void loop(void) {}

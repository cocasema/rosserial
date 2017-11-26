/*
 * MbedHardware
 *
 *  Created on: Aug 17, 2011
 *      Author: nucho
 */

#ifndef ROS_MBED_HARDWARE_H_
#define ROS_MBED_HARDWARE_H_

#include "mbed.h"

#include "BufferedSerial.h"

class MbedHardware
{
public:
  MbedHardware(PinName tx, PinName rx, long baud = 57600)
      : iostream(tx, rx)
  {
    baud_ = baud;
    t.start();
  }

  MbedHardware()
      : iostream(USBTX, USBRX)
  {
    baud_ = 57600;
    t.start();
  }

  void setBaud(long baud) { this->baud_ = baud; }

  int getBaud() { return baud_; }

  void init() { iostream.baud(baud_); }

  int read() { return iostream.readable() ? iostream.getc() : -1; }

  void write(uint8_t* data, int length) { iostream.write(data, length); }

  unsigned long time() { return t.read_ms(); }

protected:
  BufferedSerial iostream;
  long baud_;
  Timer t;
};


#endif /* ROS_MBED_HARDWARE_H_ */

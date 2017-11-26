/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

char debug[] = "debug statements";
char info[] = "infos";
char warn[] = "warnings";
char errors[] = "errors";
char fatal[] = "fatalities";

int main()
{
  nh.initNode();
  nh.advertise(chatter);

  while (1) {
    str_msg.data = hello;
    chatter.publish(&str_msg);

    nh.logdebug(debug);
    nh.loginfo(info);
    nh.logwarn(warn);
    nh.logerror(errors);
    nh.logfatal(fatal);

    nh.spinOnce();
    wait_ms(500);
  }
}

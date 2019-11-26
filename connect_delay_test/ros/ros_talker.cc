/**
 * Copyright (c) 2019, Chao Wang
 *  All rights reserved.
 *    Files: lcm_listener.cc
 *      Created by aidous on 19-11-26.
 *        Email: aidous.mr.w@gmail.com
 */

#include <iostream>

#include "ros/ros.h"
#include "nav_msgs/Path.h"
#include "cyber/deps/cyber/include/cyber/time/time.h"

using apollo::cyber::Time;

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;

    ros::Publisher path_pub_ =
        nh.advertise<nav_msgs::Path>("channel/chatter", 1);

    ros::Rate rate(10.0);
    const std::string foo_content(307200, '+');  // 307200 = 480 * 640
    int count = 0;
    while (ros::ok()) {
        nav_msgs::Path msg;
        msg.header.frame_id = foo_content;

        std::stringstream ss;
        ss << Time::Now().ToNanosecond();;
        msg.header.frame_id.append(ss.str());

        path_pub_.publish(msg);

        ++count;
        if (count == 1000) {
            std::cout << "talk over" << std::endl;
            break;
        }

        rate.sleep();
    }

    return 0;
}

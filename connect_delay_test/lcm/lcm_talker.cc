/**
 * Copyright (c) 2019, Chao Wang
 *  All rights reserved.
 *    Files: lcm_talker.cc
 *      Created by aidous on 19-11-26.
 *        Email: aidous.mr.w@gmail.com
 */
#include <iostream>
#include <sstream>

#include <ros/ros.h>
#include <lcm/lcm-cpp.hpp>
#include "lcmtypes/exlcm/Example.hpp"
#include "cyber/deps/cyber/include/cyber/time/time.h"

using apollo::cyber::Time;

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;

    lcm::LCM lcm;
    if(!lcm.good())
        return 1;

    const std::string foo_content(307200, '+');  // 307200 = 480 * 640
    int count = 0;

    ros::Rate rate(10.0);
    while (ros::ok()) {
        exlcm::Example data;
        data.a = foo_content;

        std::stringstream ss;
        ss << Time::Now().ToNanosecond();
        data.a.append(ss.str());

        lcm.publish("channel/chatter", &data);

        ++count;
        if (count == 1000) {
            std::cout << "talk over" << std::endl;
            break;
        }

        rate.sleep();
    }

    return 0;
}
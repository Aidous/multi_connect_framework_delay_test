/**
 * Copyright (c) 2019, Chao Wang
 *  All rights reserved.
 *    Files: lcm_listener.cc
 *      Created by aidous on 19-11-26.
 *        Email: aidous.mr.w@gmail.com
 */

#include <iostream>
#include <fstream>

#include "ros/ros.h"
#include "nav_msgs/Path.h"
#include "cyber/deps/cyber/include/cyber/time/time.h"
#include "cyber/deps/cyber/include/cyber/common/environment.h"

using apollo::cyber::Time;
using apollo::cyber::common::GetEnv;

std::ofstream outFile;
uint64_t count = 0;
uint64_t latency = 0;
uint64_t total_latency = 0;
void MessageCallback(const nav_msgs::Path& msg) {
    uint64_t now = Time::Now().ToNanosecond();;
    std::string ts(msg.header.frame_id, 307200);
    latency = now - std::stoul(ts);
    total_latency += now - std::stoul(ts);
    ++count;

    outFile << count << ',' << latency / 1000 << std::endl;

//    std::cout << "count: " << count
//              << " latency_us: " << latency / 1000 << std::endl;
//  std::cout << "receive msg: " << msg.header.frame_id;
}

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;

    ros::Subscriber path_sub_ =
        nh.subscribe("channel/chatter", 1,
                     &MessageCallback);

//    std::string scripts_path = GetEnv("CYBER_PATH");
    outFile.open("rosdata.csv", std::ios::out);
    outFile << "counter" << ',' << "latency" << std::endl;

    ros::spin();

    std::cout << "count: " << count
              << " avg_latency_us: "
              << total_latency / count / 1000 << std::endl;

    outFile.close();

    return 0;
}


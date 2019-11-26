/**
 * Copyright (c) 2019, Chao Wang
 *  All rights reserved.
 *    Files: lcm_listener.cc
 *      Created by aidous on 19-11-26.
 *        Email: aidous.mr.w@gmail.com
 */

#include <iostream>
#include <fstream>

#include <lcm/lcm-cpp.hpp>
#include "lcmtypes/exlcm/Example.hpp"
#include "cyber/deps/cyber/include/cyber/time/time.h"

using apollo::cyber::Time;

std::ofstream outFile;
uint64_t count = 0;
uint64_t latency = 0;
uint64_t total_latency = 0;
class Handler {
 public:
 Handler() {}
 void handleMessage(const lcm::ReceiveBuffer* rbuf,
                    const std::string& chan,
                    const exlcm::Example* msg)
 {
     uint64_t now_nano = Time::Now().ToNanosecond();
     std::string ts(msg->a, 307200);
     total_latency += now_nano - std::stoul(ts);
     latency = now_nano - std::stoul(ts);
     ++count;

     outFile << count << ',' << latency / 1000 << std::endl;
//     std::cout << "count: " << count
//               << " latency_us: " << latency / 1000 << std::endl;
 }
};

int main(int argc, char* argv[]) {
    lcm::LCM lcm;
    if(!lcm.good())
        return 1;

    Handler handlerObject;
    lcm.subscribe("channel/chatter",
                  &Handler::handleMessage, &handlerObject);

    outFile.open("lcmdata.csv", std::ios::out);
    outFile << "counter" << ',' << "latency" << std::endl;

    while(0 == lcm.handle());

    std::cout << "count: " << count
              << " latency_us: " << total_latency / count / 1000 << std::endl;

    return 0;
}
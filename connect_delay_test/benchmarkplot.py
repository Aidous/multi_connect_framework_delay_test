#!/usr/bin/env python2.7
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
#filename = ["line-limit-1.csv", "line-limit-2.csv", "pulse-limit-1.csv", "pulse-limit-2.csv", "saw-limit-1.csv"]
filename = ["cyberdata.csv", "rosdata.csv", "lcmdata.csv"]

data_cyber = pd.read_csv(filename[0])
cybercount = data_cyber["counter"]
cyberlatency = data_cyber["latency"]

data_ros = pd.read_csv(filename[1])
roscount = data_ros["counter"]
roslatency = data_ros["latency"]

data_lcm = pd.read_csv(filename[2])
lcmcount = data_lcm["counter"]
lcmlatency = data_lcm["latency"]

fig1 =  plt.figure("benchmark")
sub1 =  plt.subplot(111)
sub1.set_xlabel('counter')
sub1.set_ylabel('latency')
sub1.plot(cybercount, cyberlatency, c='blue', label='cyber')
sub1.plot(roscount, roslatency, c='green', label='ros')
sub1.plot(lcmcount, lcmlatency, c='red', label='lcm')

sub1.legend()
plt.show()

# multi_connect_framework_delay_test
The simple delay tesing based on apollo-cyber, ros-1, lcm.

## Build
```
catkin build connect_delay_test
```

## Test lcm
```
source src/connect_delay_test/setup.bash
```

- Talker
```
lcm_talker
```

- Listener
```
lcm_listener
```

## Test ros
```
source src/connect_delay_test/setup.bash
```

- Talker
```
ros_talker
```

- Listener
```
ros_listener
```

## Test cyber
```
source src/connect_delay_test/setup.bash
```

- Talker
```
cyber_talker
```

- Listener
```
cyber_listener
```

## Data display
```
python benchmarkplot.py 
```

## simple results

![benchmark](https://github.com/Aidous/multi_connect_framework_delay_test/blob/master/connect_delay_test/benchmark.png)

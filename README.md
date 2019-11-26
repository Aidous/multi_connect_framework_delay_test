# Multi_connect_framework_delay_test
The simple delay tesing based on apollo-cyber, ros-1, lcm.

## Build
```
catkin build connect_delay_test
```

## Test [lcm](https://github.com/lcm-proj/lcm)
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

## Test [ros1](http://www.ros.org)
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

## Test [cyber](https://github.com/ApolloAuto/apollo/edit/master/cyber)
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

## Simple results

![benchmark](https://github.com/Aidous/multi_connect_framework_delay_test/blob/master/connect_delay_test/benchmark.png)

### Create Workspace

```
mkdir -p ~/dev_ws/src
cd ~/dev_ws/src

rosdep install -i --from-path src --rosdistro foxy -y

colcon build (From the root of workspace)
```

```
source /opt/ros/foxy/setup.bash

cd ~/dev_ws

. install/local_setup.bash
```


### Create Package

```
cd ~/dev_ws/src

ros2 pkg create --build-type ament_cmake <pkg name>
```



### Build Package

```
cd ~/dev_ws

colcon build
colcon build --packages-select <pkg name>

. install/setup.bash
```



### Run Package

```
ros2 run <pkg name> <pkg node>
```



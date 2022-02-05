- [1.安装配置ros环境](#1安装配置ros环境)
- [2.ros文件系统介绍](#2ros文件系统介绍)
- [3.创建程序包](#3创建程序包)
- [4.编译程序包](#4编译程序包)
- [5.ros节点Node](#5ros节点node)
- [6.话题topic](#6话题topic)
- [7.rosservice and rosparam](#7rosservice-and-rosparam)
- [8.使用 rqt_console 和 roslaunch](#8使用-rqt_console-和-roslaunch)
- [9.使用rosed编辑ROS中的文件](#9使用rosed编辑ros中的文件)
- [10.创建ROS消息和ROS服务](#10创建ros消息和ros服务)
- [11.写一个简单的消息发布器和订阅器（C++）  //todo](#11写一个简单的消息发布器和订阅器c--todo)
- [12.写一个简单的消息发布器和订阅器（python）](#12写一个简单的消息发布器和订阅器python)
- [13.编写简单的Service和Client(C++)  //todo](#13编写简单的service和clientc--todo)
- [14.编写简单的Service和Client(python)](#14编写简单的service和clientpython)
- [15.录制与回放](#15录制与回放)
- [16.ros系统自检](#16ros系统自检)
- [17.管理依赖包](#17管理依赖包)
# 1.安装配置ros环境
```
  $ mkdir -p ~/catkin_ws/src
  $ cd ~/catkin_ws/src
  $ cd ~/catkin_ws/
  $ catkin_make
  $ source devel/setup.bash //使当前工作空间置为顶层
```
# 2.ros文件系统介绍
  packages 软件包，包含程序库、可执行文件、脚本或者其它手动创建的东西  
  Manifest (package.xml): 清单，描述软件包相关元信息之间的依赖关系，这些信息包括版本、维护者和许可协议等 
  ``` 
  $ rospack find [包名称] //返回软件包路径  
  $ roscd [本地包名称[/子目录]] //直接进入软件包  
  $ roscd log  //进入ros日志  
  $ rosls [本地包名称[/子目录]]   
  $ roscp [package_name] [file_to_copy_path] [copy_path]  
  ```
# 3.创建程序包
  程序包中含有 CMakeLists.txt package.xml  
  ```
  $ catkin_create_pkg <package_name> [depend1] [depend2] [depend3]  
  $ cd ~catkin_ws/src  
  $ catkin_create_pkg beginner std_msgs rospy roscpp //创建程序包beginner，后面三个是依赖项  
  $ rospack depends1 beginner_tutorials  //查看一级依赖包  
  $ rospack depends beginner_tutorials  //查看所有依赖  
  ```
# 4.编译程序包
```
$ catkin_make --source my_src  //如果程序包不在src中，则加上source 程序包路径
```
# 5.ros节点Node
  ros允许不同的编程语言编写的程序之间相互通讯 rospy = python 客户端库 roscpp = c++ 客户端库  
  ```
  $ roscore  //运行所有程序之前必须运行这命令
  $ rosnode list   //查看活跃的节点
  $ rosnode info /rosout   //查看/rosout 这个节点的信息
  $ rosrun [package_name] [node_name]  //运行节点
  $ rosnode ping my_turtle（节点名）  //ping节点
  ```
# 6.话题topic
  使用rqt—graph  
  ```
  安装rqt
  $ sudo apt-get install ros-<distro>-rqt
  $ sudo apt-get install ros-<distro>-rqt-common-plugins
  ```
  ```
  $ rosrun rqt_graph rqt_graph   //运行rqt—graph
  $ rostopic -h  //获取帮助命令
  $ rostopic echo [topic]  //打印话题
  $ rostopic list 
  $ rostopic type [topic]  //查看话题的消息类型
  $ rosmsg show 消息类型   //显示msg的格式
  $ rostopic pub [topic] [msg_type] [args]  //在终端中发布消息
  $ rostopic pub /turtle1/cmd_vel geometry_msgs/Twist -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'  //z.B with params
  $ rostopic type /turtle1/cmd_vel | rosmsg show   //结合显示msg
  $ rosrun rqt_plot rqt_plot   //plot工具
  ```
# 7.rosservice and rosparam
```
  rosservice list         //输出可用服务的信息
  rosservice type [service] 
  rossrv show [service_type]  //查看服务参数  
  rosservice call [service] [args]   //调用服务，args及上面的服务参数
  rosparam delete         删除参数
  rosparam list           列出参数名
  $ rosparam set [param_name]   //设置参数
  $ rosservice call clear    //设置完参数后调用clear service 刷新
  $ rosparam set background_r 150
  $ rosparam get [param_name]  //获取参数
  $ rosparam get background_g   //获取指定参数
  $ rosparam get /      //查看所有参数
  $ rosparam dump [file_name]   //向文件中写入参数
  $ rosparam dump params.yaml
  $ rosparam load [file_name] [namespace]  //从文件读取参数
  $ rosparam load params.yaml copy
  $ rosparam get copy/background_b
```
# 8.使用 rqt_console 和 roslaunch
```
  $ rosrun rqt_console rqt_console   //用来显示节点的输出信息
  $ rosrun rqt_logger_level rqt_logger_level //修改日志等级
  $ roslaunch [package] [filename.launch]  //运行多个节点
  
  $ roscd [package]
  $ mkdir launch
  $ cd launch
  创建launch文件
  <launch>

  <group ns="turtlesim1">
    <node pkg="turtlesim" name="sim" type="turtlesim_node"/>
  </group>

  <group ns="turtlesim2">
    <node pkg="turtlesim" name="sim" type="turtlesim_node"/>
  </group>

  <node pkg="turtlesim" name="mimic" type="mimic">
    <remap from="input" to="turtlesim1/turtle1"/>
    <remap from="output" to="turtlesim2/turtle1"/>
  </node>

  </launch
```
# 9.使用rosed编辑ROS中的文件
  $ rosed [package_name] [filename]  
  在~/.bashr 增加 export EDITOR='emacs -nw'  //将默认编辑器改为emacs，如果不改编辑器可不用这一步
# 10.创建ROS消息和ROS服务
  消息(msg): msg文件就是一个描述ROS中所使用消息类型的简单文本。它们会被用来生成不同语言的源代码。 //msg文件存放在package的msg目录下    
  ##msg文件实例  
  Header header  
  string child_frame_id  
  geometry_msgs/PoseWithCovariance pose  
  geometry_msgs/TwistWithCovariance twist  
  
  为了确保msg文件被转换成为C++，Python和其他语言的源代码，查看package.xml, 确保它包含一下两条语句:
  
  <build_depend>message_generation</build_depend>  
  <exec_depend>message_runtime</exec_depend>  
  
  此外需要更改CmakeList.txt //看roswiki第10课  
  $ rosmsg show [package名]/[消息名]  //z.B rosmsg show beginner_tutorials/Num 或者 rosmsg show Num  ，package名可以省略  
  
  服务(srv): 一个srv文件描述一项服务。它包含两个部分：请求和响应  //srv文件则存放在package的srv目录下  
  srv文件实例  
  int64 A  
  int64 B  
  ---               //上面是请求，下面是响应  
  int64 Sum  

  将上面实例的.srv文件放在srv文件夹下  
  修改CmakeList.txt   //详情见roswiki  
  ##rossrv show <service type>  //与rosmsg同理  
# 11.写一个简单的消息发布器和订阅器（C++）  //todo  
# 12.写一个简单的消息发布器和订阅器（python） 
``` 
  $ roscd beginner_tutorials
  $ mkdir scripts
  $ cd scripts //在此文件夹中放入发布和订阅的两个文件，即talker.py  listener.py
  别忘记编译catkin_make
  $ cd ~/catkin_ws
  $ source ./devel/setup.bash
  $ roscore
  $ rosrun beginner_tutorials talker.py
  $ rosrun beginner_tutorials listener.py
```
# 13.编写简单的Service和Client(C++)  //todo
# 14.编写简单的Service和Client(python)
  service脚本放在scripts下  //脚本实例见附录
  $ chmod +x scripts/add_two_ints_server.py  //给脚本执行权限
# 15.录制与回放
  $ rosbag record -h  //rosbag record -o subset /turtle1/command_velocity /turtle1/pose   //记录两个话题，包名为subset
  ##rosbag play <your bagfile>
# 16.ros系统自检
  $ roscd  
  $ roswtf  
# 17.管理依赖包
  $ roscd [package]    
  $ rosdep install [package]  

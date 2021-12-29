- [Docker](#docker)
  - [Introduction](#introduction)
  - [命令](#命令)
    - [帮助命令](#帮助命令)
    - [镜像命令](#镜像命令)
    - [容器命令](#容器命令)
      - [新建并启动容器](#新建并启动容器)
      - [退出容器](#退出容器)
      - [重新进入容器](#重新进入容器)
      - [删除容器](#删除容器)
      - [查看日志](#查看日志)
      - [拷贝容器中的文件到主机](#拷贝容器中的文件到主机)
      - [将容器新建为image](#将容器新建为image)
      - [其他](#其他)
  - [数据卷volume](#数据卷volume)
    - [命令建立数据卷](#命令建立数据卷)
    - [dockerfile建立数据卷](#dockerfile建立数据卷)
    - [容器间共享数据卷](#容器间共享数据卷)
  - [Dockerfile](#dockerfile)
    - [关键字](#关键字)
    - [build](#build)
# Docker
## Introduction
可以理解为轻量级沙盒机制虚拟机  
主要构成： 
* 镜像image
* 容器container
* 仓库repository  
从镜像产生容器，镜像可以来自远端服务器仓库，也可以来自本地。
## 命令
**核心命令 --help** 官方文档0.0
### 帮助命令
```
$ docker version //查看版本
$ docker info //查看详细的信息
$ docker --help //帮助文档
```
### 镜像命令
```
$ docker images //list all images
$ docker search //Search the Docker Hub for images
$ docker pull ubuntu  //Pull an image or a repository from a registry
$ docker rmi  //Remove one or more images
$ docker rmi -f $(docker images -qa) //组合命令
$ docker history {image的名字} //查看image变化历史
```
### 容器命令
#### 新建并启动容器
```
$ docker run [OPTIONS] IMAGE [COMMAND] [ARG...] 
options
-i 开启交互
-t 开启伪终端，与-i一般一起使用
--name string 为容器命名
-d 后台启动，后台启动的容器必须要有前台进程，否则就会自动停止退出
```
#### 退出容器
1. exit //容器停止推出
2. ctrl+P+Q //容器不停止退出
#### 重新进入容器
```
docker attach [container] //重新进入容器
docker exec [container] //在容器中执行进程并返还结果
docker exec zyh ls
```
#### 删除容器
```
$ docker rm 
```
#### 查看日志
```
Usage:  docker logs [OPTIONS] CONTAINER
Fetch the logs of a container
Options:
  -f, --follow         Follow log output
  -n, --tail string    Number of lines to show from the end of the logs
                       (default "all")
  -t, --timestamps     Show timestamps
```
#### 拷贝容器中的文件到主机
```
docker cp [OPTIONS] CONTAINER:SRC_PATH DEST_PATH
docker cp [OPTIONS] SRC_PATH CONTAINER:DEST_PATH
```
#### 将容器新建为image
```
Usage:  docker commit [OPTIONS] CONTAINER [REPOSITORY[:TAG]]

Create a new image from a container's changes

Options:
  -a, --author string    Author (e.g., "John Hannibal Smith
                         <hannibal@a-team.com>")
  -c, --change list      Apply Dockerfile instruction to the created image
  -m, --message string   Commit message
  -p, --pause            Pause container during commit (default true)
```
#### 其他
```
$ docker ps //查看运行了哪些容器
$ docker start [容器名字或ID] //启动
$ docker restart [容器名字或ID] //重启
$ docker stop [容器名字或ID] //正常停止
$ docker kill [容器名字或ID] //强制杀掉容器
$ docker top [container] //查看容器内进程
$ docker inspect [container]
```
## 数据卷volume
实现容器与容器，容器与主机之间的数据共享
### 命令建立数据卷
```
docker run -it -v /主机绝对路径:/容器内路径 image
docker run -it -v /主机绝对路径:/容器内路径:ro image  //read only
```
### dockerfile建立数据卷
1. 建立dockerfile
2. docker build -f {docker file 路径} -t zyh/ubuntu:1.3 .生成新镜像
3. run 
通过docker inspect查看主机的路径
```
//dockerfile的内容
# volume test
FROM centos
VOLUME ["/data1","/data2"]
CMD echo "zyh success"
CMD /bin/bash
```
### 容器间共享数据卷
```
docker run -it --name c1 ubuntu
docker run -it --name c2 --volume-from c1 ubuntu
```
## Dockerfile
用于构建image  
### 关键字
* FROM ubuntu//当前镜像基于哪个镜像
* MAINTAINER Zhang-yihang  \<zhang_yihang@126.com\>
* RUN //后面加需要运行的命令，入shell
* EXPOSE 当前容器对外的端口
* WORKDIR /data   //终端登陆后默认进来的目录
* ENV ZYH_PATH /usr/myfile 用来构建环境变量
* ADD  //拷贝加解压，后面加压缩文件
* COPY src dest || COPY ["src","dest"]//拷贝
* VOLUUME //数据卷
* CMD 指定容器启动时需要运行的命令，dockerfile 可以有多个CMD，但只有最后一个生效。而且会被docker run 后面的命令替换
* ENTRYPOINT 与CMD一样，但docker run 后面的命令会被添加
* ONBUILD 被继承的时候运行
### build
```
$ docker build -t nginx:v3 .
$ docker build -f {docker file 路径} -t zyh/ubuntu:1.3 .
```
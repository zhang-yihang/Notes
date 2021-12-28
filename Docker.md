- [Docker](#docker)
  - [Introduction](#introduction)
  - [命令](#命令)
    - [帮助命令](#帮助命令)
    - [镜像命令](#镜像命令)
    - [容器命令](#容器命令)
      - [新建并启动容器](#新建并启动容器)
      - [退出容器](#退出容器)
      - [删除容器](#删除容器)
      - [其他](#其他)
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
```
### 容器命令
#### 新建并启动容器
```
$ docker run [OPTIONS] IMAGE [COMMAND] [ARG...] 
options
-i 开启交互
-t 开启伪终端，与-i一般一起使用
--name string 为容器命名
```
#### 退出容器
1. exit //容器停止推出
2. ctrl+P+Q //容器不停止退出
#### 删除容器
```
$ docker rm 
```
#### 其他
```
$ docker ps //查看运行了哪些容器
$ docker start [容器名字或ID] //启动
$ docker restart [容器名字或ID] //重启
$ docker stop [容器名字或ID] //正常停止
$ docker kill [容器名字或ID] //强制杀掉容器
```
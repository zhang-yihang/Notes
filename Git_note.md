# Git_note  
## create repository  
```
$ mkdir name_dir
$ cd name_dir
$ git init
```
## add file and commit  
```
$ git add <name_file>  // after each change 
$ git commit -m 'messages'  
```
## commands
```
$ git status // get the status of repository
$ git diff <file> // get the difference 
$ git log //查看最近git修改日志
$ git reflog //记录版本变化的id

```
## 版本回退  
```
如果已经commit
$ git reset --hard Head^  //回退上一个版本
$ git reset --hard <id>   //回到id的版本
如果没有commit，且没有add
$ git checkout -- <file>  //丢弃工作区的修改，如果add后修改，则回到暂存区的状态，如果没add就修改，则回到工作区修改前的样子
如果没有commit，但是add
$ git reset Head <file> //撤销暂存区，然后回到上一步
$ git checkout -- <file> //其实就是用版本库里的文件替换工作区文件
```
## 删除文件
```
$ rm <file>
$ git rm <file>
$ git commit -m 'message'
如果删除错误，想回退
$ rm <file>

$ git checkout  -- <file>
如果已经git rm 
$ rm <file>
$ git rm <file>

$ git reset Head <file>
$ git checkout -- <file>
如果已经commit
$ rm <file>
$ git rm <file>
$ git commit -m 'message'

$ git reset --hard Head^  //回退上一个版本
```
## 远程仓库
建立github账户
创建SSH Key。

> 在用户主目录下，看看有没有.ssh目录，如果有，再看看这个目录下有没有`id_rsa`和`id_rsa.pub`这两个文件，如果已经有了，可直接跳到下一步。
>
> 如果没有，打开Shell（Windows下打开Git Bash），创建SSH Key：
> 一路回车，使用默认值即可，由于这个Key也不是用于军事目的，所以也无需设置密码。
>
> ```
> $ ssh-keygen -t rsa -C "youremail@example.com"
> ```
>
> 如果一切顺利的话，可以在用户主目录里找到`.ssh`目录，里面有`id_rsa`和`id_rsa.pub`两个文件，这两个就是SSH Key的秘钥对，`id_rsa`是私钥，不能泄露出去，`id_rsa.pub`是公钥，可以放心地告诉任何人。

将id_rsa.pub输入到github中
### 将本地git推给Github
第一次
```
git remote add origin git@github.com:zhang-yihang/Notes //添加远程库 origin
```

```
$ git push -u origin master //将本地master分支推给远程库origin
Counting objects: 20, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (15/15), done.
Writing objects: 100% (20/20), 1.64 KiB | 560.00 KiB/s, done.
Total 20 (delta 5), reused 0 (delta 0)
remote: Resolving deltas: 100% (5/5), done.
To github.com:michaelliao/learngit.git
 * [new branch]      master -> master
Branch 'master' set up to track remote branch 'master' from 'origin'.
```
以后
```
$ git push origin master
```
### 删除远程库
```
$ git remote -v //查看远程库信息
$ git remote rm origin //删除远程库与本地库的联系
```

### 从远程库克隆到本地  

```
$ git clone git@github.com:zhang-yihang/Notes
//也可以https://github.com/zhang-yihang/Notes 使用https协议，比较慢
```

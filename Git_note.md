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
$ git reset --hard Head^  //回退上一个版本
$ git reset --hard <id>   //回到id的版本
```


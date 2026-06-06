# Linux 和 Git 笔记

## 一、Linux命令行操作

### 1. 编译命令

```bash
# 编译C程序
gcc -I include src/main.c src/quiz_data.c src/quiz_utils.c -o bin/quiz.exe

# 运行程序
./bin/quiz.exe

# 将输出重定向到文件
./bin/quiz.exe > output/run_result.txt
```

### 2. run.sh 脚本说明

```bash
#!/bin/bash

# 创建输出目录
mkdir -p bin output

# 编译程序
echo "正在编译..."
gcc -I include src/main.c src/quiz_data.c src/quiz_utils.c -o bin/quiz

# 检查编译是否成功
if [ $? -eq 0 ]; then
    echo "编译成功！"
    echo "正在运行测试..."
    
    # 运行程序并保存输出
    ./bin/quiz > output/run_result.txt
    
    echo "测试完成！结果已保存到 output/run_result.txt"
else
    echo "编译失败！"
    exit 1
fi
```

### 3. 脚本使用方法

```bash
# 赋予执行权限
chmod +x run.sh

# 运行脚本
./run.sh

# 查看运行结果
cat output/run_result.txt
```

---

## 二、Git 操作指南

### 1. 仓库初始化

```bash
# 初始化本地仓库
git init

# 配置用户信息
git config user.name "zql139"
git config user.email "3362431677@qq.com"
```

### 2. 基本操作

```bash
# 添加文件到暂存区
git add .

# 提交到本地仓库
git commit -m "commit message"

# 查看状态
git status

# 查看提交历史
git log --oneline
```

### 3. 分支管理

```bash
# 创建分支
git checkout -b dev

# 切换分支
git checkout main

# 合并分支
git merge dev --no-ff -m "merge: dev分支合并"

# 删除分支
git branch -d dev
```

### 4. 远程仓库操作

```bash
# 添加远程仓库
git remote add origin https://github.com/zql139/electrical-safety-quiz.git

# 推送到远程
git push -u origin main

# 拉取远程代码
git pull origin main
```

### 5. 本次项目提交记录

```
06f3d23 docs: 更新Issue和PR记录
1626892 merge: 解决冲突，使用远程版本  
ae33aca merge: dev分支合并到main
b55a662 docs: 添加Linux和Git笔记
e3db66a test: 添加运行结果文件
4978b86 docs: 添加开发进度记录
07c21b0 feat: 初始化电气安全答题项目 v2.0
```

---

## 三、GitHub 仓库信息

### 仓库地址
- **GitHub**: https://github.com/zql139/electrical-safety-quiz

### 分支结构
```
main          # 主分支，稳定版本
└── dev       # 开发分支，功能开发
```

### Issue 记录
- **Issue #1**: 添加更多题目类型支持（待处理）

### Pull Request
- **PR #1**: dev分支合并到main（已完成）

---

## 四、常见问题解决

### 问题1：Git 推送失败

**错误信息**：
```
error: failed to push some refs to 'https://github.com/xxx/xxx.git'
```

**解决方法**：
```bash
git pull origin main --allow-unrelated-histories
# 解决冲突后重新提交
git add .
git commit -m "merge: 解决冲突"
git push origin main
```

### 问题2：编译错误

**错误信息**：
```
fatal error: quiz.h: No such file or directory
```

**解决方法**：
```bash
# 使用 -I 参数指定头文件目录
gcc -I include src/main.c src/quiz_data.c src/quiz_utils.c -o bin/quiz
```

### 问题3：脚本无法执行

**错误信息**：
```
bash: ./run.sh: Permission denied
```

**解决方法**：
```bash
chmod +x run.sh
```
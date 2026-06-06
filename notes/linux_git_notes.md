# Linux 和 Git 使用笔记

## 一、Linux 命令基础

### 1. 文件管理

```bash
# 查看当前目录
pwd

# 列出文件
ls -la

# 创建目录
mkdir -p src include output notebooks

# 删除文件/目录
rm file.txt
rm -rf dirname

# 复制文件
cp source.txt dest.txt
cp -r sourcedir destdir

# 移动文件
mv oldname.txt newname.txt

# 创建空文件
touch README.md
```

### 2. 编译命令

```bash
# 编译单个文件
gcc main.c -o main

# 编译多个文件
gcc -I include src/main.c src/quiz_data.c src/quiz_utils.c -o bin/quiz

# 编译并生成调试信息
gcc -g -I include src/*.c -o bin/quiz

# 使用makefile
make
make clean
```

### 3. 运行程序

```bash
# 运行可执行文件
./bin/quiz

# 后台运行
./bin/quiz &

# 重定向输出到文件
./bin/quiz > output.txt
./bin/quiz > output.txt 2>&1

# 管道命令
echo "1" | ./bin/quiz
```

## 二、Git 版本控制

### 1. 初始化仓库

```bash
# 创建新仓库
mkdir quiz-project
cd quiz-project
git init

# 配置用户信息
git config user.name "Your Name"
git config user.email "your.email@example.com"

# 添加远程仓库
git remote add origin https://github.com/yourusername/quiz-project.git
```

### 2. 基本操作

```bash
# 查看状态
git status

# 添加文件
git add .
git add src/main.c

# 提交
git commit -m "feat: 初始化项目结构"

# 查看日志
git log
git log --oneline

# 推送到远程
git push origin main
```

### 3. 分支管理

```bash
# 创建分支
git branch dev

# 切换分支
git checkout dev

# 创建并切换
git checkout -b feature/new-feature

# 查看分支
git branch -a

# 合并分支
git checkout main
git merge dev

# 删除分支
git branch -d feature/new-feature
```

### 4. 工作流示例

```bash
# 日常开发流程
git checkout dev
git pull origin dev

# 创建特性分支
git checkout -b feature/add-explanation

# 修改代码...
git add .
git commit -m "feat: 添加答错解释功能"

# 推送到远程
git push origin feature/add-explanation

# 创建Pull Request后合并
git checkout dev
git merge feature/add-explanation
git push origin dev
```

## 三、项目操作记录

### Commit 记录

| 序号 | 时间 | 提交信息 | 分支 |
|------|------|---------|------|
| 1 | 2026-06-06 | feat: 初始化项目结构 | main |
| 2 | 2026-06-06 | feat: 添加题库数据模块 | dev |
| 3 | 2026-06-06 | feat: 添加工具函数模块 | dev |
| 4 | 2026-06-06 | feat: 实现主程序逻辑 | dev |
| 5 | 2026-06-06 | feat: 添加答错解释功能 | dev |

### 分支合并记录

```bash
# dev -> main 合并
git checkout main
git merge dev --no-ff
git push origin main
```

## 四、常见问题

### 问题1：编译错误

```bash
# 错误：找不到头文件
# 解决：使用 -I 指定包含目录
gcc -I include src/main.c -o main
```

### 问题2：权限问题

```bash
# 错误：Permission denied
# 解决：添加执行权限
chmod +x run.sh
```

### 问题3：中文乱码

```bash
# 在Linux下设置UTF-8编码
export LANG=zh_CN.UTF-8
export LC_ALL=zh_CN.UTF-8
```

### 问题4：Git冲突

```bash
# 查看冲突文件
git status

# 手动解决冲突后
git add .
git commit -m "fix: 解决合并冲突"
```

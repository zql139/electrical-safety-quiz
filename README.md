# 电气安全常识课堂答题程序 v2.0

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub stars](https://img.shields.io/github/stars/YOUR_USERNAME/electrical-safety-quiz)](https://github.com/YOUR_USERNAME/electrical-safety-quiz/stargazers)

## GitHub 仓库

**🔗 仓库地址**：[https://github.com/YOUR_USERNAME/electrical-safety-quiz](https://github.com/YOUR_USERNAME/electrical-safety-quiz)

**⭐ 如何创建自己的GitHub仓库：**

1. 登录 [GitHub](https://github.com) 并注册账号
2. 点击右上角 **"+"** → **"New repository"**
3. 仓库名称填写：`electrical-safety-quiz`
4. 选择 **Public**（公开）
5. 勾选 **"Add a README file"**
6. 点击 **"Create repository"**

**📤 推送本地代码到GitHub：**

```bash
# 1. 在本地仓库初始化Git
git init

# 2. 添加所有文件
git add .

# 3. 首次提交
git commit -m "feat: 初始化电气安全答题项目 v2.0"

# 4. 添加远程仓库
git remote add origin https://github.com/YOUR_USERNAME/electrical-safety-quiz.git

# 5. 推送到GitHub
git branch -M main
git push -u origin main
```

## 项目简介

本项目是一个基于C语言的电气安全常识选择题答题系统，适用于课堂教学和自我测试。

### 功能特点

- **随机抽题**：从15道题库中随机抽取5道题目
- **计分系统**：答对+1分，答错-1分（可配置最低分）
- **即时反馈**：答错时显示正确答案和详细解释
- **结果统计**：显示最终得分、答对/答错数量

### 项目结构

```
├── src/                 # 源代码目录
│   ├── main.c          # 主程序入口
│   ├── quiz_data.c     # 题库数据
│   └── quiz_utils.c    # 工具函数
├── include/            # 头文件目录
│   └── quiz.h          # 数据结构和函数声明
├── output/             # 输出文件目录
│   └── run_result.txt  # 运行结果
├── notebooks/          # Jupyter笔记本目录
│   └── analysis.ipynb  # 数据分析
├── README.md           # 项目说明
├── prompt_log.md       # AI代码审查记录
├── run.sh              # Linux编译运行脚本
└── notes/              # 笔记目录
    └── linux_git_notes.md
```

## 快速开始

### 环境要求

- C语言编译器（GCC推荐）
- Python 3.8+（可选，用于数据分析）

### 编译运行

**方式1：使用run.sh脚本（Linux/Mac）**

```bash
chmod +x run.sh
./run.sh
```

**方式2：手动编译**

```bash
gcc -I include src/main.c src/quiz_data.c src/quiz_utils.c -o bin/quiz.exe
./bin/quiz.exe
```

### 运行测试

```bash
# 编译并运行测试
./run.sh test

# 查看输出结果
cat output/run_result.txt
```

## 使用说明

1. 运行程序后，查看规则说明
2. 按任意键开始答题
3. 输入1-4选择答案
4. 答题后按任意键继续下一题
5. 完成5道题后查看最终成绩

## 题库内容

题库包含15道电气安全常识选择题，涵盖：
- 触电急救知识
- 电气火灾预防
- 安全用电习惯
- 雷雨天气防护
- 接地保护知识

## AI代码审查

本项目包含完整的AI代码审查记录：

1. **初学者语言解释**：用简单易懂的语言解释C代码
2. **错误审查**：检查数组/结构体、计分逻辑、随机出题等问题
3. **边界测试用例**：8个测试场景覆盖各种输入情况
4. **代码审查清单**：代码质量和安全检查
5. **重构方案对比**：三种架构方案分析

## 贡献指南

### 分支管理

- `main`：主分支，稳定版本
- `dev`：开发分支，功能开发
- `feature/*`：特性分支，新功能

### 提交规范

```
feat: 添加新功能
fix: 修复bug
docs: 更新文档
refactor: 代码重构
test: 添加测试
```

## 许可证

MIT License - 详见 LICENSE 文件

## 作者信息

- 完成日期：2026-06-06
- 编程语言：C语言
- 开发环境：Windows/PowerShell / Linux

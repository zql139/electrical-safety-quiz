# 电气安全常识课堂答题程序 v3.0

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/Version-3.0-blue.svg)](https://github.com/zql139/electrical-safety-quiz)

## GitHub 仓库

**🔗 仓库地址**：[https://github.com/zql139/electrical-safety-quiz](https://github.com/zql139/electrical-safety-quiz)

## 项目简介

本项目是一个基于C语言的电气安全常识选择题答题系统，采用模块化设计，支持随机抽题、即时反馈和结果统计。

### 功能特点

- **随机抽题**：从15道题库中随机抽取5道题目
- **计分系统**：答对+1分，答错-1分
- **即时反馈**：答错时显示正确答案和详细解释
- **结果统计**：显示最终得分、答对/答错数量

---

## 重构说明 (v2.0 → v3.0)

### 重构目标

将v2.0的单文件代码重构为模块化架构，提高代码的可维护性、可扩展性和可测试性。

### 重构对比

#### v2.0（旧版本 - 单文件）

```
origin_main.c
├── 头文件包含
├── 常量定义
├── 结构体定义
├── 题库数据（15道题）
├── 主函数
│   ├── 初始化
│   ├── 洗牌算法
│   ├── 显示题目
│   ├── 获取输入
│   ├── 判断答案
│   └── 显示结果
└── 总计约 300+ 行
```

**问题**：
- 代码臃肿，单文件超过300行
- 职责不清晰，所有功能混在一起
- 难以测试单个功能
- 代码复用性差

#### v3.0（新版本 - 模块化）

```
├── include/
│   └── quiz.h           # 头文件（声明、宏定义）
├── src/
│   ├── main.c           # 主程序入口
│   ├── quiz_data.c      # 题库数据模块
│   └── quiz_utils.c     # 工具函数模块
└── 总计约 400+ 行（包含详细注释）
```

**优势**：
| 方面 | v2.0 | v3.0 |
|------|------|------|
| 代码组织 | 单文件 | 模块分离 |
| 可读性 | 一般 | 优秀 |
| 可维护性 | 困难 | 容易 |
| 可测试性 | 差 | 好 |
| 扩展性 | 差 | 好 |
| 代码复用 | 低 | 高 |

### 主要重构点

#### 1. 头文件分离 (quiz.h)

```c
// v2.0：常量直接写在源文件中
#define MAX_QUESTIONS 15

// v3.0：使用头文件管理所有声明
#ifndef QUIZ_H
#define QUIZ_H
// 所有声明、宏定义、结构体
#endif
```

**优点**：
- 统一管理接口
- 便于多文件共享定义
- 防止重复包含

#### 2. 题库数据模块化 (quiz_data.c)

```c
// v2.0：题库数据写在main函数所在文件
void initQuestions(Question questions[]) {
    // 15道题全部写在这里
}

// v3.0：独立模块
// quiz_data.c - 题库数据
// quiz_utils.c - 工具函数
// main.c - 主程序
```

**优点**：
- 题库扩展更方便
- 独立编译，减少编译时间
- 便于题库管理

#### 3. 函数封装

| 功能 | v2.0写法 | v3.0写法 |
|------|---------|---------|
| 输入清理 | while循环 | `clearInputBuffer()` |
| 题目显示 | printf嵌套 | `displayQuestion()` |
| 统计更新 | 直接修改变量 | `updateStats()` |
| 结果保存 | 无 | `saveResultsToFile()` |

#### 4. 结构体改进

```c
// v2.0：基础结构体
typedef struct {
    char question[200];
    char options[4][100];
    int answer;
    char explanation[300];
} Question;

// v3.0：扩展结构体（新增字段）
typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char options[4][MAX_OPTION_LENGTH];
    int answer;
    char explanation[MAX_EXPLANATION_LENGTH];
    int difficulty;    // 新增：难度等级
    int category;      // 新增：题目分类
} Question;

// v3.0：新增结构体
typedef struct {
    int question_id;
    int user_answer;
    int correct_answer;
    int is_correct;
    int score_change;
} QuizResult;

typedef struct {
    int total_questions;
    int correct_count;
    int wrong_count;
    int final_score;
} QuizStats;
```

#### 5. 编译方式

```bash
# v2.0：单文件编译
gcc origin_main.c -o quiz

# v3.0：多文件编译
gcc -I include src/main.c src/quiz_data.c src/quiz_utils.c -o quiz
```

---

## 项目结构

```
电气安全答题v3.0/
├── include/                 # 头文件目录
│   └── quiz.h             # 主头文件（数据结构和函数声明）
├── src/                    # 源代码目录
│   ├── main.c             # 主程序入口
│   ├── quiz_data.c        # 题库数据模块
│   ├── quiz_utils.c       # 工具函数模块
│   └── origin_main.c      # 旧版本代码（v2.0单文件，用于对比）
├── output/                 # 输出目录
│   └── run_result.txt     # 运行结果
├── notes/                  # 笔记目录
│   └── linux_git_notes.md # Linux和Git使用笔记
├── tools/                  # 工具目录
│   └── gen_tests.py       # 测试用例生成脚本
├── notebooks/              # Jupyter笔记本
│   └── test_record.ipynb  # 测试记录
├── README.md              # 项目说明
├── prompt_log.md          # AI代码审查记录
├── self_check.md          # 自我检查清单
├── git_log.txt            # Git提交日志
└── issue_or_pr.md         # Issue和PR记录
```

---

## 快速开始

### 环境要求

- C语言编译器（GCC推荐）
- Python 3.8+（用于数据分析，可选）

### 编译运行

```bash
# 使用run.sh脚本（Linux/Mac）
chmod +x run.sh
./run.sh

# 手动编译（Windows）
gcc -I include src/main.c src/quiz_data.c src/quiz_utils.c -o quiz.exe

# 运行程序
./quiz.exe
```

---

## 重构前后对比总结

| 指标 | v2.0 | v3.0 | 改进 |
|------|------|------|------|
| 代码行数 | ~300行 | ~400行 | 增加注释 |
| 文件数量 | 1个 | 4个 | 模块化 |
| 可维护性 | 低 | 高 | 职责分离 |
| 可扩展性 | 低 | 高 | 结构化设计 |
| 测试难度 | 高 | 低 | 模块独立 |
| 学习曲线 | 低 | 中 | 需要理解模块 |

---

## 作者信息

- 完成日期：2026-06-19
- 版本：v3.0
- 编程语言：C语言
- 开发环境：Windows/PowerShell / Linux

---

*项目版本：v3.0*
*重构日期：2026-06-19*

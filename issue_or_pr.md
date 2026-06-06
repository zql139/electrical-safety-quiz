# Issue 和 Pull Request 记录

## Issue #1: 添加更多题目类型支持

### 问题描述
当前程序仅支持单选题，建议增加多选题、判断题等题型，以丰富答题形式。

### 改进建议
1. 在 `quiz.h` 中扩展 `Question` 结构体，添加题型字段
2. 在 `quiz_data.c` 中添加多选题和判断题数据
3. 在 `quiz_utils.c` 中实现多选题和判断题的计分逻辑

### 优先级
- [ ] 高
- [x] 中
- [ ] 低

### 状态
- [x] 待处理
- [ ] 进行中
- [ ] 已完成

---

## Pull Request #1: dev分支合并到main

### PR信息
- **源分支**: dev
- **目标分支**: main
- **合并时间**: 2026-06-06
- **状态**: ✅ 已合并

### 提交记录
```
1626892 merge: 解决冲突，使用远程版本
ae33aca merge: dev分支合并到main
b55a662 docs: 添加Linux和Git笔记
e3db66a test: 添加运行结果文件
4978b86 docs: 添加开发进度记录
```

### 变更内容
- 添加了 `notes/linux_git_notes.md` - Linux和Git使用笔记
- 添加了 `output/run_result.txt` - 运行结果示例
- 添加了 `notes/dev_progress.md` - 开发进度记录

---

## 分支管理策略

### 分支结构
```
main          # 主分支，稳定版本
└── dev       # 开发分支，功能开发
    └── feature/*  # 特性分支（可选）
```

### 合并流程
1. 在dev分支开发新功能
2. 完成测试后合并到main分支
3. 使用 `--no-ff` 参数保留分支历史

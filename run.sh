#!/bin/bash

# 电气安全答题程序 - 编译运行脚本
# Usage: ./run.sh [test]

set -e

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# 目录定义
SRC_DIR="src"
INCLUDE_DIR="include"
BIN_DIR="bin"
OUTPUT_DIR="output"

# 创建必要目录
mkdir -p $BIN_DIR $OUTPUT_DIR

echo -e "${YELLOW}========================================${NC}"
echo -e "${YELLOW}    电气安全答题程序 - 编译脚本${NC}"
echo -e "${YELLOW}========================================${NC}"

# 编译程序
echo -e "\n${GREEN}[1/3] 编译源代码...${NC}"
gcc -I $INCLUDE_DIR \
    $SRC_DIR/main.c \
    $SRC_DIR/quiz_data.c \
    $SRC_DIR/quiz_utils.c \
    -o $BIN_DIR/quiz 2>&1

if [ $? -eq 0 ]; then
    echo -e "${GREEN}编译成功！${NC}"
else
    echo -e "${RED}编译失败！${NC}"
    exit 1
fi

# 运行程序
echo -e "\n${GREEN}[2/3] 运行程序...${NC}"
echo -e "${YELLOW}注意：交互式程序需要手动输入答案${NC}"

if [ "$1" = "test" ]; then
    # 测试模式：使用预设输入
    echo -e "\n${YELLOW}测试模式：自动输入答案...${NC}"
    { echo ""; echo "1"; echo ""; echo "2"; echo ""; echo "3"; echo ""; echo "4"; echo ""; echo "1"; echo ""; } | ./$BIN_DIR/quiz > $OUTPUT_DIR/run_result.txt
    echo -e "${GREEN}测试完成！输出已保存到 output/run_result.txt${NC}"
    
    # 显示结果
    echo -e "\n${GREEN}[3/3] 显示测试结果：${NC}"
    cat $OUTPUT_DIR/run_result.txt
else
    # 交互模式
    ./$BIN_DIR/quiz
fi

echo -e "\n${GREEN}========================================${NC}"
echo -e "${GREEN}           程序执行完成${NC}"
echo -e "${GREEN}========================================${NC}"

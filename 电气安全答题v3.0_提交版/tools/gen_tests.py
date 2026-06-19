#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@file gen_tests.py
@brief 测试用例生成脚本
@version 3.0

用于生成电气安全答题程序的测试用例
"""

import random
import json
from datetime import datetime

class TestCaseGenerator:
    """测试用例生成器类"""
    
    def __init__(self, num_cases=10):
        """初始化生成器"""
        self.num_cases = num_cases
        self.test_cases = []
        
    def generate_random_inputs(self):
        """生成随机输入序列"""
        # 生成5个1-4之间的随机答案
        answers = [random.randint(1, 4) for _ in range(5)]
        return answers
    
    def calculate_expected_score(self, answers, correct_answers):
        """计算预期分数"""
        score = 0
        for user_ans, correct_ans in zip(answers, correct_answers):
            if user_ans == correct_ans:
                score += 1
            else:
                score -= 1
        return score
    
    def generate_edge_cases(self):
        """生成边界测试用例"""
        edge_cases = [
            {
                "id": "TC001",
                "name": "全部答对",
                "inputs": [1, 1, 1, 1, 1],
                "expected_score": 5,
                "expected_correct": 5,
                "expected_wrong": 0,
                "priority": "高"
            },
            {
                "id": "TC002",
                "name": "全部答错",
                "inputs": [2, 2, 2, 2, 2],
                "expected_score": -5,
                "expected_correct": 0,
                "expected_wrong": 5,
                "priority": "高"
            },
            {
                "id": "TC003",
                "name": "输入非数字",
                "inputs": ["abc", "xyz", 1, 2, 3],
                "expected_behavior": "提示错误，要求重新输入",
                "priority": "高"
            },
            {
                "id": "TC004",
                "name": "输入超出范围",
                "inputs": [0, 5, -1, 10, 1],
                "expected_behavior": "提示错误，要求重新输入",
                "priority": "高"
            },
            {
                "id": "TC005",
                "name": "空输入",
                "inputs": ["", "", 1, 2, 3],
                "expected_behavior": "提示错误，要求重新输入",
                "priority": "中"
            },
            {
                "id": "TC006",
                "name": "混合答题",
                "inputs": [1, 2, 1, 2, 1],
                "expected_behavior": "根据实际题目计算分数",
                "priority": "高"
            },
            {
                "id": "TC007",
                "name": "多次错误输入后正确",
                "inputs": ["abc", "5", "0", 1, 1],
                "expected_behavior": "最终接受有效输入",
                "priority": "中"
            },
            {
                "id": "TC008",
                "name": "多次运行随机性",
                "inputs": None,
                "expected_behavior": "每次题目顺序不同",
                "priority": "高"
            }
        ]
        return edge_cases
    
    def generate_random_test_cases(self):
        """生成随机测试用例"""
        for i in range(self.num_cases):
            test_case = {
                "id": f"TC{random.randint(100, 999)}",
                "name": f"随机测试{i+1}",
                "inputs": self.generate_random_inputs(),
                "timestamp": datetime.now().isoformat(),
                "priority": random.choice(["高", "中", "低"])
            }
            self.test_cases.append(test_case)
        return self.test_cases
    
    def save_to_json(self, filename="test_cases.json"):
        """保存测试用例到JSON文件"""
        all_cases = {
            "edge_cases": self.generate_edge_cases(),
            "random_cases": self.generate_random_test_cases(),
            "generated_at": datetime.now().isoformat()
        }
        
        with open(filename, 'w', encoding='utf-8') as f:
            json.dump(all_cases, f, ensure_ascii=False, indent=2)
        
        print(f"测试用例已保存到: {filename}")
        return all_cases
    
    def print_test_cases(self):
        """打印测试用例"""
        print("\n" + "="*60)
        print("边界测试用例")
        print("="*60)
        
        edge_cases = self.generate_edge_cases()
        for tc in edge_cases:
            print(f"\n[{tc['id']}] {tc['name']}")
            print(f"  优先级: {tc['priority']}")
            if tc['inputs']:
                print(f"  输入: {tc['inputs']}")
            print(f"  预期: {tc['expected_behavior']}")

def main():
    """主函数"""
    print("="*60)
    print("    电气安全答题程序 - 测试用例生成工具 v3.0")
    print("="*60)
    
    # 创建生成器
    generator = TestCaseGenerator(num_cases=10)
    
    # 打印边界测试用例
    generator.print_test_cases()
    
    # 保存测试用例
    test_cases = generator.save_to_json("test_cases.json")
    
    # 生成测试报告
    print("\n" + "="*60)
    print("测试用例统计")
    print("="*60)
    print(f"边界测试用例: {len(test_cases['edge_cases'])} 个")
    print(f"随机测试用例: {len(test_cases['random_cases'])} 个")
    print(f"总计: {len(test_cases['edge_cases']) + len(test_cases['random_cases'])} 个")
    print("="*60)

if __name__ == "__main__":
    main()

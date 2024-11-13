#include <iostream>
#include <string>

#define MAX_SIZE 100 // 栈的最大容量

using namespace std;

// 顺序栈的定义
class Stack {
private:
    char data[MAX_SIZE];
    int top;

public:
    // 初始化栈
    Stack() {
        top = -1;
    }

    // 检查栈是否为空
    bool isEmpty() {
        return top == -1;
    }

    // 检查栈是否已满
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // 入栈操作
    bool push(char c) {
        if (!isFull()) {
            data[++top] = c;
            return true;
        }
        return false;
    }

    // 出栈操作
    bool pop(char& c) {
        if (!isEmpty()) {
            c = data[top--];
            return true;
        }
        return false;
    }

    // 获取栈顶元素
    char getTop() {
        if (!isEmpty()) {
            return data[top];
        }
        return '\0'; // 返回空字符表示栈为空
    }
};

// 判断左右括号是否匹配
bool isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') || (left == '[' && right == ']');
}

// 检查表达式中的括号匹配
bool checkBrackets(const string& expression) {
    Stack stack;
    for (char ch : expression) {
        if (ch == '(' || ch == '[') {
            // 遇到左括号，入栈
            stack.push(ch);
        }
        else if (ch == ')' || ch == ']') {
            // 遇到右括号，检查栈是否为空
            if (stack.isEmpty()) {
                return false; // 右括号多余
            }
            char topChar;
            stack.pop(topChar);
            if (!isMatchingPair(topChar, ch)) {
                return false; // 不匹配
            }
        }
    }
    // 检查栈是否为空
    return stack.isEmpty(); // 栈空表示匹配正确，栈非空表示左括号多余
}

int main() {
    string expression;
    cout << "请输入包含两种括号的表达式：";
    getline(cin, expression);

    if (checkBrackets(expression)) {
        cout << "表达式中的括号匹配正确！" << endl;
    }
    else {
        cout << "表达式中的括号匹配不正确！" << endl;
    }

    return 0;
}

#include <iostream>
#include <variant>
#include <any>
#include <vector>
#include <string>

// 定义表达式节点的类

// 定义操作符的类型
enum class Op
{
    Plus,
    Minus,
    Multiply,
    Divide
};
using Expr = std::variant<int, Op>;

// 计算表达式的值
int eval(const Expr &expr)
{
    if (std::holds_alternative<int>(expr))
    {
        return std::get<int>(expr);
    }
    else
    {
        auto &op_str = std::get<std::string>(expr);
        Op op;
        if (op_str == "+")
            op = Op::Plus;
        else if (op_str == "-")
            op = Op::Minus;
        else if (op_str == "*")
            op = Op::Multiply;
        else if (op_str == "/")
            op = Op::Divide;
        else
            throw std::runtime_error("Unknown operator");

        // 这里需要一个更复杂的解析器来处理操作符
        // 这里仅演示如何处理操作符，实际情况需要构建抽象语法树（AST）
        throw std::runtime_error("Operator evaluation not implemented");
    }
    return 0; // 仅用于编译通过
}

int main()
{
    // 示例：构建一个简单的表达式 3 + 4 * 5
    // 这里需要一个解析器来构建这样的表达式树
    std::vector<Expr> expr = {3, Op::Plus, 4, Op::Multiply, 5};

    try
    {
        int result = eval(expr[1]);
        std::cout << "The result of the expression is: " << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
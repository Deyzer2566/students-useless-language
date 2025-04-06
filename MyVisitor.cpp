#include "MyVisitor.h"
#include <iostream>
#include <functional>

using namespace std;

// std::any MyVisitor::visitStmt(lolParser::StmtContext *ctx) {
//     // cout<<"exit stmt"<<" "<<ctx->getRuleIndex()<<" "<<ctx->getText()<<" "<<ctx->expr()<<" "<<ctx->if_()<<endl;
//     if(ctx->expr() != nullptr) {
//         // ctx->expr()->ex
//     }
//     return 0;
// }

template <typename T>
std::pair<T, T> toOneType(std::any first, std::any second) {
    if(first.type().name() == "string" || second.type().name() == "string") {
        if(first.type().name() == "int") {
            first = std::to_string(std::any_cast<int>(first));
        } else if(first.type().name() == "double") {
            first = std::to_string(std::any_cast<double>(first));
        }
        if(second.type().name() == "int") {
            second = std::to_string(std::any_cast<int>(second));
        } else if(second.type().name() == "double") {
            second = std::to_string(std::any_cast<double>(second));
        }
    } else if(first.type().name() == "double" || second.type().name() == "double") {
        if(first.type().name() == "int") {
            first = static_cast<double>(std::any_cast<int>(first));
        } else if(first.type().name() == "string") {
            first = std::stod(std::any_cast<std::string>(first));
        }
        if(second.type().name() == "int") {
            second = static_cast<double>(std::any_cast<int>(second));
        } else if(second.type().name() == "string") {
            second = std::stod(std::any_cast<std::string>(second));
        }
    } else {
        if(first.type().name() == "double") {
            first = static_cast<int>(std::any_cast<double>(first));
        } else if(first.type().name() == "string") {
            first = std::stoi(std::any_cast<std::string>(first));
        }
        if(second.type().name() == "double") {
            second = static_cast<int>(std::any_cast<double>(second));
        } else if(second.type().name() == "string") {
            second = std::stoi(std::any_cast<std::string>(second));
        }
    }
    return std::make_pair(std::any_cast<T>(first), std::any_cast<T>(second));
}

std::any MyVisitor::visitCast(lolParser::CastContext *ctx) {
    std::any value = visit(ctx->expr());
    std::string cast_type = ctx->type()->getText();
    if(value.type() == typeid(int)) {
        int int_val = std::any_cast<int>(value);
        if(cast_type == "int") {
            return (int)int_val;
        } else if (cast_type == "real") {
            return (double)int_val;
        } else if (cast_type == "str") {
            return std::to_string(int_val);
        }
    } else if (value.type() == typeid(double)) {
        double real_val = std::any_cast<double>(value);
        if(cast_type == "int") {
            return (int)real_val;
        } else if (cast_type == "real") {
            return (double)real_val;
        } else if (cast_type == "str") {
            return std::to_string(real_val);
        }
    } else if (value.type() == typeid(std::string)){
        std::string str_val = std::any_cast<std::string>(value);
        if(cast_type == "int") {;
            return std::stoi(str_val);
        } else if (cast_type == "real") {
            return std::stod(str_val);
        } else if (cast_type == "str") {
            return str_val;
        }
    }
    throw invalid_operand();
}
std::any operator+(std::any first, std::any second) {
    if(first.type() != second.type())
        throw invalid_operands();
    if(first.type() == typeid(int)) {
        return std::any_cast<int>(first) + std::any_cast<int>(second);
    } else if(first.type() == typeid(double)) {
        return std::any_cast<double>(first) + std::any_cast<double>(second);
    } else if(first.type() == typeid(std::string)) {
        return std::any_cast<std::string>(first) + std::any_cast<std::string>(second);
    }
    throw invalid_operands();
}
std::any operator-(std::any first, std::any second) {
    if(first.type() != second.type())
        throw invalid_operands();
    if(first.type() == typeid(int)) {
        return std::any_cast<int>(first) - std::any_cast<int>(second);
    } else if(first.type() == typeid(double)) {
        return std::any_cast<double>(first) - std::any_cast<double>(second);
    }
    throw invalid_operands();
}
std::any operator*(std::any first, std::any second) {
    if(first.type() != second.type())
        throw invalid_operands();
    if(first.type() == typeid(int)) {
        return std::any_cast<int>(first) * std::any_cast<int>(second);
    } else if(first.type() == typeid(double)) {
        return std::any_cast<double>(first) * std::any_cast<double>(second);
    }
    throw invalid_operands();
}
std::any operator/(std::any first, std::any second) {
    if(first.type() != second.type())
        throw invalid_operands();
    if(first.type() == typeid(int)) {
        return std::any_cast<int>(first) / std::any_cast<int>(second);
    } else if(first.type() == typeid(double)) {
        return std::any_cast<double>(first) / std::any_cast<double>(second);
    }
    throw invalid_operands();
}
int operator==(std::any first, std::any second) {
    if(first.type() != second.type())
        throw invalid_operands();
    if(first.type() == typeid(int)) {
        return std::any_cast<int>(first) == std::any_cast<int>(second);
    } else if(first.type() == typeid(double)) {
        return std::any_cast<double>(first) == std::any_cast<double>(second);
    } else if(first.type() == typeid(std::string)) {
        return std::any_cast<std::string>(first) == std::any_cast<std::string>(second);
    }
    throw invalid_operands();
}
int operator>(std::any first, std::any second) {
    if(first.type() != second.type())
        throw invalid_operands();
    if(first.type() == typeid(int)) {
        return std::any_cast<int>(first) > std::any_cast<int>(second);
    } else if(first.type() == typeid(double)) {
        return std::any_cast<double>(first) > std::any_cast<double>(second);
    } else if(first.type() == typeid(std::string)) {
        return std::any_cast<std::string>(first) > std::any_cast<std::string>(second);
    }
    throw invalid_operands();
}
int operator<(std::any first, std::any second) {
    if(first.type() != second.type())
        throw invalid_operands();
    if(first.type() == typeid(int)) {
        return std::any_cast<int>(first) < std::any_cast<int>(second);
    } else if(first.type() == typeid(double)) {
        return std::any_cast<double>(first) < std::any_cast<double>(second);
    } else if(first.type() == typeid(std::string)) {
        return std::any_cast<std::string>(first) < std::any_cast<std::string>(second);
    }
    throw invalid_operands();
}
const map<std::string, std::function<std::any(std::any, std::any)>> operations = {
    {"*", [](std::any f, std::any s){return f*s;}},
    {"/", [](std::any f, std::any s){return f/s;}},
    {"+", [](std::any f, std::any s){return f+s;}},
    {"-", [](std::any f, std::any s){return f-s;}},
    {"==", [](std::any f, std::any s){return f==s;}},
    {">", [](std::any f, std::any s){return f>s;}},
    {"<", [](std::any f, std::any s){return f<s;}}
};
std::any MyVisitor::visitMul_div(lolParser::Mul_divContext *ctx) {
    if(ctx->operation->getText() == "*") {
        return visit(ctx->expr(0)) * visit(ctx->expr(1));
    } else {
        return visit(ctx->expr(0)) / visit(ctx->expr(1));
    }
}
std::any MyVisitor::visitSum_sub(lolParser::Sum_subContext *ctx) {
    if(ctx->operation->getText() == "+") {
        return visit(ctx->expr(0)) + visit(ctx->expr(1));
    } else {
        return visit(ctx->expr(0)) - visit(ctx->expr(1));
    }
}
std::any MyVisitor::visitCompare(lolParser::CompareContext *ctx) {
    if(ctx->operation->getText() == "==") {
        return visit(ctx->expr(0)) == visit(ctx->expr(1));
    } else if(ctx->operation->getText() == ">"){
        return visit(ctx->expr(0)) > visit(ctx->expr(1));
    } else 
        return visit(ctx->expr(0)) < visit(ctx->expr(1));
}
std::any MyVisitor::visitIdent(lolParser::IdentContext *ctx) {
    try{
        return variables.at(ctx->IDENT()->getText());   
    } catch (std::out_of_range except) {
        throw std::logic_error("invalid name of variable \""
                                +ctx->IDENT()->getText()
                                +"\" at line "
                                +std::to_string(ctx->getStart()->getLine())
                                +":"
                                +std::to_string(ctx->getStart()->getCharPositionInLine()));
    }
}
std::any MyVisitor::visitInteger_val(lolParser::Integer_valContext *ctx) {
    return std::stoi(ctx->INTEGER()->getText());
}
std::any MyVisitor::visitReal_val(lolParser::Real_valContext *ctx) {
    return std::stod(ctx->REAL()->getText());
}
std::any MyVisitor::visitString_val(lolParser::String_valContext *ctx) {
    std::string str_val = ctx->STRING()->getText();
    str_val = str_val.substr(1,str_val.size()-2);
    for(size_t i = 0; i < str_val.size()-1; i++) {
        if(str_val[i] == '\\' && str_val[i+1] != '\\') {
            if(str_val[i+1] == 'n') {
                str_val[i] = '\n';
            } else if(str_val[i+1] == 't') {
                str_val[i] = '\t';
            } else if(str_val[i+1] == 'r') {
                str_val[i] = '\r';
            }
            str_val.erase(i+1);
            if(i != 0)
                i--;
        }
    }
    return str_val;
}
std::any MyVisitor::visitAssignment(lolParser::AssignmentContext *ctx) {
    variables[ctx->assignment123()->IDENT()->getText()] = visit(ctx->assignment123()->expr());
    return variables[ctx->assignment123()->IDENT()->getText()];
}
std::any MyVisitor::visitPrint(lolParser::PrintContext *ctx) {
    std::any expr = visit(ctx->expr());
    if(expr.type() == typeid(int)) {
        std::cout<<std::any_cast<int>(expr);
    } else if(expr.type() == typeid(double)) {
        std::cout<<std::any_cast<double>(expr);
    } else if(expr.type() == typeid(std::string)) {
        std::string str_val = std::any_cast<std::string>(expr);
        std::cout<<str_val;
    }
    return expr;
}
std::any MyVisitor::visitParenthesis(lolParser::ParenthesisContext *ctx) {
    return visit(ctx->expr());
}
std::any MyVisitor::visitNegation(lolParser::NegationContext *ctx) {
    std::any value = visit(ctx->expr());
    if(value.type() == typeid(int)) {
        return -std::any_cast<int>(value);
    } else if(value.type() == typeid(double)) {
        return -std::any_cast<double>(value);
    }
    throw invalid_operand();
}
int operator!(std::any value) {
    if(value.type() == typeid(int)) {
        return !std::any_cast<int>(value);
    } else if(value.type() == typeid(double)) {
        return !std::any_cast<double>(value);
    } else if(value.type() == typeid(std::string)) {
        return !(std::any_cast<std::string>(value).size() != 0);
    }
    throw invalid_operand();
}
std::any MyVisitor::visitLogical_inversion(lolParser::Logical_inversionContext *ctx) {
    return !visit(ctx->expr());
}
std::any MyVisitor::visitIf(lolParser::IfContext *ctx) {
    std::any expr = visit(ctx->expr());
    if(!(!expr)) {
        visit(ctx->block(0));
    } else {
        visit(ctx->block(1));
    }
    return (int)(!(!expr));
}
std::any MyVisitor::visitBlock(lolParser::BlockContext *ctx) {
    variables.incDepth();
    std::any res = visitChildren(ctx);
    variables.decDepth();
    return res;
}
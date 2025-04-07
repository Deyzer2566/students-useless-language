#pragma once
#include "sulBaseVisitor.h"
#include "MyTreeMap.h"

class invalid_operand : public std::exception {
public:
    const char* what() const noexcept override {
        return "invalid operand for operation";
    }
};

class invalid_operands: public std::exception {
public:
    const char* what() const noexcept override {
        return "invalid operands for operation";
    }
};

class  MyVisitor : public sulBaseVisitor {
public:
    std::any visitBlock(sulParser::BlockContext *ctx);
    std::any visitParenthesis(sulParser::ParenthesisContext *ctx);
    std::any visitCast(sulParser::CastContext *ctx);
    std::any visitMul_div(sulParser::Mul_divContext *ctx);
    std::any visitSum_sub(sulParser::Sum_subContext *ctx);
    std::any visitCompare(sulParser::CompareContext *ctx);
    std::any visitAssignment(sulParser::AssignmentContext *ctx);
    std::any visitNegation(sulParser::NegationContext *ctx);
    std::any visitLogical_inversion(sulParser::Logical_inversionContext *ctx);
    std::any visitIdent(sulParser::IdentContext *ctx);
    std::any visitInteger_val(sulParser::Integer_valContext *ctx);
    std::any visitReal_val(sulParser::Real_valContext *ctx);
    std::any visitString_val(sulParser::String_valContext *ctx);

    std::any visitPrint(sulParser::PrintContext *ctx);

    std::any visitIf(sulParser::IfContext *ctx);

    std::any visitWhile(sulParser::WhileContext *ctx);
protected:
    MyTreeMap<std::string, std::any> variables;
};

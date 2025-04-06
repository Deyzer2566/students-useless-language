#pragma once
#include "lolBaseVisitor.h"
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

class  MyVisitor : public lolBaseVisitor {
public:
    std::any visitBlock(lolParser::BlockContext *ctx);
    std::any visitParenthesis(lolParser::ParenthesisContext *ctx);
    std::any visitCast(lolParser::CastContext *ctx);
    std::any visitMul_div(lolParser::Mul_divContext *ctx);
    std::any visitSum_sub(lolParser::Sum_subContext *ctx);
    std::any visitCompare(lolParser::CompareContext *ctx);
    std::any visitAssignment(lolParser::AssignmentContext *ctx);
    std::any visitNegation(lolParser::NegationContext *ctx);
    std::any visitLogical_inversion(lolParser::Logical_inversionContext *ctx);
    std::any visitIdent(lolParser::IdentContext *ctx);
    std::any visitInteger_val(lolParser::Integer_valContext *ctx);
    std::any visitReal_val(lolParser::Real_valContext *ctx);
    std::any visitString_val(lolParser::String_valContext *ctx);

    std::any visitPrint(lolParser::PrintContext *ctx);

    std::any visitIf(lolParser::IfContext *ctx);
protected:
    MyTreeMap<std::string, std::any> variables;
};

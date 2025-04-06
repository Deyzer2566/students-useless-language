#include "MyListener.h"
#include <iostream>

using namespace std;

void MyListener::exitStmt(lolParser::StmtContext *ctx) {
    cout<<"exit stmt"<<" "<<ctx->getRuleIndex()<<" "<<ctx->getText()<<" "<<ctx->expr()<<" "<<ctx->if_()<<endl;
}

void MyListener::exitIf(lolParser::IfContext *ctx) {
    cout<<"exit if"<<" "<<ctx->getRuleIndex()<<" "<<ctx->getText()<<endl;
}

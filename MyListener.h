#include "lolBaseListener.h"

class  MyListener : public lolBaseListener {
public:
    void exitStmt(lolParser::StmtContext *ctx);
    void exitIf(lolParser::IfContext *ctx);
};
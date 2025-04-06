#include <iostream>

#include "antlr4-runtime.h"
#include "lolLexer.h"
#include "lolParser.h"
#include "MyVisitor.h"

using namespace antlr4;


int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  lolLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  lolParser parser(&tokens);

  tree::ParseTree *tree = parser.program();
  MyVisitor visitor;
  visitor.visit(tree);

  return 0;
}

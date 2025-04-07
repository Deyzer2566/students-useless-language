#include <iostream>

#include "antlr4-runtime.h"
#include "sulLexer.h"
#include "sulParser.h"
#include "MyVisitor.h"

using namespace antlr4;


int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  sulLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  sulParser parser(&tokens);

  tree::ParseTree *tree = parser.program();
  MyVisitor visitor;
  visitor.visit(tree);

  return 0;
}

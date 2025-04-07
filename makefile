.PHONY: clean
LANG_NAME = sul
C_FILES = \
	main.cpp \
	MyVisitor.cpp \
	MyVisitor.h \
	MyTreeMap.h
GENERATED_FILES = \
	$(LANG_NAME)BaseVisitor.cpp \
	$(LANG_NAME)BaseVisitor.h \
	$(LANG_NAME)Lexer.cpp \
	$(LANG_NAME)Lexer.h \
	$(LANG_NAME)Parser.cpp \
	$(LANG_NAME)Parser.h \
	$(LANG_NAME)Visitor.h \
	$(LANG_NAME)Visitor.cpp
OBJS = \
	$(LANG_NAME)BaseVisitor.o \
	$(LANG_NAME)Lexer.o \
	$(LANG_NAME)Parser.o \
	$(LANG_NAME)Visitor.o \
	MyVisitor.o \
	main.o
test: interp.exe
	./interp ./примеры/база.кк
interp.exe: $(OBJS)
	g++ -g $^ -L./LIBANTLR4/lib -l:libantlr4-runtime.dll.a -o interp
%.o: %.cpp
	g++ -c -g $^ -I./LIBANTLR4/include/antlr4-runtime
$(GENERATED_FILES): $(LANG_NAME).g4
	java -jar antlr-4.13.2-complete.jar -visitor -no-listener -Dlanguage=Cpp $^
clean:
	rm $(OBJS)
clean_src:
	rm $(GENERATED_FILES)

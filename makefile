# name of C++ compiler
CXX       = g++
# options to C++ compiler
CXX_FLAGS = -std=c++17 -pedantic-errors -Wall -Wextra -Werror
# flag to linker to make it link with math library
LDLIBS    = -lm
# list of object files
OBJS      = pa-driver.o pa.o
# name of executable program
EXEC      = pa.out

# by convention the default target (the target that is built when writing
# only make on the command line) should be called all and it should
# be the first target in a makefile
all : $(EXEC)

# however, the problem that arises with the previous rule is that make
# will think all is the name of the target file that should be created
# so, we tell make that all is not a file name
.PHONY : all

# this rule says that target $(EXEC) will be built if prerequisite
# files $(OBJS) have changed more recently than $(EXEC)
# text $(EXEC) will be replaced with value pa.out
# text $(OBJS) will be substituted with list of prerequisites in line 10
# line 31 says to build $(EXEC) using command $(CXX) with
# options $(CXX_FLAGS) specified on line 6
$(EXEC) : $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(EXEC) $(LDLIBS)

# target pa-driver.o depends on both pa-driver.cpp and pa.hpp
# and is created with command $(CXX) given the options $(CXX_FLAGS)
pa-driver.o : pa-driver.cpp pa.hpp
	$(CXX) $(CXX_FLAGS) -c pa-driver.cpp -o pa-driver.o
	
# target pa.o depends on both pa.cpp and pa.hpp
# and is created with command $(CXX) given the options $(CXX_FLAGS)
pa.o : pa.cpp pa.hpp
	$(CXX) $(CXX_FLAGS) -c pa.cpp -o pa.o

# says that clean is not the name of a target file but simply the name for
# a recipe to be executed when an explicit request is made
.PHONY : clean
# clean is a target with no prerequisites;
# typing the command in the shell: make clean
# will only execute the command which is to delete the object files
clean :
	rm -f $(OBJS) $(EXEC)

# says that rebuild is not the name of a target file but simply the name
# for a recipe to be executed when an explicit request is made
.PHONY : rebuild
# rebuild is for starting over by removing cleaning up previous builds
# and starting a new one
rebuild :
	$(MAKE) clean
	$(MAKE)

.PHONY : test
test : $(EXEC)
	./$(EXEC) 001.txt 001-output.txt 001-youroutput.txt
	./$(EXEC) 002.txt 002-output.txt 002-youroutput.txt
	./$(EXEC) 003.txt 003-output.txt 003-youroutput.txt
	./$(EXEC) 004.txt 004-output.txt 004-youroutput.txt

	./$(EXEC) 006.txt 006-output.txt 006-youroutput.txt
	./$(EXEC) 007.txt 007-output.txt 007-youroutput.txt
	./$(EXEC) 008.txt 008-output.txt 008-youroutput.txt
	./$(EXEC) 009.txt 009-output.txt 009-youroutput.txt
	./$(EXEC) 010.txt 010-output.txt 010-youroutput.txt
	./$(EXEC) 011.txt 011-output.txt 011-youroutput.txt
	./$(EXEC) 012.txt 012-output.txt 012-youroutput.txt
	./$(EXEC) 013.txt 013-output.txt 013-youroutput.txt
	./$(EXEC) 014.txt 014-output.txt 014-youroutput.txt
	./$(EXEC) 015.txt 015-output.txt 015-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 001-output.txt 001-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 002-output.txt 002-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 003-output.txt 003-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 004-output.txt 004-youroutput.txt

	diff -y --strip-trailing-cr --suppress-common-lines 006-output.txt 006-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 007-output.txt 007-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 008-output.txt 008-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 009-output.txt 009-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 010-output.txt 010-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 011-output.txt 011-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 012-output.txt 012-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 012-output.txt 013-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 014-output.txt 014-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 015-output.txt 015-youroutput.txt
	
	./$(EXEC) 005.txt 005-output.txt 005-youroutput.txt
	diff -y --strip-trailing-cr --suppress-common-lines 005-output.txt 005-youroutput.txt
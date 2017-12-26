######################################
#
######################################
CC = gcc  
C++ = g++  
LINK = g++  
AR = ar
  
LIBS = -lz -lm
#must add -fPIC option  
CCFLAGS = $(COMPILER_FLAGS) -c -g -fPIC   
C++FLAGS = $(COMPILER_FLAGS) -c -g -fPIC -std=c++11
  
TARGET=uvBaselib.a  
  
INCLUDES = -I. 
  
C++FILES = MessageThread.cpp \
	MessageQueue.cpp \
	MessageHandle.cpp \
	logging.cpp
		   
CFILES = $(wildcard *.c) 
  
OBJFILE = $(CFILES:.c=.o) $(C++FILES:.cpp=.o)  
  
all:$(TARGET)  
  
$(TARGET): $(OBJFILE)  
	$(AR) -rs uvBaselib.a $^ 
  
%.o:%.c  
	$(CC) -o $@ $(CCFLAGS) $< $(INCLUDES)  
  
%.o:%.cpp  
	$(C++) -o $@ $(C++FLAGS) $< $(INCLUDES) 
  
clean:  
	rm -rf $(TARGET)  
	rm -rf $(OBJFILE)  

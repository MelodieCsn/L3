CC = g++
CFLAGS = -Wall -pedantic -ansi
SOURCE = $(wildcard *.cpp)

MSQ = @
RM = $(MSQ)rm -f
CLEAR = $(MSQ)clear

MSG = $(MSQ)echo 
MSG1 = $(MSG) "Compilation de $^ ==> $@"
MSG_OK = $(MSG) ".......OK"

all : main vers strophe

#clean
cls :
	$(RM) *.o
	$(RM) $(SOURCE:.cpp=)

clean : cls
	$(MSG) "Cleanup is running...."
	$(CLEAR)
	$(MSG_OK)

#Compilation
vers : vers.cc
	$(MSG1)
	$(CC) $(CFLAGS) $^ -o $@
	$(CLEAR)
	$(MSG_OK)


#Compilation
strophe : strophe.cc
	$(MSG1)
	$(CC) $(CFLAGS) $^ -o $@
	$(CLEAR)
	$(MSG_OK)

vers : main.cc
	$(MSG1)
	$(CC) $(CFLAGS) $^ -o $@
	$(CLEAR)
	$(MSG_OK)
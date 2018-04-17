SRCS:=$(shell ls *.cpp)
OBJS:=$(SRCS:.cpp=.o)
EXEC:=mytar
CXX:=c++
.PHONEY: dep depend

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

dep: .depend

depend: .depend

.depend:
	$(CXX) -M $(SRCS) > $@

clean:
	rm -rf *~ *.o $(EXEC) .depend

sinclude .depend
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS :=
CC_FLAGS := -std=c++11
CPP := clang++
EXEC := test.exe

all: directories bin/$(EXEC)

bin/$(EXEC): $(OBJ_FILES)
	$(CPP) $(LD_FLAGS) -o $@ $^

obj/%.o: src/%.cpp
	$(CPP) $(CC_FLAGS) -c -o $@ $<

CC_FLAGS += -MMD
-include $(OBJFILES:.o=.d)

./PHONY: directories clean

clean:
	rm -rf obj bin

directories:
	mkdir -p obj src inc bin

run: all
	./bin/$(EXEC)

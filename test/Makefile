TMPDIR=.
PROJECT_ROOT=..
GMOCK_LIB=-lgtest -lgtest_main -lgmock
GMOCK_INCLUDE=-I $(PROJECT_ROOT)
CPP11_FLAGS=-g -O0 -std=c++17 -fno-inline -falign-functions=32
SRC=$(wildcard *.cpp)
TARGETS=$(patsubst %.cpp, %, $(SRC))
TARGETS_PATH=$(patsubst %.cpp, $(TMPDIR)/%.out, $(SRC))
RECENT=runtime_patch_test
RECENT_PATH=$(patsubst %, $(TMPDIR)/%.out, $(RECENT))
# Example
%: %.cpp
	g++ $(CPP11_FLAGS) $^ $(GMOCK_INCLUDE) $(GMOCK_LIB) -o $(TMPDIR)/$@.out
# Default
all: $(TARGETS)
clean:
	rm -f *.out
# Recent
recent: $(RECENT)
# Test
test: all
	echo $(TARGETS_PATH) | tr " " "\n" | while read test; do echo "Test: $$test"; $$test; done
# Recent test
recent-test: recent
	$(RECENT_PATH)

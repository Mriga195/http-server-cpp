# make ex L=02     build exercises/L02-*.cpp  -> build/L02
# make run L=02    build and run it
# make server      build server/*.cpp         -> build/server
CXXFLAGS = -std=c++17 -Wall -Wextra -g -pthread
EX = $(wildcard exercises/L$(L)-*.cpp)

ex:
	@test -n "$(EX)" || { echo "no file exercises/L$(L)-*.cpp"; exit 1; }
	@mkdir -p build
	g++ $(CXXFLAGS) $(EX) -o build/L$(L)

run: ex
	./build/L$(L)

server:
	@mkdir -p build
	g++ $(CXXFLAGS) server/*.cpp -o build/server

clean:
	rm -rf build

.PHONY: ex run server clean

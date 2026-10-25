# make NAME=echo_server  ->  builds src/echo_server.cpp into build/echo_server
NAME ?= server
CXXFLAGS = -std=c++17 -Wall -Wextra -g -pthread

build/$(NAME): src/$(NAME).cpp
	@mkdir -p build
	g++ $(CXXFLAGS) $< -o $@

clean:
	rm -rf build

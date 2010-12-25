# CXXFLAGS += -I.
BOOST_PATH=../ssworking/boost_1_41_0
# or -static-libstdc++ or -static-libgcc or -static
CXXFLAGS = -I$(BOOST_PATH) -Wl,--enable-auto-import -I. -std=gnu++0x

main: main.cpp

main.cpp : console.hpp sink.hpp lines.hpp

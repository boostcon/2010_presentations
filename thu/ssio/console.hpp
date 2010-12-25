#include <sink.hpp>
#include <cstdio>

struct Console {};

template<>
struct sink<Console>
{
    typedef char type;
    static void put( const Console, char c )
    {
        std::putchar( c );
    }
};

const Console console = Console();

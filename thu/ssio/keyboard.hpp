#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include <source.hpp>

struct Keyboard {};
const Keyboard keyboard = Keyboard();

template<>
struct source<Keyboard>
{
    typedef char type;

    template< typename Sink >
    static
    void connect( const Keyboard, const Sink & s )
    {
        put( s, getchar() );
    }
};

#endif

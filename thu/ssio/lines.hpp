#ifndef LINES_HPP_
#define LINES_HPP_

#include <sink.hpp>
#include <filter.hpp>
#include <iostream>

template<typename Sink>
struct LinesSink
{
    LinesSink( const Sink & s_ ) : s( s_ )
    {
    }
    Sink s;
};

template<typename T>
struct sink<LinesSink<T> >
{
    typedef std::string type;
    template<typename U>
    static void put( const LinesSink<U> &l, const std::string & s )
    {
        //TODO: make this faster
        for( int i = 0; i < s.size(); ++i )
            ::put( l.s, s[i] );
        ::put( l.s, '\n' );
    }
};

struct Lines
{
};
const Lines lines = Lines();

struct LinesApSink
{
    typedef LinesApSink this_type;

    template<typename T>
    struct result;

    template<typename Sink>
    struct result< this_type (const Lines &, const Sink &) >
    {
        typedef LinesSink<Sink>  type;
    };

    template<typename Sink>
    typename result< this_type (const Lines &, const Sink &) >::type
    operator()( const Lines &, const Sink & s ) const
    {
        return LinesSink<Sink>( s );
    }
};

template<>
struct filter<Lines>
{
    typedef LinesApSink apSink;
};


#endif

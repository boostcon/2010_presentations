#ifndef FILTER_HPP_
#define FILTER_HPP_

#include <boost/utility/result_of.hpp>

template<typename T>
struct filter { };

struct ApSink
{
    typedef ApSink this_type;

    template<typename T>
    struct result;

    template<typename Filter, typename Sink>
    struct result< this_type( const Filter &, const Sink & ) >
    {
        typedef typename filter<Filter>::apSink apSink;
        typedef typename boost::result_of<apSink(const Filter&, const Sink &)>::type type;
    };

    template<typename Filter, typename Sink>
    typename result< this_type( const Filter &, const Sink & ) >::type
    operator()( const Filter & f, const Sink & s ) const
    {
        return typename filter<Filter>::apSink()( f, s );
    }
};

const ApSink apSink = ApSink();
#endif

#ifndef SINK_HPP_
#define SINK_HPP_

template<typename T>
struct sink;

struct Put
{
    typedef void result_type;
    template< typename Sink, typename SinkType >
    void operator()( const Sink & s, const SinkType & a ) const
    {
        return sink<Sink>::put( s, a );
    }
};

const Put put = Put();

#endif

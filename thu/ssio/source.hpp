#ifndef SOURCE_HPP_
#define SOURCE_HPP_

template<typename T>
struct source;

struct Step
{
    typedef void result_type;
    template< typename Source, typename Sink >
    void operator()( const Source & sc, const Sink & sk ) const
    {
        source<Source>::step( sc, sk );
    }
};
const Step step = Step();
#endif

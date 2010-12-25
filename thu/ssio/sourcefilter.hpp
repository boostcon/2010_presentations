#ifndef SOURCEFILTER_HPP_
#define SOURCEFILTER_HPP_

template< typename SinkFilter>
struct sourcefilter;

struct ApSource
{
    typedef ApSource this_type;
    template<typename T>
    struct result;

    template<typename Filter, typename Source>
    struct result< this_type( const Filter &, const Source & ) >
    {
        typedef typename sourcefilter<Filter>::apSource apSource;
        typedef typename boost::result_of<apSource( const Filter&
                                                  , const Source &
                                                  )
                                         >::type type;
    };

    template<typename Filter, typename Source>
    typename result< this_type( const Filter &, const Source & ) >::type
    operator()( const Filter & f, const Source & s ) const
    {
        return typename sourcefilter<Filter>::apSource()( f, s );
    }

};

const ApSource apSource = ApSource();

//What follows is SinkFilter->SourceFilter stuff.
template<typename F, typename S>
struct SinkApSourceSource
{
    SinkApSourceSource
        ( const F &f_
        , const S &s_
        )
        : f( f_ )
        , s( s_ )
    {
    }
    F f;
    S s;
};

template<typename F, typename S>
struct source<SinkApSourceSource<F,S> >
{
    //TODO: figure out the type here.
    template< typename A, typename B, typename Sink >
    static void step( const SinkApSourceSource<A,B> & z, const Sink & s )
    {
        ::step( z.s, apSink( z.f, s ));
    }
};

struct SinkApSource
{
    typedef SinkApSource this_type;
    template<typename T>
    struct result;

    template<typename F, typename S>
    struct result< this_type( const F &, const S & ) >
    {
        typedef SinkApSourceSource<F,S> type;
    };

    template<typename F, typename S>
    typename result< this_type( const F &, const S & ) >::type
    operator()( const F & f, const S & s ) const
    {
        return SinkApSourceSource<F,S>( f, s );
    }

};

//Here is the SinkFilter->SourceFilter stuff.
//Default instance works for all sink filters.
template< typename SinkFilter>
struct sourcefilter
{
    typedef SinkApSource apSource;
};

#endif

#include <sink.hpp>
#include <source.hpp>
#include <console.hpp>
#include <keyboard.hpp>
#include <filter.hpp>
#include <sourcefilter.hpp>
#include <lines.hpp>


struct HelloWorld { };
const HelloWorld helloWorld = HelloWorld();

template<>
struct source<HelloWorld>
{
    typedef std::string type;

    template<typename Sink>
    static void step( const HelloWorld, const Sink & s )
    {
        put( s, std::string("hello world") );
    }
};

int main()
{
//    put( console, 'a' );

    //apSource(lines,a) convert a string source to a char   source.
    //apSink(lines,a)   convert a char   sink   to a string sink.

    step( apSource( lines, helloWorld ), console);


    auto lineConsole = apSink( lines, console );
    put( lineConsole, "ehhawef" );
    put( lineConsole, std::string("ehhawef goober") );

//    step( keyboard, console );
//    step( keyboard, console );
//    step( keyboard, console );
//    step( keyboard, console );

}

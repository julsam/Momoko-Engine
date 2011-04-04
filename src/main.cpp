#include "Engine.h"

#define TESTSIMPLE
//#define ENGINEMODE

#ifdef TESTSIMPLE
	#include "tests/simple/Simple.h"
#endif

int
main(int argc, char **argv)
{
    Engine e(argc, argv);
    try
    {
        if(!e.init())
            return 1;
		
#ifdef TESTSIMPLE
		e.setScene(new Simple::GameScene());
#endif
        e.execute();

    }
    catch(Exception& ee)
    {
        std::cout << ee.what() << std::endl;
    }
    return 0;
}

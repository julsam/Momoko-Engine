#include "../include/Engine.h"

#define TESTBASIC
//#define ENGINEMODE

#ifdef TESTBASIC
	#include "../../tests/basic/Basic.h"
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
		e.setScene(new Basic::GameScene());
#endif
		e.execute();

	}
	catch(Exception& ee)
	{
		std::cout << ee.what() << std::endl;
	}
	return 0;
}

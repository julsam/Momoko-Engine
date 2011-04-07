#include "helloBox2d.h"

int
main(int argc, char **argv)
{
    Engine e(argc, argv);
    try
    {
        if(!e.init())
            return 1;
        e.setScene(new helloBox2d::GameScene());
        e.execute();

    }
    catch(Exception& ee)
    {
        std::cout << ee.what() << std::endl;
    }
    return 0;
}

#include "Engine.h"

int
main(int argc, char **argv)
{
    Engine e(argc, argv);
    if(!e.init())
        return 1;
    return e.execute();
}

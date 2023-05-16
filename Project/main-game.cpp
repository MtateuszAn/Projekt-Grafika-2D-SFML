#include <iostream>
#include "Engine.h"
int main()
{
    //Engine
    Engine engine;
    //Pêtla gry
    while (engine.running())
    {   
        //Update
        engine.update();
        //Renderowanie
        engine.render();
    }

    //Koniec aplikacji

    return 0;
}
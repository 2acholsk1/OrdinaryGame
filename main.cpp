#include <game.h>
#include <menu.h>

using namespace std;



int main()
{
    //MAIN LOOP

    Menu menu;
    while(menu.IsWorking())
    {
        menu.Update();
        menu.Draw();

    }
    Game game;
    while(game.IsWorking())
    {
        game.Update();
        game.Draw();

    }


        return 0;
}

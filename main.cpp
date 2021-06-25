#include <game.h>
#include <menu.h>

using namespace std;



int main()
{
    //MAIN LOOP


    Game game;
    game.MenuWorking();
    while(game.IsWorking())
    {
        game.Draw();
        game.Update();

    }


        return 0;
}

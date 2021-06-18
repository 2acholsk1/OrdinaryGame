#include <game.h>

using namespace std;



int main()
{
    //MAIN LOOP

    Game game;
    while(game.IsWorking())
    {
        game.Update();
        game.Draw();

    }


        return 0;
}

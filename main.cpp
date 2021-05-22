#include <game.h>

using namespace std;



int main()
{
    //MAIN LOOP

    Game game;
    while(game.IsWorking())
    {
        game.Draw();
        game.Update();
    }


        return 0;
}

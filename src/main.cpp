#include <iostream>
#include "include/engine.hpp"

using namespace std;

int main(int argc, char**argv){
        string levelPath;
        if(argc == 1){
                levelPath = "./data/maps/mylevel.txt";
        }
        else{
                levelPath = "./data/maps/" + string(argv[1]) + ".txt";
        }
        cout << "levelPath: " << levelPath << endl;

        engine *gameEngine = new engine();
        gameEngine->runGame();

        return 0;
}

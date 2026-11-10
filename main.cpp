#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include "Board.hpp"

using namespace std;
using namespace sf;

int main(){
    Board board;
    RenderWindow window(VideoMode({420, 420}), "Tetris");
    window.setFramerateLimit(60);
    board.InstallPart();
    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }
        board.UpdateBoard();
        board.UpdateBoardColors();
        window.clear(Color(20, 20, 20));
        window.draw(board);
        window.display();
    }

    return 0;
}


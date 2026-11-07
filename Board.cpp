#include "Board.hpp"

using namespace std;
using namespace sf;

Board::Board()
{
    memset(board, 0, sizeof(board));
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            boardShapes[i][j] = RectangleShape(Vector2f(20, 20));
            boardShapes[i][j].setPosition({j * 20.f, i * 20.f});
            boardShapes[i][j].setFillColor(Color(50, 50, 50));
            boardShapes[i][j].setOutlineThickness(2.f);
            boardShapes[i][j].setOutlineColor(Color(1, 1, 1));
            
        }
    }
}

void Board::UpdateBoardColors(){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            switch (board[i][j]) {
                case 0: boardShapes[i][j].setFillColor(Color(50, 50, 50)); break;    // rgb(50, 50, 50)
                case 1: boardShapes[i][j].setFillColor(Color(255, 166, 0)); break;   // rgb(255, 166, 0)
                case 2: boardShapes[i][j].setFillColor(Color(245, 152, 245)); break; // rgb(245, 152, 245)
                case 3: boardShapes[i][j].setFillColor(Color(51, 204, 153)); break;  // rgb(51, 204, 153)
                case 4: boardShapes[i][j].setFillColor(Color(255, 110, 110)); break; // rgb(255, 110, 110)
                case 5: boardShapes[i][j].setFillColor(Color(255, 204, 77)); break;  // rgb(255, 204, 77)
                case 6: boardShapes[i][j].setFillColor(Color(166, 166, 255)); break; // rgb(166, 166, 255)
                case 7: boardShapes[i][j].setFillColor(Color(138, 194, 247)); break; // rgb(138, 194, 247)

            }
           
        }
    }
}

void Board::draw(RenderTarget& rt, RenderStates rs) const{
    rs.transform.translate({10.f, 10.f});
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            rt.draw(boardShapes[i][j], rs);
        }
    }
}
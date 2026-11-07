#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>

using namespace std;
using namespace sf;

class Board : public Drawable
{
    private:
        int board[20][10];
        RectangleShape boardShapes[20][10];
    public:
        Board();
        void UpdateBoardColors();
        virtual void draw(RenderTarget& rt, RenderStates rs) const override; 
};
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <time.h>
#include "Parts.hpp"

using namespace std;
using namespace sf;

class Board : public Drawable
{
    private:
        Parts parts;
        int indNewPart, indColorNewPart;
        Color newPartColor;
        int indX, indY;
        int board[20][10];
        RectangleShape boardShapes[20][10];
    public:
        Board();
        bool InstallPart();
        void UpdateBoardColors();
        virtual void draw(RenderTarget& rt, RenderStates rs) const override; 
};
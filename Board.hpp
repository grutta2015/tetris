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

        int timer=0;       // contador de tiempo para el movimiento de la pieza
        int limitTimer=30; // limitador de ese tiempo


        int board[20][10];
        RectangleShape boardShapes[20][10];
    public:
        Board();
        bool InstallPart();
        bool UpdateBoard(); // actualiza tablero, para ver si hay lineas completas, la pieza se ha colocado, se perdio, etc
        void UpdateBoardColors();
        virtual void draw(RenderTarget& rt, RenderStates rs) const override; 
};
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

bool Board::InstallPart(){
    srand(time(NULL));
    indNewPart = rand()%7;

    vector<vector<bool>> part = parts.ConsultPart(indNewPart);
    int sz = (int) part.size();

    indY = 0;
    indX = 5 - sz/2;

    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            if(part[i][j]){
                if(board[i+indY][j+indX] > 0) return false;
                board[i+indY][j+indX]=-1;
            }
        }
    }
    indColorNewPart = indNewPart + 1; // el mas uno es patra que coincida con el switch case de colores
    switch (indColorNewPart) {
        case 1: newPartColor = Color(240, 240, 0); break;   // rgb(240, 240, 0)   O amarillo
        case 2: newPartColor = Color(0, 240, 0); break;     // rgb(0, 240, 0)     S verde
        case 3: newPartColor = Color(240, 0, 0); break;     // rgb(240, 0, 0)     Z rojo
        case 4: newPartColor = Color(0, 0, 240); break;     // rgb(0, 0, 240)     J azul
        case 5: newPartColor = Color(240, 160, 0); break;   // rgb(240, 160, 0)   L naranja
        case 6: newPartColor = Color(160, 0, 240); break;   // rgb(160, 0, 240)   T púrpura
        case 7: newPartColor = Color(0, 240, 240); break;   // rgb(0, 240, 240)   I cian
    }     
    return true;             
}

bool Board::UpdateBoard(){
    bool limit=0;
    int aux;

    if(timer>=limitTimer){
        aux=0;
        for(int i=18; i>=0; i--){
            for(int j=0; j<10; j++){
                if (board[i][j]==-1){
                    if(board[i+1][j]<=0) aux++;
                }
            }
        }
        if (aux==4){
            indY++;
            for(int i=18; i>=0; i--){
                for(int j=0; j<10; j++){
                    if (board[i][j]==-1){
                        board[i][j]=0;
                        board[i+1][j]=-1;                     
                    }
                }
            }
            aux=0;
            for(int i=18; i>=0; i--){
                for(int j=0; j<10; j++){
                    if (board[i][j]==-1){
                        if(board[i+1][j]<=0) aux++;
                    }
                }
            }
            if (aux!=4){
                for(int i=19; i>=0; i--){
                    for(int j=0; j<10; j++){
                        if(board[i][j]==-1) board[i][j]=indColorNewPart;                    
                    }
                }
                limit=1;
            }
            else{
                limit=1; 
            }
        }
        timer=0;
    }
    timer++;
    return limit;

}

void Board::UpdateBoardColors(){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            switch (board[i][j]) {
                case 0: boardShapes[i][j].setFillColor(Color(50, 50, 50)); break;    // rgb(50, 50, 50)    vacío
                case 1: boardShapes[i][j].setFillColor(Color(240, 240, 0)); break;   // rgb(240, 240, 0)   O amarillo
                case 2: boardShapes[i][j].setFillColor(Color(0, 240, 0)); break;     // rgb(0, 240, 0)     S verde
                case 3: boardShapes[i][j].setFillColor(Color(240, 0, 0)); break;     // rgb(240, 0, 0)     Z rojo
                case 4: boardShapes[i][j].setFillColor(Color(0, 0, 240)); break;     // rgb(0, 0, 240)     J azul
                case 5: boardShapes[i][j].setFillColor(Color(240, 160, 0)); break;   // rgb(240, 160, 0)   L naranja
                case 6: boardShapes[i][j].setFillColor(Color(160, 0, 240)); break;   // rgb(160, 0, 240)   T púrpura
                case 7: boardShapes[i][j].setFillColor(Color(0, 240, 240)); break;   // rgb(0, 240, 240)   I cian
                default:
                    boardShapes[i][j].setFillColor(newPartColor);
                    break; 
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


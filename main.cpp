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
    srand(time(NULL)); // antes estaba en Board::InstallPart
    board.InstallPart();

    int right = 0, left = 0, up = 0;
    int transMove = 6;
    int score = 0;

    while (window.isOpen())
    {
        
        while (const optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !up){
             board.RotatePart(), 
             up=1;
        }else if(!Keyboard::isKeyPressed(Keyboard::Key::Up)){
            up=0;
        }
        // else if(Keyboard::isKeyPressed(Keyboard::Key::Up) && up){ // no tiene sentido esto, la rotacion mejor una vez por cada vez apretado up
        //     up++;
        //     if(up==transMove) up=0;
        // }           

        if (Keyboard::isKeyPressed(Keyboard::Key::Down)) board.UpdateLimitTimer(5);
        else board.UpdateLimitTimer(30);

        if (Keyboard::isKeyPressed(Keyboard::Key::Right) && !right){
            board.Right();
            right=1;

        } else if(!Keyboard::isKeyPressed(Keyboard::Key::Right)) {
            right=0;
        } else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right){
            right++;
            if(right==transMove) right=0;
        }

        
        if (Keyboard::isKeyPressed(Keyboard::Key::Left) && !left){
            board.Left();
            left=1;

        } else if(!Keyboard::isKeyPressed(Keyboard::Key::Left)) {
            left=0;
        } else if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left){
            left++;
            if(left==transMove) left=0;
        } 


        if(board.UpdateBoard()){ // si es 1, verdadeo, instala nueva pieza
            score += board.CheckLines()*5;
            cout<<score<<endl;
            if(!board.InstallPart()){
                cout<<"Game Over"<<endl;
                window.close();
            }
        }

        board.UpdateBoardColors();
        // int newScore = board.CheckLines()*5; //esto lo solucione arrriba en updateBoard, ya que si se hace aqui, 
        // board.CheckLines();                 //   no se ve reflejado en el tablero, y no se puede ver la animacion de la linea desapareciendo
        // score+=newScore;
        // cout<<score<<endl;
        window.clear(Color(20, 20, 20));
        window.draw(board);
        window.display();
    }

    return 0;
}


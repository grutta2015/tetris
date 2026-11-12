#include "Parts.hpp"

Parts::Parts(){
    parts = {
        // O (2x2)
        {{1,1}, 
         {1,1}},
         
        // J (3x3)
        {{1,0,0}, 
         {1,1,1}, 
         {0,0,0}},
         
        // L (3x3)
        {{0,0,1}, 
         {1,1,1}, 
         {0,0,0}},
         
        // S (3x3)
        {{0,1,1}, 
         {1,1,0}, 
         {0,0,0}},
         
        // Z (3x3)
        {{1,1,0}, 
         {0,1,1}, 
         {0,0,0}},
         
        // T (3x3)
        {{0,1,0}, 
         {1,1,1}, 
         {0,0,0}},
         
        // I (4x4)
        {{0,0,0,0}, 
         {1,1,1,1}, 
         {0,0,0,0}, 
         {0,0,0,0}}
    };
}

vector<vector<bool>> Parts::ConsultPart(int ind){
    return parts[ind];
}

void Parts::RotatePart(int ind) {
    // Ya no es necesario si se rota localmente en Board
}
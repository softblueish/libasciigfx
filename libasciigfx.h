#include <iostream>

class asciigfx{
    public:

        // Default variables
        bool COLORSUPPORT = false;
        const static int FRAMEX = 20;
        const static int FRAMEY = 80;
        const static int LAYERAMOUNT = 3;
        std::string frame[LAYERAMOUNT][FRAMEX][FRAMEY] = {};
        std::string colorLayer[FRAMEX][FRAMEY];

        // Adds color support
        void enableColorSupport(){
            COLORSUPPORT = true;
        }

        // Initializes layers by making them blank
        void initLayer(int layer){
            for(int a = 0; a<=FRAMEX; a++){
                for(int b = 0; b<=FRAMEY; b++){
                    frame[layer][a][b] = " ";
                }
            }
        }

        // Creates square
        void drawSquare(int layer, int x1, int y1, int x2, int y2, std::string character){
            for(int a = x1; a<=x2; a++){
                for(int b = y1; b<=y2; b++){
                    frame[layer][a][b] = character;
                }
            }
        }

        // Draws frame
        void renderFrame(int c){
            // Blends layers
            for(int a = 0; a<=LAYERAMOUNT-1; a++){
                for(int b = 0; b<=FRAMEX; b++){
                    for(int c = 0; c<=FRAMEY-1; c++){
                        if(frame[a][b][c]!=" "&&a!=0){
                            frame[0][b][c] = frame[a][b][c];
                        }
                    }
                }
            }

            // Prints result
            for(int a = 0; a<=FRAMEX; a++){
                for(int b = 0; b<=FRAMEY; b++){
                    std::cout << frame[c][a][b];
                }
                std::cout << "\n";
            }
        }
};

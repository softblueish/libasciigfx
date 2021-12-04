#ifndef LIBASCIIGFX_H_INCLUDED
#define LIBASCIIGFX_H_INCLUDED

#include <iostream>
#include <vector>
#include <cmath>

class Asciigfx{

        // Default variables
        bool COLORSUPPORT;
        int FRAMEX;
        int FRAMEY;
        int LAYERAMOUNT;
        std::vector<std::vector<std::vector<char>>> frame;
        std::vector<std::vector<char>> colorLayer;

public:

        Asciigfx(bool colourSupport, int sizeX, int sizeY, int layerCount){
            FRAMEX = sizeX;
            FRAMEY = sizeY;
            COLORSUPPORT = colourSupport;
            LAYERAMOUNT = layerCount;

            /// initialize frame vector

            frame.resize(layerCount);

            for(int i = 0; i < layerCount; ++i){
                frame[i].resize(sizeX);
                for(int x = 0; x < sizeX; ++x)
                    frame[i][x].resize(sizeY);
            }

            /// initialize colorLayer vector

            colorLayer.resize(sizeX);

            for(int i = 0; i < sizeX; ++i)
                colorLayer[i].resize(sizeY);

        }

        // Checks if a certain point is inside the frame

        bool frameSanityCheck(int x, int y){return x >= FRAMEX || x < 0 || y >= FRAMEY || y < 0;}

        // Adds color support
        void setColorSupport(bool v){
            COLORSUPPORT = v;
        }

        // Initializes layers by making them blank
        void initLayer(int layer){
            for(int a = 0; a < FRAMEX; a++){
                for(int b = 0; b < FRAMEY; b++){
                    frame[layer][a][b] = ' ';
                }
            }
        }

        // Creates point

        void drawPoint(int layer, int x, int y, char c){

            /// sanity check

            if(frameSanityCheck(x, y)){
                std::cout << "FAILED TO DRAW POINT AT LAYER " << layer << ". (FRAME LIMIT)\n";
                return;
            }

            frame[layer][x][y] = c;

        }

	// Creates a line from (x1,y1) to (x2, y2) filled with characters c

	void drawLine(int layer, int x1, int y1, int x2, int y2, char c){
					
           	/// sanity check

           	if(frameSanityCheck(x1, y1) || frameSanityCheck(x2, y2)){
                	std::cout << "FAILED TO DRAW LINE AT LAYER " << layer << ". (FRAME LIMIT)\n";
                	return;
           	}

		// get unit vector of direction

		float dx = x2 - x1;
		float dy = y2 - y1;
		float l  = sqrt(dx*dx + dy*dy);
		
		dx /= l;
		dy /= l;

		// draw the line onto the layer
		
		float cx = x1;
		float cy = y1;

		while ( dx >= 0 ? floor(cx) < x2 : ceil(cx) > x2
		&&      dy >= 0 ? floor(cy) < y2 : ceil(cy) > y2){
			
			frame[layer][floor(cx)][floor(cy)] = c;
			cx += dx;
			cy += dy;

		}


	}

        // Creates square

        void drawSquare(int layer, int x1, int y1, int x2, int y2, char character){

            /// sanity check

            if(frameSanityCheck(x1, y1) && frameSanityCheck(x2, y2)){
                std::cout << "FAILED TO DRAW SQUARE AT LAYER " << layer << ". (FRAME LIMIT)\n";
                return;
            }

            for(int a = x1; a< x2; a++){
                for(int b = y1; b < y2; b++){
                    frame[layer][a][b] = character;
                }
            }
        }

        // Draws frame
        void renderFrame(){
            // Blends layers
            for(int a = 0; a < LAYERAMOUNT; a++){
                for(int b = 0; b < FRAMEX; b++){
                    for(int c = 0; c < FRAMEY; c++){
                        if((frame[a][b][c]!=' ' && frame[a][b][c]!=0) && a!=0){
                            frame[0][b][c] = frame[a][b][c];

                        }
                    }
                }
            }

            // Prints result
            for(int b = 0; b < FRAMEY; b++){
                for(int a = 0; a < FRAMEX; a++){
                    std::cout << frame[0][a][b];
                }
                std::cout << "\n";
            }
        }
};


#endif // LIBASCIIGFX_H_INCLUDED

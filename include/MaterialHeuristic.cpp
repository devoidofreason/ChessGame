#include "MaterialHeuristic.h"
#include "Piece.h"

float MaterialHeuristic::evaluatePosition(Board* board){
	bool whiteBishop = false, blackBishop = false;
	float whiteMaterial = 0.0f, blackMaterial = 0.0f;
	for(int i=0; i<board->pieces.size(); i++){
		int owner = board->pieces[i]->getOwner();
		char codeText = board->pieces[i]->getCodeText();
		if(owner == 1){
			if(codeText == 'P'){
				whiteMaterial += 1.0f;
			}
			else if(codeText == 'B'){
				if(!whiteBishop){
					whiteBishop = true;
					whiteMaterial += 3.0f;
				}
				else{
					whiteMaterial += 3.5f;
				}
			}
			else if(codeText == 'N'){
				whiteMaterial += 3.0f;
			}
			else if(codeText == 'R'){
				whiteMaterial += 5.0f;
			}
			else if(codeText == 'Q'){
				whiteMaterial += 9.0f;
			}
			else if(codeText == 'K'){
				whiteMaterial += 100.0f;
			}
		}
		else{
			if(codeText == 'P'){
				blackMaterial += 1.0f;
			}
			else if(codeText == 'B'){
				if(!blackBishop){
					blackBishop = true;
					blackMaterial += 3.0f;
				}
				else{
					blackMaterial += 3.5f;
				}
			}
			else if(codeText == 'N'){
				blackMaterial += 3.0f;
			}
			else if(codeText == 'R'){
				blackMaterial += 5.0f;
			}
			else if(codeText == 'Q'){
				blackMaterial += 9.0f;
			}
			else if(codeText == 'K'){
				blackMaterial += 100.0f;
			}
		}
	}
	return (whiteMaterial - blackMaterial) * board->whosTurn;
}
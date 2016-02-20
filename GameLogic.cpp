#include <string>
#include "GameLogic.h"

/*
 *Returns whether or not the Konami Code was contained in the input
 */
bool GameLogic::containsKonamiCode(std::string inputFile){
    std::string konamiCode = "uuddlrlrba";
	if (inputFile.find(konamiCode) != std::string::npos){
		
		return true;

	}
    return false;
}

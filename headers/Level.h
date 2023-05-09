//
// Created by Paul on 07/04/2023.
//

#ifndef OOP_LEVEL_H
#define OOP_LEVEL_H

#include <vector>
#include "Piece.h"
#include "Board.h"

class Level {
private:
    std::vector<Piece> pieceInventory;
    Board currentBoard;
public:
    //maybe_unused clang-tidy thing here, most likely a false positive
    [[maybe_unused]] explicit Level(const std::string&);

    std::vector<Piece> &getPieceInventory() ;

    Board &getCurrentBoard();

    ~Level();
};


#endif //OOP_LEVEL_H

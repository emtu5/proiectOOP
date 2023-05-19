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
    std::vector<std::shared_ptr<Piece>> pieceInventory;
    std::shared_ptr<Board> currentBoard;
public:
    Level();

    //maybe_unused clang-tidy thing here, most likely a false positive
    [[maybe_unused]] explicit Level(const std::string&);

    [[nodiscard]] const std::vector<std::shared_ptr<Piece>> &getPieceInventory() const;

    [[nodiscard]] const std::shared_ptr<Board> &getCurrentBoard() const;

    ~Level();
};


#endif //OOP_LEVEL_H

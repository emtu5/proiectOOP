//
// Created by Paul on 07/04/2023.
//

#ifndef OOP_LEVEL_H
#define OOP_LEVEL_H

#include <vector>
#include "Piece.h"
#include "Board.h"
#include <unordered_map>
#include "BoardFactory.h"
#include "Exceptions.h"

class Level {
private:
    std::vector<Piece> pieceInventory;
    std::shared_ptr<Board> currentBoard;
public:
    Level();

    //maybe_unused clang-tidy thing here, most likely a false positive
    [[maybe_unused]] explicit Level(const std::string&);

    [[nodiscard]] const std::vector<Piece> &getPieceInventory() const;

    [[nodiscard]] const std::shared_ptr<Board> &getCurrentBoard() const;

    ~Level();
};

class LevelList {
private:
    static std::unordered_map<int, Level> levelList;
public:
    static void loadLevels(int);
    static Level& getLevel(int);
};
#endif //OOP_LEVEL_H

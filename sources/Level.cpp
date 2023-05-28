//
// Created by Paul on 07/04/2023.
//

#include "../headers/Level.h"

#include <fstream>
#include <unordered_set>

Level::Level() = default;

[[maybe_unused]] Level::Level(const std::string &levelPath) {
    std::ifstream fin(levelPath);
    if (!fin) {
        throw FileNotFound(levelPath);
    }
    std::string currentLine, boardType; fin >> boardType;

    BoardFactory &factory = BoardFactory::get_factory();

    //Board
    std::vector<std::string> stringBoard;
    for (int i = 0; i < BOARD_LENGTH; i++) {
        fin >> currentLine;
        stringBoard.emplace_back(currentLine);
    }
    //(stringBoard, TILE_SIZE, 'w', sf::Vector2i{BOARD_X, BOARD_Y});

    //Pieces
    char currentId; std::unordered_set<char> ids;
    while (fin >> currentId) {
        try {
            if (ids.count(currentId)) {
                throw SamePieceId(currentId, levelPath);
            }
            ids.insert(currentId);
            bool rotate, flip; fin >> rotate >> flip;
            std::vector<std::string> stringPiece;
            for (int i = 0; i < PIECE_LENGTH; i++) {
                fin >> currentLine;
                stringPiece.emplace_back(currentLine);
            }
            unsigned int height = stringPiece.size();
            if (height % 2 == 0) {
                throw InvalidPieceDimensions(height, stringPiece[0].size());
            }
            for (unsigned int i = 0; i < height; i++) {
                if (height != stringPiece[i].size()) {
                    throw InvalidPieceDimensions(height, stringPiece[0].size());
                }
            }
            pieceInventory.emplace_back(stringPiece, TILE_SIZE, currentId, sf::Vector2i{PIECE_X, PIECE_Y}, rotate, flip);
        } catch (GameExceptions &err) {
            std::cout << err.what() << '\n';
        }
    }
    currentBoard = factory.createBoard(boardType, stringBoard, TILE_SIZE, sf::Vector2i{BOARD_X, BOARD_Y}, pieceInventory.size());
}

const std::vector<Piece> &Level::getPieceInventory() const {
    return pieceInventory;
}


const std::shared_ptr<Board> &Level::getCurrentBoard() const {
    return currentBoard;
}
Level::~Level() = default;

std::unordered_map<int, Level> LevelList::levelList;


void LevelList::loadLevels(int count) {
    std::string x = "level";
    for (int i = 1; i <= count; i++) {
        try {
            if (i < 10) {
                levelList[i] = Level{"resources/levels/level0" + std::to_string(i) + ".txt"};
                continue;
            }
            levelList[i] = Level{"resources/levels/level" + std::to_string(i) + ".txt"};
        } catch (FileNotFound &err) {
            std::cout << err.what() << '\n';
        }
    }
}

Level &LevelList::getLevel(int number) {
    if (!levelList.count(number)) {
        throw BadLevelID(number);
    }
    return levelList[number];
}

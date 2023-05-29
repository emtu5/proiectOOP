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
    while(fin >> currentLine && (currentLine[0] == emptyTile || currentLine[0] == unusedTile)) {
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
            while(fin >> currentLine && (currentLine[0] == emptyTile || currentLine[0] == unusedTile)) {
                stringPiece.emplace_back(currentLine);
            }

            int pieceWidth = static_cast<int>(stringPiece[0].size());
            int pieceHeight = static_cast<int>(stringPiece.size());

            if (pieceHeight % 2 == 0 || pieceWidth % 2 == 0) {
                throw InvalidPieceDimensions(pieceHeight, pieceWidth);
            }

            pieceInventory.emplace_back(stringPiece, TILE_SIZE, currentId, pieceWidth, pieceHeight, sf::Vector2i{PIECE_X, PIECE_Y}, rotate, flip);
        } catch (GameExceptions &err) {
            std::cout << err.what() << '\n';
        }
    }
    int boardWidth = static_cast<int>(stringBoard[0].size());
    int boardHeight = static_cast<int>(stringBoard.size());
    currentBoard = factory.createBoard(boardType, stringBoard, TILE_SIZE, boardWidth, boardHeight, sf::Vector2i{BOARD_X, BOARD_Y}, pieceInventory.size());
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

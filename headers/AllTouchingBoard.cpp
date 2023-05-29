//
// Created by Paul on 29/05/2023.
//

#include "AllTouchingBoard.h"

#include <unordered_set>
#include <queue>

AllTouchingBoard::AllTouchingBoard(const std::vector<std::string> &boardLayout, int size, char id, int w, int h, const sf::Vector2i &pos, unsigned int no_pieces) : Board(boardLayout, size, id, w, h, pos), pieceRequirement(no_pieces) {}

std::shared_ptr<Board> AllTouchingBoard::clone() const {
    return std::make_shared<AllTouchingBoard>(*this);
}

// Win Condition: Place all pieces so that they all touch each other

bool AllTouchingBoard::checkWinCondition() {
    std::unordered_set<char> used_pieces;
    for (int i = 0; i < heightGrid; i++) {
        for (int j = 0; j < widthGrid; j++) {
            if (gridLayout[i][j] == emptyTile || gridLayout[i][j] == unusedTile) {
                continue;
            }
            used_pieces.insert(gridLayout[i][j]);
        }
    }
    if (used_pieces.size() != pieceRequirement) {
        return false;
    }

    // flood-fill

    int startI = 0, startJ = 0;
    for (int i = 0; i < heightGrid; i++) {
        for (int j = 0; j < widthGrid; j++) {
            if (gridLayout[i][j] != emptyTile && gridLayout[i][j] != unusedTile) {
                startI = i; startJ = j;
                i = heightGrid; break;
            }
        }
    }

    std::queue<std::pair<int, int>> flood;
    std::vector<std::string> tempFloodGrid = gridLayout;
    std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    char markedTile = '!';

    flood.emplace(startI, startJ);
    while(!flood.empty()) {
        std::pair<int, int> current = flood.front();
//        std::cout << "Current: " << current.first << " " << current.second << " to the queue\n";
        flood.pop();
        if (tempFloodGrid[current.first][current.second] != emptyTile
        && tempFloodGrid[current.first][current.second] != unusedTile
        && tempFloodGrid[current.first][current.second] != markedTile) {
            tempFloodGrid[current.first][current.second] = markedTile;
            for (auto &d : directions) {
                int newI = current.first + d.first, newJ = current.second + d.second;
                if (0 <= newI && newI < heightGrid && 0 <= newJ && newJ < widthGrid) {
                    flood.emplace(newI, newJ);
//                    std::cout << "Added " << newI << " " << newJ << " to the queue\n";
                }
            }
        }
    }

    std::cout << "---------\n";
    for (auto &line : tempFloodGrid) {
        for (auto &tile : line) {
            std::cout << tile;
        }
        std::cout << '\n';
    }
    std::cout << "---------\n";
    // checking if whole board has been flooded

    for (int i = 0; i < heightGrid; i++) {
        for (int j = 0; j < widthGrid - 1; j++) {
            if (gridLayout[i][j] != emptyTile && gridLayout[i][j] != unusedTile && tempFloodGrid[i][j] != '!') {
                std::cout << "failed flood check, detected another body at " << i << "-" << j
                << ", compared to " << startI << "-" << startJ << '\n';
                return false;
            }
        }
    }

    return true;
}
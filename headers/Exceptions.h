//
// Created by Paul on 28/05/2023.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class GameExceptions : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class FileNotFound : public GameExceptions{
public:
    explicit FileNotFound(const std::string &path) : GameExceptions("File not found: " + path) {}
};

class BadLevelID : public GameExceptions {
public:
    explicit BadLevelID(unsigned int lvl) : GameExceptions("Bad level id: level " + std::to_string(lvl) + " doesn't exist") {}
};

class InvalidPieceDimensions : public GameExceptions{
public:
    explicit InvalidPieceDimensions(unsigned int row, unsigned int col) :
    GameExceptions("Every piece should have an odd number of rows and columns, current dimensions: " + std::to_string(row) + "x" + std::to_string(col)) {}
};

class SamePieceId : public GameExceptions {
public:
    explicit SamePieceId(char id, const std::string &path) : GameExceptions("Duplicate piece id '" + std::string{id} + "' detected in " + path) {}
};

#endif //OOP_EXCEPTIONS_H

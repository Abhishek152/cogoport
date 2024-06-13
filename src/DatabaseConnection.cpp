// DatabaseConnection.cpp
#include "DatabaseConnection.h"
#include <stdexcept>

DatabaseConnection::DatabaseConnection(const std::string& connectionString)
    : conn(connectionString) {
    if (!conn.is_open()) {
        throw std::runtime_error("Failed to connect to database");
    }
}

pqxx::connection& DatabaseConnection::getConnection() {
    return conn;
}

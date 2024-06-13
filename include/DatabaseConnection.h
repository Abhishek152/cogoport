// DatabaseConnection.h
#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <pqxx/pqxx>
#include <string>

class DatabaseConnection {
private:
    pqxx::connection conn;
    
public:
    DatabaseConnection(const std::string& connectionString);
    pqxx::connection& getConnection();
};

#endif // DATABASE_CONNECTION_H

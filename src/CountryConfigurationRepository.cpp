// CountryConfigurationRepository.cpp
#include "CountryConfigurationRepository.h"
#include <sstream>

CountryConfigurationRepository::CountryConfigurationRepository(DatabaseConnection& dbConn)
    : dbConn(dbConn) {}

void CountryConfigurationRepository::createConfiguration(const CountryConfiguration& configuration) {
    try {
        pqxx::work txn(dbConn.getConnection());
        
        // Example query execution (replace with your actual SQL queries)
        std::stringstream query;
        query << "INSERT INTO country_configurations (country_code, business_name, registration_number) "
              << "VALUES ('" << configuration.getCountryCode() << "', '" << configuration.getBusinessName() << "', '"
              << configuration.getRegistrationNumber() << "')";
        
        txn.exec(query.str());
        txn.commit();
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("Failed to create configuration: ") + e.what());
    }
}

CountryConfiguration* CountryConfigurationRepository::getConfiguration(const std::string& countryCode) {
    try {
        pqxx::work txn(dbConn.getConnection());
        
        // Example query execution (replace with your actual SQL queries)
        std::stringstream query;
        query << "SELECT * FROM country_configurations WHERE country_code = '" << countryCode << "'";
        
        pqxx::result result = txn.exec(query.str());
        
        if (result.size() == 1) {
            pqxx::tuple row = result[0];
            return new CountryConfiguration(row["id"].as<int>(), row["country_code"].as<std::string>(),
                                             row["business_name"].as<std::string>(), row["registration_number"].as<std::string>());
        } else {
            return nullptr;
        }
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("Failed to retrieve configuration: ") + e.what());
    }
}

void CountryConfigurationRepository::updateConfiguration(const CountryConfiguration& configuration) {
    try {
        pqxx::work txn(dbConn.getConnection());
        
        // Example update query (replace with your actual SQL update)
        std::stringstream query;
        query << "UPDATE country_configurations SET business_name = '" << configuration.getBusinessName()
              << "', registration_number = '" << configuration.getRegistrationNumber() << "' "
              << "WHERE country_code = '" << configuration.getCountryCode() << "'";
        
        txn.exec(query.str());
        txn.commit();
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("Failed to update configuration: ") + e.what());
    }
}

void CountryConfigurationRepository::deleteConfiguration(const std::string& countryCode) {
    try {
        pqxx::work txn(dbConn.getConnection());
        
        // Example delete query (replace with your actual SQL delete)
        std::stringstream query;
        query << "DELETE FROM country_configurations WHERE country_code = '" << countryCode << "'";
        
        txn.exec(query.str());
        txn.commit();
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("Failed to delete configuration: ") + e.what());
    }
}

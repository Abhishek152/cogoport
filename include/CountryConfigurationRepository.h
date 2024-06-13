// CountryConfigurationRepository.h
#ifndef COUNTRY_CONFIGURATION_REPOSITORY_H
#define COUNTRY_CONFIGURATION_REPOSITORY_H

#include <pqxx/pqxx>
#include "CountryConfiguration.h"
#include "DatabaseConnection.h"

class CountryConfigurationRepository {
private:
    DatabaseConnection& dbConn;
    
public:
    CountryConfigurationRepository(DatabaseConnection& dbConn);
    
    void createConfiguration(const CountryConfiguration& configuration);
    CountryConfiguration* getConfiguration(const std::string& countryCode);
    void updateConfiguration(const CountryConfiguration& configuration);
    void deleteConfiguration(const std::string& countryCode);
};

#endif // COUNTRY_CONFIGURATION_REPOSITORY_H

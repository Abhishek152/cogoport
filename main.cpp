// main.cpp
#include <iostream>
#include "CountryConfiguration.h"
#include "CountryConfigurationRepository.h"
#include "DatabaseConnection.h"

int main() {
    try {
        // Example connection string
        std::string connectionString = "dbname=mydb user=myuser password=mypassword hostaddr=127.0.0.1 port=5432";
        DatabaseConnection dbConn(connectionString);
        CountryConfigurationRepository repository(dbConn);
        
        // Test create
        CountryConfiguration indiaConfig(0, "IND", "Indian Company", "PAN12345");
        repository.createConfiguration(indiaConfig);
        
        // Test get
        CountryConfiguration* retrievedConfig = repository.getConfiguration("IND");
        if (retrievedConfig) {
            std::cout << "Retrieved Configuration:\n";
            std::cout << "ID: " << retrievedConfig->getId() << "\n";
            std::cout << "Country Code: " << retrievedConfig->getCountryCode() << "\n";
            std::cout << "Business Name: " << retrievedConfig->getBusinessName() << "\n";
            std::cout << "Registration Number: " << retrievedConfig->getRegistrationNumber() << "\n";
        } else {
            std::cout << "Configuration not found.\n";
        }
        
        // Test update
        indiaConfig.setBusinessName("Updated Indian Company");
        repository.updateConfiguration(indiaConfig);
        
        // Test delete
        repository.deleteConfiguration("IND");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

// CountryConfiguration.h
#ifndef COUNTRY_CONFIGURATION_H
#define COUNTRY_CONFIGURATION_H

#include <string>

class CountryConfiguration {
private:
    int id;
    std::string countryCode;
    std::string businessName;
    std::string registrationNumber;

public:
    CountryConfiguration(int id, const std::string& countryCode, const std::string& businessName, const std::string& registrationNumber);
    
    // Getters
    int getId() const;
    std::string getCountryCode() const;
    std::string getBusinessName() const;
    std::string getRegistrationNumber() const;
    
    // Setters (optional, depending on your requirements)
    void setBusinessName(const std::string& businessName);
    void setRegistrationNumber(const std::string& registrationNumber);
};

#endif // COUNTRY_CONFIGURATION_H

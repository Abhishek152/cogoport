// CountryConfiguration.cpp
#include "CountryConfiguration.h"

CountryConfiguration::CountryConfiguration(int id, const std::string& countryCode, const std::string& businessName, const std::string& registrationNumber)
    : id(id), countryCode(countryCode), businessName(businessName), registrationNumber(registrationNumber) {}

int CountryConfiguration::getId() const {
    return id;
}

std::string CountryConfiguration::getCountryCode() const {
    return countryCode;
}

std::string CountryConfiguration::getBusinessName() const {
    return businessName;
}

std::string CountryConfiguration::getRegistrationNumber() const {
    return registrationNumber;
}

void CountryConfiguration::setBusinessName(const std::string& businessName) {
    this->businessName = businessName;
}

void CountryConfiguration::setRegistrationNumber(const std::string& registrationNumber) {
    this->registrationNumber = registrationNumber;
}

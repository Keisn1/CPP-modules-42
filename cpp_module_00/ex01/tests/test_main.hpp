#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#include <gtest/gtest.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

struct ContactParams {
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string mobile;
    std::string secret;
};


#endif // TEST_MAIN_H

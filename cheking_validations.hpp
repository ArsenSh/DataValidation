#ifndef cheking_validations_h
#define cheking_validations_h

#include <iostream>
#include <string>

bool checking_mail(std::string& mail);
bool is_digit(const char& c);
bool checking_url(std::string& url);
bool checking_date(int& day, int& month, int& year);
bool checking_card_number(std::string& card_number);
bool checking_phone_number(std::string& phone_number);
bool checking_number(std::string& number);
void operation_choice(int& num);
void operations();
void chosing_first();
void chosing_second();
void chosing_third();
void chosing_forth();
void chosing_fifth();
void chosing_sixth();

#endif

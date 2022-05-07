#include "cheking_validations.h"


void operations()
{
    std::cout << "\n 1. Email \n 2. Website URL \n 3. Date \n 4. Number \n 5. Credit Card Number \n 6. Mobile Phone Number \n \n 0. For EXIT \n" << std::endl;
    int index;
    do{
        std::cout << "Enter the index: ";
        std::cin >> index;
        operation_choice(index);
    }while(index < 0 || index > 6);
}

void operation_choice(int& num)
{
    switch(num)
    {
        case 0:
                break;
        case 1:
                chosing_first();
                operations();
                break;
        case 2:
                chosing_second();
                operations();
                break;
        case 3:
                chosing_third();
                operations();
                break;
        case 4:
                chosing_forth();
                operations();
                break;
        case 5:
                chosing_fifth();
                operations();
                break;
        case 6:
                chosing_sixth();
                operations();
                break;
        default:
            std::cout << "You have entered the wrong index !" << std::endl;
                break;
    }
}

void chosing_first()
{
    std::string mail = "";
    std::cout << "Enter your email: ";
    std::cin >> mail;
    std::cout << std::endl;
    std::cout << (checking_mail(mail) ? "Your mail is Correct !" : "Your mail is not Correct !") << std::endl;
}

void chosing_second()
{
    std::string url = "";
    std::cout << "Enter website URL: ";
    std::cin >> url;
    std::cout << (checking_url(url) ? "Your URL is Correct !" : "Your URL is not Correct !") << std::endl;
}

void chosing_third()
{
    int day = 0, month = 0, year = 0;
    std::cout << "Enter the date in this way (day.month.year)." << std::endl;
    std::cout << "Day: ";
    std::cin >> day;
    std::cout << "Month: ";
    std::cin >> month;
    std::cout << "Year: ";
    std::cin >> year;
    std::cout << std::endl;
    std::cout << (checking_date(day, month, year) ? "Your date is Correct !" : "Your date is not Correct !") << std::endl;
}

void chosing_forth()
{
    std::string num;
    std::cout << "Enter your number: ";
    std::cin >> num;
    std::cout << std::endl;
    std::cout << (checking_number(num) ? "The number is Valide !" : "The number is not Valide !") << std::endl;
}

bool checking_number(std::string& number)
{
    int size =  sizeof number / sizeof number[0];
    int count = 0;

    if(!is_digit(number[0]))
    {
        return false;
    }
    for(int i = 1; i < size; i++)
    {
        if(!is_digit(number[i]))
        {
            if(number[i] != 'e')
            {
                return false;
            }
            if(number[i] == 'e')
            {
                ++count;
            }
        }
    }
    if(count > 1)
    {
        return false;
    }
    return true;
}

void chosing_fifth()
{
    std::string card_number = "";
    std::cout << "Enter the number of the card: ";
    std::cin.ignore();
    std::getline(std::cin, card_number);
    std::cout << (checking_card_number(card_number) ? "Your card number is Correct !" : "Your card number is not Correct !") << std::endl;
}

bool checking_card_number(std::string& card_number)
{
    int size = 0;
    int card_number_size = 0;
    
    for(int i = 0; card_number[i] != '\0'; i++)
    {
        ++size;
    }

    for(int i = 0; i < size; i++)
    {
        if(is_digit(card_number[i]))
        {
            ++card_number_size;
        }
    }
    if(card_number_size != 16)
    {
        return false;
    }
    
    return true;
}

void chosing_sixth()
{
    std::string phone_number;
    std::cout << "Enter the  number of the phone: ";
    std::cin >> phone_number;
    std::cout << (checking_phone_number(phone_number) ? "The phone number is Correct !" : "The phone number is not Correct !") << std::endl;
}

bool checking_phone_number(std::string& phone_number)
{
    int size = 0;
    for(int i = 0; phone_number[i] != '\0'; i++)
    {
        ++size;
    }
    if(phone_number[0] != '+' && phone_number[0] != '0')
    {
        std::cout << "The number does not start with + or 0 !" << std::endl;
        return false;
    }
    else
    {
        for(int i = 1; i < size; i++)
        {
            if(!is_digit(phone_number[i]))
            {
                std::cout << "\t" << i << std::endl;
                std::cout << "The number contains letter caracter !" << std::endl;
                return false;
            }
        }
    }
    return true;
}


bool checking_mail(std::string& mail)
{
    int size = sizeof mail / sizeof mail[0];

    int dog = -1, dot = -1;

    for(int i = 0; i < size; i++)
    {
        if(is_digit(mail[0]))
        {
            return false;
        }

        if(mail[i] == '@')
        {
            dog = i;
            mail.find(i, size - 1);
        }
        if (mail[i] == '.')
        {
            dot = i;
        }
    }
    if(dog == -1 || dot== -1 || dog > dot || (dot - dog) == 1)
    {
        return false;
    }
    return true;
}

bool is_digit(const char& c)
{
    bool check = ((c <= 57) && (c >= 48));
    return check;
}

bool checking_url(std::string& url)
{
    std::string protocol_domain = "https://";
    int size_protocol = 8;
    int size_url = 0;
    for(int i = 0; url[i] != '\0'; i++)
    {
        ++size_url;
    }
    
    for(int i = 0; i < size_protocol; i++)
    {
        if(url[i] != protocol_domain[i])
        {
            return false;
        }
    }
    
    int dot = -1, d = -1;
    
    for(int i = size_protocol; i < size_url; i++)
    {
        if(url[i] == '.')
        {
            dot = i;
        }
        if(url[i] == '/')
        {
            d = i;
            break;
        }
    }
    if(dot == -1 || d == -1 || dot > d)
    {
        return false;
    }
    
    return true;
}

bool checking_date(int& day, int& month, int& year)
{
    if(year > 1000 && year < 3000)
    {
        if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31)
        {
            return true;
        }
        else if ((month == 4 || month == 6 || month == 9|| month == 11) && day > 0 && day <= 30)
        {
            return true;
        }
        else if (month == 2)
        {
            if (( year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && day > 0 && day <= 29)
            {
                return true;
            }
        }
    }
    return false;
}

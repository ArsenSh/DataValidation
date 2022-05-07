#include <iostream>
#include "cheking_validations.h"


int main ()
{
    int num = 0;
    std::cout << "Which data validation operation do you chose ?" << std::endl << std::endl;
    std::cout << " 1. Email \n 2. Website URL \n 3. Date \n 4. Number \n 5. Credit Card Number \n 6. Mobile Phone Number \n \n 0. For EXIT \n" << std::endl;
    do{
        std::cout << "Enter the correct index of the operation: ";
        std::cin >> num;
        operation_choice(num);
      }while((num < 0) || (num > 6));
    
    return 0;
}

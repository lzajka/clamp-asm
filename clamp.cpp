#include <iostream>
#include "clamp.hpp"

int main(){
    u_int16_t middle = 128;
    u_int16_t range = 128;

    while(true){
        print_przedzial(range, middle);
        std::string input;
        std::cin >> input;

        
        if(input == "<"){       // Zmniejsz przedział
            range = range - 1;
            
        }
        else if(input == ">") { // Zwiększ przedział
            range = range + 1;
        }
        else {                  // Wykonaj operacje clamp na podanym przedziale
            u_int16_t value = std::stoi(input);
            u_int16_t min = middle - range;
            u_int16_t max = middle + range;
            u_int16_t output = clamp(value, min, max);
            std::cout << output << std::endl;
        }
    }
    return 0;
    
}

void print_przedzial(int range, int middle) {
    std::cout << "Przedział: <" << middle - range << ", " << middle + range << ">" << std::endl;
}

int clamp(u_int16_t value, u_int16_t min, u_int16_t max){
    u_int16_t output;
    asm(
/*
GCC używa składni AT&T.
source -> destination

Zmienne przypisałem następująco:
%0 - output
%1 - value
%2 - min
%3 - max

Wykorzyanie \n\t jest konieczne w słowie kluczowym asm
*/
        "CLAMP:\n\t"
        "mov %1, %0\n\t"                        // output = value. Wartość zostanie jeśli mieści się w przebiegu.
        "cmp %3, %1\n\t"
        "jg CLAMP_CEIL\n\t"   
        "cmp %2, %1\n\t" 
        "jl CLAMP_FLOOR\n\t"
        "jmp CLAMP_EXIT\n\t"                    // return output
        "CLAMP_FLOOR:\n\t"                      // if value < min
        "mov %2, %0\n\t"                            // output = min
        "jmp CLAMP_EXIT\n\t"                        // return output
        "CLAMP_CEIL:\n\t"                       // if value > max
        "mov %3, %0\n\t"                            // output = max
        "jmp CLAMP_EXIT\n\t"                        // return output
        "CLAMP_EXIT:\n\t"
        : "=r" (output)                         // Ta część jest używana w asm w C/C++ w celu oznaczenia zmiennej wyjściowej
        : "r" (value), "r" (min), "r" (max)     // Ta część jest używana w asm w C/C++ w celu oznaczenia zmiennych wejściowych
    );
    return output;

}


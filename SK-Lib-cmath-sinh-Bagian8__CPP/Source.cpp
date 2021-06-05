#pragma fenv_access (on)
#pragma warning(disable:4996)

#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main() {
    std::cout << "sinh(1) = " << std::sinh(1) << '\n'
        << "sinh(-1) = " << std::sinh(-1) << '\n'
        << "log(sinh(1)+cosh(1)) = "
        << std::log(std::sinh(1) + std::cosh(1)) << '\n';
    
    // special values
    std::cout << "sinh(+0) = " << std::sinh(0.0) << '\n'
        << "sinh(-0) = " << std::sinh(-0.0) << '\n';
    
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "sinh(710.5) = " << std::sinh(710.5) << '\n';
    
    if (errno == ERANGE) {
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    }
        
    if (std::fetestexcept(FE_OVERFLOW)) {
        std::cout << "    FE_OVERFLOW raised\n";
    }
        
    _getch();
    return 0;
}
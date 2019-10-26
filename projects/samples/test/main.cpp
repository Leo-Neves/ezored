#define CATCH_CONFIG_MAIN
#include "catch.hpp"

unsigned int Fatorial(unsigned int number){
    return number<=1 ? number : Fatorial(number-1)*number;
}

TEST_CASE("Fatoriais computados", "[fatorial]"){
    REQUIRE (Fatorial(1) == 1);
    REQUIRE (Fatorial(2) == 2);
    REQUIRE (Fatorial(3) == 6);
    REQUIRE (Fatorial(10) == 3628800);
}
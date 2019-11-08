#include "catch.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include "rapidjson/document.h"
#include "ezored/helpers/MapHelper.hpp"
#include "ezored/time/DateTime.hpp"

using std::string;
using rapidjson::Document;
using ezored::helpers::MapHelper;
using ezored::time::DateTime;

TEST_CASE("Parser Json", "[parser-json]"){
    Document json = MapHelper::toJson("{\"nome\": \"Leo\", \"nascimento\": \"1993-05-28\", \"sobrenome\": \"Santana\"}");
    string nome = MapHelper::getString("nome", json);
    string sobrenome = MapHelper::getString("sobrenome", json);
    std::chrono::system_clock::time_point nascimentoJson = MapHelper::getDate("nascimento", json, "%F");
    std::chrono::system_clock::time_point nascimentoDateTime = DateTime::getDateTimeFromStringFormat("1993-05-28", "%F");
    REQUIRE (nome == "Leo");
    REQUIRE (sobrenome == "Santana");
    REQUIRE (nascimentoJson == nascimentoDateTime);
    string reverseNascimentoJson = DateTime::getStringFromDateTimeFormat(nascimentoJson, "%F");
    string reverseNascimentoDateTime = DateTime::getStringFromDateTimeFormat(nascimentoDateTime, "%F");
    std::cout<<"Nascimento JSON: "<<reverseNascimentoJson<<std::endl;
    std::cout<<"Nascimento DateTime: "<<reverseNascimentoDateTime<<std::endl;
    REQUIRE (reverseNascimentoJson == reverseNascimentoDateTime);
}
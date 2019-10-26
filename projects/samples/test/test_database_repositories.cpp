#include "catch.hpp"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "ezored/time/DateTime.hpp"
#include "ezored/holiday/PaisRepositoryImpl.hpp"
#include "ezored/holiday/PaisRepository.hpp"
#include "ezored/holiday/PaisParser.hpp"
#include "ezored/holiday/Pais.hpp"
#include "ezored/holiday/FeriadoRepositoryImpl.hpp"
#include "ezored/holiday/FeriadoRepository.hpp"
#include "ezored/holiday/FeriadoParser.hpp"
#include "ezored/holiday/Feriado.hpp"

using std::string;
using std::vector;
using ezored::time::DateTime;
using ezored::holiday::PaisRepositoryImpl;
using ezored::holiday::PaisRepository;
using ezored::holiday::PaisParser;
using ezored::holiday::Pais;
using ezored::holiday::FeriadoRepositoryImpl;
using ezored::holiday::FeriadoRepository;
using ezored::holiday::FeriadoParser;
using ezored::holiday::Feriado;

Feriado criarFeriado(string nome, string siglaPais, string date){
    std::chrono::system_clock::time_point data = DateTime::getDateTimeFromStringFormat(date, "%F");
    return Feriado{siglaPais, data, nome};
}

TEST_CASE("Pais repository", "[pais-repository]"){
    Pais pais = PaisParser::createPais();
    pais.nome = "Brasil";
    pais.sigla = "BR";
    PaisRepositoryImpl::deletarTudo();
    PaisRepositoryImpl::salvar(pais);
    vector<Pais> paises = PaisRepository::findAll();
    Pais p = paises[0];
    REQUIRE (paises.size() == 1);
    REQUIRE (p.nome == pais.nome);
    REQUIRE (p.nome == "Brasil");
}

TEST_CASE("Feriado Repository", "[feriado-repository]"){
    FeriadoRepositoryImpl::deletarTudo();
    Feriado natal = FeriadoParser::createFeriado();
    natal.nome = "Natal";
    natal.siglaPais = "BR";
    natal.data = DateTime::getDateTimeFromStringFormat("25/12", "%d/%m/");
    Feriado laborDay = FeriadoParser::createFeriado();
    laborDay.nome = "Labor Day";
    laborDay.siglaPais = "US";
    laborDay.data = DateTime::getDateTimeFromStringFormat("2019-05-01", "%F");
    Feriado diaDoTrabalho = criarFeriado("Dia do Trabalho", "BR", "2019-05-01");
    FeriadoRepositoryImpl::salvar(natal);
    FeriadoRepositoryImpl::salvar(laborDay);
    FeriadoRepositoryImpl::salvar(diaDoTrabalho);
    REQUIRE (FeriadoRepository::findAll().size() == 3);
    REQUIRE (FeriadoRepository::findByPais("BR").size() == 2);
    REQUIRE (FeriadoRepository::findByPais("US").size() == 1);
    REQUIRE (FeriadoRepository::findByPais("PT").size() == 0);
}
#pragma once

#include "ezored/agricola/FeriadoRepository.hpp"
#include "ezored/agricola/Feriado.hpp"
#include "SQLiteCpp/SQLiteCpp.h"
#include <memory>
#include <vector>
#include <string>

namespace ezored
{
namespace agricola
{

class FeriadoRepositoryImpl : FeriadoRepository
{
    public: 
        virtual ~FeriadoRepositoryImpl() {}
        static void salvar(std::string json);
        static void salvar(Feriado feriado);
        static void salvarTudo(std::string json);
        static Feriado findByPaisAndNome(std::string siglaPais, std::string nome);
        static std::vector<Feriado> findAll();
};

} // namespace systemservices
} // namespace ezored


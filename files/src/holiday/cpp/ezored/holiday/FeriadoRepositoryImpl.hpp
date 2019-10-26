#pragma once

#include "ezored/holiday/FeriadoRepository.hpp"
#include "ezored/holiday/Feriado.hpp"
#include "SQLiteCpp/SQLiteCpp.h"
#include <memory>
#include <vector>
#include <string>

using ezored::holiday::Feriado;

namespace ezored
{
namespace holiday
{

class FeriadoRepositoryImpl : FeriadoRepository
{
    public: 
        virtual ~FeriadoRepositoryImpl() {}
        static void salvar(std::string json);
        static void salvar(Feriado feriado);
        static void salvarTudo(std::string json);
};

} // namespace systemservices
} // namespace ezored


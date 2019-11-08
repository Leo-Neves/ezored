#pragma once

#include "ezored/holiday/PaisRepository.hpp"
#include "ezored/holiday/Pais.hpp"
#include <memory>
#include <vector>
#include <string>

namespace ezored
{
namespace holiday
{

class PaisRepositoryImpl : PaisRepository
{
    public: 
        virtual ~PaisRepositoryImpl() {}
        static void salvar(std::string json);
        static void salvar(Pais pais);
        static void salvarTudo(std::string json);
        static void deletarTudo();
};

} // namespace systemservices
} // namespace ezored


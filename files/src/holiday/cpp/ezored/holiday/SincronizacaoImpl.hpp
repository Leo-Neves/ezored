#pragma once

#include "ezored/holiday/Sincronizacao.hpp"
#include "ezored/holiday/SincronizacaoListener.hpp"
#include <memory>
#include <vector>
#include <string>

namespace ezored
{
namespace holiday
{

class SincronizacaoImpl : Sincronizacao
{
    public: 
        virtual ~SincronizacaoImpl() {};
        void baixarPais(const std::string & sigla, const std::shared_ptr<SincronizacaoListener> & listener);
};

} // namespace systemservices
} // namespace ezored


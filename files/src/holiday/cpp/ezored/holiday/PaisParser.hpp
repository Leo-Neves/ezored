#pragma once

#include "ezored/holiday/Pais.hpp"
#include "SQLiteCpp/SQLiteCpp.h"
#include <memory>
#include <vector>
#include <string>

namespace ezored
{
namespace holiday
{

class PaisParser 
{
    public: 
        virtual ~PaisParser() {}
        static Pais parseJsonParaObjeto(std::string json);
        static Pais parseCursorParaObjeto(SQLite::Statement &query);
        static std::string parseObjetoParaJson(Pais pais);
        static Pais createPais();
};

} // namespace systemservices
} // namespace ezored


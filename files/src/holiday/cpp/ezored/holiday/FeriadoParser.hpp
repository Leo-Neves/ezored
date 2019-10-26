#pragma once

#include "ezored/holiday/Feriado.hpp"
#include "SQLiteCpp/SQLiteCpp.h"
#include <memory>
#include <vector>
#include <string>

namespace ezored
{
namespace holiday
{

class FeriadoParser 
{
    public: 
        virtual ~FeriadoParser() {}
        static Feriado parseJsonParaObjeto(std::string json);
        static Feriado parseCursorParaObjeto(SQLite::Statement query);
        static Feriado createFeriado();
};

} // namespace systemservices
} // namespace ezored


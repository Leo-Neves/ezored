#include "ezored/holiday/Feriado.hpp"
#include "ezored/holiday/FeriadoRepositoryImpl.hpp"
#include "ezored/holiday/PaisRepositoryImpl.hpp"
#include "ezored/holiday/FeriadoParser.hpp"
#include "ezored/time/DateTime.hpp"
#include "ezored/helpers/MapHelper.hpp"

#include "rapidjson/document.h"
#include "rapidjson/pointer.h"

#include <string>
#include <cstddef>
#include <memory>

using ezored::holiday::Feriado;
using ezored::holiday::FeriadoParser;
using ezored::helpers::MapHelper;

namespace ezored{
namespace holiday{

    Feriado FeriadoParser::parseJsonParaObjeto(std::string &json){
        rapidjson::Document jsonFeriado = MapHelper::toJson(json);
        if (!jsonFeriado.IsNull() && jsonFeriado.IsObject()){
            std::string siglaPais = MapHelper::getString("countryCode", jsonFeriado);
            std::chrono::system_clock::time_point data = MapHelper::getDate("date", jsonFeriado, "%F");
            std::string nome = MapHelper::getString("localName", jsonFeriado);
            return Feriado{siglaPais, data, nome};
        }
        return FeriadoParser::createFeriado();
    }

    Feriado FeriadoParser::parseCursorParaObjeto(SQLite::Statement &row){
        auto feriado = FeriadoParser::createFeriado();
        feriado.siglaPais = row.getColumn("sigla_pais").getString();
        feriado.nome = row.getColumn("nome").getString();
        std::string dataString = row.getColumn("data").getString();
        feriado.data = time::DateTime::getDateTimeFromStringFormat(dataString, "%F");
        return feriado;
    }

    Feriado FeriadoParser::createFeriado(){
        return Feriado{"", time::DateTime::getCurrentDateTime(), ""};
    }

}
}

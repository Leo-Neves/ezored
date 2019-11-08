#include "ezored/holiday/Pais.hpp"
#include "ezored/holiday/PaisRepositoryImpl.hpp"
#include "ezored/holiday/PaisParser.hpp"
#include "ezored/time/DateTime.hpp"
#include "ezored/helpers/MapHelper.hpp"

#include "rapidjson/document.h"
#include "rapidjson/pointer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

#include <string>
#include <cstddef>
#include <memory>

using ezored::helpers::MapHelper;

namespace ezored{
namespace holiday{

    Pais PaisParser::parseJsonParaObjeto(std::string json){
        rapidjson::Document jsonPais = MapHelper::toJson(json);
        if (!jsonPais.IsNull() && jsonPais.IsObject()){
            std::string sigla = MapHelper::getString("key", jsonPais);
            std::string nome = MapHelper::getString("value", jsonPais);
            return Pais{sigla, nome};
        }
        return PaisParser::createPais();
    }

    Pais PaisParser::parseCursorParaObjeto(SQLite::Statement &row){
        auto pais = PaisParser::createPais();
        pais.sigla = row.getColumn("sigla").getString();
        pais.nome = row.getColumn("nome").getString();
        return pais;
    }

    std::string PaisParser::parseObjetoParaJson(Pais pais){
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        writer.StartObject();

        //'Key' is the short name of country
        writer.Key("key");
        writer.String(pais.sigla.c_str());

        //'value' is the full name of country
        writer.Key("value");
        writer.String(pais.nome.c_str());

        writer.EndObject();
        auto json = buffer.GetString();
        return json;
    }

    Pais PaisParser::createPais(){
        return Pais{"", ""};
    }

}
}

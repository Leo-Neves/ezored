#include "ezored/holiday/Feriado.hpp"
#include "ezored/holiday/FeriadoRepositoryImpl.hpp"
#include "ezored/holiday/PaisRepositoryImpl.hpp"
#include "ezored/holiday/FeriadoParser.hpp"
#include "ezored/core/ApplicationCore.hpp"
#include "ezored/core/ApplicationCoreImpl.hpp"
#include "ezored/time/DateTime.hpp"
#include "ezored/helpers/MapHelper.hpp"

#include "rapidjson/document.h"
#include "rapidjson/pointer.h"

#include <string>
#include <cstddef>
#include <memory>

namespace ezored{
namespace holiday{

    void FeriadoRepositoryImpl::salvar(std::string json){
        Feriado feriado = FeriadoParser::parseJsonParaObjeto(json);
        FeriadoRepositoryImpl::salvar(feriado);
    }

    void FeriadoRepositoryImpl::salvar(Feriado feriado){
        auto sql =
        "INSERT INTO FERIADO (nome, data, sigla_pais) "
        "VALUES (:nome, :data, :sigla_pais)";

        auto application = std::static_pointer_cast<core::ApplicationCoreImpl>(core::ApplicationCore::shared());
        auto db = application->getDB();

        SQLite::Statement query(*db, sql);

        query.bind(":nome", feriado.nome);
        query.bind(":data", time::DateTime::getStringFromDateTime(feriado.data));
        query.bind(":sigla_pais", feriado.siglaPais);
        query.exec();
    }

    void FeriadoRepositoryImpl::salvarTudo(std::string json){
        auto jsonArray = helpers::MapHelper::toJson(json);
        for (auto& objeto : jsonArray.GetArray()){
            rapidjson::Document document;
            objeto.Swap(document);
            rapidjson::Pointer("").Set(document, objeto);
            std::string feriadoJson = helpers::MapHelper::toString(document);
            FeriadoRepositoryImpl::salvar(feriadoJson);
        }
    }

    std::vector<Feriado> FeriadoRepository::findByPais(const std::string &siglaPais){
        auto sql = "SELECT * FROM FERIADO where sigla_pais = :siglaPais";
        auto application = std::static_pointer_cast<core::ApplicationCoreImpl>(core::ApplicationCore::shared());
        auto db = application->getDB();
        SQLite::Statement query(*db, sql);
        query.bind(":siglaPais", siglaPais);

        auto feriados = std::vector<Feriado>{};
        while (query.executeStep()){
            auto feriado = FeriadoParser::parseCursorParaObjeto(query);
            feriados.push_back(feriado);
        }

        return feriados;
    }

    std::vector<Feriado> FeriadoRepository::findAll(){
        auto sql = "SELECT * FROM FERIADO order by data ASC";
        auto application = std::static_pointer_cast<core::ApplicationCoreImpl>(core::ApplicationCore::shared());
        auto db = application->getDB();
        SQLite::Statement query(*db, sql);

        auto feriados = std::vector<Feriado>{};

        while (query.executeStep())
        {
            auto feriado = FeriadoParser::parseCursorParaObjeto(query);
            feriados.push_back(feriado);
        }

        return feriados;
    }

    void FeriadoRepositoryImpl::deletarTudo(){
            auto sql = "DELETE FROM FERIADO";
            auto application = std::static_pointer_cast<core::ApplicationCoreImpl>(core::ApplicationCore::shared());
            auto db = application->getDB();
            SQLite::Statement query(*db, sql);
            query.exec();
        }

}
}

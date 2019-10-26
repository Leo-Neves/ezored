#include "ezored/holiday/Pais.hpp"
#include "ezored/holiday/PaisRepositoryImpl.hpp"
#include "ezored/holiday/PaisParser.hpp"
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
    namespace agricola{

        void PaisRepositoryImpl::salvar(std::string json){
            Pais pais = PaisParser::parseJsonParaObjeto(json);
            PaisRepositoryImpl::salvar(feriado);
        }

        void PaisRepositoryImpl::salvar(Pais pais){
            auto sql =
            "INSERT INTO Pais (sigla, nome) "
            "VALUES (:sigla, :nome)";

            auto application = std::static_pointer_cast<core::ApplicationCoreImpl>(core::ApplicationCore::shared());
            auto db = application->getDB();

            SQLite::Statement query(*db, sql);

            query.bind(":nome", pais.nome);
            query.bind(":sigla", pais.sigla);
            query.exec();
        }

        void PaisRepositoryImpl::salvarTudo(std::string json){
            auto jsonArray = helpers::MapHelper::toJson(json);
            for (auto& objeto : jsonArray.GetArray()){
                rapidjson::Document document;
                objeto.Swap(document);
                rapidjson::Pointer("").Set(document, objeto);
                std::string paisJson = helpers::MapHelper::toString(document);
                PaisRepositoryImpl::salvar(paisJson);
            }
        }

        Pais PaisRepository::getBySigla(std::string siglaPais){
            auto sql = "SELECT * FROM PAIS where sigla = :siglaPais LIMIT 1";
            auto application = std::static_pointer_cast<core::ApplicationCoreImpl>(core::ApplicationCore::shared());
            auto db = application->getDB();
            SQLite::Statement query(*db, sql);

            query.bind(":siglaPais", siglaPais);

            while (query.executeStep())
            {
                auto pais = PaisParser::parseCursorParaObjeto(query);
                return pais;
            }

            return PaisParser::criarPais();
        }

        std::vector<Pais> PaisRepository::findAll(){
            auto sql = "SELECT * FROM PAIS order by nome ASC";
            auto application = std::static_pointer_cast<core::ApplicationCoreImpl>(core::ApplicationCore::shared());
            auto db = application->getDB();
            SQLite::Statement query(*db, sql);

            auto paises = std::vector<Pais>{};

            while (query.executeStep())
            {
                auto pais = PaisParser::parseCursorParaObjeto(query);
                paises.push_back(pais);
            }

            return paises;
        }

    }
}

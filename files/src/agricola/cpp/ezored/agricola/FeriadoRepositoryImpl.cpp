#include "ezored/agricola/Feriado.hpp"
#include "ezored/agricola/FeriadoRepositoryImpl.hpp"
#include "ezored/agricola/PaisRepositoryImpl.hpp"
#include "ezored/agricola/FeriadoParser.hpp"
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
        std::vector<Feriado> FeriadoRepository::getFeriados(const std::string & siglaPais){
            Feriado diaDoTrabalho = FeriadoParser::criarFeriado();
            Feriado natal = FeriadoParser::criarFeriado();
            Feriado tiradentes = FeriadoParser::criarFeriado();
            auto feriados = std::vector<Feriado>{};
            feriados.push_back(diaDoTrabalho);
            feriados.push_back(natal);
            feriados.push_back(tiradentes);
            return feriados;
        }

        void FeriadoRepository::deletarTudo(){
            Feriado feriado = FeriadoParser::criarFeriado();
        }

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

        Feriado FeriadoRepositoryImpl::findByPaisAndNome(std::string siglaPais, std::string nome){
            auto sql = "SELECT * FROM FERIADO where sigla_pais = :siglaPais and nome = :nome LIMIT 1";
            auto application = std::static_pointer_cast<core::ApplicationCoreImpl>(core::ApplicationCore::shared());
            auto db = application->getDB();
            SQLite::Statement query(*db, sql);

            query.bind(":countryCode", siglaPais);
            query.bind(":name", nome);

            while (query.executeStep())
            {
                auto feriado = FeriadoParser::parseCursorParaObjeto(query);
                return feriado;
            }

            return FeriadoParser::criarFeriado();
        }

        std::vector<Feriado> FeriadoRepositoryImpl::findAll(){
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

    }
}

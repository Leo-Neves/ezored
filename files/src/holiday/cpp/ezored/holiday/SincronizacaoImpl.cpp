#include "ezored/core/ApplicationCore.hpp"
#include "ezored/core/ApplicationCoreImpl.hpp"
#include "ezored/helpers/ResponseHelper.hpp"

#include "ezored/net/http/HttpClient.hpp"
#include "ezored/net/http/HttpHeader.hpp"
#include "ezored/net/http/HttpMethod.hpp"
#include "ezored/net/http/HttpRequest.hpp"
#include "ezored/net/http/HttpRequestParam.hpp"
#include "ezored/net/http/HttpResponse.hpp"

#include "ezored/holiday/FeriadoRepositoryImpl.hpp"
#include "ezored/holiday/SincronizacaoImpl.hpp"
#include "ezored/holiday/Pais.hpp"
#include "ezored/holiday/SincronizacaoListener.hpp"
#include <string>

namespace ezored
{
namespace holiday
{
    using namespace ezored::helpers;
    using namespace ezored::core;
    using namespace ezored::net::http;

    void Sincronizacao::baixarTudo(const std::shared_ptr<SincronizacaoListener> & listener){
        
    }

    void SincronizacaoImpl::baixarPais(const std::string & sigla, const std::shared_ptr<SincronizacaoListener> & listener){
        auto application = std::static_pointer_cast<ApplicationCoreImpl>(ApplicationCore::shared());

        auto httpHeaders = application->getDefaultHttpRequestHeaders();
        httpHeaders.push_back(HttpHeader{"Content-Type", "application/json"});
        httpHeaders.push_back(HttpHeader{"User-Agent", "PostmanRuntime/7.18.0"});
        httpHeaders.push_back(HttpHeader{"Accept", "*/*"});
        httpHeaders.push_back(HttpHeader{"Cache-Control", "no-cache"});
        httpHeaders.push_back(HttpHeader{"Postman-Token", "305f7cfd-1f19-41e5-a5c7-882c25926b90"});
        httpHeaders.push_back(HttpHeader{"Host", "date.nager.at"});
        httpHeaders.push_back(HttpHeader{"Accept-Encoding", "gzip, deflate"});
        httpHeaders.push_back(HttpHeader{"Connection", "keep-alive"});
        httpHeaders.push_back(HttpHeader{"Leo", "Santana"});

        auto httpParams = application->getDefaultHttpRequestParams();

        auto httpURL = "https://date.nager.at/api/v2/PublicHolidays/2017/BR";

        auto httpRequest = HttpRequest{httpURL, HttpMethod::METHOD_GET, httpParams, httpHeaders, ""};
        ezored::net::http::HttpResponse httpResponse = HttpClient::shared()->doRequest(httpRequest);

        auto response = ResponseHelper::fromHttpResponse(httpResponse);
        if (httpResponse.code==200){
            FeriadoRepositoryImpl::salvarTudo(httpResponse.body);
            if (listener!=nullptr){
                listener->sucesso();
            }
        }else{
            if (listener!=nullptr){
            listener->falha(httpResponse.body);}
        }
    }
}
}

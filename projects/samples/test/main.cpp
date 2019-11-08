#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ezored/core/ApplicationCore.hpp"

#include "Poco/File.h"
#include "Poco/Path.h"
#include "ezored/util/Logger.hpp"
#include "ezored/util/LoggerLevel.hpp"
#include "ezored/util/SimpleLoggerPlatformService.hpp"

#include "ezored/net/http/HttpClient.hpp"
#include "ezored/net/http/HttpClientLoggerImpl.hpp"
#include "ezored/net/http/HttpRequest.hpp"
#include "ezored/net/http/HttpResponse.hpp"
#include "ezored/net/http/SimpleHttpClientPlatformService.hpp"

#include "ezored/helpers/StringHelper.hpp"
#include "ezored/io/FileHelper.hpp"
#include "ezored/time/DateTime.hpp"

#include "ezored/helpers/CustomerHelper.hpp"
#include "ezored/helpers/EnvironmentHelper.hpp"
#include "ezored/helpers/TodoHelper.hpp"

#include "ezored/data/SharedData.hpp"
#include "ezored/data/SimpleSharedDataPlatformService.hpp"

#include "ezored/domain/DeviceData.hpp"
#include "ezored/domain/InitializationData.hpp"
#include "ezored/domain/Todo.hpp"

#include "ezored/dataservices/TodoDataService.hpp"

#include "ezored/systemservices/CustomerSystemService.hpp"
#include "ezored/systemservices/CustomerSystemServiceLoginData.hpp"

#include <iostream>
#include <memory>

using namespace ezored::util;
using namespace ezored::net::http;
using namespace ezored::time;
using namespace ezored::helpers;
using namespace ezored::io;
using namespace ezored::data;

using namespace ezored::domain;
using namespace ezored::core;
using namespace ezored::dataservices;
using namespace ezored::systemservices;
using namespace ezored::helpers;

void init(){
    // platform services
    Logger::shared()->setPlatformService(std::make_shared<SimpleLoggerPlatformService>());
    Logger::shared()->setLevel(LoggerLevel::VERBOSE);

    HttpClient::shared()->setPlatformService(std::make_shared<SimpleHttpClientPlatformService>());
    SharedData::shared()->setPlatformService(std::make_shared<SimpleSharedDataPlatformService>());

    // application core
    auto homeDir = Poco::Path::home() + "ezored";
    Poco::File(homeDir).createDirectory();

    auto initializationData = InitializationData{"com.ezored.sample", "ezored", homeDir, 0, true};
    auto deviceData = DeviceData{"", "", "", "", "", "", "", "", "", 0, 0, 0, "", "", "", ""};

    ApplicationCore::shared()->initialize(initializationData, deviceData);
}

TEST_CASE("Iniciar testes", "[init]"){
    init();
}
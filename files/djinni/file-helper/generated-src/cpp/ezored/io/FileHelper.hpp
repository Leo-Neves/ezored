// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace ezored { namespace io {

class FileHelperPlatformService;

class FileHelper {
public:
    virtual ~FileHelper() {}

    static std::shared_ptr<FileHelper> shared();

    virtual void setPlatformService(const std::shared_ptr<FileHelperPlatformService> & ps) = 0;

    virtual std::shared_ptr<FileHelperPlatformService> getPlatformService() = 0;

    virtual bool hasPlatformService() = 0;

    static bool createFile(const std::string & path);

    static bool createFileWithStringContent(const std::string & path, const std::string & content);

    static bool createFileWithBinaryContent(const std::string & path, const std::vector<uint8_t> & content);

    static bool createDir(const std::string & path);

    static std::vector<std::string> listFiles(const std::string & path);

    static std::string getExtension(const std::string & path);

    static std::string getFilename(const std::string & path);

    static std::string getBasename(const std::string & path);

    static std::string getFilenameFromUrl(const std::string & url);

    static std::string getBasenameFromUrl(const std::string & url);

    static bool removeFile(const std::string & path);

    static bool removeDir(const std::string & path);

    static bool isDir(const std::string & path);

    static bool isFile(const std::string & path);

    static int64_t getFileSize(const std::string & path);

    static bool copyFile(const std::string & from, const std::string & to);

    static bool moveFile(const std::string & from, const std::string & to);

    static std::string join(const std::string & first, const std::string & second);

    static std::string getFileContentAsString(const std::string & path);

    static std::vector<uint8_t> getFileContentAsBinary(const std::string & path);
};

} }  // namespace ezored::io

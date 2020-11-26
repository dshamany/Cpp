#ifndef HTTPREQUESTBUILDER_HPP
#define HTTPREQUESTBUILDER_HPP

#include <string>
#include <map>
#include <utility>

class HttpRequestBuilder
{
public:
    HttpRequestBuilder();
    HttpRequestBuilder(
        const std::string &method_type,
        const std::string &host_name,
        const std::string &path_str,
        const std::string &http_version,
        const std::map<std::string, std::string> &headers,
        const std::string &q,
        const std::map<std::string, std::string> &param_list,
        const std::string &json_str);
    void method(const std::string &method_type);
    std::string method() const;
    void host(const std::string &host_name);
    std::string host() const;
    void path(const std::string &path_str);
    std::string path() const;
    void httpVersion(const std::string &http_version);
    std::string httpVersion() const;
    void headers(const std::map<std::string, std::string> &headers_list);
    std::map<std::string, std::string> headers() const;
    void query(const std::string &q);
    std::string query() const;
    void params(const std::map<std::string, std::string> &param_list);
    std::map<std::string, std::string> params() const;
    void body(const std::string &json_str);
    std::string body() const;

private:
    std::string _method_type;
    std::string _host_name;
    std::string _path_str;
    std::string _http_version;
    std::map<std::string, std::string> _headers_list;
    std::string _query;
    std::map<std::string, std::string> _params;
    std::string _body;
};

#endif //HTTPREQUESTBUILDER_HPP
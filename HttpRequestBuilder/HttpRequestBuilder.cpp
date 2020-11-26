#include "HttpRequestBuilder.hpp"

HttpRequestBuilder::HttpRequestBuilder()
    : _method_type("GET"),
      _host_name(""),
      _path_str("/"),
      _http_version("HTTP/2"),
      _headers_list({}),
      _query(""),
      _params({}),
      _body("{}")

{
}

HttpRequestBuilder::HttpRequestBuilder(
    const std::string &method_type,
    const std::string &host_name,
    const std::string &path_str,
    const std::string &http_version,
    const std::map<std::string, std::string> &headers_list,
    const std::string &q,
    const std::map<std::string, std::string> &param_list,
    const std::string &json_str)
    : _method_type(method_type),
      _host_name(host_name),
      _path_str(path_str),
      _http_version(http_version),
      _headers_list(headers_list),
      _query(q),
      _params(param_list),
      _body(json_str)
{
}

void HttpRequestBuilder::method(const std::string &method_type)
{
    _method_type = method_type;
}

std::string HttpRequestBuilder::method() const
{
    return _method_type;
}

void HttpRequestBuilder::host(const std::string &host_name)
{
    _host_name = host_name;
}

std::string HttpRequestBuilder::host() const
{
    return _host_name;
}

void HttpRequestBuilder::path(const std::string &path_str)
{
    _path_str = path_str;
}

std::string HttpRequestBuilder::path() const
{
    return _path_str;
}

void HttpRequestBuilder::httpVersion(const std::string &http_version)
{
    _http_version = http_version;
}

std::string HttpRequestBuilder::httpVersion() const
{
    return _http_version;
}

void HttpRequestBuilder::headers(
    const std::map<std::string, std::string> &headers_list)
{
    _headers_list = headers_list;
}

std::map<std::string, std::string> HttpRequestBuilder::headers() const
{
    return _headers_list;
}

void HttpRequestBuilder::query(const std::string &q)
{
    _query = "?q=" + q;
}

std::string HttpRequestBuilder::query() const
{
    return _query;
}

void HttpRequestBuilder::params(
    const std::map<std::string, std::string> &param_list)
{
    _params = param_list;
}

std::map<std::string, std::string> HttpRequestBuilder::params() const
{
    return _params;
}

void HttpRequestBuilder::body(const std::string &json_str)
{
    _body = json_str;
}

std::string HttpRequestBuilder::body() const
{
    return _body;
}
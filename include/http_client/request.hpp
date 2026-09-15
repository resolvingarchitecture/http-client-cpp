#pragma once

/// Formats an HTTP/1.1 request line + headers + optional body.

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "http_client/url.hpp"

namespace http_client {

enum class Method { Get, Post, Put, Delete };

inline const char* ToString(Method m) {
    switch (m) {
        case Method::Get: return "GET";
        case Method::Post: return "POST";
        case Method::Put: return "PUT";
        case Method::Delete: return "DELETE";
    }
    return "GET";
}

/// GET carries no body (mirrors `ra.http.HTTPService`: `Request.Builder.get()`
/// never attaches one, even when one was built). POST/PUT/DELETE send `body`
/// with a `Content-Length`.
inline std::vector<std::uint8_t> FormatRequest(Method method, const ParsedUrl& url,
                                                const std::map<std::string, std::string>& headers,
                                                const std::vector<std::uint8_t>& body) {
    const bool has_body = method != Method::Get;

    std::string head = std::string(ToString(method)) + " " + url.path + " HTTP/1.1\r\n";
    head += "Host: " + url.host + "\r\n";
    bool has_user_agent = false;
    for (const auto& [name, value] : headers) {
        head += name + ": " + value + "\r\n";
        if (name == "User-Agent") has_user_agent = true;
    }
    if (!has_user_agent) head += "User-Agent: ra-http-client\r\n";
    head += "Connection: close\r\n";
    if (has_body) head += "Content-Length: " + std::to_string(body.size()) + "\r\n";
    head += "\r\n";

    std::vector<std::uint8_t> out(head.begin(), head.end());
    if (has_body) out.insert(out.end(), body.begin(), body.end());
    return out;
}

}  // namespace http_client

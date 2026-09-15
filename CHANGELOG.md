# Changelog

## 0.1.0

- Initial direct HTTP/HTTPS client: `HttpClient` (`FromConfig`/`Start`/
  `Stop`/`Send`), GET/POST/PUT/DELETE, redirect following, `Content-Length`
  and chunked response bodies, optional SOCKS5 proxy.
- TLS via OpenSSL (`TlsStream`) — SNI, hostname verification, optional
  `trust_all_certs` for test/self-signed servers. No `libcurl` dependency
  (see `DESIGN.md`).
- Depends on `ra-common-cpp` for `Envelope`; uses `ra::common::RaException`
  for errors.
- No connection pooling, no local server/SPA/WebSocket hosting (see
  `DESIGN.md`).

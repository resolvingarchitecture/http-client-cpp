# TODO

- [ ] Connection pooling / keep-alive reuse (see DESIGN.md "No connection
      pooling") — a fresh TCP(+TLS) connection per request/redirect hop is
      simple but costly under real load.
- [ ] A formal blocked-response report type once `ra-common-cpp` gets a
      `NetworkConnectionReport` equivalent (`network.hpp` doesn't have one
      yet) — today, 403/408/410/418/451/511 are only logged to stderr.
- [ ] `tor-client-cpp` could depend on this library's `HttpClient` +
      `proxy_host`/`proxy_port` instead of maintaining its own
      `socks.hpp`/`http.hpp` — not attempted here (out of scope for this
      pass; would need coordinated changes on both repos).
- [ ] Non-absolute, non-root-relative `Location` redirect resolution (e.g.
      `Location: path` relative to the current path's directory, not just
      root).
- [ ] Cookie handling, HTTP/2, `Accept-Encoding`/`Content-Encoding`
      (gzip/br) compression.
- [ ] Local server / SPA / WebSocket hosting, if a future `1m5-core-cpp`
      ever needs the desktop RPC API or Tor hidden-service handling that
      `http-client-java`'s `EnvelopeHandler`/`SPAHandler`/
      `EnvelopeWebSocket`/`EnvelopeJSONDataHandler`/
      `EnvelopeProxyDataHandler` provide there. No other language port has
      needed this yet either.
- [ ] Windows/macOS socket portability (currently POSIX-only, matching the
      rest of this monorepo's C++ ports).
- [ ] Wire an `HttpProtocolService`-equivalent into `1m5-core-cpp` once that
      core exists (mirrors `network.onemfive.core.protocol.
      HttpProtocolService` in `1m5-core-java`) — `1m5-core-cpp` is an empty
      directory today, nothing to wire into.

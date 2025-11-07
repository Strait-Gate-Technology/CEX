# C-Extension (CEX)

## TODO
- Fix or cleanup NUM as a test case for an applied OBJ,
- Consider making COPY a similar macro to FREE which really passes a reference to OBJ's self and calls an internal ->copy() method,
- Once this is done for ->copy() and ->free(), consider string processing cases or move straight to WEB.

Think about...
1. How will WEB work? What will it represent?
2. If it does represent a webhook of sorts, how can or will responses be received? Will they all just return strings?
3. What are sane defaults for this kind of thing? Where, why and how would I find it useful to host webhooks in C?

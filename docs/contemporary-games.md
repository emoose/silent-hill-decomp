## Contemporaries
Konami games from the same timeframe may share code or symbols with SH, could be worth digging through prototypes/alternate releases:
-  **Tokimeki Memorial \~forever with you\~**: has partial debug symbols which unfortunately don't match its executable, making any comparisons a bit harder.
-  **beatmania APPEND 5thMIX**: partial source available, uses similar movie player code but doesn't appear to share much else, contains a Konami `SD` sound library that's completely different to the one used in SH.
-  **Pachinko Dream**: source available, doesn't appear to share much (if anything) with SH, but seems to employ similar "SYS_W" structures holding things like current game state index.
-  **International Track & Field** / **ITF2000**: SH contains unused graphics from it & seems to share very similar overlay/data handling code, likely has more in common too.
-  **Konami International Rally Racing**: unreleased game that contains MAP/SYM symbols, shares the same `SD` sound library as SH (albeit a slightly different version)
-  **ESPN International Track & Field (PS2)**: sequel of ITF2000 with debug symbols available, seems to mostly be a C++ codebase, maybe a rewrite, or a completely different engine.
-  **Silent Hill 2 (PS2)**: the sequel, prototypes are available with debug symbols but doesn't appear to share much in common with SH1, though shared dev team members could mean similar code conventions within.

(there are many other Konami games that could share code too - they released a *lot* during the PSX/PS2 era - any Konami prototype releases may be useful to look through!)
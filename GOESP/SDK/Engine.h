#pragma once

#include "Utils.h"

#include <tuple>

struct PlayerInfo {
    __int64 pad;
    union {
        __int64 steamID64;
        __int32 xuidLow;
        __int32 xuidHigh;
    };
    char name[128];
    int userId;
    char steamIdString[20];
    char pad1[16];
    unsigned long steamId;
    char friendsName[128];
    bool fakeplayer;
    bool ishltv;
    unsigned int customfiles[4];
    unsigned char filesdownloaded;
};

class Engine {
public:
    constexpr auto getScreenSize() noexcept
    {
        int w = 0, h = 0;
        callVirtualMethod<void, int&, int&>(this, 5, w, h);
        return std::make_pair(w, h);
    }

    constexpr auto getLocalPlayer() noexcept
    {
        return callVirtualMethod<int>(this, 12);
    }

    constexpr auto getMaxClients() noexcept
    {
        return callVirtualMethod<int>(this, 20);
    }

    constexpr auto isInGame() noexcept
    {
        return callVirtualMethod<bool>(this, 26);
    }
};
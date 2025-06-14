#pragma once

#include <string>
#include <cstring>

// Global login state
inline std::string slotZ = "X-001";
inline std::string inVip = "100";
inline std::string autoskillsZ = "off";
inline std::string expired = "Unlimited";
inline std::string battleData = "false";
inline std::string clientManager = "XCODE Local";

inline std::string g_Token = "local_token";
inline std::string g_Auth = "local_auth";
inline bool bValid = true;
inline bool bInitDone = false;

namespace SignIN {
    inline bool user = false;
}

inline std::string Login(void* jvm, const char* user_key, bool* success) {
    if (strcmp(user_key, "xcodevip") == 0) {
        if (success) *success = true;

        // Aktifkan semua state mod
        battleData = "true";
        slotZ = "X-001";
        inVip = "100";
        expired = "Never";
        clientManager = "XCODE Offline";

        g_Token = "local_token";
        g_Auth = "local_auth";
        bValid = true;

        return "Login success (offline mode)";
    } else {
        if (success) *success = false;
        battleData = "false";
        return "Invalid key (use xcodevip)";
    }
}

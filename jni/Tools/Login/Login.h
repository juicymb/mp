#pragma once
#include "curl/curl.h"
#include "Tools.h"
#include "json.hpp"

using json = nlohmann::ordered_json;

std::string title, version;
std::string UUID;

static std::string slotZ = "";
static std::string inVip = "";
static std::string autoskillsZ = "";
static std::string expired = "";
static std::string EXP = "LOGIN FIRST";
static std::string name ="";
static std::string device = "";
static std::string status = "";
static std::string floating ="";
static std::string battleData = "";
static std::string clientManager = "";

std::string g_Token, g_Auth;
bool bValid = false;

bool bInitDone;

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

        pthread_t t;

        return "Login success (offline mode)";
    } else {
        if (success) *success = false;
        battleData = "false";
        return "Invalid key (use xcodevip)";
    }
}

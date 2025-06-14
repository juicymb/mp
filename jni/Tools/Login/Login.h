#pragma once
#include <string>

inline std::string slotZ = "0";
inline std::string inVip = "0"; 
inline std::string autoskillsZ = ""; 
inline std::string expired = "N/A"; 
inline std::string battleData = "true"; 
inline std::string clientManager = "XCode Local";

inline std::string g_Token = "", g_Auth = "";

inline std::string Login(void* jvm, const char* user_key, bool* success) {
    if (success) *success = true; // Always allow if local key matches
    return "Login success (offline mode)";
}


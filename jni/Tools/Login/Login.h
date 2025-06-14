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
static std::string EXP = "1212";
static std::string name ="";
static std::string device = "";
static std::string status = "";
static std::string floating ="";
static std::string battleData = "true";
static std::string clientManager = "";

std::string g_Token, g_Auth;
bool bValid = false;

bool bInitDone;

namespace SignIN
{
    static bool user;
}

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;
    mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

std::string Login(void* jvm, const char* user_key, bool* success) {
    battleData = "true";
    pthread_t t;
    if (success) *success = true; // Always allow if local key matches
    return "Login success (offline mode)";
}


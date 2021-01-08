#define CURL_STATICLIB
#include "curl.h"

#include "curl/curl.h"

#ifdef _DEBUG
#pragma comment (lib, "curl/libcurl_a_debug.lib")
#else
#pragma comment (lib, "curl/libcurl_a.lib")
#endif

#pragma comment (lib, "Normaliz.lib")
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Wldap32.lib")
#pragma comment (lib, "Crypt32.lib")
#pragma comment (lib, "advapi32.lib")

Curl* Curl::m_pInstance;

std::string Curl::curl_request(const char* request_url)
{
	std::string result;
	CURL* curl;
	CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (!curl)
        return "ERROR: Request failed.";

    curl_easy_setopt(curl, CURLOPT_URL, request_url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (CURLE_OK != res)
    {
        // TODO error handling / exceptions
    }

    curl_global_cleanup();
    return result;
}

size_t Curl::write(void* buffer, size_t size, size_t nmemb, void* param)
{
	std::string& text = *static_cast<std::string*>(param);
	size_t total_size = size * nmemb;
	text.append(static_cast<char*>(buffer), total_size);
	return total_size;
}

Curl* Curl::GetInstance()
{
    if (!m_pInstance)
        m_pInstance = new Curl();

    return m_pInstance;
}

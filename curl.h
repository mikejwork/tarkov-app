#pragma once
#include <string>

class Curl
{
public:
	std::string curl_request(const char* request_url);

	static Curl* GetInstance();
private:
	static size_t write(void* buffer, size_t size, size_t nmemb, void* param);

	static Curl* m_pInstance;
};
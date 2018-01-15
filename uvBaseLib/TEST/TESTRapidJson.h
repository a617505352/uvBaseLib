#ifndef _TEST_RAPIDJSON_H_
#define _TEST_RAPIDJSON_H_

/**
* ©¥©¥©¥©¥©¥ÉñÊÞ³öÃ»©¥©¥©¥©¥©¥©¥
*¡¡¡¡¡¡¡¡©³©·¡¡    ©³©·
*¡¡¡¡¡¡©³©¿©ß©¥©¥©¥©¿©ß©·
*¡¡¡¡¡¡©§¡¡¡¡¡¡¡¡¡¡¡¡  ©§ ¡¡
*¡¡¡¡¡¡©§      ©¥¡¡¡¡  ©§
*¡¡¡¡¡¡¨€¨€¨€¨€©¥¨€¨€¨€¨€
*¡¡¡¡¡¡©§¡¡¡¡¡¡¡¡¡¡¡¡¡¡©§
*¡¡¡¡¡¡©§¡¡¡¡¡¡©ß¡¡¡¡¡¡©§
*¡¡¡¡¡¡©§¡¡¡¡¡¡¡¡	   ©§
*¡¡¡¡¡¡©»©¥©·¡¡¡¡¡¡©³©¥©¿
*¡¡¡¡¡¡¡¡¡¡©§¡¡¡¡¡¡©§¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡
*¡¡¡¡¡¡¡¡¡¡©§¡¡¡¡¡¡©§¡¡¡¡
*¡¡¡¡¡¡¡¡¡¡©§¡¡¡¡¡¡©§
*¡¡¡¡¡¡¡¡¡¡©§¡¡¡¡¡¡©§¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡
*¡¡¡¡¡¡¡¡¡¡©§¡¡ ¡¡ ©»©¥©¥©¥©·
*¡¡¡¡¡¡¡¡¡¡©§ ¡¡¡¡¡¡¡¡     ©Ç©·
*¡¡¡¡¡¡¡¡¡¡©§ ¡¡¡¡¡¡¡¡¡¡   ©³©¿
*¡¡¡¡¡¡¡¡¡¡©»©·©·©³©¥©×©·©³©¿
*¡¡¡¡¡¡¡¡¡¡¡¡©§©Ï©Ï  ©§©Ï©Ï
*¡¡¡¡¡¡¡¡¡¡¡¡©»©ß©¿  ©»©ß©¿
*
* Create by chen, 2018/1/11
**/

#include "rapidjson/document.h"

class CTestRapidJson
{
public:
	CTestRapidJson();
	~CTestRapidJson();

public:
	void NewJson(char* path);
	void ParseJsonFromFile(char* path);
	void ParseJsonFromMem(char* path);

private:
	void parsedoc(rapidjson::Document& doc);

private:
	char*	m_reader_buf;
	int		m_reader_buf_size;
};

#endif

#include <sstream>
#include <iostream>
#include <fstream>
#include "rapidjson/writer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/ostreamwrapper.h"
#include "rapidjson/document.h"
#include "TESTRapidJson.h"

#define logPrint(x) std::cout << #x " = " << (x) << std::endl

using namespace rapidjson;

CTestRapidJson::CTestRapidJson()
{
	m_reader_buf = NULL;
	m_reader_buf_size = 0;
}

CTestRapidJson::~CTestRapidJson()
{
	if (m_reader_buf){
		free(m_reader_buf);
	}
}

void CTestRapidJson::NewJson(char* path)
{
	Document doc;
	doc.SetObject();
	Document::AllocatorType& allocator = doc.GetAllocator();

	doc.AddMember("name", "rapidjson", allocator);
	doc.AddMember("version", "1.0.1", allocator);
	doc.AddMember("numbers", "1.12", allocator);
	doc.AddMember("Major", 100, allocator);
	doc.AddMember("description", "![](doc/logo/rapidjson.png)", allocator);
	doc.AddMember("main", "include_dirs.js", allocator);

	Value directories(kObjectType);
	directories.AddMember("doc", "doc", allocator);
	directories.AddMember("example", "example", allocator);
	directories.AddMember("test", "test", allocator);
	directories.AddMember("value", 99, allocator);
	directories.AddMember("decimal", 0.15346, allocator);
	doc.AddMember("directories", directories, allocator);

	Value scripts(kObjectType);
	scripts.AddMember("test", "echo \"Error: no test specified\" && exit 1", allocator);
	doc.AddMember("scripts", scripts, allocator);

	Value repository(kObjectType);
	repository.AddMember("type", "git", allocator);
	repository.AddMember("url", "git+https://github.com/Tencent/rapidjson.git", allocator);
	doc.AddMember("repository", repository, allocator);

	doc.AddMember("author", "", allocator);
	doc.AddMember("license", "ISC", allocator);

	Value bugs(kObjectType);
	bugs.AddMember("url", "https://github.com/Tencent/rapidjson/issues", allocator);
	doc.AddMember("bugs", bugs, allocator);

	doc.AddMember("homepage", "https://github.com/Tencent/rapidjson#readme", allocator);

	Value sites(kArrayType);
	{
		Value o(kObjectType);
		o.AddMember("name", "Google", allocator);
		Value a(kArrayType);
		{
			Value a1("Android");
			Value a2("Google search");
			Value a3("Google translate");
			a.PushBack(a1, allocator);
			a.PushBack(a2, allocator);
			a.PushBack(a3, allocator);
		}
		o.AddMember("info", a, allocator);
		sites.PushBack(o, allocator);
	}
	{
		Value o(kObjectType);
		o.AddMember("name", "Runoob", allocator);
		Value a(kArrayType);
		{
			Value a1("菜鸟教程");
			Value a2("菜鸟工具");
			Value a3("菜鸟微信");
			a.PushBack(a1, allocator);
			a.PushBack(a2, allocator);
			a.PushBack(a3, allocator);
		}
		o.AddMember("info", a, allocator);
		sites.PushBack(o, allocator);
	}
	{
		Value o(kObjectType);
		o.AddMember("name", "subject", allocator);
		Value a(kArrayType);
		{
			Value a1(96);
			Value a2(98.5);
			Value a3(100);
			a.PushBack(a1, allocator);
			a.PushBack(a2, allocator);
			a.PushBack(a3, allocator);
		}
		o.AddMember("info", a, allocator);
		sites.PushBack(o, allocator);
	}
	doc.AddMember("sites", sites, allocator);

	StringBuffer buffer;
	PrettyWriter<StringBuffer> writer(buffer);	// easily readable by human
	//Writer<StringBuffer> writer(buffer);		// without white-spaces,suitable for network transfer or storage
	doc.Accept(writer);
	std::cout << buffer.GetString() << std::endl;

	//write in file
	FILE* out = fopen(path, "wb+");
	std::string s = buffer.GetString();
	fwrite(s.c_str(), 1, buffer.GetLength(), out);
	fflush(out);
	fclose(out);
}

void CTestRapidJson::ParseJsonFromFile(char* path)
{
	// file opration, get file length 
	FILE* in = fopen(path, "rb");
	fseek(in, 0, SEEK_END);
	int length = ftell(in);
	if (length > m_reader_buf_size){
		m_reader_buf = (char*)realloc(m_reader_buf, length);
		m_reader_buf_size = length;
	}
	fseek(in, 0, SEEK_SET);
	logPrint(length);

	//parse json from file
	FileReadStream is(in, m_reader_buf, m_reader_buf_size);
	Document doc;
	doc.ParseStream(is);
	if (doc.HasParseError()){
		rapidjson::ParseErrorCode errcode = doc.GetParseError();
		logPrint(errcode);
	}

	parsedoc(doc);
	fclose(in);
}

void CTestRapidJson::ParseJsonFromMem(char* path)
{
	// file opration, get file length 
	FILE* in = fopen(path, "rb");
	fseek(in, 0, SEEK_END);
	int length = ftell(in);
	if (length > m_reader_buf_size){
		m_reader_buf = (char*)realloc(m_reader_buf, length);
		m_reader_buf_size = length;
	}
	fseek(in, 0, SEEK_SET);
	logPrint(length);

	int reader = 0;
	while (length){
		int len = fread(m_reader_buf + reader, 1, length, in);
		reader += len;
		length -= len;
	}
	fclose(in);

	Document doc;
	doc.Parse(m_reader_buf);

	parsedoc(doc);
}

void CTestRapidJson::parsedoc(rapidjson::Document& doc)
{
	if (doc.HasMember("name") && doc["name"].IsString()){
		std::string name = doc["name"].GetString();
		logPrint(name);
	}

	if (doc.HasMember("version")){
		std::string version = doc["version"].GetString();
		logPrint(version);
	}

	if (doc.HasMember("numbers")){
		std::string numbers = doc["numbers"].GetString();
		logPrint(numbers);
	}

	if (doc.HasMember("Major")){
		int Major = doc["Major"].GetInt();
		logPrint(Major);
	}

	if (doc.HasMember("pi")){
		double pi = doc["pi"].GetDouble();
		logPrint(pi);
	}

	std::string description = doc["description"].GetString();
	logPrint(description);

	std::string main = doc["main"].GetString();
	logPrint(main);

	std::string author = doc["author"].GetString();
	logPrint(author);

	std::string license = doc["license"].GetString();
	logPrint(license);

	std::string homepage = doc["homepage"].GetString();
	logPrint(homepage);

	const Value& obj = doc["directories"].GetObject();
	if (obj.IsObject()){
		std::string doc = obj["doc"].GetString();
		std::string example = obj["example"].GetString();
		std::string test = obj["test"].GetString();
		int value = obj["value"].GetInt();
		double decimal = obj["decimal"].GetDouble();
		printf("doc:%s,example:%s,test:%s,value:%d,decimal:%f\n",
			doc.c_str(), example.c_str(), test.c_str(), value, decimal);
	} else {
		printf("not object.\n");
	}

	const Value& scripts = doc["scripts"].GetObject();
	if (scripts.IsObject()){
		std::string test = scripts["test"].GetString();
		logPrint(test);
	}

	const Value& repository = doc["repository"].GetObject();
	if (repository.IsObject()){
		std::string type = repository["type"].GetString();
		std::string url = repository["url"].GetString();
		logPrint(type);
		logPrint(url);
	}

	if (doc["bugs"].IsObject()){
		std::string bug_url = (doc["bugs"].GetObject())["url"].GetString();
		logPrint(bug_url);
	}

	if (doc["sites"].IsArray()){
		Value google = doc["sites"][0].GetObject();
		{
			std::string name = google["name"].GetString();
			Value info = google["info"].GetArray();
			{
				std::string s1 = info[0].GetString();
				std::string s2 = info[1].GetString();
				std::string s3 = info[2].GetString();
				printf("s1:%s,s2:%s,s3:%s.\n", s1.c_str(), s2.c_str(), s3.c_str());
			}
			logPrint(name);
		}

		Value Runoob = doc["sites"][1].GetObject();
		{
			std::string name = Runoob["name"].GetString();
			Value info = Runoob["info"].GetArray();
			{
				std::string s1 = info[0].GetString();
				std::string s2 = info[1].GetString();
				std::string s3 = info[2].GetString();
				printf("s1:%s,s2:%s,s3:%s.\n", s1.c_str(), s2.c_str(), s3.c_str());
			}
			logPrint(name);
		}

		Value subject = doc["sites"][2].GetObject();
		{
			std::string name = subject["name"].GetString();
			Value info = subject["info"].GetArray();
			{
				double s1 = info[0].GetDouble();
				double s2 = info[1].GetDouble();
				double s3 = info[2].GetDouble();
				printf("s1:%f,s2:%f,s3:%f.\n", s1, s2, s3);
			}
			logPrint(name);
		}
	} else {
		printf("not array.\n");
	}
}

/////////////////////////////////////////////////////////////////

#include "Configure.h"

#ifdef TEST_RAPIDJSON

int main()
{
	CTestRapidJson* json = new CTestRapidJson;
	json->NewJson("new.json");
	json->ParseJsonFromMem("new.json");
	json->ParseJsonFromFile("new.json");
	system("pause");
	return 0;
}

#endif

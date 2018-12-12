#include <sstream>
#include <iostream>
#include "rapidxml.hpp"  
#include "rapidxml_utils.hpp"  
#include "rapidxml_print.hpp" 

#include "TESTRapidXml.h"

using namespace rapidxml;

#define PARSE_XML_NODE_VALUE( title, var )								\
	node = root->first_node(title);										\
	if (NULL == node)													\
	{																	\
		printf("failed to load %s, so set default value.\n", title);	\
	}																	\
	else																\
	{																	\
		node_value = node->value();										\
		if(node_value == NULL)											\
		{																\
			printf("node value null, so set default value.\n", title);	\
		}																\
		else															\
		{																\
			sstr.clear(), sstr << node_value, sstr >> var;				\
		}																\
	}																	\

CTestRapidXml::CTestRapidXml()
{

}

CTestRapidXml::~CTestRapidXml()
{

}

void CTestRapidXml::ParseXml(char* path)
{
	file<> fdoc(path);
	xml_document<> doc;
	doc.parse<0>(fdoc.data());

	char* node_value = NULL;
	char errHead[] = "Failed to load config file, %s info error.\n";
	std::stringstream sstr;

	// 获取根节点  
	xml_node<>* root = doc.first_node();
	printf("root name:%s.\n", root->name());
 
	xml_node<>* node = NULL;
	node = root->first_node("ServerId");
	printf("node name:%s, value:%d.\n", node->name(), atoi(node->value()));

	std::string cms_addr;
	PARSE_XML_NODE_VALUE("Listen", cms_addr);
	printf("CMS listen addr:%s\n", cms_addr.c_str());

	int expires;
	PARSE_XML_NODE_VALUE("HeartBeat", expires);
	printf("heartbeat:%d\n", expires);

	int begin_port, end_port;
	xml_attribute<>* attribute = NULL;
	node = root->first_node("TESTPortRange");
	if (node != NULL){
		attribute = node->first_attribute("begin");
		if (attribute != NULL){
			begin_port = atoi(attribute->value());
		}
		attribute = node->first_attribute("end");
		if (attribute != NULL){
			end_port = atoi(attribute->value());
		}
	}
	printf("port range, begin:%d, end:%d\n", begin_port, end_port);

	int send_buf_size;
	PARSE_XML_NODE_VALUE("SendSocketBufSize", send_buf_size);
	printf("SendSocketBufSize:%d\n", send_buf_size);

	int recv_buf_size;
	PARSE_XML_NODE_VALUE("RecvSocketBufSize", recv_buf_size);
	printf("RecvSocketBufSize:%d\n", recv_buf_size);

	int enable, level;
	std::string log_path;
	node = root->first_node("LogInfo");
	if (node != NULL){
		attribute = node->first_attribute("enable");
		if (attribute != NULL){
			enable = atoi(attribute->value());
		}
		attribute = node->first_attribute("level");
		if (attribute != NULL){
			level = atoi(attribute->value());
		}
		attribute = node->first_attribute("filename");
		if (attribute != NULL){
			log_path = attribute->value();
		}
	}
	printf("log enable:%d, level:%d, log path:%s\n", enable, level, log_path.c_str());

	int limits;
	PARSE_XML_NODE_VALUE("Limits", limits);
	printf("Limits:%d\n", limits);

	std::string devide_type;
	std::string devide_name;
	node = root->first_node("TestInfomation");
	if (node != NULL){
		xml_node<>* sec_node = NULL;
		sec_node = node->first_node("DeviceType");
		if (sec_node != NULL){
			devide_type = sec_node->value();
		}
		sec_node = node->first_node("DeviceName");
		if (sec_node != NULL){
			devide_name = sec_node->value();
		}
	}
	printf("device type:%s, device name:%s\n", devide_type.c_str(), devide_name.c_str());

	std::string display_mode;
	std::string screen_type;
	node = root->first_node("DisplayMode");
	if (node != NULL){
		display_mode = node->value();

		attribute = node->first_attribute("fullscreen");
		screen_type = attribute->value();
	}
	printf("display mode:%s, screen mode:%s\n", display_mode.c_str(), screen_type.c_str());
}

void CTestRapidXml::NewXml(char* path)
{
	xml_document<> doc;
	xml_node<>* root = doc.allocate_node(rapidxml::node_pi, doc.allocate_string("xml version='1.0' encoding='utf-8'"));
	doc.append_node(root);

	xml_node<>* config  = doc.allocate_node(node_element, "config", "information");
	doc.append_node(config);

	xml_node<>* node = doc.allocate_node(node_element, "ServerId", "1001");
	config->append_node(node);

	node = doc.allocate_node(node_element, "Listen", "0.0.0.0:8088");
	config->append_node(node);

	node = doc.allocate_node(node_element, "HeartBeat", "60");
	config->append_node(node);

	node = doc.allocate_node(node_element, "TESTPortRange", NULL);
	node->append_attribute(doc.allocate_attribute("begin", "10000"));
	node->append_attribute(doc.allocate_attribute("end", "30000"));
	config->append_node(node);

	node = doc.allocate_node(node_element, "SendSocketBufSize", "256");
	config->append_node(node);

	node = doc.allocate_node(node_element, "RecvSocketBufSize", "256");
	config->append_node(node);

	node = doc.allocate_node(node_element, "LogInfo", NULL);
	node->append_attribute(doc.allocate_attribute("enable", "1"));
	node->append_attribute(doc.allocate_attribute("level", "1"));
	node->append_attribute(doc.allocate_attribute("filename", "./log/cms.log"));
	config->append_node(node);

	node = doc.allocate_node(node_element, "Limits", "8");
	config->append_node(node);

	node = doc.allocate_node(node_element, "TestInfomation", "information");
	node->append_node(doc.allocate_node(node_element, "DeviceType", "M1"));
	node->append_node(doc.allocate_node(node_element, "DeviceName", "0B603C"));
	config->append_node(node);

	node = doc.allocate_node(node_element, "DisplayMode", "screen mode");
	node->append_attribute(doc.allocate_attribute("fullscreen", "false"));
	config->append_node(node);

	std::ofstream out(path);
	out << doc;
}

////////////////////////////////////////////////////////////////////////

#include "Configure.h"

#ifdef TEST_RAPIDXML

int main()
{
	CTestRapidXml* rapidxml = new CTestRapidXml;
	rapidxml->NewXml("CMS.xml");
	rapidxml->ParseXml("CMS.xml");
	delete rapidxml;

	system("pause");
	return 0;
}

#endif

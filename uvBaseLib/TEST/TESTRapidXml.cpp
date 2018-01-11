#include <sstream>
#include "rapidxml.hpp"  
#include "rapidxml_utils.hpp"  
#include "rapidxml_print.hpp" 

#include "TESTRapidXml.h"

using namespace rapidxml;

#define PARSE_XML_NODE_VALUE( title, var )								\
	node = root->first_node(title);										\
	node_value = node->value();											\
	if (NULL == node || node_value == NULL)								\
	{																	\
		printf("failed to load %s, so set default value.\n", title);	\
	}																	\
	else																\
	{																	\
		sstr.clear(), sstr << node_value, sstr >> var;					\
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
	PARSE_XML_NODE_VALUE("BLS", cms_addr);
	printf("BLS listen addr:%s\n", cms_addr.c_str());

	int expires;
	PARSE_XML_NODE_VALUE("Expires", expires);
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
}

void CTestRapidXml::NewXml(char* path)
{

}

////////////////////////////////////////////////////////////////////////

#include "Configure.h"

#ifdef TEST_RAPIDXML

int main()
{
	CTestRapidXml* rapidxml = new CTestRapidXml;
	rapidxml->ParseXml("TCS.xml");
	rapidxml->NewXml("CMS.xml");
	delete rapidxml;

	system("pause");
	return 0;
}

#endif

#include <iostream>
#include"tinyxml2.h"

using namespace std;
using namespace tinyxml2;

void createXml()
{
	//------------
	//声明要创建的xml文件
	//------------
	tinyxml2::XMLDocument xml;
	tinyxml2::XMLDeclaration* declaration = xml.NewDeclaration();
	xml.InsertFirstChild(declaration);

	//------------
	//创建根节点
	//------------
	tinyxml2::XMLElement* rootNode = xml.NewElement("computer");
	xml.InsertEndChild(rootNode);

	//------------
	//创建子节点
	//------------
	tinyxml2::XMLElement* root_1_NodeComputerMonitor = xml.NewElement("ComputerMonitor");
	tinyxml2::XMLElement* root_1_NodeKeyboard = xml.NewElement("Keyboard");
	tinyxml2::XMLElement* root_1_CPU = xml.NewElement("CPU");

	//------------
	//给子节点增加内容
	//------------
	tinyxml2::XMLText* text_root_1_NodeComputerMonitor = xml.NewText("SAMSUNG");
	root_1_NodeComputerMonitor->InsertFirstChild(text_root_1_NodeComputerMonitor);

	tinyxml2::XMLText* text_root_1_root_1_CPU = xml.NewText("intel");
	root_1_CPU->InsertFirstChild(text_root_1_root_1_CPU);

	//------------
	//给子节点增加内容
	//------------
	root_1_NodeComputerMonitor->SetAttribute("size", "15");
	root_1_CPU->SetAttribute("series", "XEON");

	//------------
	//创建子节点的子节点
	//------------
	tinyxml2::XMLElement* root_2_NodeKeyboardAttribute = xml.NewElement("KeyboardAttribute");
	
	//------------
	//给子节点的子节点增加内容
	//------------
	tinyxml2::XMLText* text_root_2_NodeKeyboardAttribute = xml.NewText("cherry Mechanical Keyboard");
	root_2_NodeKeyboardAttribute->InsertFirstChild(text_root_2_NodeKeyboardAttribute);

	//------------
	//构建xml树，根节点的下的子节点树
	//------------
	rootNode->InsertEndChild(root_1_NodeComputerMonitor);//childNodeStu是root的子节点
	rootNode->InsertEndChild(root_1_NodeKeyboard);
	rootNode->InsertEndChild(root_1_CPU);
	//------------
	//构建xml树，根节点的下的子节点的子节点树
	//------------
	root_1_NodeKeyboard->InsertEndChild(root_2_NodeKeyboardAttribute);

	//------------
	//将xml保存到当前项目中
	//------------
	xml.SaveFile("computer.xml");
}
 
void deCodeXml()
{
	//------------
	//声明
	//------------
	tinyxml2::XMLDocument xml;

	//------------
	//导入xml文件
	//------------
	if (xml.LoadFile("computer.xml") != XML_SUCCESS)
	{
		return;
	}

	//------------
	//找到导入的xml的根节点
	//------------
	tinyxml2::XMLElement* rootNode = xml.RootElement();
	if (rootNode == NULL) {
		return;
	}

	//------------
	//读取第一层子节点信息并且打印在控制台上
	//------------
	tinyxml2::XMLElement* root_1_NodeComputerMonitor = rootNode->FirstChildElement("ComputerMonitor");
	std::string text_root_1_NodeComputerMonitor = root_1_NodeComputerMonitor->GetText();
	cout << "text_root_1_NodeComputerMonitor = " << text_root_1_NodeComputerMonitor.c_str()<<endl;

	//------------
	//读取第二层子节点信息并且打印在控制台上
	//------------
	tinyxml2::XMLElement* root_1_NodeKeyboard = rootNode->FirstChildElement("Keyboard");
	tinyxml2::XMLElement* root_2_NodeKeyboardAttribute = root_1_NodeKeyboard->FirstChildElement("KeyboardAttribute");
	std::string text_root_2_NodeKeyboardAttribute = root_2_NodeKeyboardAttribute->GetText();
	cout << "text_root_2_NodeKeyboardAttribute = " << text_root_2_NodeKeyboardAttribute.c_str() << endl;
}
int main()
{
	cout << "----------------------begin create xml-----------------------" << endl;
	createXml();
	cout << "----------------------finished create xml--------------------" << endl;



	cout << "-----------------------begin read xml------------------------" << endl;
	deCodeXml();
	cout << "-----------------------finished read xml---------------------" << endl;
    return 0;
}
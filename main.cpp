#include <iostream>
#include"tinyxml2.h"

using namespace std;
using namespace tinyxml2;

void createXml()
{
	//------------
	//����Ҫ������xml�ļ�
	//------------
	tinyxml2::XMLDocument xml;
	tinyxml2::XMLDeclaration* declaration = xml.NewDeclaration();
	xml.InsertFirstChild(declaration);

	//------------
	//�������ڵ�
	//------------
	tinyxml2::XMLElement* rootNode = xml.NewElement("computer");
	xml.InsertEndChild(rootNode);

	//------------
	//�����ӽڵ�
	//------------
	tinyxml2::XMLElement* root_1_NodeComputerMonitor = xml.NewElement("ComputerMonitor");
	tinyxml2::XMLElement* root_1_NodeKeyboard = xml.NewElement("Keyboard");
	tinyxml2::XMLElement* root_1_CPU = xml.NewElement("CPU");

	//------------
	//���ӽڵ���������
	//------------
	tinyxml2::XMLText* text_root_1_NodeComputerMonitor = xml.NewText("SAMSUNG");
	root_1_NodeComputerMonitor->InsertFirstChild(text_root_1_NodeComputerMonitor);

	tinyxml2::XMLText* text_root_1_root_1_CPU = xml.NewText("intel");
	root_1_CPU->InsertFirstChild(text_root_1_root_1_CPU);

	//------------
	//���ӽڵ���������
	//------------
	root_1_NodeComputerMonitor->SetAttribute("size", "15");
	root_1_CPU->SetAttribute("series", "XEON");

	//------------
	//�����ӽڵ���ӽڵ�
	//------------
	tinyxml2::XMLElement* root_2_NodeKeyboardAttribute = xml.NewElement("KeyboardAttribute");
	
	//------------
	//���ӽڵ���ӽڵ���������
	//------------
	tinyxml2::XMLText* text_root_2_NodeKeyboardAttribute = xml.NewText("cherry Mechanical Keyboard");
	root_2_NodeKeyboardAttribute->InsertFirstChild(text_root_2_NodeKeyboardAttribute);

	//------------
	//����xml�������ڵ���µ��ӽڵ���
	//------------
	rootNode->InsertEndChild(root_1_NodeComputerMonitor);//childNodeStu��root���ӽڵ�
	rootNode->InsertEndChild(root_1_NodeKeyboard);
	rootNode->InsertEndChild(root_1_CPU);
	//------------
	//����xml�������ڵ���µ��ӽڵ���ӽڵ���
	//------------
	root_1_NodeKeyboard->InsertEndChild(root_2_NodeKeyboardAttribute);

	//------------
	//��xml���浽��ǰ��Ŀ��
	//------------
	xml.SaveFile("computer.xml");
}
 
void deCodeXml()
{
	//------------
	//����
	//------------
	tinyxml2::XMLDocument xml;

	//------------
	//����xml�ļ�
	//------------
	if (xml.LoadFile("computer.xml") != XML_SUCCESS)
	{
		return;
	}

	//------------
	//�ҵ������xml�ĸ��ڵ�
	//------------
	tinyxml2::XMLElement* rootNode = xml.RootElement();
	if (rootNode == NULL) {
		return;
	}

	//------------
	//��ȡ��һ���ӽڵ���Ϣ���Ҵ�ӡ�ڿ���̨��
	//------------
	tinyxml2::XMLElement* root_1_NodeComputerMonitor = rootNode->FirstChildElement("ComputerMonitor");
	std::string text_root_1_NodeComputerMonitor = root_1_NodeComputerMonitor->GetText();
	cout << "text_root_1_NodeComputerMonitor = " << text_root_1_NodeComputerMonitor.c_str()<<endl;

	//------------
	//��ȡ�ڶ����ӽڵ���Ϣ���Ҵ�ӡ�ڿ���̨��
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
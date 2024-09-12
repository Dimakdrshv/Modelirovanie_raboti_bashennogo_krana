#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <string>
#include <vector>
#include <map>

#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(&signal_f)
#define HANDLER_D(handler_f)(TYPE_HANDLER)(&handler_f)

class cl_base;

typedef void (cl_base::* TYPE_SIGNAL) (std::string& msg);
typedef void (cl_base::* TYPE_HANDLER) (std::string msg);

struct o_sh { // ��������� ������� ����� �����
	TYPE_SIGNAL p_signal; // ��������� �� ����� �������
	cl_base* p_target; // ��������� �� ������� ������
	TYPE_HANDLER p_handler; // ��������� �� ����� �����������
};

class cl_base {


	std::string s_name; //��� �������
	cl_base* p_head_object; //�������� ������
	std::vector<cl_base*> p_sub_objects; //����������� �������

	std::vector<o_sh*> connects; //�������� ���������� ����� �������� � ������������
	int readiness = 0; //���������� �������

public:

	//----------------------------------------------------------��-5--------------------------------------------------------------//
	
	std::map<int, std::vector<std::string>> cargoes;
	int tick = 0;

	int length_house, width_house;
	std::map<int, std::vector<std::string>> house_area;
	std::vector<int> left_house_part;
	std::vector<int> right_house_part;
	std::vector<int> center_house_part;

	std::string cargo_in_hook;

	void turn_on_objects();

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	int object_class = 0;
	//
	std::string Absolute_Way();
	void set_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER p_handler);
	void delete_connection(TYPE_SIGNAL p_signal, cl_base* p_target, TYPE_HANDLER p_handler);
	void emit_signal(TYPE_SIGNAL p_signal, std::string s_message);

	cl_base* get_root(); //����� ��������� ������� ������

	//------------------------------------------------//
	//����� ��������������� ��������� ������� ��� 
	//�������� � ������ ��������
	//------------------------------------------------//
	bool Change_Head(cl_base* p_head);

	//------------------------------------------------//
	//����� �������� ������������ ������� �� ������������
	//------------------------------------------------//
	void Delete_Object(std::string s_name);

	//------------------------------------------------//
	//����� ��������� ��������� �� ����� ������ � �������
	//������ �������� �������� �������� ���� (����������)
	//------------------------------------------------//
	cl_base* find_object_by_coordinate(std::string s_coordinate);

	//------------------------------------------------//
	//��������������� ����� ������ �������
	//� �������� ������, ������� � �������� �������
	//------------------------------------------------//
	cl_base* find_object_from_current(std::string);

	//------------------------------------------//
	//��������������� ����� ������ �������
	//� �������� ������, ������� � ����� ������
	//-----------------------------------------//
	cl_base* find_object_from_root(std::string s_name);
	void Print_Tree(); //����� ������ �������� �������� (������ ��� �����) �� �������� �������
	//-----------------------------------//
	//����� ������
	//������ �������� � ����������
	//��������� (is_ready, is_not_ready)
	//-----------------------------------//
	void Print_Readiness();
	//----------------------------------//
	//����� �������� �������� � 
	//�������� ������ � ������ ��������
	//---------------------------------//
	void Set_Readiness(int state = 0); //����� ��������� ���������� ������� 

	cl_base(cl_base* p_head, std::string s_name = "Base Object"); //����������� ������
	~cl_base(); //���������� ������
	bool set_name(std::string s_new_name); //��������� ����� �������
	std::string get_name(); //��������� ����� �������
	cl_base* get_head(); //��������� ��������� �������
	cl_base* get_sub_object(std::string s_name); //���������� ������������ ������� �� �����
};

#endif
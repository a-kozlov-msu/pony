#pragma once

extern void pony_init(char*);
extern char pony_step();
extern void pony_terminate();
extern void pony_add_plugin(void(*newplugin)());
extern void pony_free();

typedef struct                 //��� ���������, ������������ ����� ���� �����
{
	double val;                //���������
	int count;                 //�������
	char valid;                //������� ����������
} pony_data;

typedef struct                 //��� ���������, ������������ ����� ��������� �����
{
	double *val;               //������ ���������
	int count;                 //�������
	char valid;                //������� ����������
	unsigned char arrsize;     //������ �������
} pony_dataArray;

typedef struct                 //������������ ������
{
	char* conf;                //������������
	char conflength;           //����� ������ ������������

	pony_dataArray w;          //���������
	pony_dataArray f;          //�������������
	pony_dataArray q;          //����������
}pony_imu;

typedef struct                 //����������� ������
{
	char* conf;                //������������
	char conflength;           //����� ������ ������������

}pony_gnss;

typedef struct                 //����
{
	int mode;                  //������� ������
	pony_imu* imu;
	pony_gnss* gnss;

	pony_data t;               //�����

	char* conf;                //������������
	char conflength;           //����� ������ ������������
} pony_bus;

extern struct
{
	pony_bus bus;

	void(**plugins)();         //��������� �� ������ ���������� �� �������
	int pluginsNum;            //���������� ��������

	char* conf;                //������������
	char conflength;           //����� ������ ������������

	unsigned char exitplnum;   //����� �������, ���������� ������������� ������
} pony;

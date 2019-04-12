char pony_add_plugin(void(*newplugin)(void));
char pony_init(char*);
char pony_step(void);
char pony_terminate(void);

typedef struct                 //��� ���������, ������������ ����� ���� �����
{
	double val;                //��������
	unsigned char count;       //�������
	unsigned char valid;       //������� ����������
} pony_data;

typedef struct                 //��� ���������, ������������ ����� ��������� �����
{
	double *val;               //������ ��������
	int count;                 //�������
	char valid;                //������� ����������
	int arrsize;               //������ �������
} pony_dataArray;

typedef struct                 //������������ ������
{
	char* conf;                //������������
	int conflength;            //����� ������ ������������

	pony_dataArray w;          //���������
	pony_dataArray f;          //�������������
	pony_dataArray q;          //����������
} pony_imu;

typedef struct                 //
{
	char* conf;                //������������
	int conflength;            //����� ������ ������������

} pony_gnss_gps;

typedef struct                 //
{
	char* conf;                //������������
	int conflength;            //����� ������ ������������

} pony_gnss_glo;

typedef struct                 //����������� ������
{
	char* conf;                //������������
	int conflength;            //����� ������ ������������

	pony_gnss_gps* gps;
	pony_gnss_glo* glo;

	char* wconf;
	int wconflength;

} pony_gnss;

#define pony_bus_version 0     //������ ���� 
typedef struct                 //����
{
	int ver;                   //������ ����, ��� ������������� � runtime
	int mode;                  //����� ������: 0 �������������, >0 ������, <0 ����������

	pony_imu* imu;
	pony_gnss* gnss;

	pony_data t;               //�����

	char* conf;                //������������
	int conflength;            //����� ������ ������������
} pony_bus;

typedef struct
{
	pony_bus bus;

	void(**plugins)(void);     //��������� �� ������ ���������� �� �������
	int pluginsNum;            //���������� ��������

	char* conf;                //������������
	int conflength;            //����� ������ ������������

	int exitplnum;             //����� �������, ���������� ������������� ������
} pony_struct;

extern pony_struct pony;

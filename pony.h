char pony_add_plugin(void(*newplugin)(void));
char pony_init(char*);
char pony_step(void);
char pony_terminate(void);



char pony_extract_string_length(char* confstr, int length, char* identifier, int* res);
char pony_extract_string(char* confstr, int length, char* identifier, char** res);
char pony_extract_char_sym(char* confstr, int length, char* identifier, char* res);
char pony_extract_char_num(char* confstr, int length, char* identifier, char* res);
char pony_extract_short(char* confstr, int length, char* identifier, short* res);
char pony_extract_int(char* confstr, int length, char* identifier, int* res);
char pony_extract_long(char* confstr, int length, char* identifier, long* res);
char pony_extract_float(char* confstr, int length, char* identifier, float* res);
char pony_extract_double(char* confstr, int length, char* identifier, double* res);
char pony_extract_bool(char* confstr, int length, char* identifier, char* res);



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


// IMU
typedef struct                 //������������ ������
{
	char* conf;                //������������
	int conflength;            //����� ������ ������������

	pony_dataArray w;          //���������
	pony_dataArray f;          //�������������
	pony_dataArray q;          //����������
} pony_imu;



// GNSS
typedef struct {

	char prn;

	double x[3];
	double v[3];
	double t_em;

	double eph[32];
	
	char visible;
	double sinEl;

} pony_gps_sat;

typedef struct                 //
{
	char* conf;                //������������
	int conflength;            //����� ������ ������������

	pony_gps_sat *sat;
	int max_sat_num;
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


// CORE
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


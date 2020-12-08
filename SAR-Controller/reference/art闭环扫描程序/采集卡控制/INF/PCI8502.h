#ifndef _PCI8502_DEVICE_
#define _PCI8502_DEVICE_
//***********************************************************
// ����AD������ʵ��Ӳ������
typedef struct _PCI8502_PARA_AD     
{
	LONG Frequency;         // �ɼ�Ƶ��,��λΪHz, [10, 40000000]
	LONG InputRange[4];		// ģ������������ѡ��
	LONG CouplingType;		// �������(ֱ�����, �������)
	LONG M_Length;          // M�γ���(��)
	LONG N_Length;          // N�γ���(��)
	LONG TriggerMode;		// ����ģʽѡ��
	LONG ATRTriggerChannel;	// ATRͨ��ѡ��
	LONG TriggerSource;		// ����Դѡ��
	LONG TriggerDir;		// ��������ѡ��(����/���򴥷�)
	LONG TrigLevelVolt;		// ������ƽ(0--10000mV)
	LONG ClockSource;		// ʱ��Դѡ��(��/��ʱ��Դ)
	LONG OutClockSource;	// ʱ���������Դ
	LONG bClockSourceDir;   // �Ƿ�ʱ���ź������PXI����,=TRUE:�������, =FALSE:��������
} PCI8502_PARA_AD, *PPCI8502_PARA_AD;

//***********************************************************
// AD����PCI8502_PARA_AD�е�InputRange[X]ʹ�õ�Ӳ������ѡ��
const long PCI8502_INPUT_N1000_P1000mV		= 0x00; // ��1000mV
const long PCI8502_INPUT_N5000_P5000mV		= 0x01; // ��5000mV

// AD����PCI8502_PARA_AD�е�CouplingType���������ʹ�õ�ѡ��
const long PCI8502_COUPLING_AC				= 0x00;	// �������
const long PCI8502_COUPLING_DC				= 0x01;	// ֱ�����

//***********************************************************
// ADӲ������PCI8502_PARA_AD�е�TriggerMode��Ա������ʹ�ô���ģʽѡ��
const long PCI8502_TRIGMODE_MIDL			= 0x00; // �м䴥��
const long PCI8502_TRIGMODE_POST			= 0x01; // �󴥷�
const long PCI8502_TRIGMODE_PRE				= 0x02; // Ԥ����
const long PCI8502_TRIGMODE_DELAY			= 0x03; // Ӳ����ʱ����

//***********************************************************
// ADӲ������PCI8502_PARA_AD�е�ATRTriggerChannel��Ա������ʹ��ATR����ͨ��ѡ��
const long PCI8502_ATRTRIG_CH0				= 0x00; // ͨ��0�ź���ΪATR����
const long PCI8502_ATRTRIG_CH1				= 0x01; // ͨ��1�ź���ΪATR����
const long PCI8502_ATRTRIG_CH2				= 0x02; // ͨ��2�ź���ΪATR����
const long PCI8502_ATRTRIG_CH3				= 0x03; // ͨ��3�ź���ΪATR����

//***********************************************************
// ADӲ������PCI8502_PARA_AD�е�TriggerSource����Դ�ź���ʹ�õ�ѡ��
const long PCI8502_TRIGMODE_SOFT			= 0x00; // �������
const long PCI8502_TRIGSRC_DTR				= 0x01; // ѡ��DTR��Ϊ����Դ
const long PCI8502_TRIGSRC_ATR				= 0x02; // ѡ��ATR��Ϊ����Դ
const long PCI8502_TRIGSRC_TRIGGER		    = 0x03; // Trigger�źŴ��������ڶ࿨ͬ����

//***********************************************************
// ADӲ������PCI8502_PARA_AD�е�TriggerDir����������ʹ�õ�ѡ��
const long PCI8502_TRIGDIR_NEGATIVE			= 0x00; // �½��ش���
const long PCI8502_TRIGDIR_POSITIVE			= 0x01; // �����ش���
const long PCI8502_TRIGDIR_NEGAT_POSIT		= 0x02; // ���±��ؾ�����

//***********************************************************
// ADӲ������PCI8502_PARA_AD�е�ClockSourceʱ��Դ��ʹ�õ�ѡ��
const long PCI8502_CLOCKSRC_IN				= 0x00; // ʹ���ڲ�ʱ��
const long PCI8502_CLOCKSRC_OUT				= 0x01; // ʹ���ⲿʱ��

//***********************************************************
// ADӲ������PCI8502_PARA_AD�е�OutClockSourceʱ��Դ��ʹ�õ�ѡ��
const long PCI8502_OUTCLOCKSRC_TRIGGER0		= 0x00; // ѡ��PXI�����ϵ�TRIG0����/���ʱ��
const long PCI8502_OUTCLOCKSRC_TRIGGER1		= 0x01; // ѡ��PXI�����ϵ�TRIG1����/���ʱ��
const long PCI8502_OUTCLOCKSRC_TRIGGER2		= 0x02; // ѡ��PXI�����ϵ�TRIG2����/���ʱ��
const long PCI8502_OUTCLOCKSRC_TRIGGER3		= 0x03; // ѡ��PXI�����ϵ�TRIG3����/���ʱ��
const long PCI8502_OUTCLOCKSRC_TRIGGER4		= 0x04; // ѡ��PXI�����ϵ�TRIG4����/���ʱ��
const long PCI8502_OUTCLOCKSRC_TRIGGER5		= 0x05; // ѡ��PXI�����ϵ�TRIG5����/���ʱ��
const long PCI8502_OUTCLOCKSRC_TRIGGER6		= 0x06; // ѡ��PXI�����ϵ�TRIG6����/���ʱ��
const long PCI8502_OUTCLOCKSRC_TRIGGER7		= 0x07; // ѡ��PXI�����ϵ�TRIG7����/���ʱ��
const long PCI8502_OUTCLOCKSRC_PXISTAR		= 0x08; // PXI_STAR�źŴ���

//*************************************************************************************
// ����AD������ʵ��Ӳ������
typedef struct _PCI8502_STATUS_AD     
{
	LONG bADEanble;	// AD�Ƿ��Ѿ�ʹ�ܣ�=TRUE:��ʾ��ʹ�ܣ�=FALSE:��ʾδʹ��
	LONG bTrigger;  // AD�Ƿ񱻴�����=TRUE:��ʾ�ѱ�������=FALSE:��ʾδ������
	LONG bComplete; // AD�Ƿ�����ת�������Ƿ������=TRUE:��ʾ�ѽ�����=FALSE:��ʾδ����
	LONG bAheadTrig;// AD�������Ƿ���ǰ��=TRUE:��ʾ��������ǰ��=FALSE:��ʾ������δ��ǰ
	LONG lEndAddr;	// ������ɵĽ�����ַ
} PCI8502_STATUS_AD, *PPCI8502_STATUS_AD;

//***********************************************************
// �û������ӿ�
#ifndef _PCI8502_DRIVER_
#define DEVAPI __declspec(dllimport)
#else
#define DEVAPI __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
	//######################## ����ͨ�ú��� #################################
	// �����ڱ��豸�����������
	HANDLE DEVAPI FAR PASCAL PCI8502_CreateDevice(int DeviceID = 0);		// �����豸����
	int DEVAPI FAR PASCAL PCI8502_GetDeviceCount(HANDLE hDevice);			// ȡ���豸��̨��
	BOOL DEVAPI FAR PASCAL PCI8502_ListDeviceDlg(HANDLE hDevice);			// �б�ϵͳ���е����еĸ�PCI�豸
    BOOL DEVAPI FAR PASCAL PCI8502_ReleaseDevice(HANDLE hDevice);			// �ر��豸,��ֹ����,���ͷ���Դ

	//####################### AD���ݶ�ȡ���� #################################
	// ���ڴ������ͨ�û�����Щ�ӿ���򵥡����ݡ���ɿ������û�����֪���豸
	// �Ͳ㸴�ӵ�Ӳ������Э��ͷ����������Ʊ�̣���������ĳ�ʼ���豸�Ͷ�ȡ
	// AD�������������������ɸ�Ч��ʵ�ָ��١����������ݲɼ�
	BOOL DEVAPI FAR PASCAL PCI8502_GetDDR2Length(								// ��ȡDDR2�Ĵ洢����
												HANDLE hDevice,					// �豸����
												PULONG pulDDR2Length);			// DDR2�ĳ���(��λ��MB)
	BOOL DEVAPI FAR PASCAL PCI8502_ADCalibration(								// ADУ׼
												HANDLE hDevice);				// �豸����				
    BOOL DEVAPI FAR PASCAL PCI8502_InitDeviceAD(								// ��ʼ���豸��������TRUE��,�豸���̿�ʼ����.
												HANDLE hDevice,					// �豸����
												PPCI8502_PARA_AD pADPara);		// Ӳ������, �����ڴ˺����о���Ӳ��״̬

    BOOL DEVAPI FAR PASCAL PCI8502_StartDeviceAD(								// �ڳ�ʼ��֮�������豸
												HANDLE hDevice);				// �豸������

	BOOL DEVAPI FAR PASCAL PCI8502_SetDeviceTrigAD(								// ���豸ʹ������󣬲�����������¼���ֻ�д���ԴΪ�������ʱ��Ч��
												HANDLE hDevice);				// �豸������
	
	BOOL DEVAPI FAR PASCAL PCI8502_GetDevStatusAD(
												HANDLE hDevice,					// �豸���
												PPCI8502_STATUS_AD pADStatus);	// AD״̬
	///////////////////////////////////////////////////////////////////////
	BOOL DEVAPI FAR PASCAL PCI8502_ReadDeviceAD(								// DMA��ʽ��AD����
												HANDLE hDevice,					// �豸���
												PWORD pADBuffer,				// �����ڽ������ݵ��û�������(�������뿪�ٴ���M��N���ֵĿռ�)
												ULONG nReadSizeWords,			// �������M��N�ĳ���
												ULONG ulStartAddr,				// ������RAM�е���ʼ��ַ
												PLONG nRetSizeWords);			// ����ʵ�ʶ�ȡ�����ݳ���
								
    BOOL DEVAPI FAR PASCAL PCI8502_StopDeviceAD(								// �������豸֮����ͣ�豸
												HANDLE hDevice);				// �豸������

	BOOL DEVAPI FAR PASCAL PCI8502_ReleaseDeviceAD(								// �ر�AD�豸,��ֹ����,���ͷ���Դ
												HANDLE hDevice);				// �豸���

	//################# AD��Ӳ�������������� ########################
	BOOL DEVAPI FAR PASCAL PCI8502_SaveParaAD(HANDLE hDevice, PPCI8502_PARA_AD pADPara);  
    BOOL DEVAPI FAR PASCAL PCI8502_LoadParaAD(HANDLE hDevice, PPCI8502_PARA_AD pADPara);
	BOOL DEVAPI FAR PASCAL PCI8502_ResetParaAD(HANDLE hDevice, PPCI8502_PARA_AD pADPara);

	//################# �ڴ�ӳ��Ĵ���ֱ�Ӳ�������д���� ########################
	// �������û��Ա��豸��ֱ�ӡ������⡢���Ͳ㡢�����ӵĿ��ơ�������������
	// ���ƶ�����Ҫ����Ŀ������̺Ϳ���Ч��ʱ�����û�����ʹ����Щ�ӿ�����ʵ�֡�
	BOOL DEVAPI FAR PASCAL PCI8502_GetDeviceBar(					// ȡ��ָ����ָ���豸�Ĵ�����BAR��ַ
											HANDLE hDevice,			// �豸������,����CreateDevice��������
											__int64 pbPCIBar[6]);	// ����PCI BAR���е�ַ,����PCI BAR���ж��ٿ��õ�ַ�뿴Ӳ��˵����
	BOOL DEVAPI FAR PASCAL PCI8502_GetDevVersion(					// ��ȡ�豸�̼�������汾
											HANDLE hDevice,			// �豸������,����CreateDevice��������
											PULONG pulFmwVersion,	// �̼��汾
											PULONG pulDriverVersion);// �����汾
	BOOL DEVAPI FAR PASCAL PCI8502_WriteRegisterByte(				// ���豸��ӳ��Ĵ����ռ�ָ���˿�д�뵥��������
											HANDLE hDevice,			// �豸����
											__int64 pbLinearAddr,		// ָ��ӳ��Ĵ��������Ի���ַ
											ULONG OffsetBytes,		// ����ڻ���ַ��ƫ��λ��
											BYTE Value);			// ��ָ����ַд�뵥�ֽ����ݣ����ַ�����Ի���ַ��ƫ��λ�þ�����
	BOOL DEVAPI FAR PASCAL PCI8502_WriteRegisterWord(				// д˫�ֽ����ݣ�����ͬ�ϣ�
											HANDLE hDevice, 
											__int64 pbLinearAddr, 
											ULONG OffsetBytes,  
											WORD Value);
	BOOL DEVAPI FAR PASCAL PCI8502_WriteRegisterULong(				// д�Ľ������ݣ�����ͬ�ϣ�
											HANDLE hDevice, 
											__int64 pbLinearAddr, 
											ULONG OffsetBytes,  
											ULONG Value);
	BYTE DEVAPI FAR PASCAL PCI8502_ReadRegisterByte(				// ���뵥�ֽ����ݣ�����ͬ�ϣ�
											HANDLE hDevice, 
											__int64 pbLinearAddr, 
											ULONG OffsetBytes);
	WORD DEVAPI FAR PASCAL PCI8502_ReadRegisterWord(				// ����˫�ֽ����ݣ�����ͬ�ϣ�
											HANDLE hDevice, 
											__int64 pbLinearAddr, 
											ULONG OffsetBytes);
	ULONG DEVAPI FAR PASCAL PCI8502_ReadRegisterULong(				// �������ֽ����ݣ�����ͬ�ϣ�
											HANDLE hDevice, 
											__int64 pbLinearAddr, 
											ULONG OffsetBytes);

	//################# I/O�˿�ֱ�Ӳ�������д���� ########################
	// �������û��Ա��豸��ֱ�ӡ������⡢���Ͳ㡢�����ӵĿ��ơ�������������
	// ���ƶ�����Ҫ����Ŀ������̺Ϳ���Ч��ʱ�����û�����ʹ����Щ�ӿ�����ʵ�֡�
	// ����Щ������Ҫ�����ڴ�ͳ�豸����ISA���ߡ����ڡ����ڵ��豸���������ڱ�PCI�豸
    BOOL DEVAPI FAR PASCAL PCI8502_WritePortByte(HANDLE hDevice, __int64 pbPort, ULONG offserBytes, BYTE Value);
    BOOL DEVAPI FAR PASCAL PCI8502_WritePortWord(HANDLE hDevice, __int64 pbPort, ULONG offserBytes, WORD Value);
    BOOL DEVAPI FAR PASCAL PCI8502_WritePortULong(HANDLE hDevice, __int64 pbPort, ULONG offserBytes, ULONG Value);

    BYTE DEVAPI FAR PASCAL PCI8502_ReadPortByte(HANDLE hDevice, __int64 pbPort, ULONG offserBytes);
    WORD DEVAPI FAR PASCAL PCI8502_ReadPortWord(HANDLE hDevice, __int64 pbPort, ULONG offserBytes);
    ULONG DEVAPI FAR PASCAL PCI8502_ReadPortULong(HANDLE hDevice, __int64 pbPort, ULONG offserBytes);

	//########################### �̲߳������� ######################################
	HANDLE DEVAPI FAR PASCAL PCI8502_CreateSystemEvent(void);			// �����ں��¼����󣬹�InitDeviceInt��VB���̵߳Ⱥ���ʹ��
	BOOL DEVAPI FAR PASCAL PCI8502_ReleaseSystemEvent(HANDLE hEvent);	// �ͷ��ں��¼�����

#ifdef __cplusplus
}
#endif

// �Զ������������������
#ifndef _PCI8502_DRIVER_
	#ifndef _WIN64
		#pragma comment(lib, "PCI8502_32.lib")
		#pragma message("======== Welcome to use our art company's products!")
		#pragma message("======== Automatically linking with PCI8502_32.dll...")
		#pragma message("======== Successfully linked with PCI8502_32.dll")
	#else
		#pragma comment(lib, "PCI8502_64.lib")
		#pragma message("======== Welcome to use our art company's products!")
		#pragma message("======== Automatically linking with PCI8502_64.dll...")
		#pragma message("======== Successfully linked with PCI8502_64.dll")
	#endif
	
#endif

#endif // _PCI8502_DEVICE_

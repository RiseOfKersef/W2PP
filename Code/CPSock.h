#ifndef _CPSOCK_ // Last updated august 2012
#define _CPSOCK_ 

#include <Windows.h>

#define WSA_READ            (WM_USER + 100)
#define WSA_READDB          (WM_USER + 2) 
#define WSA_ACCEPT          (WM_USER + 3) 
#define WSA_READBILL		(WM_USER + 4)
#define WSA_ACCEPTADMIN     (WM_USER + 5) 
#define WSA_READADMIN		(WM_USER + 6) 
#define WSA_READADMINCLIENT	(WM_USER + 7) 

#define MAX_PENDING_CONNECTS  8

#define RECV_BUFFER_SIZE      (128*1024)         // Maximum buffer size to receive messages of 64k
#define SEND_BUFFER_SIZE      (128*1024)         // Maximum buffer size to send messages of 64K

#define MAX_MESSAGE_SIZE           8192         // Maximum size a single message can have, 4K

#define INITCODE               0x1F11F311

unsigned char b[512] = { 0x84, 0x87, 0x37, 0xD7, 0xEA, 0x79, 0x91, 0x7D, 0x4B, 0x4B, 0x85, 0x7D, 0x87, 0x81, 0x91, 0x7C, 0x0F, 0x73, 0x91, 0x91, 0x87, 0x7D, 0x0D, 0x7D, 0x86, 0x8F, 0x73, 0x0F, 0xE1, 0xDD,
0x85, 0x7D, 0x05, 0x7D, 0x85, 0x83, 0x87, 0x9C, 0x85, 0x33, 0x0D, 0xE2, 0x87, 0x19, 0x0F, 0x79, 0x85, 0x86, 0x37, 0x7D, 0xD7, 0xDD, 0xE9, 0x7D, 0xD7, 0x7D, 0x85, 0x79, 0x05, 0x7D,
0x0F, 0xE1, 0x87, 0x7E, 0x23, 0x87, 0xF5, 0x79, 0x5F, 0xE3, 0x4B, 0x83, 0xA3, 0xA2, 0xAE, 0x0E, 0x14, 0x7D, 0xDE, 0x7E, 0x85, 0x7A, 0x85, 0xAF, 0xCD, 0x7D, 0x87, 0xA5, 0x87, 0x7D,
0xE1, 0x7D, 0x88, 0x7D, 0x15, 0x91, 0x23, 0x7D, 0x87, 0x7C, 0x0D, 0x7A, 0x85, 0x87, 0x17, 0x7C, 0x85, 0x7D, 0xAC, 0x80, 0xBB, 0x79, 0x84, 0x9B, 0x5B, 0xA5, 0xD7, 0x8F, 0x05, 0x0F,
0x85, 0x7E, 0x85, 0x80, 0x85, 0x98, 0xF5, 0x9D, 0xA3, 0x1A, 0x0D, 0x19, 0x87, 0x7C, 0x85, 0x7D, 0x84, 0x7D, 0x85, 0x7E, 0xE7, 0x97, 0x0D, 0x0F, 0x85, 0x7B, 0xEA, 0x7D, 0xAD, 0x80,
0xAD, 0x7D, 0xB7, 0xAF, 0x0D, 0x7D, 0xE9, 0x3D, 0x85, 0x7D, 0x87, 0xB7, 0x23, 0x7D, 0xE7, 0xB7, 0xA3, 0x0C, 0x87, 0x7E, 0x85, 0xA5, 0x7D, 0x76, 0x35, 0xB9, 0x0D, 0x6F, 0x23, 0x7D,
0x87, 0x9B, 0x85, 0x0C, 0xE1, 0xA1, 0x0D, 0x7F, 0x87, 0x7D, 0x84, 0x7A, 0x84, 0x7B, 0xE1, 0x86, 0xE8, 0x6F, 0xD1, 0x79, 0x85, 0x19, 0x53, 0x95, 0xC3, 0x47, 0x19, 0x7D, 0xE7, 0x0C,
0x37, 0x7C, 0x23, 0x7D, 0x85, 0x7D, 0x4B, 0x79, 0x21, 0xA5, 0x87, 0x7D, 0x19, 0x7D, 0x0D, 0x7D, 0x15, 0x91, 0x23, 0x7D, 0x87, 0x7C, 0x85, 0x7A, 0x85, 0xAF, 0xCD, 0x7D, 0x87, 0x7D,
0xE9, 0x3D, 0x85, 0x7D, 0x15, 0x79, 0x85, 0x7D, 0xC1, 0x7B, 0xEA, 0x7D, 0xB7, 0x7D, 0x85, 0x7D, 0x85, 0x7D, 0x0D, 0x7D, 0xE9, 0x73, 0x85, 0x79, 0x05, 0x7D, 0xD7, 0x7D, 0x85, 0xE1,
0xB9, 0xE1, 0x0F, 0x65, 0x85, 0x86, 0x2D, 0x7D, 0xD7, 0xDD, 0xA3, 0x8E, 0xE6, 0x7D, 0xDE, 0x7E, 0xAE, 0x0E, 0x0F, 0xE1, 0x89, 0x7E, 0x23, 0x7D, 0xF5, 0x79, 0x23, 0xE1, 0x4B, 0x83,
0x0C, 0x0F, 0x85, 0x7B, 0x85, 0x7E, 0x8F, 0x80, 0x85, 0x98, 0xF5, 0x7A, 0x85, 0x1A, 0x0D, 0xE1, 0x0F, 0x7C, 0x89, 0x0C, 0x85, 0x0B, 0x23, 0x69, 0x87, 0x7B, 0x23, 0x0C, 0x1F, 0xB7,
0x21, 0x7A, 0x88, 0x7E, 0x8F, 0xA5, 0x7D, 0x80, 0xB7, 0xB9, 0x18, 0xBF, 0x4B, 0x19, 0x85, 0xA5, 0x91, 0x80, 0x87, 0x81, 0x87, 0x7C, 0x0F, 0x73, 0x91, 0x91, 0x84, 0x87, 0x37, 0xD7,
0x86, 0x79, 0xE1, 0xDD, 0x85, 0x7A, 0x73, 0x9B, 0x05, 0x7D, 0x0D, 0x83, 0x87, 0x9C, 0x85, 0x33, 0x87, 0x7D, 0x85, 0x0F, 0x87, 0x7D, 0x0D, 0x7D, 0xF6, 0x7E, 0x87, 0x7D, 0x88, 0x19,
0x89, 0xF5, 0xD1, 0xDD, 0x85, 0x7D, 0x8B, 0xC3, 0xEA, 0x7A, 0xD7, 0xB0, 0x0D, 0x7D, 0x87, 0xA5, 0x87, 0x7C, 0x73, 0x7E, 0x7D, 0x86, 0x87, 0x23, 0x85, 0x10, 0xD7, 0xDF, 0xED, 0xA5,
0xE1, 0x7A, 0x85, 0x23, 0xEA, 0x7E, 0x85, 0x98, 0xAD, 0x79, 0x86, 0x7D, 0x85, 0x7D, 0xD7, 0x7D, 0xE1, 0x7A, 0xF5, 0x7D, 0x85, 0xB0, 0x2B, 0x37, 0xE1, 0x7A, 0x87, 0x79, 0x84, 0x7D,
0x73, 0x73, 0x87, 0x7D, 0x23, 0x7D, 0xE9, 0x7D, 0x85, 0x7E, 0x02, 0x7D, 0xDD, 0x2D, 0x87, 0x79, 0xE7, 0x79, 0xAD, 0x7C, 0x23, 0xDA, 0x87, 0x0D, 0x0D, 0x7B, 0xE7, 0x79, 0x9B, 0x7D,
0xD7, 0x8F, 0x05, 0x7D, 0x0D, 0x34, 0x8F, 0x7D, 0xAD, 0x87, 0xE9, 0x7C, 0x85, 0x80, 0x85, 0x79, 0x8A, 0xC3, 0xE7, 0xA5, 0xE8, 0x6B, 0x0D, 0x74, 0x10, 0x73, 0x33, 0x17, 0x0D, 0x37,
0x21, 0x19 };
typedef struct _HEADER
{
	short		  Size;
	char		  KeyWord;
	char		  CheckSum;
	short		  Type;
	short		  ID;
	unsigned int  ClientTick; 
} HEADER, *PHEADER;


class  CPSock
{   
public:
	unsigned int  Sock;
	char   *pSendBuffer;
	char   *pRecvBuffer;
	int		nSendPosition;
	int		nRecvPosition;
	int		nProcPosition;
	int		nSentPosition;
	int     Init;	

public:
	CPSock();
	~CPSock();

	BOOL	CloseSocket			();
	BOOL	WSAInitialize		();
	SOCKET	StartListen			(HWND hWnd, int ip, int Port, int WSA);
	SOCKET	ConnectServer		(char *HostAddr, int Port, int ip, int WSA);
	SOCKET  ConnectBillServer	(char *HostAddr, int Port, int ip, int WSA);

	BOOL	Receive				();
	char   *ReadMessage			(int *ErrorCode, int *ErrorType);
	
	BOOL	AddMessage			(char *pMsg, int Size);
	BOOL	SendMessageA		();
	BOOL	SendOneMessage		(char* Msg, int Size);
	
	void	RefreshRecvBuffer	(void);
	void	RefreshSendBuffer	(void);
	BOOL	SendBillMessage		(char * Msg);
	char   *ReadBillMessage		(int *ErrorCode, int *ErrorType);
};

struct _AUTH_GAME // NEEDS TO BE FIXED ACCORDING TO WYD 1.2 6.13 SIZE IS 0xC4 (196)
{
	char Unk[196];	
};

/* FROM TANTRA
struct _AUTH_GAME{
	int 	Packet_Type;	//	4
	int		Result;			//	4 
	char	S_KEY[32];		//	4*8	 
	char	Session[32];	//  4*8
	char	User_CC[4];		//	4
	char	User_No[20];	//	4*5
	char	User_ID[52];	//  4*13
	char	User_IP[24];	//  4*6
	char	User_Gender;	
	char	User_Status[3];	//	4	
	char	User_PayType[4];//	2 ?
	int 	User_Age;		//  4
	int 	Game_No;		//  4
	char	Bill_PayType[2];
	char	Bill_Method[2];	//	4
	char	Bill_Expire[12];//	4*3 	
	int 	Bill_Remain;	//	4
};

struct _AUTH_GAME2{
	int 	Packet_Type;
	int		Packet_result;
	char	User_ID[52];
	char	User_roleName[20];
	int		Map_number;	
	int		User_co[2];	
	int		article_number;
	int		Dressed;
	int		Time_Exchanged;	
	int		ItemNo;		
	char	cardNumber[20];	
	char	cardPassword[20];
	char	messageflag[4];
	char	activeMessage[20];	
	char 	reserved[36];
};*/

#define g_cGame  (sizeof(_AUTH_GAME))

#endif

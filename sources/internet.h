#if !defined(INTERNET_HDR)
#define INTERNET_HDR

// Determines Status and debug mode or not
extern int internet_status;
extern int debug_status;

// SMTP Configuration Structure
typedef struct mail_config{
	unsigned short IP1, IP2, IP3, IP4;	// IPADDRESS:  192.168.0.11 --> IP1.IP2.IP3.IP4
	unsigned char sender[40];			// the senders email address (sender@company.com)
	unsigned char recipient[40];		// the receivers email address (iwantemail@company.com)
	unsigned char subject[40];			// the email subject, needs to be someting and can't be blank
	unsigned char reply[40];			// the address where to reply to, needs to be someting and can't be blank
	unsigned char local_file[16];		// the name of the file that will be saved on the terminal ( <drive (optional)>:<filename8>.<extension3> )
	char *smtp_msg;
	unsigned char attach;				// variable to enable/disable to attach as file to email
	unsigned char base64;
	unsigned char abort_key;
}mail_config;

// POP Configuration Structure
typedef struct pop_config
{
	unsigned short IP1, IP2, IP3, IP4;
	unsigned char local_file[16];		// the name of the local file <drive (optional)>:<filename8>.<extension3>
	unsigned char user[40];
	unsigned char pass[40];
	unsigned char nr_of_msgs;
	unsigned char incl_hdrs;
	unsigned char delete_msg;
	unsigned char msg_number;
	unsigned char abort_key;
}pop_config;

// FTP Configuration Structure
typedef struct ftp_config
{
	unsigned short IP1, IP2, IP3, IP4;	// IPADDRESS:  192.168.0.11 --> IP1.IP2.IP3.IP4
	unsigned char user[40];				// username with (maximum size of 40 !!!)
	unsigned char pass[40];				// password with (maximum size of 40 !!!)
	unsigned char local_file[16];		// File name of the local file for send and receive operations (also used for rename and list operation)
	unsigned char remote_file[40];		// File name of the remote file for send, receive and delete operations (also used for rename operation)
	unsigned char append;
	unsigned char abort_key;
}ftp_config;

// DNS Configuration Structure
typedef struct dns_config
{
	unsigned char domain_address[80];	// Domain Address name i.e. www.altavista.com
	unsigned short IP1, IP2, IP3, IP4;		// RETURNED IPADDRESS:  209.73.164.91 --> IP1.IP2.IP3.IP4
	unsigned char abort_key;
}dns_config;

// NTP Configuration Structure
typedef struct ntp_config
{
	unsigned short IP1, IP2, IP3, IP4;		// IP-ADDRESS of NTP-sserver:  192.168.0.11 --> IP1.IP2.IP3.IP4
	struct date *date;
	struct time *time;
	unsigned char abort_key;
}ntp_config;


// ISP Configuration Structure
typedef struct isp_config
{
	unsigned char phonenumber[20];		// ISP phone number
	unsigned char user[40];				// ISP username
	unsigned char pass[40];				// ISP password
	unsigned char com;					// Com port on which the modem is on
	unsigned char abort_key;
}isp_config;

/* Functions that will be called from the LIBRARY */
extern void TCPIP_init(int internet_status, int debug_status);

extern int ftp_command(struct ftp_config *ftp, unsigned int ftp_command);
extern int ftp_connected(void);

extern int get_host_by_name(struct dns_config *dns);
extern int get_host_by_addr(struct dns_config *dns);

extern int get_local_IP_address(struct dns_config *dns, int timeout);
extern int get_ISP_server_IP(struct dns_config *dns, int timeout);
extern int get_primary_DNS_server_IP(struct dns_config *dns, int timeout);
extern int get_secondary_DNS_server_IP(struct dns_config *dns, int timeout);

extern void set_primary_DNS_server_IP(struct dns_config *dns);
extern void set_secondary_DNS_server_IP(struct dns_config *dns);

extern int change_FTP_remote_port_nr(unsigned short port_nr);
extern int change_SMTP_remote_port_nr(unsigned short port_nr);
extern int change_POP_remote_port_nr(unsigned short port_nr);
extern int change_TCP_maximum_segment_size(unsigned short mss);

extern int get_NTP_time(struct ntp_config *ntp, int time_zone);

extern int getmail(struct pop_config *pop, unsigned int command);
extern int sendmail(struct mail_config *);
extern int sendmail_authenticated(mail_config *mstruct, unsigned char *username, unsigned char *password);
extern int disconnect(struct isp_config *);
extern char *tcpip_lib_version(void);

extern int checkstring(const char *adres2, int timeout, unsigned char abort_key);
extern void sendstring(const char *adres);

#if PHL2700
int dialup_phl2700(struct isp_config *isp);
int dialup_phl2700_additional_ATcommand(struct isp_config *isp, char* AT_Command);
int dialup_phl2700_user_specified_ATcommand(struct isp_config *isp, char* AT_Command);
int dialup_phl2700_already_connected(struct isp_config *isp);

#define connect(isp) (dialup_phl2700(isp))
#define connect_additional_ATcommand(isp, AT_Command) (dialup_phl2700_additional_ATcommand(isp, AT_Command))
#define connect_user_specified_ATcommand(isp, AT_Command) (dialup_phl2700_user_specified_ATcommand(isp, AT_Command))
#define register_manual_connection(isp) (dialup_phl2700_already_connected(isp))
#else
#if PHL1000
int dialup_phl2700(struct isp_config *isp);
int dialup_phl2700_additional_ATcommand(struct isp_config *isp, char* AT_Command);
int dialup_phl2700_user_specified_ATcommand(struct isp_config *isp, char* AT_Command);
int dialup_phl2700_already_connected(struct isp_config *isp);

#define connect(isp) (dialup_phl2700(isp))
#define connect_additional_ATcommand(isp, AT_Command) (dialup_phl2700_additional_ATcommand(isp, AT_Command))
#define connect_user_specified_ATcommand(isp, AT_Command) (dialup_phl2700_user_specified_ATcommand(isp, AT_Command))
#define register_manual_connection(isp) (dialup_phl2700_already_connected(isp))
#else
#if PHL
int dialup_phl1700(struct isp_config *isp);
int dialup_phl1700_additional_ATcommand(struct isp_config *isp, char* AT_Command);
int dialup_phl1700_user_specified_ATcommand(struct isp_config *isp, char* AT_Command);
int dialup_phl1700_already_connected(struct isp_config *isp);

#define connect(isp) (dialup_phl1700(isp))
#define connect_additional_ATcommand(isp, AT_Command) (dialup_phl1700_additional_ATcommand(isp, AT_Command))
#define connect_user_specified_ATcommand(isp, AT_Command) (dialup_phl1700_user_specified_ATcommand(isp, AT_Command))
#define register_manual_connection(isp) (dialup_phl1700_already_connected(isp))
#else

int connect(struct isp_config *isp);
int connect_additional_ATcommand(struct isp_config *isp, char* AT_Command);
int connect_user_specified_ATcommand(struct isp_config *isp, char* AT_Command);
int register_manual_connection(struct isp_config *isp);

#endif
#endif
#endif

#define ERR_USER_ABORTED					-1		// User has hit a key in process
#define ERR_NO_SUCH_FILE					-2		// The file that was tried to open did not exist
#define ERR_POLLED							-3		// The connection has timed out
#define ERR_ILLEGAL_COMMAND					-4		// One command was not accepted
#define ERR_SERVER_REJECTED					-5		// The server rejected an acknowledgment packet
#define ERR_CONNECTION_ABORTED				-6		// The TCP connection was aborted by the server

#define ERR_TCP_PORT_NOT_SUPPORTED			-7		// The TCP port in the incoming packet is unknown
#define ERR_TCP_RECEIVED_RESET				-8		// The TCP connection was reset by the server

#define ERR_NODIALTONE						-9
#define ERR_BUSY							-10
#define ERR_NOANSWER						-11
#define ERR_NOCARRIER						-12
#define ERR_MODEM							-13
#define ERR_DELAYED							-14
#define ERR_BLACKLISTED						-15
#define ERR_NORESPONSE						-16		// There was an error opening
#define ERR_BUFFER							-17
#define ERR_DIALUP_COM_PORT					-18		// There was an error opening
#define ERR_LOGIN_FAIL						-19		// Could not log in at ISP

#define ERR_CLOSING_COM_PORT				-20		// The COM port was not correctly closed
#define ERR_OFF_HOOK						-21		// The modem did not respond to the ATH0 command that instructs the modem to go off hook

#define ERR_SMTP_SENDER_REJECTED			-22		// The sender was rejected by the SMTP server
#define ERR_SMTP_RECIPIENT_REJECTED			-23		// The recipient was rejected by the SMTP server
#define ERR_SMTP_SERVER_DOWN				-24		// The SMTP server does not respond
#define ERR_SMTP_DATA_REJECTED				-25		// The data send by the terminal was not accepted by the SMTP server
#define ERR_SMTP_AUTH_FAILED				-42		// The username/password was rejected by the SMTP server or the server does not support "AUTH PLAIN"

#define ERR_POP_USER_REJECTED				-26		// The username was rejected by the POP server
#define ERR_POP_PASS_REJECTED				-27		// The password was rejected by the POP server
#define ERR_POP_SERVER_DOWN					-28		// The POP server does not respond

#define ERR_FTP_TEMP_ERROR					-29		// The FTP gives temporary error (try later)
#define ERR_FTP_NOT_LOGGED_IN				-30		// The user is not logged in
#define ERR_FTP_SERVER_DOWN					-31		// The FTP server does not respond
#define ERR_FTP_SYNTAX						-32		// The syntax of one of the command lines is wrong
#define ERR_FTP_NO_ACCOUNT					-33		// There is no account to login..

#define ERR_FTP_NO_CONNECTION				-34		// There is no connection

#define ERR_DNS_NO_RESPONSE					-35		// DNS servers didn't respond (both the primary as well as the secondary DNS server)
#define ERR_DNS_DATA_INVALID				-36		// The response of the DNS server wasn't in the correct format
#define ERR_DNS_NO_SERVERS_FOUND			-37		// The internet provider didn't provide the necessary IP-addresses of a DNS servers
#define ERR_DNS_NAME_ERROR					-38		// The DNS servers don't know the given IP or domain address

#define ERR_NTP_NO_RESPONSE					-39		// NTP server didn't respond
#define ERR_NTP_DATA_INVALID				-40		// The response of the NTP server wasn't in the correct format

#define ERR_INVALID_PORT_NUMBER				-41		// The choosen port number may not be used
#define ERR_PPP_RECEIVED					-42		// Checkstring received (unexpected) PPP packet
#define ERR_INVALID_MSS						-43		// The choosen maximum segment size is outside range of 40 < mss < 800


/* Define good states */
#define DIALUP_SUCCESS						0
#define FTP_SUCCESS							0
#define DISCONNECTED						0
#define EMAIL_SENT							0
#define EMAIL_RETRIEVED						0
#define FTP_DONE							0
#define DNS_OK								0
#define NTP_OK								0
#define IP_OK								0

#define FTP_INIT							0
#define FTP_PUT								20
#define FTP_GET								21
#define FTP_CWD								22
#define	FTP_LIST							23
#define FTP_DEL								24
#define FTP_REN								25
#define FTP_QUIT							27

#define POP_INIT							0
#define POP_GET								28
#define POP_QUIT							29

#define FTP_PUT_PASSIVE						30
#define FTP_GET_PASSIVE						31
#define FTP_LIST_PASSIVE					32


/* Log files */
#if OPH									// Log-files are always stored on RAM disk, because if the log files would be stored on flash disk,
	#define PPPLOG	"A:PPPlog.txt"		// would be stored on flash disk, some received data could be lost
	#define UIPLOG	"A:UIPlog.txt"		// while the interrupts are shortly disabled during the storage of communication data.
#else									// This could cause a lot of retransmissions and a very slow connection speed.
	#define PPPLOG	"PPPlog.txt"
	#define UIPLOG	"UIPlog.txt"		// All other terminals only have a RAM disk
#endif

#endif /*INTERNET_HDR*/

/* This file is generated by BUSMASTER */
/* VERSION [1.1] */
/* BUSMASTER VERSION [1.7.0] */
/* PROTOCOL [CAN] */

/* Start BUSMASTER include header */
#include <Windows.h>
#include <CANIncludes.h>

/* End BUSMASTER include header */


/* Start BUSMASTER global variable */
unsigned int counter_100ms = 0;

unsigned char _RADIO_ACTION = 0;
unsigned char _CLIMATE_ACTION = 0;
unsigned char _left_temp = 0;
unsigned char _right_temp = 0;
unsigned char _0=0;
unsigned char _1=0;
unsigned char _2=0;
unsigned char _3=0;
unsigned char _4=0;
unsigned char _5=0;
unsigned char _6=0;
unsigned char _7=0;
unsigned char _8=0;
unsigned char _9=0;
unsigned char _AUTO=0;
unsigned char _SCAN=0;
unsigned char _POWER=0;
unsigned char _TUNING=0;
unsigned char _MENU=0;
unsigned char _ENTER=0;
unsigned char _PHONE=0;
unsigned char _EXIT=0;
unsigned char _UP=0;
unsigned char _DOWN=0;
unsigned char _LEFT=0;
unsigned char _RIGHT=0;
unsigned char _AMFM=0;
unsigned char _EJECT=0;
unsigned char _MODE=0;

unsigned char killtx=0;

const unsigned char lut_o0_counter[]={0x00,0x40,0x80,0xC0};
const unsigned char lut_o0_counter2[]={0x00,0x20,0x80};
const unsigned char lut_o0_counter3[]={0xA0,0x20,0x20,0x20,0x20,0x20,0x80};
/* End BUSMASTER global variable */


/* Start BUSMASTER Function Prototype  */
GCC_EXTERN void GCC_EXPORT OnError_Warning_Limit(SCAN_ERR ErrorMsg);
GCC_EXTERN void GCC_EXPORT OnDLL_Load();
GCC_EXTERN void GCC_EXPORT OnDLL_Unload();
GCC_EXTERN void GCC_EXPORT OnBus_Connect();
GCC_EXTERN void GCC_EXPORT OnBus_Disconnect();
GCC_EXTERN void GCC_EXPORT OnTimer_timer1_50( );
GCC_EXTERN void GCC_EXPORT OnTimer_timer2_100( );
GCC_EXTERN void GCC_EXPORT OnTimer_timer3_200( );
GCC_EXTERN void GCC_EXPORT OnTimer_timer4_350( );
void Utils_ccm_msg_send_45ms_04A0409E(void);
void Utils_ccm_msg_send_50ms_05704000(void);
void Utils_ccm_msg_send_100ms_12404002(void);
void Utils_ccm_msg_send_200ms_1BD00004(void);
void Utils_ccm_msg_send_350ms_1C810066(void);
GCC_EXTERN void GCC_EXPORT OnKey_z(unsigned char KeyValue);
GCC_EXTERN void GCC_EXPORT OnKey_s(unsigned char KeyValue);
GCC_EXTERN void GCC_EXPORT OnKey_q(unsigned char KeyValue);
GCC_EXTERN void GCC_EXPORT OnKey_d(unsigned char KeyValue);
GCC_EXTERN void GCC_EXPORT OnKey_e(unsigned char KeyValue);
GCC_EXTERN void GCC_EXPORT OnKey_a(unsigned char KeyValue);
GCC_EXTERN void GCC_EXPORT OnKey_w(unsigned char KeyValue);
GCC_EXTERN void GCC_EXPORT OnKey_x(unsigned char KeyValue);
GCC_EXTERN void GCC_EXPORT OnTimer_timer0_45( );
/* End BUSMASTER Function Prototype  */

/* Start BUSMASTER generated function - OnError_Warning_Limit */
void OnError_Warning_Limit(SCAN_ERR ErrorMsg)
{
Trace("Warning Limit reached");
}/* End BUSMASTER generated function - OnError_Warning_Limit */
/* Start BUSMASTER generated function - OnDLL_Load */
void OnDLL_Load()
{
/* TODO: Define and Initialise the following variables*/

 EnableLogging();

}/* End BUSMASTER generated function - OnDLL_Load */
/* Start BUSMASTER generated function - OnDLL_Unload */
void OnDLL_Unload()
{
/* TODO */
}/* End BUSMASTER generated function - OnDLL_Unload */
/* Start BUSMASTER generated function - OnBus_Connect */
void OnBus_Connect()
{
Trace("Bus connected");
}/* End BUSMASTER generated function - OnBus_Connect */
/* Start BUSMASTER generated function - OnBus_Disconnect */
void OnBus_Disconnect()
{
Trace("Bus Disconnected");
}/* End BUSMASTER generated function - OnBus_Disconnect */
/* Start BUSMASTER generated function - OnTimer_timer1_50 */
void OnTimer_timer1_50( )
{
if(!killtx)Utils_ccm_msg_send_50ms_05704000();
}/* End BUSMASTER generated function - OnTimer_timer1_50 */
/* Start BUSMASTER generated function - OnTimer_timer2_100 */
void OnTimer_timer2_100( )
{
if(!killtx)Utils_ccm_msg_send_100ms_12404002();
}/* End BUSMASTER generated function - OnTimer_timer2_100 */
/* Start BUSMASTER generated function - OnTimer_timer3_200 */
void OnTimer_timer3_200( )
{
if(!killtx)Utils_ccm_msg_send_200ms_1BD00004();
}/* End BUSMASTER generated function - OnTimer_timer3_200 */
/* Start BUSMASTER generated function - OnTimer_timer4_350 */
void OnTimer_timer4_350( )
{
if(!killtx)Utils_ccm_msg_send_350ms_1C810066();
}/* End BUSMASTER generated function - OnTimer_timer4_350 */
/* Start BUSMASTER generated function - Utils_ccm_msg_send_45ms_04A0409E */
void Utils_ccm_msg_send_45ms_04A0409E(void)
{
STCAN_MSG sMsg;
unsigned char i = 0;
static char j = 0;
static char k = 0;
static unsigned char lsb1 = 0;
static unsigned char counter = 0;
if(j>=sizeof(lut_o0_counter)) j=0;
if(k>=sizeof(lut_o0_counter3)) k=0;

sMsg.id = 0x04A0409E;   // Message ID
sMsg.isExtended = TRUE; // Stwandard Message type
sMsg.isRtr = FALSE;     // Not RTR type
sMsg.dlc = 8;           // Length is 8 Bytes
sMsg.data[i++] = lut_o0_counter[j++];    // Lower 4 Bytes
sMsg.data[i++] = lsb1;
if(_RADIO_ACTION)
sMsg.data[i++] = lut_o0_counter3[k++];
else
sMsg.data[i++] = 0x00;
if(k==sizeof(lut_o0_counter3)){_RADIO_ACTION=0;_UP=0;_DOWN=0;_LEFT=0;_RIGHT=0;_MENU=0;_EXIT=0;_ENTER=0;_POWER=0;}
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.cluster = 1;
SendMsg(sMsg);

counter++;

//lsb1
if(!(counter%2)) lsb1 = 0x41;
else lsb1 = 0x01;
if(!(counter%22)) lsb1 |= 0x02;
else lsb1 &= (~0x02);
}/* End BUSMASTER generated function - Utils_ccm_msg_send_45ms_04A0409E */
/* Start BUSMASTER generated function - Utils_ccm_msg_send_50ms_05704000 */
void Utils_ccm_msg_send_50ms_05704000(void)
{
STCAN_MSG sMsg;
unsigned char i = 0;
static char j = 0;
static char k = 0;

static unsigned char _UP_PRE = 0;
static unsigned char _DOWN_PRE = 0;
static unsigned char _LEFT_PRE = 0;
static unsigned char _RIGHT_PRE = 0;

if(j>=sizeof(lut_o0_counter)) j=0;

if(!k && _EXIT==1){_EXIT=3;k++;}
else if(_EXIT==3)_EXIT=1;
else if(k && _EXIT==0)_EXIT=2;
else if(!k && _EXIT==2)_EXIT=0;

if(!k && _MENU==1){_MENU=3;k++;}
else if(_MENU==3)_MENU=1;
else if(k && _MENU==0)_MENU=2;
else if(!k && _MENU==2)_MENU=0;

if(!k && _ENTER==1){_ENTER=3;k++;}
else if(_ENTER==3)_ENTER=1;
else if(k && _ENTER==0)_ENTER=2;
else if(!k && _ENTER==2)_ENTER=0;

if(!k && _POWER==1){_POWER=3;k++;}
else if(_POWER==3)_POWER=1;
else if(k && _POWER==0)_POWER=2;
else if(!k && _POWER==2)_POWER=0;

sMsg.id = 0x05704000;   // Message ID
sMsg.isExtended = TRUE; // Standard Message type
sMsg.isRtr = FALSE;     // Not RTR type
sMsg.dlc = 8;           // Length is 8 Bytes
sMsg.data[i++] = lut_o0_counter[j++];    // Lower 4 Bytes
if(_UP_PRE != _UP || _DOWN_PRE != _DOWN || _LEFT_PRE != _LEFT || _RIGHT_PRE != _RIGHT)
sMsg.data[i++] = 0x01;
else
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = (_EXIT << 0) | (_MENU << 2) | (_POWER << 6);
sMsg.data[i++] = (_ENTER << 6);
sMsg.data[i++] = 0x00;
sMsg.data[i++] = (_UP << 0) | (_DOWN << 1) | (_LEFT << 2) | (_RIGHT << 3);
sMsg.cluster = 1;
SendMsg(sMsg);

if(k && !_RADIO_ACTION)k--;

_UP_PRE = _UP;
_DOWN_PRE = _DOWN;
_LEFT_PRE = _LEFT;
_RIGHT_PRE = _RIGHT;
}/* End BUSMASTER generated function - Utils_ccm_msg_send_50ms_05704000 */
/* Start BUSMASTER generated function - Utils_ccm_msg_send_100ms_12404002 */
void Utils_ccm_msg_send_100ms_12404002(void)
{
STCAN_MSG sMsg;
unsigned char i = 0;

sMsg.id = 0x12404002;   // Message ID
sMsg.isExtended = TRUE; // Standard Message type
sMsg.isRtr = FALSE;     // Not RTR type
sMsg.dlc = 8;           // Length is 8 Bytes
sMsg.data[i++] = _right_temp;// Lower 4 Bytes
sMsg.data[i++] = _left_temp;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x43;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.cluster = 1;
SendMsg(sMsg);
}/* End BUSMASTER generated function - Utils_ccm_msg_send_100ms_12404002 */
/* Start BUSMASTER generated function - Utils_ccm_msg_send_200ms_1BD00004 */
void Utils_ccm_msg_send_200ms_1BD00004(void)
{
STCAN_MSG sMsg;
unsigned char i = 0;
static char j = 0;
if(j>=4) j=0;

sMsg.id = 0x1BD00004;   // Message ID
sMsg.isExtended = TRUE; // Standard Message type
sMsg.isRtr = FALSE;     // Not RTR type
sMsg.dlc = 8;           // Length is 8 Bytes
sMsg.data[i++] = 0x00;  // Lower 4 Bytes
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
if(j++ >= 4)
sMsg.data[i++] = 0x02;
else
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x40;
sMsg.cluster = 1;
SendMsg(sMsg);
}/* End BUSMASTER generated function - Utils_ccm_msg_send_200ms_1BD00004 */
/* Start BUSMASTER generated function - Utils_ccm_msg_send_350ms_1C810066 */
void Utils_ccm_msg_send_350ms_1C810066(void)
{
STCAN_MSG sMsg;
unsigned char i = 0;
static char j = 0;
if(j>=sizeof(lut_o0_counter2)) j=0;

sMsg.id = 0x1C810066;   // Message ID
sMsg.isExtended = TRUE; // Standard Message type
sMsg.isRtr = FALSE;     // Not RTR type
sMsg.dlc = 8;           // Length is 8 Bytes
sMsg.data[i++] = 0x20;  // Lower 4 Bytes
sMsg.data[i++] = 0x09 | lut_o0_counter2[j++];
sMsg.data[i++] = 0xB8;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x7E;
sMsg.data[i++] = 0x26;
sMsg.data[i++] = 0x00;
sMsg.data[i++] = 0x00;
sMsg.cluster = 1;
SendMsg(sMsg);
}/* End BUSMASTER generated function - Utils_ccm_msg_send_350ms_1C810066 */
/* Start BUSMASTER generated function - OnKey_z */
void OnKey_z(unsigned char KeyValue)
{
if(!_UP){_UP=1;_RADIO_ACTION=1;}
Trace("Up");
}/* End BUSMASTER generated function - OnKey_z */
/* Start BUSMASTER generated function - OnKey_s */
void OnKey_s(unsigned char KeyValue)
{
if(!_DOWN){_DOWN=1;_RADIO_ACTION=1;}
Trace("Down");
}/* End BUSMASTER generated function - OnKey_s */
/* Start BUSMASTER generated function - OnKey_q */
void OnKey_q(unsigned char KeyValue)
{
if(!_LEFT){_LEFT=1;_RADIO_ACTION=1;}
Trace("Left");
}/* End BUSMASTER generated function - OnKey_q */
/* Start BUSMASTER generated function - OnKey_d */
void OnKey_d(unsigned char KeyValue)
{
if(!_RIGHT){_RIGHT=1;_RADIO_ACTION=1;}
Trace("Right");
}/* End BUSMASTER generated function - OnKey_d */
/* Start BUSMASTER generated function - OnKey_e */
void OnKey_e(unsigned char KeyValue)
{
if(!_ENTER){_ENTER=1;_RADIO_ACTION=1;}
Trace("Enter");
}/* End BUSMASTER generated function - OnKey_e */
/* Start BUSMASTER generated function - OnKey_a */
void OnKey_a(unsigned char KeyValue)
{
if(!_EXIT){_EXIT=1;_RADIO_ACTION=1;}
Trace("Exit");
}/* End BUSMASTER generated function - OnKey_a */
/* Start BUSMASTER generated function - OnKey_w */
void OnKey_w(unsigned char KeyValue)
{
if(!_MENU){_MENU=1;_RADIO_ACTION=1;}
Trace("Menu");
}/* End BUSMASTER generated function - OnKey_w */
/* Start BUSMASTER generated function - OnKey_x */
void OnKey_x(unsigned char KeyValue)
{
if(!_POWER){_POWER=1;_RADIO_ACTION=1;}
Trace("Power");
}/* End BUSMASTER generated function - OnKey_x */
/* Start BUSMASTER generated function - OnTimer_timer0_45 */
void OnTimer_timer0_45( )
{
if(!killtx)Utils_ccm_msg_send_45ms_04A0409E();
}/* End BUSMASTER generated function - OnTimer_timer0_45 */

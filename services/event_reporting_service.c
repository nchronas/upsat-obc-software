#include "event_Reporting_service.h"

#undef __FILE_ID__
#define __FILE_ID__ 666

SAT_returnState event_crt_pkt_api(uint8_t *buf, char *f, int fi, int l, char *e, uint16_t *size, SAT_returnState mode) {

	uint8_t sub_type;
	uint8_t res_crc;

	if(mode == SATR_OK) { sub_type = TM_EV_NORMAL_REPORT; }
	else { sub_type = TM_EV_ERROR_REPORT; }

	buf[0] = HLDLC_START_FLAG;
	buf[1] = ox08;
	buf[2] = SYSTEM_APP_ID;
	buf[3] = 0xC0;
	buf[4] = 0;
	buf[5] = 0;
	buf[6] = 5;
    buf[7] = 16;
    buf[8] = TC_EVENT_SERVICE;
    buf[9] = sub_type;
    buf[10] = DBG_APP_ID;

	sprintf((char*)&buf[11], "Assertion failed %s,%d,%d,%s\n", f, fi, l, e);
	*size = strnlen(&buf[11], 200);
    *size += 11 + 1;
    buf[*size] = 0;

	checkSum(buf, *size, &res_crc);
    buf[(*size)+1] = res_crc;
    buf[(*size)+2] = HLDLC_START_FLAG;

	return SATR_OK;
}

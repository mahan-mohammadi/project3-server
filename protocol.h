#ifndef PROTOCOL_H
#define PROTOCOL_H


string protocolMap[] = {
	"REG",
	"LOG",
	"MSG",
	"WHO"
};

enum Protocol {
	REG , LOG , MSG , WHO , UNAMECHECK , UNAMEANSWER ,  PHONECHECK , PHONEANSWER
};

#endif

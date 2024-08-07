
static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b00000000, //
    0b00000111, 0b11100000, //      ######
    0b00011111, 0b11111000, //    ##########
    0b00111111, 0b11111100, //   ############
    0b01110000, 0b00001110, //  ###        ###
    0b01100111, 0b11100110, //  ##  ######  ##
    0b00001111, 0b11110000, //     ########
    0b00011000, 0b00011000, //    ##      ##
    0b00000011, 0b11000000, //       ####
    0b00000111, 0b11100000, //      ######
    0b00000100, 0b00100000, //      #    #
    0b00000001, 0b10000000, //        ##
    0b00000001, 0b10000000, //        ##
    0b00000000, 0b00000000, //
    0b00000000, 0b00000000, //
    0b00000000, 0b00000000,  };

static unsigned char PROGMEM dropsign[] =
{ 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xfd, 0xbf, 0xff, 
0xff, 0xf9, 0x9f, 0xff, 0xff, 0xf3, 0xcf, 0xff, 0xff, 0xf7, 0xef, 0xff, 0xff, 0xe7, 0xe7, 0xff, 
0xff, 0xef, 0xf7, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0x9f, 0xf9, 0xff, 0xff, 0xbf, 0xfd, 0xff, 
0xff, 0x3f, 0xfc, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xfe, 0x7f, 0xfe, 0x7f, 0xfe, 0xff, 0xff, 0x7f, 
0xfe, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0xff, 0x3f, 0xfc, 0xcf, 0xff, 0x3f, 0xfd, 0xdf, 0xff, 0xbf, 
0xfd, 0xdf, 0xff, 0xbf, 0xfd, 0xdf, 0xff, 0xbf, 0xfd, 0xdf, 0xff, 0xbf, 0xfc, 0xcf, 0xff, 0x3f, 
0xfc, 0xef, 0xff, 0x3f, 0xfe, 0xef, 0xff, 0x7f, 0xfe, 0x7f, 0xfe, 0x7f, 0xff, 0x3f, 0xfc, 0xff, 
0xff, 0x9f, 0xf9, 0xff, 0xff, 0xc7, 0xe3, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff };

static unsigned char PROGMEM tap[] =
{
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xf0, 0x1f, 0xee, 0xff, 0xee, 0x7f, 0xe0, 0x1f, 
0xe0, 0x0f, 0xe4, 0x07, 0xef, 0xc7, 0xff, 0xc7, 0xff, 0xff, 0xff, 0xff
};
static unsigned char PROGMEM splashlogo[] =
{
 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0x3f, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x37, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0x37, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x37, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0x30, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x30, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 
	0xff, 0x30, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x30, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
	0xff, 0x30, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x30, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
	0xff, 0x30, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x30, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
	0xff, 0x30, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x37, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xff, 
	0xff, 0x07, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xff, 
	0xff, 0x1f, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x7f, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xf8, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 
	0xff, 0xf9, 0xfc, 0xff, 0x7f, 0xbf, 0xdf, 0xff, 0xff, 0xe0, 0x70, 0x3c, 0x1e, 0x0f, 0x07, 0xff, 
	0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x8f, 0x07, 0x81, 0xc0, 0xe0, 0x70, 0xff, 
	0xff, 0xf1, 0xf8, 0x7e, 0x3f, 0x1f, 0x8f, 0xff, 0xff, 0xc0, 0x20, 0x18, 0x0c, 0x06, 0x03, 0xff, 
	0xff, 0x84, 0x03, 0x00, 0x80, 0x40, 0x20, 0xff, 0xff, 0x8f, 0x8f, 0xc3, 0xe1, 0xf0, 0xf8, 0xff

};
static unsigned char PROGMEM splashlogo2[] =
{
 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 0xff, 0xfb, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xbd, 0xbf, 0xc3, 0xe7, 0x1f, 0xff, 0xff, 0xff, 0xbd, 0xbd, 0x83, 0x06, 0x0f, 0xff, 
	0xff, 0xff, 0x81, 0xd9, 0x3b, 0x3d, 0xef, 0xff, 0xff, 0xff, 0x81, 0xdb, 0x7b, 0x7d, 0xef, 0xff, 
	0xff, 0xff, 0xbd, 0xc3, 0x7b, 0x7d, 0xef, 0xff, 0xff, 0xff, 0xbd, 0xe7, 0x7b, 0x7c, 0xef, 0xff, 
	0xff, 0xff, 0xbd, 0xef, 0x83, 0x7e, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xef, 0xdf, 0xff, 0x3f, 0xff, 
	0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbb, 0xc7, 0xcf, 0x8f, 0x1f, 0xff, 
	0xff, 0xff, 0xbf, 0x93, 0x07, 0x2e, 0x4f, 0xff, 0xff, 0xff, 0x9f, 0x3b, 0x72, 0xfc, 0xef, 0xff, 
	0xff, 0xff, 0xe3, 0x47, 0x7a, 0x7d, 0x1f, 0xff, 0xff, 0xff, 0xf9, 0x1f, 0x7b, 0x8c, 0x7f, 0xff, 
	0xff, 0xff, 0xb9, 0x7f, 0x7b, 0xe5, 0xff, 0xff, 0xff, 0xff, 0x83, 0x83, 0x73, 0x0e, 0x0f, 0xff, 
	0xff, 0xff, 0xef, 0xc7, 0xff, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

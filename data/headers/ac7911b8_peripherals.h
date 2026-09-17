/* JieLi AC7911B8 / WL82 Peripheral Structures */



typedef struct {
    volatile const unsigned int SOFT_INT;
    volatile unsigned int SOFT_SET;
    volatile unsigned int SOFT_CLR;
    volatile unsigned int CON;
} JL_CMNG_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int KEY;
} JL_SDTAP_TypeDef;

typedef struct {
    volatile unsigned int MBISTCTL;
    volatile const unsigned int MBISTSOGO;
} JL_MBIS_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int PAGE_END;
} JL_HMEM_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int CADR;
    volatile unsigned int CONST;
    volatile unsigned int TEST1;
} JL_FFT_TypeDef;

typedef struct {
    volatile unsigned int C0_CON;
    volatile unsigned int C1_CON;
    volatile unsigned int CACHE_CON;
    volatile unsigned int DCACHE_WAY;
    volatile unsigned int ICACHE_WAY;
    volatile unsigned int RING_OSC;
    volatile const unsigned int REV_80_3[0x80 - 0x5 - 1];
    volatile unsigned int C0_IF_UACNTL;
    volatile unsigned int C0_IF_UACNTH;
    volatile unsigned int C0_RD_UACNTL;
    volatile unsigned int C0_RD_UACNTH;
    volatile unsigned int C0_WR_UACNTL;
    volatile unsigned int C0_WR_UACNTH;
    volatile unsigned int C0_TL_CKCNTL;
    volatile unsigned int C0_TL_CKCNTH;
    volatile unsigned int C1_IF_UACNTL;
    volatile unsigned int C1_IF_UACNTH;
    volatile unsigned int C1_RD_UACNTL;
    volatile unsigned int C1_RD_UACNTH;
    volatile unsigned int C1_WR_UACNTL;
    volatile unsigned int C1_WR_UACNTH;
    volatile unsigned int C1_TL_CKCNTL;
    volatile unsigned int C1_TL_CKCNTH;
    volatile unsigned int DBG_WR_EN;
    volatile const unsigned int DBG_MSG;
    volatile unsigned int DBG_MSG_CLR;
    volatile const unsigned int REV_9c_92[0xa0 - 0x92 - 1];
    volatile unsigned int WR_LIMIT0_H;
    volatile unsigned int WR_LIMIT1_H;
    volatile unsigned int WR_LIMIT2_H;
    volatile unsigned int WR_LIMIT3_H;
    volatile unsigned int WR_LIMIT4_H;
    volatile unsigned int WR_LIMIT5_H;
    volatile unsigned int WR_LIMIT6_H;
    volatile unsigned int WR_LIMIT7_H;
    volatile const unsigned int REV_b0_a7[0xb0 - 0xa7 - 1];
    volatile unsigned int WR_LIMIT0_L;
    volatile unsigned int WR_LIMIT1_L;
    volatile unsigned int WR_LIMIT2_L;
    volatile unsigned int WR_LIMIT3_L;
    volatile unsigned int WR_LIMIT4_L;
    volatile unsigned int WR_LIMIT5_L;
    volatile unsigned int WR_LIMIT6_L;
    volatile unsigned int WR_LIMIT7_L;
    volatile const unsigned int REV_c0_b7[0xc0 - 0xb7 - 1];
    volatile unsigned int WR_ALLOW_ID0;
    volatile unsigned int WR_ALLOW_ID1;
    volatile unsigned int WR_ALLOW_ID2;
    volatile unsigned int WR_ALLOW_ID3;
    volatile unsigned int WR_ALLOW_ID4;
    volatile unsigned int WR_ALLOW_ID5;
    volatile unsigned int WR_ALLOW_ID6;
    volatile unsigned int WR_ALLOW_ID7;
    volatile const unsigned int REV_d0_c7[0xd0 - 0xc7 - 1];
    volatile unsigned int DBG_EN;
    volatile unsigned int DBG_CON;
    volatile unsigned int C0_WR_LIMIT_EN;
    volatile unsigned int C1_WR_LIMIT_EN;
    volatile unsigned int PRP_WR_LIMIT_EN;
    volatile unsigned int PRP_WR_ALLOW_EN;
    volatile unsigned int PRP_OUTLIM_ERR_EN;
    volatile const unsigned int REV_d8_d5[0xd8 - 0xd6 - 1];
    volatile const unsigned int C0_WR_LIMIT_ERR_NUM;
    volatile const unsigned int C1_WR_LIMIT_ERR_NUM;
    volatile const unsigned int PRP_WR_LIMIT_ERR_NUM;
    volatile const unsigned int PRP_WR_LIMIT_ID;
    volatile const unsigned int AXI_RD_INV_ID;
    volatile const unsigned int AXI_WR_INV_ID;
    volatile const unsigned int PRP_MMU_ERR_WID;
    volatile const unsigned int PRP_MMU_ERR_RID;
    volatile const unsigned int REV_e0_de[0xe0 - 0xdf - 1];
    volatile unsigned int PC_LIMIT0_H;
    volatile unsigned int PC_LIMIT0_L;
    volatile unsigned int PC_LIMIT1_H;
    volatile unsigned int PC_LIMIT1_L;
} JL_TypeDef_corex2;

typedef struct {
    volatile const unsigned int DR00;
    volatile const unsigned int DR01;
    volatile const unsigned int DR02;
    volatile const unsigned int DR03;
    volatile const unsigned int DR04;
    volatile const unsigned int DR05;
    volatile const unsigned int DR06;
    volatile const unsigned int DR07;
    volatile const unsigned int DR08;
    volatile const unsigned int DR09;
    volatile const unsigned int DR10;
    volatile const unsigned int DR11;
    volatile const unsigned int DR12;
    volatile const unsigned int DR13;
    volatile const unsigned int DR14;
    volatile const unsigned int DR15;
    volatile const unsigned int RETI;
    volatile const unsigned int RETE;
    volatile const unsigned int RETX;
    volatile const unsigned int RETS;
    volatile const unsigned int SR04;
    volatile const unsigned int PSR;
    volatile const unsigned int CNUM;
    volatile const unsigned int SR07;
    volatile const unsigned int SR08;
    volatile const unsigned int SR09;
    volatile const unsigned int SR10;
    volatile const unsigned int ICFG;
    volatile const unsigned int USP;
    volatile const unsigned int SSP;
    volatile const unsigned int SP;
    volatile const unsigned int PCRS;
    volatile unsigned int BPCON;
    volatile unsigned int BSP;
    volatile unsigned int BP0;
    volatile unsigned int BP1;
    volatile unsigned int BP2;
    volatile unsigned int BP3;
    volatile unsigned int CMD_PAUSE;
    volatile const unsigned int REV_30_26[0x30 - 0x26 - 1];
    volatile unsigned int PMU_CON;
    volatile const unsigned int REV_34_30[0x34 - 0x30 - 1];
    volatile unsigned int EMU_CON;
    volatile unsigned int EMU_MSG;
    volatile unsigned int EMU_SSP_H;
    volatile unsigned int EMU_SSP_L;
    volatile unsigned int EMU_USP_H;
    volatile unsigned int EMU_USP_L;
    volatile const unsigned int REV_3b_39[0x3b - 0x39 - 1];
    volatile unsigned char TTMR_CON;
    unsigned char reserved_1_TTMR_CON;
    unsigned char reserved_2_TTMR_CON;
    unsigned char reserved_3_TTMR_CON;
    volatile unsigned int TTMR_CNT;
    volatile unsigned int TTMR_PRD;
    volatile unsigned int BANK_CON;
    volatile unsigned int BANK_NUM;
    volatile unsigned int ICFG00;
    volatile unsigned int ICFG01;
    volatile unsigned int ICFG02;
    volatile unsigned int ICFG03;
    volatile unsigned int ICFG04;
    volatile unsigned int ICFG05;
    volatile unsigned int ICFG06;
    volatile unsigned int ICFG07;
    volatile unsigned int ICFG08;
    volatile unsigned int ICFG09;
    volatile unsigned int ICFG10;
    volatile unsigned int ICFG11;
    volatile unsigned int ICFG12;
    volatile unsigned int ICFG13;
    volatile unsigned int ICFG14;
    volatile unsigned int ICFG15;
    volatile unsigned int ICFG16;
    volatile unsigned int ICFG17;
    volatile unsigned int ICFG18;
    volatile unsigned int ICFG19;
    volatile unsigned int ICFG20;
    volatile unsigned int ICFG21;
    volatile unsigned int ICFG22;
    volatile unsigned int ICFG23;
    volatile unsigned int ICFG24;
    volatile unsigned int ICFG25;
    volatile unsigned int ICFG26;
    volatile unsigned int ICFG27;
    volatile unsigned int ICFG28;
    volatile unsigned int ICFG29;
    volatile unsigned int ICFG30;
    volatile unsigned int ICFG31;
    volatile const unsigned int IPND0;
    volatile const unsigned int IPND1;
    volatile const unsigned int IPND2;
    volatile const unsigned int IPND3;
    volatile const unsigned int IPND4;
    volatile const unsigned int IPND5;
    volatile const unsigned int IPND6;
    volatile const unsigned int IPND7;
    volatile unsigned int ILAT_SET;
    volatile unsigned int ILAT_CLR;
    volatile unsigned int IPMASK;
    volatile const unsigned int REV_70_6a[0x70 - 0x6a - 1];
    volatile unsigned int ETM_CON;
    volatile const unsigned int ETM_PC0;
    volatile const unsigned int ETM_PC1;
    volatile const unsigned int ETM_PC2;
    volatile const unsigned int ETM_PC3;
    volatile unsigned int WP0_ADRH;
    volatile unsigned int WP0_ADRL;
    volatile unsigned int WP0_DATH;
    volatile unsigned int WP0_DATL;
    volatile unsigned int WP0_PC;
} JL_TypeDef_q32DSP;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int BAUD;
    volatile unsigned int CODE;
    volatile unsigned int BASE_ADR;
} JL_SFC_TypeDef;

typedef struct {
    volatile unsigned char CON;
    unsigned char reserved_1_CON;
    unsigned char reserved_2_CON;
    unsigned char reserved_3_CON;
    volatile unsigned short KEY;
    unsigned short reserved_1_KEY;
    volatile unsigned int UNENC_ADRH;
    volatile unsigned int UNENC_ADRL;
    volatile unsigned int LENC_ADRH;
    volatile unsigned int LENC_ADRL;
} JL_SFCENC_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int CON2;
    volatile unsigned int CON3;
    volatile unsigned int CON4;
    volatile unsigned int CON5;
    volatile unsigned int CON6;
    volatile unsigned int CON7;
    volatile unsigned int CON8;
    volatile unsigned int CON9;
    volatile unsigned int CON10;
    volatile unsigned int CON11;
    volatile unsigned int CON12;
    volatile unsigned int CON13;
    volatile unsigned int DBG_INFO;
    volatile unsigned int DBG_START;
    volatile unsigned int DBG_END;
    volatile unsigned int DBG_ADR;
} JL_SDR_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int BAUD;
    volatile unsigned int QUCNT;
} JL_PSRAM_TypeDef;

typedef struct {
    volatile unsigned int MBISTCTLH;
    volatile const unsigned int MBISTSOGOH;
} JL_MBISTH_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int DATIN;
    volatile unsigned int KEY;
    volatile unsigned int ENCRES0;
    volatile unsigned int ENCRES1;
    volatile unsigned int ENCRES2;
    volatile unsigned int ENCRES3;
    volatile unsigned int DECRES0;
    volatile unsigned int DECRES1;
    volatile unsigned int DECRES2;
    volatile unsigned int DECRES3;
} JL_AES_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int ADR;
} JL_DCP_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int CON2;
    volatile unsigned int ADR;
    volatile unsigned int CNT;
} JL_EMI_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int CON2;
    volatile unsigned int YUVLINE;
    volatile unsigned int YDCVAL;
    volatile unsigned int UDCVAL;
    volatile unsigned int VDCVAL;
    volatile unsigned int YPTR;
    volatile unsigned int UPTR;
    volatile unsigned int VPTR;
    volatile unsigned int BADDR;
    volatile unsigned int BCNT;
    volatile unsigned int MCUCNT;
    volatile unsigned int PRECNT;
    volatile unsigned int HQTBLADR;
    volatile unsigned int HQTBLDAT;
    volatile unsigned int PTR_NUM;
    volatile unsigned int HAS_PTR;
    volatile unsigned int MCU_BUF;
} JL_JPG_TypeDef;

typedef struct {
    volatile unsigned int COM_CON;
    volatile unsigned int PND_CON;
    volatile unsigned int PND_CLR;
    volatile unsigned int RCV_CON;
    volatile unsigned int RCV_VTT;
    volatile unsigned int RCV_VBLK;
    volatile unsigned int RCV_VACT;
    volatile unsigned int RCV_HTT;
    volatile unsigned int RCV_HBLK;
    volatile unsigned int RCV_HACT;
    volatile unsigned int FRC_CON;
    volatile unsigned int OSD_CON;
    volatile unsigned int OSD_BASE;
    volatile unsigned int OSD_H_CFG;
    volatile unsigned int OSD_V_CFG;
    volatile unsigned int OSD_COLOR;
    volatile unsigned int DMA_CON;
    volatile unsigned int DMA_CNT;
    volatile unsigned int DMA_BASE0_Y;
    volatile unsigned int DMA_BASE0_U;
    volatile unsigned int DMA_BASE0_V;
    volatile unsigned int DMA_BASE1_Y;
    volatile unsigned int DMA_BASE1_U;
    volatile unsigned int DMA_BASE1_V;
} JL_ISC_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int WR_ALLOW_ID0;
    volatile unsigned int WR_ALLOW_ID1;
    volatile unsigned int LIMIT_H;
    volatile unsigned int LIMIT_L;
    volatile unsigned int WR_LIMIT_ID;
} JL_DBG_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int CON2;
    volatile unsigned int CON3;
    volatile unsigned int LD_START_ADR;
    volatile unsigned int DEBUG_PIXEL;
    volatile unsigned int SPI_CON0;
    volatile unsigned short SPI_BAUD;
    unsigned short reserved_1_SPI_BAUD;
    volatile unsigned int SPI_BUF;
    volatile unsigned int PAP_CON0;
    volatile unsigned int PAP_PRD;
    volatile unsigned int PAP_BUF;
    volatile unsigned int RGB_CON0;
    volatile unsigned int RGB_HPRD;
    volatile unsigned int RGB_VPRD;
} JL_IMD_TypeDef;

typedef struct {
    volatile unsigned int OUT;
    volatile const unsigned int IN;
    volatile unsigned int DIR;
    volatile unsigned int DIE;
    volatile unsigned int PU;
    volatile unsigned int PD;
    volatile unsigned int HD0;
    volatile unsigned int HD;
    volatile unsigned int DIEH;
} JL_PORT_FLASH_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int CON2;
} JL_USB_IO_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int CON2;
    volatile unsigned int CON3;
} JL_WAKEUP_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int CON2;
    volatile unsigned int CON3;
    volatile unsigned int CON4;
    volatile unsigned int CON5;
    volatile unsigned int CON6;
    volatile unsigned int CON7;
    volatile unsigned int CON8;
} JL_IOMAP_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile   unsigned int RESERVED[1];
    volatile unsigned int SEG_IOEN0;
    volatile unsigned int SEG_IOEN1;
} JL_LCDC_TypeDef;

typedef struct {
    volatile unsigned int CON;
} JL_POWER_TypeDef;

typedef struct {
    volatile unsigned int PWR_CON;
    volatile unsigned int RESERVED0;
    volatile unsigned int SYS_DIV;
    volatile unsigned int CLK_CON0;
    volatile unsigned int CLK_CON1;
    volatile unsigned int CLK_CON2;
    volatile unsigned int CLK_CON3;
} JL_CLOCK_TypeDef;

typedef struct {
    volatile unsigned int RST_SRC;
} JL_SYSTEM_TypeDef;

typedef struct {
    volatile unsigned int CON;
} JL_MODE_TypeDef;

typedef struct {
    volatile unsigned int CHIP_ID;
} JL_INTEST_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int CNT;
    volatile unsigned int PRD;
    volatile unsigned int PWM;
} JL_TIMER_TypeDef;

typedef struct {
    volatile unsigned char CON;
    unsigned char reserved_1_CON;
    unsigned char reserved_2_CON;
    unsigned char reserved_3_CON;
    volatile unsigned int VAL;
} JL_PCNT_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int NUM;
} JL_GPCNT_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int CON2;
    volatile unsigned int CPTR;
    volatile unsigned int DPTR;
    volatile unsigned int CTU_CON;
    volatile unsigned int CTU_CNT;
} JL_SD_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int ADR;
    volatile unsigned int RESULT0;
    volatile unsigned int RESULT1;
    volatile unsigned int RESULT2;
    volatile unsigned int RESULT3;
    volatile unsigned int RESULT4;
    volatile unsigned int RESULT5;
    volatile unsigned int RESULT6;
    volatile unsigned int RESULT7;
} JL_SHA_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int EP0_CNT;
    volatile unsigned int EP1_CNT;
    volatile unsigned int EP2_CNT;
    volatile unsigned int EP3_CNT;
    volatile unsigned int EP0_ADR;
    volatile unsigned int EP1_TADR;
    volatile unsigned int EP1_RADR;
    volatile unsigned int EP2_TADR;
    volatile unsigned int EP2_RADR;
    volatile unsigned int EP3_TADR;
    volatile unsigned int EP3_RADR;
    volatile unsigned int EP4_CNT;
    volatile unsigned int EP4_TADR;
    volatile unsigned int EP4_RADR;
} JL_USB_TypeDef;

typedef struct {
    volatile unsigned int WLA_CON0;
    volatile unsigned int WLA_CON1;
    volatile unsigned int WLA_CON2;
    volatile unsigned int WLA_CON3;
    volatile unsigned int WLA_CON4;
    volatile unsigned int WLA_CON5;
    volatile unsigned int WLA_CON6;
    volatile unsigned int WLA_CON7;
    volatile unsigned int WLA_CON8;
    volatile unsigned int WLA_CON9;
    volatile unsigned int WLA_CON10;
    volatile unsigned int WLA_CON11;
    volatile unsigned int WLA_CON12;
    volatile unsigned int WLA_CON13;
    volatile unsigned int WLA_CON14;
    volatile unsigned int WLA_CON15;
    volatile unsigned int WLA_CON16;
    volatile unsigned int WLA_CON17;
    volatile unsigned int WLA_CON18;
    volatile unsigned int WLA_CON19;
    volatile unsigned int WLA_CON20;
    volatile unsigned int WLA_CON21;
    volatile unsigned int WLA_CON22;
    volatile unsigned int WLA_CON23;
    volatile unsigned int WLA_CON24;
    volatile unsigned int WLA_CON25;
    volatile unsigned int WLA_CON26;
    volatile unsigned int WLA_CON27;
    volatile unsigned int WLA_CON28;
    volatile unsigned int WLA_CON29;
    volatile unsigned int WLA_CON30;
    volatile const unsigned int WLA_CON31;
    volatile const unsigned int WLA_CON32;
    volatile const unsigned int WLA_CON33;
    volatile const unsigned int WLA_CON34;
    volatile const unsigned int WLA_CON35;
    volatile const unsigned int WLA_CON36;
    volatile const unsigned int WLA_CON37;
    volatile const unsigned int WLA_CON38;
    volatile const unsigned int WLA_CON39;
    volatile unsigned int PLL_CON0;
    volatile unsigned int PLL_CON1;
    volatile unsigned int PLL2_CON0;
    volatile unsigned int PLL2_CON1;
    volatile const   unsigned int RESERVED0[0x30 - 0x2b - 1];
    volatile unsigned int DAA_CON0;
    volatile unsigned int DAA_CON1;
    volatile unsigned int DAA_CON2;
    volatile unsigned int DAA_CON3;
    volatile const   unsigned int RESERVED1[0x37 - 0x33 - 1];
    volatile unsigned int DAA_CON7;
    volatile unsigned int ADA_CON0;
    volatile unsigned int ADA_CON1;
    volatile unsigned int ADA_CON2;
} JL_ANA_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int BAUD;
    volatile unsigned int BUF;
    volatile unsigned int ADR;
    volatile unsigned int CNT;
} JL_SPI_TypeDef;

typedef struct {
    volatile unsigned short CON0;
    unsigned short reserved_1_CON0;
    volatile unsigned short CON1;
    unsigned short reserved_1_CON1;
    volatile unsigned short BAUD;
    unsigned short reserved_1_BAUD;
    volatile unsigned char BUF;
    unsigned char reserved_1_BUF;
    unsigned char reserved_2_BUF;
    unsigned char reserved_3_BUF;
    volatile unsigned int OTCNT;
    volatile unsigned int TXADR;
    volatile unsigned short TXCNT;
    unsigned short reserved_1_TXCNT;
    volatile unsigned int RXSADR;
    volatile unsigned int RXEADR;
    volatile unsigned int RXCNT;
    volatile const unsigned short HRXCNT;
    unsigned short reserved_1_HRXCNT;
} JL_UART_TypeDef;

typedef struct {
    volatile unsigned short CON0;
    unsigned short reserved_1_CON0;
    volatile unsigned char BUF;
    unsigned char reserved_1_BUF;
    unsigned char reserved_2_BUF;
    unsigned char reserved_3_BUF;
    volatile unsigned char BAUD;
    unsigned char reserved_1_BAUD;
    unsigned char reserved_2_BAUD;
    unsigned char reserved_3_BAUD;
    volatile unsigned short CON1;
    unsigned short reserved_1_CON1;
} JL_IIC_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int DAT0;
    volatile unsigned int DAT1;
    volatile unsigned int BUF;
    volatile unsigned int ADR;
    volatile unsigned int CNT;
} JL_PAP_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile const unsigned int SR_CNT;
    volatile unsigned int IO_CON;
    volatile unsigned int DMA_CON;
    volatile unsigned int DMA_LEN;
    volatile unsigned int DAT_ADR;
    volatile unsigned int INF_ADR;
    volatile const unsigned int CSB0;
    volatile const unsigned int CSB1;
    volatile const unsigned int CSB2;
    volatile const unsigned int CSB3;
    volatile const unsigned int CSB4;
    volatile const unsigned int CSB5;
} JL_SS_TypeDef;

typedef struct {
    volatile unsigned char CON;
    unsigned char reserved_1_CON;
    unsigned char reserved_2_CON;
    unsigned char reserved_3_CON;
    volatile unsigned char DAT;
    unsigned char reserved_1_DAT;
    unsigned char reserved_2_DAT;
    unsigned char reserved_3_DAT;
} JL_RDEC_TypeDef;

typedef struct {
    volatile unsigned short CON;
    unsigned short reserved_1_CON;
    volatile unsigned char SMR;
    unsigned char reserved_1_SMR;
    unsigned char reserved_2_SMR;
    unsigned char reserved_3_SMR;
    volatile unsigned int ADR;
    volatile unsigned int LEN;
} JL_PLNK_TypeDef;

typedef struct {
    volatile unsigned short CON0;
    unsigned short reserved_1_CON0;
    volatile unsigned short CON1;
    unsigned short reserved_1_CON1;
    volatile unsigned char CON2;
    unsigned char reserved_1_CON2;
    unsigned char reserved_2_CON2;
    unsigned char reserved_3_CON2;
    volatile unsigned char CON3;
    unsigned char reserved_1_CON3;
    unsigned char reserved_2_CON3;
    unsigned char reserved_3_CON3;
    volatile unsigned int ADR0;
    volatile unsigned int ADR1;
    volatile unsigned int ADR2;
    volatile unsigned int ADR3;
    volatile unsigned short LEN;
    unsigned short reserved_1_LEN;
} JL_ALNK_TypeDef;

typedef struct {
    volatile unsigned int DAC_CON;
    volatile unsigned int DAC_ADR;
    volatile unsigned short DAC_LEN;
    unsigned short reserved_1_DAC_LEN;
    volatile unsigned short DAC_PNS;
    unsigned short reserved_1_DAC_PNS;
    volatile unsigned short DAC_HRP;
    unsigned short reserved_1_DAC_HRP;
    volatile unsigned short DAC_SWP;
    unsigned short reserved_1_DAC_SWP;
    volatile unsigned short DAC_SWN;
    unsigned short reserved_1_DAC_SWN;
    volatile const unsigned int RESERVED7;
    volatile unsigned int DAC_VL0;
    volatile unsigned int DAC_VL1;
    volatile unsigned int DAC_TM0;
    volatile unsigned int DAC_TM1;
    volatile unsigned short DAC_DTV;
    unsigned short reserved_1_DAC_DTV;
    volatile unsigned short DAC_DTB;
    unsigned short reserved_1_DAC_DTB;
    volatile const unsigned int RESERVEDe;
    volatile unsigned short DAC_COP;
    unsigned short reserved_1_DAC_COP;
    volatile unsigned int ADC_CON;
    volatile unsigned int ADC_ADR;
    volatile unsigned short ADC_LEN;
    unsigned short reserved_1_ADC_LEN;
    volatile unsigned short ADC_PNS;
    unsigned short reserved_1_ADC_PNS;
    volatile unsigned short ADC_HWP;
    unsigned short reserved_1_ADC_HWP;
    volatile unsigned short ADC_SRP;
    unsigned short reserved_1_ADC_SRP;
    volatile unsigned short ADC_SRN;
    unsigned short reserved_1_ADC_SRN;
} JL_AUDIO_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int KEY;
    volatile unsigned int ADR;
} JL_ENC_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile const unsigned int RES;
} JL_ADC_TypeDef;

typedef struct {
    volatile unsigned int RFLT_CON;
} JL_IR_TypeDef;

typedef struct {
    volatile unsigned int CON;
} JL_OSA_TypeDef;

typedef struct {
    volatile unsigned int FIFO;
    volatile unsigned int REG;
} JL_CRC_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile unsigned int NUM;
} JL_LRCT_TypeDef;

typedef struct {
    volatile unsigned int CON;
    volatile const   unsigned int RESERVED[8 - 0 - 1];
    volatile unsigned int ME;
} JL_EFUSE_TypeDef;

typedef struct {
    volatile const unsigned int R64L;
    volatile const unsigned int R64H;
} JL_RAND_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile const unsigned int RES;
} JL_CTM_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int DEC_SRC_ADR;
    volatile unsigned int DEC_DST_ADR;
    volatile unsigned int DEC_PCM_WCNT;
    volatile unsigned int DEC_INBUF_LEN;
    volatile unsigned int ENC_SRC_ADR;
    volatile unsigned int ENC_DST_ADR;
    volatile const unsigned int DEC_DST_BASE;
} JL_SBC_TypeDef;

typedef struct {
    volatile unsigned int PMU_CON;
    volatile unsigned int RTC_CON;
    volatile unsigned int SPI_CON;
    volatile unsigned int SPI_DAT;
} JL_P33_TypeDef;

typedef struct {
    volatile unsigned int PRI0;
    volatile unsigned int PRI1;
    volatile unsigned int PRI2;
    volatile unsigned int PRI3;
    volatile unsigned int PRI4;
    unsigned int RESERVED0[0x08 - 0x04 - 1];
    volatile unsigned int MSG;
    volatile const unsigned int MSG_CH;
    volatile unsigned int RDH;
    volatile unsigned int WRL;
    volatile unsigned int WRH;
} JL_DMA_TypeDef;

typedef struct {
    volatile unsigned int WL_CON0;
    volatile unsigned int WL_CON1;
    volatile unsigned int WL_CON2;
    volatile unsigned int WL_CON3;
    volatile unsigned int WL_CON4;
    volatile unsigned int WL_CON5;
    volatile unsigned int WL_CON6;
    volatile unsigned int WL_CON7;
    volatile unsigned int LOFC_CON;
    volatile unsigned int LOFC_RES;
    volatile unsigned int WL_ANL_CON0;
    volatile unsigned int WL_ANL_CON1;
    volatile unsigned int WL_ANL_CON2;
    volatile unsigned int WL_ANL_CON3;
    unsigned int RESERVED0[0x10 - 0x0d - 1];
    volatile unsigned int WF_CON0;
    volatile unsigned int WF_CON1;
    volatile unsigned int WF_CON2;
    volatile unsigned int WF_CON3;
    volatile unsigned int WF_CON4;
    volatile unsigned int WF_CON5;
    volatile unsigned int WF_CON6;
    volatile unsigned int WF_CON7;
    volatile unsigned int WF_CON8;
    volatile unsigned int WF_CON9;
    unsigned int RESERVED1[0x20 - 0x19 - 1];
    volatile unsigned int SD_CON0;
    volatile unsigned int SD_CON1;
    volatile unsigned int SD_CON2;
    volatile unsigned int SD_CTU_CON;
    volatile unsigned int SD_CTU_CNT;
    volatile unsigned int SD_CPTR;
    volatile unsigned int SD_DPTR;
} JL_WL_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int CON2;
    volatile unsigned int CON3;
    volatile unsigned int IDAT_ADR;
    volatile unsigned int IDAT_LEN;
    volatile unsigned int ODAT_ADR;
    volatile unsigned int ODAT_LEN;
    volatile unsigned int FLTB_ADR;
} JL_SRC_TypeDef;

typedef struct {
    volatile unsigned int TMR0_CON;
    volatile unsigned int TMR0_CNT;
    volatile unsigned int TMR0_PR;
    volatile unsigned int TMR1_CON;
    volatile unsigned int TMR1_CNT;
    volatile unsigned int TMR1_PR;
    volatile unsigned int TMR2_CON;
    volatile unsigned int TMR2_CNT;
    volatile unsigned int TMR2_PR;
    volatile unsigned int TMR3_CON;
    volatile unsigned int TMR3_CNT;
    volatile unsigned int TMR3_PR;
    volatile unsigned int TMR4_CON;
    volatile unsigned int TMR4_CNT;
    volatile unsigned int TMR4_PR;
    volatile unsigned int TMR5_CON;
    volatile unsigned int TMR5_CNT;
    volatile unsigned int TMR5_PR;
    volatile unsigned int TMR6_CON;
    volatile unsigned int TMR6_CNT;
    volatile unsigned int TMR6_PR;
    volatile unsigned int TMR7_CON;
    volatile unsigned int TMR7_CNT;
    volatile unsigned int TMR7_PR;
    volatile unsigned int FPIN_CON;
    volatile unsigned int CH0_CON0;
    volatile unsigned int CH0_CON1;
    volatile unsigned int CH0_CMPH;
    volatile unsigned int CH0_CMPL;
    volatile unsigned int CH1_CON0;
    volatile unsigned int CH1_CON1;
    volatile unsigned int CH1_CMPH;
    volatile unsigned int CH1_CMPL;
    volatile unsigned int CH2_CON0;
    volatile unsigned int CH2_CON1;
    volatile unsigned int CH2_CMPH;
    volatile unsigned int CH2_CMPL;
    volatile unsigned int CH3_CON0;
    volatile unsigned int CH3_CON1;
    volatile unsigned int CH3_CMPH;
    volatile unsigned int CH3_CMPL;
    volatile unsigned int CH4_CON0;
    volatile unsigned int CH4_CON1;
    volatile unsigned int CH4_CMPH;
    volatile unsigned int CH4_CMPL;
    volatile unsigned int CH5_CON0;
    volatile unsigned int CH5_CON1;
    volatile unsigned int CH5_CMPH;
    volatile unsigned int CH5_CMPL;
    volatile unsigned int CH6_CON0;
    volatile unsigned int CH6_CON1;
    volatile unsigned int CH6_CMPH;
    volatile unsigned int CH6_CMPL;
    volatile unsigned int CH7_CON0;
    volatile unsigned int CH7_CON1;
    volatile unsigned int CH7_CMPH;
    volatile unsigned int CH7_CMPL;
    volatile unsigned int MCPWM_CON0;
} JL_MCPWM_TypeDef;

typedef struct {
    volatile unsigned int MBISTCTLL;
    volatile const unsigned int MBISTSOGOL;
} JL_MBIST_TypeDef;

typedef struct {
    volatile unsigned int MBISTCTLW;
    volatile const unsigned int MBISTSOGOW;
} JL_MBISTW_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int CON2;
    volatile unsigned int CON3;
    volatile unsigned int DATAI_ADR;
    volatile unsigned int DATAO_ADR;
    volatile unsigned int DATA_LEN;
    volatile unsigned int FLT_ADR;
} JL_EQ_TypeDef;

typedef struct {
    volatile   unsigned int RAM[208];
} JL_EQ_RAM_TypeDef;

typedef struct {
    volatile unsigned int CON0;
    volatile unsigned int CON1;
    volatile unsigned int CON2;
    volatile unsigned int CON3;
    volatile unsigned int CON4;
    volatile unsigned int CON5;
    volatile unsigned int CON6;
    volatile unsigned int CON7;
    volatile unsigned int CON8;
    volatile unsigned int CON9;
    volatile unsigned int CON10;
    volatile unsigned int CON11;
    volatile unsigned int CON12;
    volatile unsigned int CON13;
} JL_ANC_TypeDef;

typedef struct {
    volatile unsigned char RAM[512 * 4];
} JL_ANC_RAM_TypeDef;



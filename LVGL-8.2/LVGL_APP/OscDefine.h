/**
  ******************************************************************************
  * @file           : OscDefine.h
  * @author         : WangLaoEr
  * @brief          : 示波器相关变量即结构体
  * @attention      : None
  * @date           : 2022/7/17
  ******************************************************************************
  */
#ifndef FINALLYOSCILLOSCOPE_OSCDEFINE_H
#define FINALLYOSCILLOSCOPE_OSCDEFINE_H

#define OSC_WAVE_DATA_LENGTH    1024
/***********基础宏定义***********/
enum {
    OSC_DISABLE = 0u,
    OSC_ENABLE  = 1u,
};

typedef enum {
    OSC_KEY_PRESS,
    OSC_KEY_RELEASE,
}OscKeyStatus_t;

/************函数返回值**********/
typedef enum {
    OSC_RETURN_SUCCEED      = 0u,
    OSC_RETURN_FAILED       = 1u,
}OscFunStatus;

/***********垂直灵敏度***********/
typedef enum {
    OSC_VER_VOL_1V         = 1,
    OSC_VER_VOL_100mV      = 2,
    OSC_VER_VOL_2mV         = 3,
}OscVerVol_t;
/***********水平灵敏度***********/
typedef enum {
    OSC_HOR_SCAN_20ms      = 1,
    OSC_HOR_SCAN_2us       = 2,
    OSC_HOR_SCAN_100ns     = 3,
}OscHorScanSpeed_t;

/************************按键键值************************/
typedef enum {
    OSC_KEY_VALUE_MAX               = 0XFF,
    OSC_KEY_VALUE_AUTO_SET          = 0X01,
    OSC_KEY_VALUE_TRI_ADD,
    OSC_KEY_VALUE_TRI_SUB,
    OSC_KEY_VALUE_WAVE_SAVE,
    OSC_KEY_VALUE_WAVE_SHOW,
    OSC_KEY_VALUE_HOR_SCAN_20ms,
    OSC_KEY_VALUE_HOR_SCAN_2us,
    OSC_KEY_VALUE_HOR_SCAN_100ns,
    OSC_KEY_VALUE_VER_VOL_1V,
    OSC_KEY_VALUE_VER_VOL_100mV,
    OSC_KEY_VALUE_VER_VOL_2mV,
}OscSoftKeyValue_t;

/******发送给FPGA采样的采样率******/
enum {
    FPGA_SAMPLING_400K        = 400u,
    FPGA_SAMPLING_1M        = 200u,
    FPGA_SAMPLING_2M        = 3u,
    FPGA_SAMPLING_5M        = 4u,
    FPGA_SAMPLING_10M       = 5u,
    FPGA_SAMPLING_20M       = 6u,
    FPGA_SAMPLING_50M       = 7u,
    FPGA_SAMPLING_100M      = 8u,
};

/******选择FPGA通道读取******/
enum {
    /**********频率控制通道**********/
    FPGA_CHANNEL_FRE_CONTROL    = 128,
    /**********采样率发送**********/
    FPGA_CHANNEL_SMAP           = 129,
    /**********采样点数发送**********/
    FPGA_CHANNEL_SMAP_POINT     = 130,
    /**********触发电平发送**********/
    FPGA_CHANNEL_TRI_VOL        = 131,
    /**********FIFO操作发送**********/
    FPGA_CHANNEL_FIFO           = 132,
    /**********等效采样**********/
    FPGA_CHANNEL_EQUIVALENT     = 133,
    /**********片选信号**********/
    FPGA_CHANNEL_CS             = 134,
};

/******选择FPGA通道接收******/
enum {
    /**********频率接收通道**********/
    FPGA_CHANNEL_FRE_RECEIVE_A    = 0,
    FPGA_CHANNEL_FRE_RECEIVE_B    = 1,
    /**********最大值最小值接收**********/
    FPGA_CHANNEL_DIGITAL_MAX      = 2,
    FPGA_CHANNEL_DIGITAL_MIN      = 3,
    /**********结束信号接收通道**********/
    FPGA_CHANNEL_RECEIVE          = 4,
    /**********波形数据接收**********/
    FPGA_CHANNEL_WAVE_RECEIVE     = 5,
};

/*******************************示波器波形相关变量*******************************/
typedef struct {
    double             vol;         /** 电压 **/
    double             freq;        /** 频率 **/
    double             triVol;      /** 触发电压 **/
    uint16_t           dataWave[OSC_WAVE_DATA_LENGTH];      /** 波形数据 **/
    uint16_t           dataSpectrum[OSC_WAVE_DATA_LENGTH/2];/** 幅度数据 **/
    OscHorScanSpeed_t  horScan;     /** 水平扫描速度 **/
    OscVerVol_t        verVol;      /** 垂直电平    **/
}OscWaveInfo_t;

/**********示波器变量**********/
typedef struct {
    OscWaveInfo_t waveInfo;
    uint16_t      maxVol;
    uint16_t      minVol;
    uint32_t      sampleRate;
    uint16_t      pointCount;
    uint16_t      triLevel;
    double        thd;
    /*******按键键值*******/
    OscSoftKeyValue_t keyValue;
    /*******按键状态变量*******/
    OscKeyStatus_t    keyStatus;
}OscVar_t;

/*******波形数据存储*******/
extern OscVar_t oscVar;
/*******保存波形数据*******/
extern OscWaveInfo_t oscWaveInfoSave;

#endif //FINALLYOSCILLOSCOPE_OSCDEFINE_H

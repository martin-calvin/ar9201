#ifndef __OB_REF_PARSER_
#define __OB_REF_PARSER_

#ifdef _WIN32
#define OB_EXPORT_API __declspec(dllexport)
#else
#define OB_EXPORT_API __attribute__ ((visibility("default")))
#endif
#include <stdint.h>

/**
* @brief �ɼ��ο�ͼʱ���¶�
*/
typedef struct ObRefTemp_t {
    float ir_cali_temp;
    float ldemp_cali_temp;
}ObRefTemp;

/**
* @brief ir sensor�ڲ�
*/
typedef struct ObIRIntrinsic_t {
    /** �ڲ� fx */
    float fx;
    /** �ڲ� fy */
    float fy;
    /** �ڲ� cx */
    float cx;
    /** �ڲ� cy */
    float cy;
}ObIRIntrinsic;

/**
* @brief ir rotation ���
*/
typedef struct ObIrExtrin_t {
    float rx;
    float ry;
    float rz;
}ObIrExtrin;

/**
* @brief ir rotation ���
*/
typedef struct ObRefCalibInfo_t {
    /** IR Sensor������ľ��� */
    float baseline;
    /** �궨���� */
    float z0;
    /** �궨ƽ��������λ */
    float zpps;
}ObRefCalibInfo;


/**
* @brief �ο�ͼ������ṹ���Ա
*/
typedef struct ObRefInfo_t {
    ObIrExtrin ir_extrin;
    ObRefTemp temp;
    int ref_len;
    /** ������ο�ͼ��buffer */
    char* ref_buf;
}ObRefInfo;

/**
* @brief �ο�ͼ�������ڲΡ��궨��Ϣ
*/
typedef struct ObDepthConfig_t {
    ObRefCalibInfo calib;
    ObIRIntrinsic intrinsic;
    uint32_t unit;//1:1mm�� 10����ʾ0.1mm
    uint32_t ref_left_extend;
}ObDepthCfg;


#ifdef __cplusplus
extern "C" {
#endif

    /**
    * @brief �ο�ͼ����
    * @param[in]       in_buf  ����ο�ͼ�ļ�����buffer
    * @param[in]       in_len  ����ο�ͼ�ļ�����buffer�ĳ���
    * @param[in/out]   ObRefInfo ���벢���������ο�ͼ��ṹ���ַ
    * @param[in/out]   cfg ���벢����Depth���ò���
    * @retval  0  �ɹ�
    * @retval ��0  ʧ��
    */
    OB_EXPORT_API int obref_parser(const char* in_buf, int in_len, ObRefInfo* info, ObDepthCfg* cfg);

    /**
    * @brief �ο�ͼ����
    * @param[in] ref_buf ����ο�ͼ�ļ�����buffer
    * @param[in] ref_len ����ο�ͼ�ļ�����buffer�ĳ���
    * @param[in/out] ref_decrypt ���벢���������ο�ͼ��ṹ���ַ
    * @param[in/out] ref_info ���벢����REF���ò���
    * @retval 0 �ɹ�
    * @retval ��0 ʧ��
    */
    OB_EXPORT_API int obref_parser_ex(const char* ref_buf, int ref_len, ObRefInfo* ref_decrypt, void* ref_info);

    /**
    * @brief �ͷ���Դ
    * @param[in/out]   info �ͷŸòο�ͼ��Դ
    *
    * @retval  0  �ɹ�
    * @retval ��0  ʧ��
    */
    OB_EXPORT_API int obref_release(ObRefInfo* info);

    /**
    * @brief ��ȡ������汾��
    * @retval  �汾�Ÿ�ʽ: �Ӹ�λ����λ������major, minor, revision
    */
    OB_EXPORT_API uint32_t obref_version();

#ifdef __cplusplus
}
#endif

#endif

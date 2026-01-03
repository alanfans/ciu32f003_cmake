/************************************************************************************************/
/**
* @file               ciu32f003_std_crc.h
* @author             MCU Ecosystem Development Team
* @brief              CRC STD������ͷ�ļ���
*                     �ṩCRC��ص�STD������������������������Լ������Ķ��塣                         
*                     
*
**************************************************************************************************
* @attention
* Copyright (c) CEC Huada Electronic Design Co.,Ltd. All rights reserved.
*
**************************************************************************************************
*/

/* ����ͷ�ļ��ظ����� */
#ifndef CIU32F003_STD_CRC_H
#define CIU32F003_STD_CRC_H

/************************************************************************************************/
/** 
* @addtogroup CIU32F003_STD_Driver
* @{
*/

/**
* @defgroup CRC CRC
* @brief ѭ������У���STD������
* @{
*/
/************************************************************************************************/


#ifdef __cplusplus
 extern "C" {
#endif

/*------------------------------------------includes--------------------------------------------*/
#include "ciu32f003_std_common.h"


/*--------------------------------------------define--------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup CRC_Constants CRC Constants 
* @brief    CRC�������弰�궨��
* @{
*
*/
/************************************************************************************************/
/* CRC����ʽѡ�� */
#define CRC_POLY_16                           CRC_CSR_POLY_SIZE_16     /**< 16λ����ʽ       */
#define CRC_POLY_32                           CRC_CSR_POLY_SIZE_32     /**< 32λ����ʽ       */

/* CRCĬ�ϳ�ʼֵ */
#define CRC_DEFAULT_INIT_VALUE                (0xFFFFFFFFU)            /**< CRCĬ�ϳ�ʼֵ    */

/** 
* @} 
*/

/*-------------------------------------------functions------------------------------------------*/

/************************************************************************************************/
/**
* @defgroup CRC_External_Functions CRC External Functions
* @brief    CRC���⺯��
* @{
*
*/
/************************************************************************************************/
/** 
* @brief  ����CRC����ʽ
* @param  poly_size ����ʽѡ��
*             @arg CRC_POLY_16��16λ����ʽ
*             @arg CRC_POLY_32��32λ����ʽ
* @retval ��
*/
__STATIC_INLINE void std_crc_set_poly_size(uint32_t poly_size)
{
    CRC->CSR = poly_size;
}

/**
* @brief  ��CRC��ʼֵδ���з�תֱ��д��Ĵ���
* @param  init_value CRC�ĳ�ʼֵ
* @retval ��
*/
__STATIC_INLINE void std_crc_set_init_value(uint32_t init_value)
{
    CRC->RDR = init_value;
}

/**
* @brief  ��ȡCRC������
* @retval uint32_t CRC������
*/
__STATIC_INLINE uint32_t std_crc_get_value(void)
{
    return(CRC->RDR);
}

/**
* @brief  �����ݼĴ�����д�������1�ֽ�����
* @param  input_data Ҫ����CRC�����ԭʼ����
* @retval ��
*/
__STATIC_INLINE void std_crc_set_byte(uint8_t input_data)
{
    CRC->DR = (uint32_t)input_data;
}


void std_crc_deinit(void);
void std_crc_set_init_value_invert(uint32_t poly_sel, uint32_t init_value);

/** 
* @} 
*/

#ifdef __cplusplus
}
#endif

/**
* @}
*/  

/**
* @}
*/

#endif /* CIU32F003_STD_CRC_H */

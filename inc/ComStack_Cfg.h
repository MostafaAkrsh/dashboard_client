/*******************************************************************************************************************************
FileName:                                        ComStack_Cfg.h
AUTOSAR Version:                                    4.2.2
******************************************************************************************************************************/

#ifndef COMSTACK_CFG_H_
#define COMSTACK_CFG_H_

/*******************************************************************************************************************************
**                                    Defines                                                                    **
********************************************************************************************************************************/
#define PduIdMax  2
#define PduLengthmax 111

/*******************************************************************************************************************************
**                                   Variables Definitions                                                                    **
********************************************************************************************************************************/


/********************************************************************************************************************************
**
Name:                                PduIdType

Type:                                uint8, uint16

Description:           This type is used within the entire AUTOSAR Com Stack except for bus drivers.

Range:          Zero-based integer number The size of this global type depends on the maximum number of PDUs
                used within one software module. This parameter shall be generated by the generator tool
                depending on the value configured in EcuC virtual layer. This parameter shall be generated in ComStack_Cfg.h file
                Example : If '''no''' software module deals with more PDUs that 256, this type can be set to uint8.
                If at least one software module handles more than 256 PDUs, this type must globally be set to uint16.                          **
*********************************************************************************************************************************/
#if(PduIdMax > 255)
#define PDUIDTYPE (uint16)
#endif

#if(PduIdMax <255)
#define PDUIDTYPE (uint8)
#endif


/********************************************************************************************************************************
**
Name:                                PduLengthType

Type:                                uint8, uint16, uint32

Description:           This type shall be used within the entire AUTOSAR COM Stack of an ECU except for bus drivers.

Range:          Zero-based integer number The size of this global type depends on the maximum length of PDUs to be sent by an ECU.
                This parameter shall be generated by the generator tool depending on the value configured in EcuC virtual layer.
                This parameter shall be generated in ComStack_Cfg.h file Example: If no segmentation is used the length depends on the
                maximum payload size of a frame of the underlying communication system (for FlexRay maximum size is 255,therefore uint8).
                If segmentation is used it depends on the maximum length of a segmented N-PDU (in general uint16 is used)                          **
*********************************************************************************************************************************/
#if((PduLengthmax <0xFF))
#define PDULENGTHTYPE (uint8)
#endif

#if((PduLengthmax >0xFF)&&(PduLengthmax <0xFFFF))
#define PDULENGTHTYPE (uint16)
#endif

#if((PduLengthmax >0xFFFF)&&(PduLengthmax <0xFFFFFFFF))
#define PDULENGTHTYPE (uint32)
#endif


/********************************************************************************************************************************

Name:                                PNCHandleType

Type:                                uint8

Description:           Used to store the identifier of a partial network cluster.

*********************************************************************************************************************************/
#define PNCHandleType (uint8)


/********************************************************************************************************************************

Name:                                NetworkHandleType

Type:                                uint8

Description:           Variables of the type NetworkHandleType shall be used to store the identifier of a communication channel.

*********************************************************************************************************************************/
#define NetworkHandleType (uint8)


/********************************************************************************************************************************

Name:                                IcomConfigIdType

Type:                                uint8

Description:           IcomConfigIdType defines the configuration ID. An ID of 0 is the default configuration.
                       An ID greater than 0 shall identify a configuration for Pretended Networking.
                       There is more than 1 configuration possible.

*********************************************************************************************************************************/
#define IcomConfigIdType (uint8)



#endif /* COMSTACK_CFG_H_ */

//definitions

#ifndef GPIO_AF_F4XX_H_
#define GPIO_AF_F4XX_H_


#ifdef __cplusplus
extern "C" {
#endif

#define  PIN_AF_NO 		0
#define  GPIO_AF_NO 		0

// alternate functions consolidated

#define  PIN_AF_CAN1 		9
#define  PIN_AF_CAN2 		9
#define  PIN_AF_DCMI 		13
#define  PIN_AF_ETH  		11
#define  PIN_AF_FSMC 		12
#define  PIN_AF_I2C1 		4
#define  PIN_AF_I2C2 		4
#define  PIN_AF_I2C3 		4
#define  PIN_AF_I2S1 		5
#define  PIN_AF_I2S2 		5
#define  PIN_AF_I2S2ext 	6
#define  PIN_AF_I2S3    	6
#define  PIN_AF_I2S3ext_SD_B4 	7
#define  PIN_AF_I2S3ext_SD_C11 	5
#define  PIN_AF_OTG_FS  	10
#define  PIN_AF_OTG_HS  	12
#define  PIN_AF_OTG_HS_ULPI 	10
#define  PIN_AF_SDIO		12
#define  PIN_AF_SPI1		5
#define  PIN_AF_SPI2		5
#define  PIN_AF_SPI3		6
#define  PIN_AF_SYS 		0
#define  PIN_AF_TIM1		1
#define  PIN_AF_TIM2		1
#define  PIN_AF_TIM3		2
#define  PIN_AF_TIM4		2
#define  PIN_AF_TIM5		2
#define  PIN_AF_TIM8		3
#define  PIN_AF_TIM9		3
#define  PIN_AF_TIM10		3
#define  PIN_AF_TIM11		3
#define  PIN_AF_TIM12		9
#define  PIN_AF_TIM13		9
#define  PIN_AF_TIM14		9
#define  PIN_AF_USART1		7
#define  PIN_AF_USART2		7
#define  PIN_AF_USART3		7
#define  PIN_AF_UART4		8
#define  PIN_AF_UART5		8
#define  PIN_AF_USART6		8
#define  PIN_AF_USARTX(usartN)  ((usartN>>3)+7)

//Alternate functions by pereferial

#define  PIN_AF_CAN1_RX_A11 9
#define  PIN_AF_CAN1_RX_B8 9
#define  PIN_AF_CAN1_RX_D0 9
#define  PIN_AF_CAN1_RX_I9 9
#define  PIN_AF_CAN1_TX_A12 9
#define  PIN_AF_CAN1_TX_B9 9
#define  PIN_AF_CAN1_TX_D1 9
#define  PIN_AF_CAN1_TX_H13 9
#define  PIN_AF_CAN2_RX_B12 9
#define  PIN_AF_CAN2_RX_B5 9
#define  PIN_AF_CAN2_TX_B13 9
#define  PIN_AF_CAN2_TX_B6 9
#define  PIN_AF_DCMI_D0_A9 13
#define  PIN_AF_DCMI_D0_C6 13
#define  PIN_AF_DCMI_D0_H9 13
#define  PIN_AF_DCMI_D1_A10 13
#define  PIN_AF_DCMI_D1_C7 13
#define  PIN_AF_DCMI_D1_H10 13
#define  PIN_AF_DCMI_D10_B5 13
#define  PIN_AF_DCMI_D10_I3 13
#define  PIN_AF_DCMI_D11_D2 13
#define  PIN_AF_DCMI_D11_H15 13
#define  PIN_AF_DCMI_D12_F11 13
#define  PIN_AF_DCMI_D13_G15 13
#define  PIN_AF_DCMI_D13_I0 13
#define  PIN_AF_DCMI_D2_C8 13
#define  PIN_AF_DCMI_D2_E0 13
#define  PIN_AF_DCMI_D2_H11 13
#define  PIN_AF_DCMI_D3_C9 13
#define  PIN_AF_DCMI_D3_E1 13
#define  PIN_AF_DCMI_D3_H12 13
#define  PIN_AF_DCMI_D4_C11 13
#define  PIN_AF_DCMI_D4_E4 13
#define  PIN_AF_DCMI_D4_H14 13
#define  PIN_AF_DCMI_D5_B6 13
#define  PIN_AF_DCMI_D5_I4 13
#define  PIN_AF_DCMI_D6_B8 13
#define  PIN_AF_DCMI_D6_E5 13
#define  PIN_AF_DCMI_D6_I6 13
#define  PIN_AF_DCMI_D7_B9 13
#define  PIN_AF_DCMI_D7_E6 13
#define  PIN_AF_DCMI_D7_I7 13
#define  PIN_AF_DCMI_D8_C10 13
#define  PIN_AF_DCMI_D8_I1 13
#define  PIN_AF_DCMI_D9_C12 13
#define  PIN_AF_DCMI_D9_I2 13
#define  PIN_AF_DCMI_HSYNC_A4 13
#define  PIN_AF_DCMI_HSYNC_H8 13
#define  PIN_AF_DCMI_PIXCK_A6 13
#define  PIN_AF_DCMI_VSYN_C_B7 13
#define  PIN_AF_DCMI_VSYNC_I5 13
#define  PIN_AF_ETH_MDC_C1 11
#define  PIN_AF_ETH_MDIO_A2 11
#define  PIN_AF_ETH_MII_COL_A3 11
#define  PIN_AF_ETH_MII_COL_H3 11
#define  PIN_AF_ETH_MII_CRS_A0 11
#define  PIN_AF_ETH_MII_CRS_H2 11
#define  PIN_AF_ETH_MII_RX_CLK_A1 11
#define  PIN_AF_ETH_MII_RX_DV_A7 11
#define  PIN_AF_ETH_MII_RX_ER_B10 11
#define  PIN_AF_ETH_MII_RX_ER_I10 11
#define  PIN_AF_ETH_MII_RXD0_C4 11
#define  PIN_AF_ETH_MII_RXD1_C5 11
#define  PIN_AF_ETH_MII_RXD2_B0 11
#define  PIN_AF_ETH_MII_RXD2_H6 11
#define  PIN_AF_ETH_MII_RXD3_B1 11
#define  PIN_AF_ETH_MII_RXD3_H7 11
#define  PIN_AF_ETH_MII_TX_CLK_C3 11
#define  PIN_AF_ETH_MII_TX_EN_B11 11
#define  PIN_AF_ETH_MII_TX_EN_G11 11
#define  PIN_AF_ETH_MII_TXD0_B12 11
#define  PIN_AF_ETH_MII_TXD0_G13 11
#define  PIN_AF_ETH_MII_TXD1_B13 11
#define  PIN_AF_ETH_MII_TXD1_G14 11
#define  PIN_AF_ETH_MII_TXD2_C2 11
#define  PIN_AF_ETH_MII_TXD3_B8 11
#define  PIN_AF_ETH_MII_TXD3_E2 11
#define  PIN_AF_ETH_PPS_OUT_B5 11
#define  PIN_AF_ETH_PPS_OUT_G8 11
#define  PIN_AF_ETH_RMII_CRS_DV_A7 11
#define  PIN_AF_ETH_RMII_REF_CLK_A1 11
#define  PIN_AF_ETH_RMII_RXD0_C4 11
#define  PIN_AF_ETH_RMII_RXD1_C5 11
#define  PIN_AF_ETH_RMII_TX_EN_B11 11
#define  PIN_AF_ETH_RMII_TX_EN_G11 11
#define  PIN_AF_ETH_RMII_TXD0_B12 11
#define  PIN_AF_ETH_RMII_TXD0_G13 11
#define  PIN_AF_ETH_RMII_TXD1_B13 11
#define  PIN_AF_ETH_RMII_TXD1_G14 11
#define  PIN_AF_FSMC_A0_F0 12
#define  PIN_AF_FSMC_A1_F1 12
#define  PIN_AF_FSMC_A10_G0 12
#define  PIN_AF_FSMC_A11_G1 12
#define  PIN_AF_FSMC_A12_G2 12
#define  PIN_AF_FSMC_A13_G3 12
#define  PIN_AF_FSMC_A14_G4 12
#define  PIN_AF_FSMC_A15_G5 12
#define  PIN_AF_FSMC_A16_D11 12
#define  PIN_AF_FSMC_A17_D12 12
#define  PIN_AF_FSMC_A18_D13 12
#define  PIN_AF_FSMC_A19_E3 12
#define  PIN_AF_FSMC_A2_F2 12
#define  PIN_AF_FSMC_A20_E4 12
#define  PIN_AF_FSMC_A21_E5 12
#define  PIN_AF_FSMC_A22_E6 12
#define  PIN_AF_FSMC_A23_E2 12
#define  PIN_AF_FSMC_A24_G13 12
#define  PIN_AF_FSMC_A25_G14 12
#define  PIN_AF_FSMC_A3_F3 12
#define  PIN_AF_FSMC_A4_F4 12
#define  PIN_AF_FSMC_A5_F5 12
#define  PIN_AF_FSMC_A6_F12 12
#define  PIN_AF_FSMC_A7_F13 12
#define  PIN_AF_FSMC_A8_F14 12
#define  PIN_AF_FSMC_A9_F15 12
#define  PIN_AF_FSMC_CD_F9 12
#define  PIN_AF_FSMC_CLK_D3 12
#define  PIN_AF_FSMC_D0_D14 12
#define  PIN_AF_FSMC_D1_D15 12
#define  PIN_AF_FSMC_D10_E13 12
#define  PIN_AF_FSMC_D11_E14 12
#define  PIN_AF_FSMC_D12_E15 12
#define  PIN_AF_FSMC_D13_D8 12
#define  PIN_AF_FSMC_D14_D9 12
#define  PIN_AF_FSMC_D15_D10 12
#define  PIN_AF_FSMC_D2_D0 12
#define  PIN_AF_FSMC_D3_D1 12
#define  PIN_AF_FSMC_D4_E7 12
#define  PIN_AF_FSMC_D5_E8 12
#define  PIN_AF_FSMC_D6_E9 12
#define  PIN_AF_FSMC_D7_E10 12
#define  PIN_AF_FSMC_D8_E11 12
#define  PIN_AF_FSMC_D9_E12 12
#define  PIN_AF_FSMC_INT2_G6 12
#define  PIN_AF_FSMC_INT3_G7 12
#define  PIN_AF_FSMC_INTR_F10 12
#define  PIN_AF_FSMC_NBL0_E0 12
#define  PIN_AF_FSMC_NBL1_E1 12
#define  PIN_AF_FSMC_NCE2_D7 12
#define  PIN_AF_FSMC_NCE3_G9 12
#define  PIN_AF_FSMC_NCE4_1_G10 12
#define  PIN_AF_FSMC_NCE4_2_G11 12
#define  PIN_AF_FSMC_NE1_D7 12
#define  PIN_AF_FSMC_NE2_G9 12
#define  PIN_AF_FSMC_NE3_G10 12
#define  PIN_AF_FSMC_NE4_G12 12
#define  PIN_AF_FSMC_NIORD_F6 12
#define  PIN_AF_FSMC_NIOWR_F8 12
#define  PIN_AF_FSMC_NL_B7 12
#define  PIN_AF_FSMC_NOE_D4 12
#define  PIN_AF_FSMC_NREG_F7 12
#define  PIN_AF_FSMC_NWAIT_D6 12
#define  PIN_AF_FSMC_NWE_D5 12
#define  PIN_AF_I2C1_SCL_B6 4
#define  PIN_AF_I2C1_SCL_B8 4
#define  PIN_AF_I2C1_SDA_B7 4
#define  PIN_AF_I2C1_SDA_B9 4
#define  PIN_AF_I2C1_SMB_A_B5 4
#define  PIN_AF_I2C2_SCL_B10 4
#define  PIN_AF_I2C2_SCL_F1 4
#define  PIN_AF_I2C2_SCL_H4 4
#define  PIN_AF_I2C2_SDA_B11 4
#define  PIN_AF_I2C2_SDA_F0 4
#define  PIN_AF_I2C2_SDA_H5 4
#define  PIN_AF_I2C2_SMBA_B12 4
#define  PIN_AF_I2C2_SMBA_F2 4
#define  PIN_AF_I2C2_SMBA_H6 4
#define  PIN_AF_I2C3_SCL_A8 4
#define  PIN_AF_I2C3_SCL_H7 4
#define  PIN_AF_I2C3_SDA_C9 4
#define  PIN_AF_I2C3_SDA_H8 4
#define  PIN_AF_I2C3_SMBA_A9 4
#define  PIN_AF_I2C3_SMBA_H9 4
#define  PIN_AF_I2S_CKIN_C9 5
#define  PIN_AF_I2S2_CK_B10 5
#define  PIN_AF_I2S2_CK_B13 5
#define  PIN_AF_I2S2_CK_I1 5
#define  PIN_AF_I2S2_MCK_C6 5
#define  PIN_AF_I2S2_SD_B15 5
#define  PIN_AF_I2S2_SD_C3 5
#define  PIN_AF_I2S2_SD_I3 5
#define  PIN_AF_I2S2_WS_B12 5
#define  PIN_AF_I2S2_WS_B9 5
#define  PIN_AF_I2S2_WS_I0 5
#define  PIN_AF_I2S2ext_SD_B14 6
#define  PIN_AF_I2S2ext_SD_C2 6
#define  PIN_AF_I2S2ext_SD_I2 6
#define  PIN_AF_I2S3_CK_B3 6
#define  PIN_AF_I2S3_CK_C10 6
#define  PIN_AF_I2S3_MCK_C7 6
#define  PIN_AF_I2S3_SD_B5 6
#define  PIN_AF_I2S3_SD_C12 6
#define  PIN_AF_I2S3_WS_A15 6
#define  PIN_AF_I2S3_WS_A4 6
#define  PIN_AF_I2S3ext_SD_B4 7
#define  PIN_AF_I2S3ext_SD_C11 5
#define  PIN_AF_JTCKSWCLK_A14 0
#define  PIN_AF_JTDI_A15 0
#define  PIN_AF_JTDO_B3 0
#define  PIN_AF_JTMSSWDIO_A13 0
#define  PIN_AF_MCO1_A8 0
#define  PIN_AF_MCO2_C9 0
#define  PIN_AF_NJTRST_B4 0
#define  PIN_AF_OTG_FS_DM_A11 10
#define  PIN_AF_OTG_FS_DP_A12 10
#define  PIN_AF_OTG_FS_ID_A10 10
#define  PIN_AF_OTG_FS_SOF_A8 10
#define  PIN_AF_OTG_HS_DM_B14 12
#define  PIN_AF_OTG_HS_DP_B15 12
#define  PIN_AF_OTG_HS_ID_B12 12
#define  PIN_AF_OTG_HS_SOF_A4 12
#define  PIN_AF_OTG_HS_ULPI_CK_A5 10
#define  PIN_AF_OTG_HS_ULPI_D0_A3 10
#define  PIN_AF_OTG_HS_ULPI_D1_B0 10
#define  PIN_AF_OTG_HS_ULPI_D2_B1 10
#define  PIN_AF_OTG_HS_ULPI_D3_B10 10
#define  PIN_AF_OTG_HS_ULPI_D4_B11 10
#define  PIN_AF_OTG_HS_ULPI_D5_B12 10
#define  PIN_AF_OTG_HS_ULPI_D6_B13 10
#define  PIN_AF_OTG_HS_ULPI_D7_B5 10
#define  PIN_AF_OTG_HS_ULPI_DIR_C2 10
#define  PIN_AF_OTG_HS_ULPI_DIR_I11 10
#define  PIN_AF_OTG_HS_ULPI_NXT_C3 10
#define  PIN_AF_OTG_HS_ULPI_NXT_H4 10
#define  PIN_AF_OTG_HS_ULPI_STP_C0 10
#define  PIN_AF_RTC_REFIN_B15 0
#define  PIN_AF_SDIO_CK_C12 12
#define  PIN_AF_SDIO_CMD_D2 12
#define  PIN_AF_SDIO_D0_C8 12
#define  PIN_AF_SDIO_D1_C9 12
#define  PIN_AF_SDIO_D2_C10 12
#define  PIN_AF_SDIO_D3_C11 12
#define  PIN_AF_SDIO_D4_B8 12
#define  PIN_AF_SDIO_D5_B9 12
#define  PIN_AF_SDIO_D6_C6 12
#define  PIN_AF_SDIO_D7_C7 12
#define  PIN_AF_SPI1_MISO_A6 5
#define  PIN_AF_SPI1_MISO_B4 5
#define  PIN_AF_SPI1_MOSI_A7 5
#define  PIN_AF_SPI1_MOSI_B5 5
#define  PIN_AF_SPI1_NSS_A15 5
#define  PIN_AF_SPI1_NSS_A4 5
#define  PIN_AF_SPI1_SCK_A5 5
#define  PIN_AF_SPI1_SCK_B3 5
#define  PIN_AF_SPI2_MISO_B14 5
#define  PIN_AF_SPI2_MISO_C2 5
#define  PIN_AF_SPI2_MISO_I2 5
#define  PIN_AF_SPI2_MOSI_B15 5
#define  PIN_AF_SPI2_MOSI_C3 5
#define  PIN_AF_SPI2_MOSI_I3 5
#define  PIN_AF_SPI2_NSS_B12 5
#define  PIN_AF_SPI2_NSS_B9 5
#define  PIN_AF_SPI2_NSS_I0 5
#define  PIN_AF_SPI2_SCK_B10 5
#define  PIN_AF_SPI2_SCK_B13 5
#define  PIN_AF_SPI2_SCK_I1 5
#define  PIN_AF_SPI3_MISO_B4 6
#define  PIN_AF_SPI3_MISO_C11 6
#define  PIN_AF_SPI3_MOSI_B5 6
#define  PIN_AF_SPI3_MOSI_C12 6
#define  PIN_AF_SPI3_NSS_A15 6
#define  PIN_AF_SPI3_NSS_A4 6
#define  PIN_AF_SPI3_SCK_B3 6
#define  PIN_AF_SPI3_SCK_C10 6
#define  PIN_AF_TIM_2_CH1_A15 1
#define  PIN_AF_TIM_2_ETR_A15 1
#define  PIN_AF_TIM_5_CH1_A0 2
#define  PIN_AF_TIM1_BKIN_A6 1
#define  PIN_AF_TIM1_BKIN_B12 1
#define  PIN_AF_TIM1_BKIN_E15 1
#define  PIN_AF_TIM1_CH1_A8 1
#define  PIN_AF_TIM1_CH1_E9 1
#define  PIN_AF_TIM1_CH1N_A7 1
#define  PIN_AF_TIM1_CH1N_B13 1
#define  PIN_AF_TIM1_CH1N_E8 1
#define  PIN_AF_TIM1_CH2_A9 1
#define  PIN_AF_TIM1_CH2_E11 1
#define  PIN_AF_TIM1_CH2N_B0 1
#define  PIN_AF_TIM1_CH2N_B14 1
#define  PIN_AF_TIM1_CH2N_E10 1
#define  PIN_AF_TIM1_CH3_A10 1
#define  PIN_AF_TIM1_CH3_E13 1
#define  PIN_AF_TIM1_CH3N_B1 1
#define  PIN_AF_TIM1_CH3N_B15 1
#define  PIN_AF_TIM1_CH3N_E12 1
#define  PIN_AF_TIM1_CH4_A11 1
#define  PIN_AF_TIM1_CH4_E14 1
#define  PIN_AF_TIM1_ETR_A12 1
#define  PIN_AF_TIM1_ETR_E7 1
#define  PIN_AF_TIM10_CH1_B8 3
#define  PIN_AF_TIM10_CH1_F6 3
#define  PIN_AF_TIM11_CH1_B9 3
#define  PIN_AF_TIM11_CH1_F7 3
#define  PIN_AF_TIM12_CH1_B14 9
#define  PIN_AF_TIM12_CH1_H6 9
#define  PIN_AF_TIM12_CH2_B15 9
#define  PIN_AF_TIM12_CH2_H9 9
#define  PIN_AF_TIM13_CH1_A6 9
#define  PIN_AF_TIM13_CH1_F8 9
#define  PIN_AF_TIM14_CH1_A7 9
#define  PIN_AF_TIM14_CH1_F9 9
#define  PIN_AF_TIM2_CH1_ETR_A0 1
#define  PIN_AF_TIM2_CH1_ETR_A5 1
#define  PIN_AF_TIM2_CH2_A1 1
#define  PIN_AF_TIM2_CH2_B3 1
#define  PIN_AF_TIM2_CH3_A2 1
#define  PIN_AF_TIM2_CH3_B10 1
#define  PIN_AF_TIM2_CH4_A3 1
#define  PIN_AF_TIM2_CH4_B11 1
#define  PIN_AF_TIM3_CH1_A6 2
#define  PIN_AF_TIM3_CH1_B4 2
#define  PIN_AF_TIM3_CH1_C6 2
#define  PIN_AF_TIM3_CH2_A7 2
#define  PIN_AF_TIM3_CH2_B5 2
#define  PIN_AF_TIM3_CH2_C7 2
#define  PIN_AF_TIM3_CH3_B0 2
#define  PIN_AF_TIM3_CH3_C8 2
#define  PIN_AF_TIM3_CH4_B1 2
#define  PIN_AF_TIM3_CH4_C9 2
#define  PIN_AF_TIM3_ETR_D2 2
#define  PIN_AF_TIM4_CH1_B6 2
#define  PIN_AF_TIM4_CH1_D12 2
#define  PIN_AF_TIM4_CH2_B7 2
#define  PIN_AF_TIM4_CH2_D13 2
#define  PIN_AF_TIM4_CH3_B8 2
#define  PIN_AF_TIM4_CH3_D14 2
#define  PIN_AF_TIM4_CH4_B9 2
#define  PIN_AF_TIM4_CH4_D15 2
#define  PIN_AF_TIM4_ETR_E0 2
#define  PIN_AF_TIM5_CH1_H10 2
#define  PIN_AF_TIM5_CH2_A1 2
#define  PIN_AF_TIM5_CH2_H11 2
#define  PIN_AF_TIM5_CH3_A2 2
#define  PIN_AF_TIM5_CH3_H12 2
#define  PIN_AF_TIM5_CH4_A3 2
#define  PIN_AF_TIM5_CH4_I0 2
#define  PIN_AF_TIM8_BKIN_A6 3
#define  PIN_AF_TIM8_BKIN_I4 3
#define  PIN_AF_TIM8_CH1_C6 3
#define  PIN_AF_TIM8_CH1_I5 3
#define  PIN_AF_TIM8_CH1N_A5 3
#define  PIN_AF_TIM8_CH1N_A7 3
#define  PIN_AF_TIM8_CH1N_H13 3
#define  PIN_AF_TIM8_CH2_C7 3
#define  PIN_AF_TIM8_CH2_I6 3
#define  PIN_AF_TIM8_CH2N_B0 3
#define  PIN_AF_TIM8_CH2N_B14 3
#define  PIN_AF_TIM8_CH2N_H14 3
#define  PIN_AF_TIM8_CH3_C8 3
#define  PIN_AF_TIM8_CH3_I7 3
#define  PIN_AF_TIM8_CH3N_B1 3
#define  PIN_AF_TIM8_CH3N_B15 3
#define  PIN_AF_TIM8_CH3N_H15 3
#define  PIN_AF_TIM8_CH4_C9 3
#define  PIN_AF_TIM8_CH4_I2 3
#define  PIN_AF_TIM8_ETR_A0 3
#define  PIN_AF_TIM8_ETR_I3 3
#define  PIN_AF_TIM9_CH1_A2 3
#define  PIN_AF_TIM9_CH1_E5 3
#define  PIN_AF_TIM9_CH2_A3 3
#define  PIN_AF_TIM9_CH2_E6 3
#define  PIN_AF_TRACECLK_E2 0
#define  PIN_AF_TRACED0_E3 0
#define  PIN_AF_TRACED1_E4 0
#define  PIN_AF_TRACED2_E5 0
#define  PIN_AF_TRACED3_E6 0
#define  PIN_AF_TRACES_WO_B3 0
#define  PIN_AF_UART4_RX_A1 8
#define  PIN_AF_UART4_RX_C11 8
#define  PIN_AF_UART4_TX_A0 8
#define  PIN_AF_UART4_TX_C10 8
#define  PIN_AF_UART5_RX_D2 8
#define  PIN_AF_UART5_TX_C12 8
#define  PIN_AF_USART1_CK_A8 7
#define  PIN_AF_USART1_CTS_A11 7
#define  PIN_AF_USART1_RTS_A12 7
#define  PIN_AF_USART1_RX_A10 7
#define  PIN_AF_USART1_RX_B7 7
#define  PIN_AF_USART1_TX_A9 7
#define  PIN_AF_USART1_TX_B6 7
#define  PIN_AF_USART2_CK_A4 7
#define  PIN_AF_USART2_CK_D7 7
#define  PIN_AF_USART2_CTS_A0 7
#define  PIN_AF_USART2_CTS_D3 7
#define  PIN_AF_USART2_RTS_A1 7
#define  PIN_AF_USART2_RTS_D4 7
#define  PIN_AF_USART2_RX_A3 7
#define  PIN_AF_USART2_RX_D6 7
#define  PIN_AF_USART2_TX_A2 7
#define  PIN_AF_USART2_TX_D5 7
#define  PIN_AF_USART3_CK_B12 7
#define  PIN_AF_USART3_CK_C12 7
#define  PIN_AF_USART3_CK_D10 7
#define  PIN_AF_USART3_CTS_B13 7
#define  PIN_AF_USART3_CTS_D11 7
#define  PIN_AF_USART3_RTS_B14 7
#define  PIN_AF_USART3_RTS_D12 7
#define  PIN_AF_USART3_RX_B11 7
#define  PIN_AF_USART3_RX_C11 7
#define  PIN_AF_USART3_RX_D9 7
#define  PIN_AF_USART3_TX_B10 7
#define  PIN_AF_USART3_TX_C10 7
#define  PIN_AF_USART3_TX_D8 7
#define  PIN_AF_USART6_CK_C8 8
#define  PIN_AF_USART6_CK_G7 8
#define  PIN_AF_USART6_CTS_G13 8
#define  PIN_AF_USART6_CTS_G15 8
#define  PIN_AF_USART6_RTS_G12 8
#define  PIN_AF_USART6_RTS_G8 8
#define  PIN_AF_USART6_RX_C7 8
#define  PIN_AF_USART6_RX_G9 8
#define  PIN_AF_USART6_TX_C6 8
#define  PIN_AF_USART6_TX_G14 8

//Alternate functions by PIN

#define  PIN_AF_A0_ETH_MII_CRS 11
#define  PIN_AF_A0_TIM2_CH1_ETR 1
#define  PIN_AF_A0_TIM8_ETR 3
#define  PIN_AF_A0_TIM_5_CH1 2
#define  PIN_AF_A0_UART4_TX 8
#define  PIN_AF_A0_USART2_CTS 7
#define  PIN_AF_A1_ETH_MII_RX_CLK 11
#define  PIN_AF_A1_ETH_RMII_REF_CLK 11
#define  PIN_AF_A1_TIM2_CH2 1
#define  PIN_AF_A1_TIM5_CH2 2
#define  PIN_AF_A1_UART4_RX 8
#define  PIN_AF_A1_USART2_RTS 7
#define  PIN_AF_A2_ETH_MDIO 11
#define  PIN_AF_A2_TIM2_CH3 1
#define  PIN_AF_A2_TIM5_CH3 2
#define  PIN_AF_A2_TIM9_CH1 3
#define  PIN_AF_A2_USART2_TX 7
#define  PIN_AF_A3_ETH_MII_COL 11
#define  PIN_AF_A3_OTG_HS_ULPI_D0 10
#define  PIN_AF_A3_TIM2_CH4 1
#define  PIN_AF_A3_TIM5_CH4 2
#define  PIN_AF_A3_TIM9_CH2 3
#define  PIN_AF_A3_USART2_RX 7
#define  PIN_AF_A4_DCMI_HSYNC 13
#define  PIN_AF_A4_I2S3_WS 6
#define  PIN_AF_A4_OTG_HS_SOF 12
#define  PIN_AF_A4_SPI1_NSS 5
#define  PIN_AF_A4_SPI3_NSS 6
#define  PIN_AF_A4_USART2_CK 7
#define  PIN_AF_A5_OTG_HS_ULPI_CK 10
#define  PIN_AF_A5_SPI1_SCK 5
#define  PIN_AF_A5_TIM2_CH1_ETR 1
#define  PIN_AF_A5_TIM8_CH1N 3
#define  PIN_AF_A6_DCMI_PIXCK 13
#define  PIN_AF_A6_SPI1_MISO 5
#define  PIN_AF_A6_TIM13_CH1 9
#define  PIN_AF_A6_TIM1_BKIN 1
#define  PIN_AF_A6_TIM3_CH1 2
#define  PIN_AF_A6_TIM8_BKIN 3
#define  PIN_AF_A7_ETH_MII_RX_DV 11
#define  PIN_AF_A7_ETH_RMII_CRS_DV 11
#define  PIN_AF_A7_SPI1_MOSI 5
#define  PIN_AF_A7_TIM14_CH1 9
#define  PIN_AF_A7_TIM1_CH1N 1
#define  PIN_AF_A7_TIM3_CH2 2
#define  PIN_AF_A7_TIM8_CH1N 3
#define  PIN_AF_A8_I2C3_SCL 4
#define  PIN_AF_A8_MCO1 0
#define  PIN_AF_A8_OTG_FS_SOF 10
#define  PIN_AF_A8_TIM1_CH1 1
#define  PIN_AF_A8_USART1_CK 7
#define  PIN_AF_A9_DCMI_D0 13
#define  PIN_AF_A9_I2C3_SMBA 4
#define  PIN_AF_A9_TIM1_CH2 1
#define  PIN_AF_A9_USART1_TX 7
#define  PIN_AF_A10_DCMI_D1 13
#define  PIN_AF_A10_OTG_FS_ID 10
#define  PIN_AF_A10_TIM1_CH3 1
#define  PIN_AF_A10_USART1_RX 7
#define  PIN_AF_A11_CAN1_RX 9
#define  PIN_AF_A11_OTG_FS_DM 10
#define  PIN_AF_A11_TIM1_CH4 1
#define  PIN_AF_A11_USART1_CTS 7
#define  PIN_AF_A12_CAN1_TX 9
#define  PIN_AF_A12_OTG_FS_DP 10
#define  PIN_AF_A12_TIM1_ETR 1
#define  PIN_AF_A12_USART1_RTS 7
#define  PIN_AF_A13_JTMSSWDIO 0
#define  PIN_AF_A14_JTCKSWCLK 0
#define  PIN_AF_A15_I2S3_WS 6
#define  PIN_AF_A15_JTDI 0
#define  PIN_AF_A15_SPI1_NSS 5
#define  PIN_AF_A15_SPI3_NSS 6
#define  PIN_AF_A15_TIM_2_CH1 1
#define  PIN_AF_A15_TIM_2_ETR 1

#define  PIN_AF_B0_ETH_MII_RXD2 11
#define  PIN_AF_B0_OTG_HS_ULPI_D1 10
#define  PIN_AF_B0_TIM1_CH2N 1
#define  PIN_AF_B0_TIM3_CH3 2
#define  PIN_AF_B0_TIM8_CH2N 3
#define  PIN_AF_B10_ETH_MII_RX_ER 11
#define  PIN_AF_B10_I2C2_SCL 4
#define  PIN_AF_B10_I2S2_CK 5
#define  PIN_AF_B10_OTG_HS_ULPI_D3 10
#define  PIN_AF_B10_SPI2_SCK 5
#define  PIN_AF_B10_TIM2_CH3 1
#define  PIN_AF_B10_USART3_TX 7
#define  PIN_AF_B11_ETH_MII_TX_EN 11
#define  PIN_AF_B11_ETH_RMII_TX_EN 11

#define  PIN_AF_B11_I2C2_SDA 4
#define  PIN_AF_B11_OTG_HS_ULPI_D4 10
#define  PIN_AF_B11_TIM2_CH4 1
#define  PIN_AF_B11_USART3_RX 7
#define  PIN_AF_B12_CAN2_RX 9
#define  PIN_AF_B12_ETH_MII_TXD0 11
#define  PIN_AF_B12_ETH_RMII_TXD0 11
#define  PIN_AF_B12_I2C2_SMBA 4
#define  PIN_AF_B12_I2S2_WS 5
#define  PIN_AF_B12_OTG_HS_ID 12
#define  PIN_AF_B12_OTG_HS_ULPI_D5 10
#define  PIN_AF_B12_SPI2_NSS 5
#define  PIN_AF_B12_TIM1_BKIN 1
#define  PIN_AF_B12_USART3_CK 7
#define  PIN_AF_B13_CAN2_TX 9
#define  PIN_AF_B13_ETH_MII_TXD1 11
#define  PIN_AF_B13_ETH_RMII_TXD1 11
#define  PIN_AF_B13_I2S2_CK 5
#define  PIN_AF_B13_OTG_HS_ULPI_D6 10
#define  PIN_AF_B13_SPI2_SCK 5
#define  PIN_AF_B13_TIM1_CH1N 1
#define  PIN_AF_B13_USART3_CTS 7
#define  PIN_AF_B14_I2S2ext_SD 6
#define  PIN_AF_B14_OTG_HS_DM 12
#define  PIN_AF_B14_SPI2_MISO 5
#define  PIN_AF_B14_TIM12_CH1 9
#define  PIN_AF_B14_TIM1_CH2N 1
#define  PIN_AF_B14_TIM8_CH2N 3
#define  PIN_AF_B14_USART3_RTS 7
#define  PIN_AF_B15_I2S2_SD 5
#define  PIN_AF_B15_OTG_HS_DP 12
#define  PIN_AF_B15_RTC_REFIN 0
#define  PIN_AF_B15_SPI2_MOSI 5
#define  PIN_AF_B15_TIM12_CH2 9
#define  PIN_AF_B15_TIM1_CH3N 1
#define  PIN_AF_B15_TIM8_CH3N 3
#define  PIN_AF_B1_ETH_MII_RXD3 11
#define  PIN_AF_B1_OTG_HS_ULPI_D2 10
#define  PIN_AF_B1_TIM1_CH3N 1
#define  PIN_AF_B1_TIM3_CH4 2
#define  PIN_AF_B1_TIM8_CH3N 3
#define  PIN_AF_B3_I2S3_CK 6
#define  PIN_AF_B3_JTDO 0
#define  PIN_AF_B3_SPI1_SCK 5
#define  PIN_AF_B3_SPI3_SCK 6
#define  PIN_AF_B3_TIM2_CH2 1
#define  PIN_AF_B3_TRACES_WO 0
#define  PIN_AF_B4_I2S3ext_SD 7
#define  PIN_AF_B4_NJTRST 0
#define  PIN_AF_B4_SPI1_MISO 5
#define  PIN_AF_B4_SPI3_MISO 6
#define  PIN_AF_B4_TIM3_CH1 2
#define  PIN_AF_B5_CAN2_RX 9
#define  PIN_AF_B5_DCMI_D10 13
#define  PIN_AF_B5_ETH_PPS_OUT 11
#define  PIN_AF_B5_I2C1_SMB_A 4
#define  PIN_AF_B5_I2S3_SD 6
#define  PIN_AF_B5_OTG_HS_ULPI_D7 10
#define  PIN_AF_B5_SPI1_MOSI 5
#define  PIN_AF_B5_SPI3_MOSI 6
#define  PIN_AF_B5_TIM3_CH2 2
#define  PIN_AF_B6_CAN2_TX 9
#define  PIN_AF_B6_DCMI_D5 13
#define  PIN_AF_B6_I2C1_SCL 4
#define  PIN_AF_B6_TIM4_CH1 2
#define  PIN_AF_B6_USART1_TX 7
#define  PIN_AF_B7_DCMI_VSYN_C 13
#define  PIN_AF_B7_FSMC_NL 12
#define  PIN_AF_B7_I2C1_SDA 4
#define  PIN_AF_B7_TIM4_CH2 2
#define  PIN_AF_B7_USART1_RX 7
#define  PIN_AF_B8_CAN1_RX 9
#define  PIN_AF_B8_DCMI_D6 13
#define  PIN_AF_B8_ETH_MII_TXD3 11
#define  PIN_AF_B8_I2C1_SCL 4
#define  PIN_AF_B8_SDIO_D4 12
#define  PIN_AF_B8_TIM10_CH1 3
#define  PIN_AF_B8_TIM4_CH3 2
#define  PIN_AF_B9_CAN1_TX 9
#define  PIN_AF_B9_DCMI_D7 13
#define  PIN_AF_B9_I2C1_SDA 4
#define  PIN_AF_B9_I2S2_WS 5
#define  PIN_AF_B9_SDIO_D5 12
#define  PIN_AF_B9_SPI2_NSS 5
#define  PIN_AF_B9_TIM11_CH1 3
#define  PIN_AF_B9_TIM4_CH4 2
#define  PIN_AF_C0_OTG_HS_ULPI_STP 10
#define  PIN_AF_C10_DCMI_D8 13
#define  PIN_AF_C10_I2S3_CK 6
#define  PIN_AF_C10_SDIO_D2 12
#define  PIN_AF_C10_SPI3_SCK 6
#define  PIN_AF_C10_UART4_TX 8
#define  PIN_AF_C10_USART3_TX 7
#define  PIN_AF_C11_DCMI_D4 13
#define  PIN_AF_C11_I2S3ext_SD 5
#define  PIN_AF_C11_SDIO_D3 12
#define  PIN_AF_C11_SPI3_MISO 6
#define  PIN_AF_C11_UART4_RX 8
#define  PIN_AF_C11_USART3_RX 7
#define  PIN_AF_C12_DCMI_D9 13
#define  PIN_AF_C12_I2S3_SD 6
#define  PIN_AF_C12_SDIO_CK 12
#define  PIN_AF_C12_SPI3_MOSI 6
#define  PIN_AF_C12_UART5_TX 8
#define  PIN_AF_C12_USART3_CK 7
#define  PIN_AF_C1_ETH_MDC 11
#define  PIN_AF_C2_ETH_MII_TXD2 11
#define  PIN_AF_C2_I2S2ext_SD 6
#define  PIN_AF_C2_OTG_HS_ULPI_DIR 10
#define  PIN_AF_C2_SPI2_MISO 5
#define  PIN_AF_C3_ETH_MII_TX_CLK 11
#define  PIN_AF_C3_I2S2_SD 5
#define  PIN_AF_C3_OTG_HS_ULPI_NXT 10
#define  PIN_AF_C3_SPI2_MOSI 5
#define  PIN_AF_C4_ETH_MII_RXD0 11
#define  PIN_AF_C4_ETH_RMII_RXD0 11
#define  PIN_AF_C5_ETH_MII_RXD1 11
#define  PIN_AF_C5_ETH_RMII_RXD1 11
#define  PIN_AF_C6_DCMI_D0 13
#define  PIN_AF_C6_I2S2_MCK 5
#define  PIN_AF_C6_SDIO_D6 12
#define  PIN_AF_C6_TIM3_CH1 2
#define  PIN_AF_C6_TIM8_CH1 3
#define  PIN_AF_C6_USART6_TX 8
#define  PIN_AF_C7_DCMI_D1 13
#define  PIN_AF_C7_I2S3_MCK 6
#define  PIN_AF_C7_SDIO_D7 12
#define  PIN_AF_C7_TIM3_CH2 2
#define  PIN_AF_C7_TIM8_CH2 3
#define  PIN_AF_C7_USART6_RX 8
#define  PIN_AF_C8_DCMI_D2 13
#define  PIN_AF_C8_SDIO_D0 12
#define  PIN_AF_C8_TIM3_CH3 2
#define  PIN_AF_C8_TIM8_CH3 3
#define  PIN_AF_C8_USART6_CK 8
#define  PIN_AF_C9_DCMI_D3 13
#define  PIN_AF_C9_I2C3_SDA 4
#define  PIN_AF_C9_I2S_CKIN 5
#define  PIN_AF_C9_MCO2 0
#define  PIN_AF_C9_SDIO_D1 12
#define  PIN_AF_C9_TIM3_CH4 2
#define  PIN_AF_C9_TIM8_CH4 3
#define  PIN_AF_D0_CAN1_RX 9
#define  PIN_AF_D0_FSMC_D2 12
#define  PIN_AF_D10_FSMC_D15 12
#define  PIN_AF_D10_USART3_CK 7
#define  PIN_AF_D11_FSMC_A16 12
#define  PIN_AF_D11_USART3_CTS 7
#define  PIN_AF_D12_FSMC_A17 12
#define  PIN_AF_D12_TIM4_CH1 2
#define  PIN_AF_D12_USART3_RTS 7
#define  PIN_AF_D13_FSMC_A18 12
#define  PIN_AF_D13_TIM4_CH2 2
#define  PIN_AF_D14_FSMC_D0 12
#define  PIN_AF_D14_TIM4_CH3 2
#define  PIN_AF_D15_FSMC_D1 12
#define  PIN_AF_D15_TIM4_CH4 2
#define  PIN_AF_D1_CAN1_TX 9
#define  PIN_AF_D1_FSMC_D3 12
#define  PIN_AF_D2_DCMI_D11 13
#define  PIN_AF_D2_SDIO_CMD 12
#define  PIN_AF_D2_TIM3_ETR 2
#define  PIN_AF_D2_UART5_RX 8
#define  PIN_AF_D3_FSMC_CLK 12
#define  PIN_AF_D3_USART2_CTS 7
#define  PIN_AF_D4_FSMC_NOE 12
#define  PIN_AF_D4_USART2_RTS 7
#define  PIN_AF_D5_FSMC_NWE 12
#define  PIN_AF_D5_USART2_TX 7
#define  PIN_AF_D6_FSMC_NWAIT 12
#define  PIN_AF_D6_USART2_RX 7
#define  PIN_AF_D7_FSMC_NCE2 12
#define  PIN_AF_D7_FSMC_NE1 12
#define  PIN_AF_D7_USART2_CK 7
#define  PIN_AF_D8_FSMC_D13 12
#define  PIN_AF_D8_USART3_TX 7
#define  PIN_AF_D9_FSMC_D14 12
#define  PIN_AF_D9_USART3_RX 7
#define  PIN_AF_E0_DCMI_D2 13
#define  PIN_AF_E0_FSMC_NBL0 12
#define  PIN_AF_E0_TIM4_ETR 2
#define  PIN_AF_E10_FSMC_D7 12
#define  PIN_AF_E10_TIM1_CH2N 1
#define  PIN_AF_E11_FSMC_D8 12
#define  PIN_AF_E11_TIM1_CH2 1
#define  PIN_AF_E12_FSMC_D9 12
#define  PIN_AF_E12_TIM1_CH3N 1
#define  PIN_AF_E13_FSMC_D10 12
#define  PIN_AF_E13_TIM1_CH3 1
#define  PIN_AF_E14_FSMC_D11 12
#define  PIN_AF_E14_TIM1_CH4 1
#define  PIN_AF_E15_FSMC_D12 12
#define  PIN_AF_E15_TIM1_BKIN 1
#define  PIN_AF_E1_DCMI_D3 13
#define  PIN_AF_E1_FSMC_NBL1 12
#define  PIN_AF_E2_ETH_MII_TXD3 11
#define  PIN_AF_E2_FSMC_A23 12
#define  PIN_AF_E2_TRACECLK 0
#define  PIN_AF_E3_FSMC_A19 12
#define  PIN_AF_E3_TRACED0 0
#define  PIN_AF_E4_DCMI_D4 13
#define  PIN_AF_E4_FSMC_A20 12
#define  PIN_AF_E4_TRACED1 0
#define  PIN_AF_E5_DCMI_D6 13
#define  PIN_AF_E5_FSMC_A21 12
#define  PIN_AF_E5_TIM9_CH1 3
#define  PIN_AF_E5_TRACED2 0
#define  PIN_AF_E6_DCMI_D7 13
#define  PIN_AF_E6_FSMC_A22 12
#define  PIN_AF_E6_TIM9_CH2 3
#define  PIN_AF_E6_TRACED3 0
#define  PIN_AF_E7_FSMC_D4 12
#define  PIN_AF_E7_TIM1_ETR 1
#define  PIN_AF_E8_FSMC_D5 12
#define  PIN_AF_E8_TIM1_CH1N 1
#define  PIN_AF_E9_FSMC_D6 12
#define  PIN_AF_E9_TIM1_CH1 1
#define  PIN_AF_F0_FSMC_A0 12
#define  PIN_AF_F0_I2C2_SDA 4
#define  PIN_AF_F10_FSMC_INTR 12
#define  PIN_AF_F11_DCMI_D12 13
#define  PIN_AF_F12_FSMC_A6 12
#define  PIN_AF_F13_FSMC_A7 12
#define  PIN_AF_F14_FSMC_A8 12
#define  PIN_AF_F15_FSMC_A9 12
#define  PIN_AF_F1_FSMC_A1 12
#define  PIN_AF_F1_I2C2_SCL 4
#define  PIN_AF_F2_FSMC_A2 12
#define  PIN_AF_F2_I2C2_SMBA 4
#define  PIN_AF_F3_FSMC_A3 12
#define  PIN_AF_F4_FSMC_A4 12
#define  PIN_AF_F5_FSMC_A5 12
#define  PIN_AF_F6_FSMC_NIORD 12
#define  PIN_AF_F6_TIM10_CH1 3
#define  PIN_AF_F7_FSMC_NREG 12
#define  PIN_AF_F7_TIM11_CH1 3
#define  PIN_AF_F8_FSMC_NIOWR 12
#define  PIN_AF_F8_TIM13_CH1 9
#define  PIN_AF_F9_FSMC_CD 12
#define  PIN_AF_F9_TIM14_CH1 9
#define  PIN_AF_G0_FSMC_A10 12
#define  PIN_AF_G10_FSMC_NCE4_1 12
#define  PIN_AF_G10_FSMC_NE3 12
#define  PIN_AF_G11_ETH_MII_TX_EN 11
#define  PIN_AF_G11_ETH_RMII_TX_EN 11
#define  PIN_AF_G11_FSMC_NCE4_2 12
#define  PIN_AF_G12_FSMC_NE4 12
#define  PIN_AF_G12_USART6_RTS 8
#define  PIN_AF_G13_ETH_MII_TXD0 11
#define  PIN_AF_G13_ETH_RMII_TXD0 11
#define  PIN_AF_G13_FSMC_A24 12
#define  PIN_AF_G13_UART6_CTS 8
#define  PIN_AF_G14_ETH_MII_TXD1 11
#define  PIN_AF_G14_ETH_RMII_TXD1 11
#define  PIN_AF_G14_FSMC_A25 12
#define  PIN_AF_G14_USART6_TX 8
#define  PIN_AF_G15_DCMI_D13 13
#define  PIN_AF_G15_USART6_CTS 8
#define  PIN_AF_G1_FSMC_A11 12
#define  PIN_AF_G2_FSMC_A12 12
#define  PIN_AF_G3_FSMC_A13 12
#define  PIN_AF_G4_FSMC_A14 12
#define  PIN_AF_G5_FSMC_A15 12
#define  PIN_AF_G6_FSMC_INT2 12
#define  PIN_AF_G7_FSMC_INT3 12
#define  PIN_AF_G7_USART6_CK 8
#define  PIN_AF_G8_ETH_PPS_OUT 11
#define  PIN_AF_G8_USART6_RTS 8
#define  PIN_AF_G9_FSMC_NCE3 12
#define  PIN_AF_G9_FSMC_NE2 12
#define  PIN_AF_G9_USART6_RX 8
#define  PIN_AF_H10_DCMI_D1 13
#define  PIN_AF_H10_TIM5_CH1 2
#define  PIN_AF_H11_DCMI_D2 13
#define  PIN_AF_H11_TIM5_CH2 2
#define  PIN_AF_H12_DCMI_D3 13
#define  PIN_AF_H12_TIM5_CH3 2
#define  PIN_AF_H13_CAN1_TX 9
#define  PIN_AF_H13_TIM8_CH1N 3
#define  PIN_AF_H14_DCMI_D4 13
#define  PIN_AF_H14_TIM8_CH2N 3
#define  PIN_AF_H15_DCMI_D11 13
#define  PIN_AF_H15_TIM8_CH3N 3
#define  PIN_AF_H2_ETH_MII_CRS 11
#define  PIN_AF_H3_ETH_MII_COL 11
#define  PIN_AF_H4_I2C2_SCL 4
#define  PIN_AF_H4_OTG_HS_ULPI_NXT 10
#define  PIN_AF_H5_I2C2_SDA 4
#define  PIN_AF_H6_ETH_MII_RXD2 11
#define  PIN_AF_H6_I2C2_SMBA 4
#define  PIN_AF_H6_TIM12_CH1 9
#define  PIN_AF_H7_ETH_MII_RXD3 11
#define  PIN_AF_H7_I2C3_SCL 4
#define  PIN_AF_H8_DCMI_HSYNC 13
#define  PIN_AF_H8_I2C3_SDA 4
#define  PIN_AF_H9_DCMI_D0 13
#define  PIN_AF_H9_I2C3_SMBA 4
#define  PIN_AF_H9_TIM12_CH2 9
#define  PIN_AF_I0_DCMI_D13 13
#define  PIN_AF_I0_I2S2_WS 5
#define  PIN_AF_I0_SPI2_NSS 5
#define  PIN_AF_I0_TIM5_CH4 2
#define  PIN_AF_I10_ETH_MII_RX_ER 11
#define  PIN_AF_I11_OTG_HS_ULPI_DIR 10
#define  PIN_AF_I1_DCMI_D8 13
#define  PIN_AF_I1_I2S2_CK 5
#define  PIN_AF_I1_SPI2_SCK 5
#define  PIN_AF_I2_DCMI_D9 13
#define  PIN_AF_I2_I2S2ext_SD 6
#define  PIN_AF_I2_SPI2_MISO 5
#define  PIN_AF_I2_TIM8_CH4 3
#define  PIN_AF_I3_DCMI_D10 13
#define  PIN_AF_I3_I2S2_SD 5
#define  PIN_AF_I3_SPI2_MOSI 5
#define  PIN_AF_I3_TIM8_ETR 3
#define  PIN_AF_I4_DCMI_D5 13
#define  PIN_AF_I4_TIM8_BKIN 3
#define  PIN_AF_I5_DCMI_VSYNC 13
#define  PIN_AF_I5_TIM8_CH1 3
#define  PIN_AF_I6_DCMI_D6 13
#define  PIN_AF_I6_TIM8_CH2 3
#define  PIN_AF_I7_DCMI_D7 13
#define  PIN_AF_I7_TIM8_CH3 3
#define  PIN_AF_I9_CAN1_RX 9


#ifdef __cplusplus
}
#endif
#endif /* GPIO_AF_FXX_H_ */

/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    can.h
 * @brief   This file contains all the function prototypes for
 *          the can.c file
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CAN_H__
#define __CAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan2;

/* USER CODE BEGIN Private defines */


/*
* ID Display-> MEK
*/
#define CANBUS_DISPLAY_TX_START   			0x400   /*Define Send Device ID*/
#define	CANBUS_DISPLAY_TX_BTN_ACEPT_CONTROL	0x400
#define	CANBUS_DISPLAY_TX_BTN_GOOD			0x401
#define	CANBUS_DISPLAY_TX_BTN_OK			0x402
#define	CANBUS_DISPLAY_TX_BTN_BAD			0x403
#define	CANBUS_DISPLAY_TX_IDNR_5	0x404
#define	CANBUS_DISPLAY_TX_IDNR_6	0x405
#define	CANBUS_DISPLAY_TX_IDNR_7	0x406
#define	CANBUS_DISPLAY_TX_IDNR_8	0x407
#define	CANBUS_DISPLAY_TX_IDNR_9	0x408
#define	CANBUS_DISPLAY_TX_IDNR_10	0x409
#define	CANBUS_DISPLAY_TX_IDNR_11	0x40A
#define	CANBUS_DISPLAY_TX_IDNR_12	0x40B
#define	CANBUS_DISPLAY_TX_IDNR_13	0x40C
#define	CANBUS_DISPLAY_TX_IDNR_14	0x40D
#define	CANBUS_DISPLAY_TX_IDNR_15	0x40E
#define	CANBUS_DISPLAY_TX_IDNR_16	0x40F
#define	CANBUS_DISPLAY_TX_IDNR_17	0x410
#define	CANBUS_DISPLAY_TX_IDNR_18	0x411
#define	CANBUS_DISPLAY_TX_IDNR_19	0x412
#define	CANBUS_DISPLAY_TX_IDNR_20	0x413
#define	CANBUS_DISPLAY_TX_IDNR_21	0x414
#define	CANBUS_DISPLAY_TX_IDNR_22	0x415
#define	CANBUS_DISPLAY_TX_IDNR_23	0x416
#define	CANBUS_DISPLAY_TX_IDNR_24	0x417
#define	CANBUS_DISPLAY_TX_IDNR_25	0x418
#define	CANBUS_DISPLAY_TX_IDNR_26	0x419
#define	CANBUS_DISPLAY_TX_IDNR_27	0x41A
#define	CANBUS_DISPLAY_TX_IDNR_28	0x41B
#define	CANBUS_DISPLAY_TX_IDNR_29	0x41C
#define	CANBUS_DISPLAY_TX_IDNR_30	0x41D
#define	CANBUS_DISPLAY_TX_IDNR_31	0x41E
#define	CANBUS_DISPLAY_TX_IDNR_32	0x41F
#define	CANBUS_DISPLAY_TX_IDNR_33	0x420
#define	CANBUS_DISPLAY_TX_IDNR_34	0x421
#define	CANBUS_DISPLAY_TX_IDNR_35	0x422
#define	CANBUS_DISPLAY_TX_IDNR_36	0x423
#define	CANBUS_DISPLAY_TX_IDNR_37	0x424
#define	CANBUS_DISPLAY_TX_IDNR_38	0x425
#define	CANBUS_DISPLAY_TX_IDNR_39	0x426
#define	CANBUS_DISPLAY_TX_IDNR_40	0x427
#define	CANBUS_DISPLAY_TX_IDNR_41	0x428
#define	CANBUS_DISPLAY_TX_IDNR_42	0x429
#define	CANBUS_DISPLAY_TX_IDNR_43	0x42A
#define	CANBUS_DISPLAY_TX_IDNR_44	0x42B
#define	CANBUS_DISPLAY_TX_IDNR_45	0x42C
#define	CANBUS_DISPLAY_TX_IDNR_46	0x42D
#define	CANBUS_DISPLAY_TX_IDNR_47	0x42E
#define	CANBUS_DISPLAY_TX_IDNR_48	0x42F
#define	CANBUS_DISPLAY_TX_IDNR_49	0x430
#define	CANBUS_DISPLAY_TX_IDNR_50	0x431
#define	CANBUS_DISPLAY_TX_IDNR_51	0x432
#define	CANBUS_DISPLAY_TX_IDNR_52	0x433
#define	CANBUS_DISPLAY_TX_IDNR_53	0x434
#define	CANBUS_DISPLAY_TX_IDNR_54	0x435
#define	CANBUS_DISPLAY_TX_IDNR_55	0x436
#define	CANBUS_DISPLAY_TX_IDNR_56	0x437
#define	CANBUS_DISPLAY_TX_IDNR_57	0x438
#define	CANBUS_DISPLAY_TX_IDNR_58	0x439
#define	CANBUS_DISPLAY_TX_IDNR_59	0x43A
#define	CANBUS_DISPLAY_TX_IDNR_60	0x43B
#define	CANBUS_DISPLAY_TX_IDNR_61	0x43C
#define	CANBUS_DISPLAY_TX_IDNR_62	0x43D
#define	CANBUS_DISPLAY_TX_IDNR_63	0x43E
#define	CANBUS_DISPLAY_TX_IDNR_64	0x43F
#define	CANBUS_DISPLAY_TX_IDNR_65	0x440
#define	CANBUS_DISPLAY_TX_IDNR_66	0x441
#define	CANBUS_DISPLAY_TX_IDNR_67	0x442
#define	CANBUS_DISPLAY_TX_IDNR_68	0x443
#define	CANBUS_DISPLAY_TX_IDNR_69	0x444
#define	CANBUS_DISPLAY_TX_IDNR_70	0x445
#define	CANBUS_DISPLAY_TX_IDNR_71	0x446
#define	CANBUS_DISPLAY_TX_IDNR_72	0x447
#define	CANBUS_DISPLAY_TX_IDNR_73	0x448
#define	CANBUS_DISPLAY_TX_IDNR_74	0x449
#define	CANBUS_DISPLAY_TX_IDNR_75	0x44A
#define	CANBUS_DISPLAY_TX_IDNR_76	0x44B
#define	CANBUS_DISPLAY_TX_IDNR_77	0x44C
#define	CANBUS_DISPLAY_TX_IDNR_78	0x44D
#define	CANBUS_DISPLAY_TX_IDNR_79	0x44E
#define	CANBUS_DISPLAY_TX_IDNR_80	0x44F
#define	CANBUS_DISPLAY_TX_IDNR_81	0x450
#define	CANBUS_DISPLAY_TX_IDNR_82	0x451
#define	CANBUS_DISPLAY_TX_IDNR_83	0x452
#define	CANBUS_DISPLAY_TX_IDNR_84	0x453
#define	CANBUS_DISPLAY_TX_IDNR_85	0x454
#define	CANBUS_DISPLAY_TX_IDNR_86	0x455
#define	CANBUS_DISPLAY_TX_IDNR_87	0x456
#define	CANBUS_DISPLAY_TX_IDNR_88	0x457
#define	CANBUS_DISPLAY_TX_IDNR_89	0x458
#define	CANBUS_DISPLAY_TX_IDNR_90	0x459
#define	CANBUS_DISPLAY_TX_IDNR_91	0x45A
#define	CANBUS_DISPLAY_TX_IDNR_92	0x45B
#define	CANBUS_DISPLAY_TX_IDNR_93	0x45C
#define	CANBUS_DISPLAY_TX_IDNR_94	0x45D
#define	CANBUS_DISPLAY_TX_IDNR_95	0x45E
#define	CANBUS_DISPLAY_TX_IDNR_96	0x45F
#define	CANBUS_DISPLAY_TX_IDNR_97	0x460
#define	CANBUS_DISPLAY_TX_IDNR_98	0x461
#define	CANBUS_DISPLAY_TX_IDNR_99	0x462
#define	CANBUS_DISPLAY_TX_IDNR_100	0x463
#define	CANBUS_DISPLAY_TX_IDNR_101	0x464
#define	CANBUS_DISPLAY_TX_IDNR_102	0x465
#define	CANBUS_DISPLAY_TX_IDNR_103	0x466
#define	CANBUS_DISPLAY_TX_IDNR_104	0x467
#define	CANBUS_DISPLAY_TX_IDNR_105	0x468
#define	CANBUS_DISPLAY_TX_IDNR_106	0x469
#define	CANBUS_DISPLAY_TX_IDNR_107	0x46A
#define	CANBUS_DISPLAY_TX_IDNR_108	0x46B
#define	CANBUS_DISPLAY_TX_IDNR_109	0x46C
#define	CANBUS_DISPLAY_TX_IDNR_110	0x46D
#define	CANBUS_DISPLAY_TX_IDNR_111	0x46E
#define	CANBUS_DISPLAY_TX_IDNR_112	0x46F
#define	CANBUS_DISPLAY_TX_IDNR_113	0x470
#define	CANBUS_DISPLAY_TX_IDNR_114	0x471
#define	CANBUS_DISPLAY_TX_IDNR_115	0x472
#define	CANBUS_DISPLAY_TX_IDNR_116	0x473
#define	CANBUS_DISPLAY_TX_IDNR_117	0x474
#define	CANBUS_DISPLAY_TX_IDNR_118	0x475
#define	CANBUS_DISPLAY_TX_IDNR_119	0x476
#define	CANBUS_DISPLAY_TX_IDNR_120	0x477
#define	CANBUS_DISPLAY_TX_IDNR_121	0x478
#define	CANBUS_DISPLAY_TX_IDNR_122	0x479
#define	CANBUS_DISPLAY_TX_IDNR_123	0x47A
#define	CANBUS_DISPLAY_TX_IDNR_124	0x47B
#define	CANBUS_DISPLAY_TX_IDNR_125	0x47C
#define	CANBUS_DISPLAY_TX_IDNR_126	0x47D
#define	CANBUS_DISPLAY_TX_IDNR_127	0x47E
#define	CANBUS_DISPLAY_TX_IDNR_128	0x47F
#define	CANBUS_DISPLAY_TX_IDNR_129	0x480
#define	CANBUS_DISPLAY_TX_IDNR_130	0x481
#define	CANBUS_DISPLAY_TX_IDNR_131	0x482
#define	CANBUS_DISPLAY_TX_IDNR_132	0x483
#define	CANBUS_DISPLAY_TX_IDNR_133	0x484
#define	CANBUS_DISPLAY_TX_IDNR_134	0x485
#define	CANBUS_DISPLAY_TX_IDNR_135	0x486
#define	CANBUS_DISPLAY_TX_IDNR_136	0x487
#define	CANBUS_DISPLAY_TX_IDNR_137	0x488
#define	CANBUS_DISPLAY_TX_IDNR_138	0x489
#define	CANBUS_DISPLAY_TX_IDNR_139	0x48A
#define	CANBUS_DISPLAY_TX_IDNR_140	0x48B
#define	CANBUS_DISPLAY_TX_IDNR_141	0x48C
#define	CANBUS_DISPLAY_TX_IDNR_142	0x48D
#define	CANBUS_DISPLAY_TX_IDNR_143	0x48E
#define	CANBUS_DISPLAY_TX_IDNR_144	0x48F
#define	CANBUS_DISPLAY_TX_IDNR_145	0x490
#define	CANBUS_DISPLAY_TX_IDNR_146	0x491
#define	CANBUS_DISPLAY_TX_IDNR_147	0x492
#define	CANBUS_DISPLAY_TX_IDNR_148	0x493
#define	CANBUS_DISPLAY_TX_IDNR_149	0x494
#define	CANBUS_DISPLAY_TX_IDNR_150	0x495
#define	CANBUS_DISPLAY_TX_IDNR_151	0x496
#define	CANBUS_DISPLAY_TX_IDNR_152	0x497
#define	CANBUS_DISPLAY_TX_IDNR_153	0x498
#define	CANBUS_DISPLAY_TX_IDNR_154	0x499
#define	CANBUS_DISPLAY_TX_IDNR_155	0x49A
#define	CANBUS_DISPLAY_TX_IDNR_156	0x49B
#define	CANBUS_DISPLAY_TX_IDNR_157	0x49C
#define	CANBUS_DISPLAY_TX_IDNR_158	0x49D
#define	CANBUS_DISPLAY_TX_IDNR_159	0x49E
#define	CANBUS_DISPLAY_TX_IDNR_160	0x49F
#define	CANBUS_DISPLAY_TX_IDNR_161	0x4A0
#define	CANBUS_DISPLAY_TX_IDNR_162	0x4A1
#define	CANBUS_DISPLAY_TX_IDNR_163	0x4A2
#define	CANBUS_DISPLAY_TX_IDNR_164	0x4A3
#define	CANBUS_DISPLAY_TX_IDNR_165	0x4A4
#define	CANBUS_DISPLAY_TX_IDNR_166	0x4A5
#define	CANBUS_DISPLAY_TX_IDNR_167	0x4A6
#define	CANBUS_DISPLAY_TX_IDNR_168	0x4A7
#define	CANBUS_DISPLAY_TX_IDNR_169	0x4A8
#define	CANBUS_DISPLAY_TX_IDNR_170	0x4A9
#define	CANBUS_DISPLAY_TX_IDNR_171	0x4AA
#define	CANBUS_DISPLAY_TX_IDNR_172	0x4AB
#define	CANBUS_DISPLAY_TX_IDNR_173	0x4AC
#define	CANBUS_DISPLAY_TX_IDNR_174	0x4AD
#define	CANBUS_DISPLAY_TX_IDNR_175	0x4AE
#define	CANBUS_DISPLAY_TX_IDNR_176	0x4AF
#define	CANBUS_DISPLAY_TX_IDNR_177	0x4B0
#define	CANBUS_DISPLAY_TX_IDNR_178	0x4B1
#define	CANBUS_DISPLAY_TX_IDNR_179	0x4B2
#define	CANBUS_DISPLAY_TX_IDNR_180	0x4B3
#define	CANBUS_DISPLAY_TX_IDNR_181	0x4B4
#define	CANBUS_DISPLAY_TX_IDNR_182	0x4B5
#define	CANBUS_DISPLAY_TX_IDNR_183	0x4B6
#define	CANBUS_DISPLAY_TX_IDNR_184	0x4B7
#define	CANBUS_DISPLAY_TX_IDNR_185	0x4B8
#define	CANBUS_DISPLAY_TX_IDNR_186	0x4B9
#define	CANBUS_DISPLAY_TX_IDNR_187	0x4BA
#define	CANBUS_DISPLAY_TX_IDNR_188	0x4BB
#define	CANBUS_DISPLAY_TX_IDNR_189	0x4BC
#define	CANBUS_DISPLAY_TX_IDNR_190	0x4BD
#define	CANBUS_DISPLAY_TX_IDNR_191	0x4BE
#define	CANBUS_DISPLAY_TX_IDNR_192	0x4BF
#define	CANBUS_DISPLAY_TX_IDNR_193	0x4C0
#define	CANBUS_DISPLAY_TX_IDNR_194	0x4C1
#define	CANBUS_DISPLAY_TX_IDNR_195	0x4C2
#define	CANBUS_DISPLAY_TX_IDNR_196	0x4C3
#define	CANBUS_DISPLAY_TX_IDNR_197	0x4C4
#define	CANBUS_DISPLAY_TX_IDNR_198	0x4C5
#define	CANBUS_DISPLAY_TX_IDNR_199	0x4C6
#define	CANBUS_DISPLAY_TX_IDNR_200	0x4C7
#define	CANBUS_DISPLAY_TX_IDNR_201	0x4C8
#define	CANBUS_DISPLAY_TX_IDNR_202	0x4C9
#define	CANBUS_DISPLAY_TX_IDNR_203	0x4CA
#define	CANBUS_DISPLAY_TX_IDNR_204	0x4CB
#define	CANBUS_DISPLAY_TX_IDNR_205	0x4CC
#define	CANBUS_DISPLAY_TX_IDNR_206	0x4CD
#define	CANBUS_DISPLAY_TX_IDNR_207	0x4CE
#define	CANBUS_DISPLAY_TX_IDNR_208	0x4CF
#define	CANBUS_DISPLAY_TX_IDNR_209	0x4D0
#define	CANBUS_DISPLAY_TX_IDNR_210	0x4D1
#define	CANBUS_DISPLAY_TX_IDNR_211	0x4D2
#define	CANBUS_DISPLAY_TX_IDNR_212	0x4D3
#define	CANBUS_DISPLAY_TX_IDNR_213	0x4D4
#define	CANBUS_DISPLAY_TX_IDNR_214	0x4D5
#define	CANBUS_DISPLAY_TX_IDNR_215	0x4D6
#define	CANBUS_DISPLAY_TX_IDNR_216	0x4D7
#define	CANBUS_DISPLAY_TX_IDNR_217	0x4D8
#define	CANBUS_DISPLAY_TX_IDNR_218	0x4D9
#define	CANBUS_DISPLAY_TX_IDNR_219	0x4DA
#define	CANBUS_DISPLAY_TX_IDNR_220	0x4DB
#define	CANBUS_DISPLAY_TX_IDNR_221	0x4DC
#define	CANBUS_DISPLAY_TX_IDNR_222	0x4DD
#define	CANBUS_DISPLAY_TX_IDNR_223	0x4DE
#define	CANBUS_DISPLAY_TX_IDNR_224	0x4DF
#define	CANBUS_DISPLAY_TX_IDNR_225	0x4E0
#define	CANBUS_DISPLAY_TX_IDNR_226	0x4E1
#define	CANBUS_DISPLAY_TX_IDNR_227	0x4E2
#define	CANBUS_DISPLAY_TX_IDNR_228	0x4E3
#define	CANBUS_DISPLAY_TX_IDNR_229	0x4E4
#define	CANBUS_DISPLAY_TX_IDNR_230	0x4E5
#define	CANBUS_DISPLAY_TX_IDNR_231	0x4E6
#define	CANBUS_DISPLAY_TX_IDNR_232	0x4E7
#define	CANBUS_DISPLAY_TX_IDNR_233	0x4E8
#define	CANBUS_DISPLAY_TX_IDNR_234	0x4E9
#define	CANBUS_DISPLAY_TX_IDNR_235	0x4EA
#define	CANBUS_DISPLAY_TX_IDNR_236	0x4EB
#define	CANBUS_DISPLAY_TX_IDNR_237	0x4EC
#define	CANBUS_DISPLAY_TX_IDNR_238	0x4ED
#define	CANBUS_DISPLAY_TX_IDNR_239	0x4EE
#define	CANBUS_DISPLAY_TX_IDNR_240	0x4EF
#define	CANBUS_DISPLAY_TX_IDNR_241	0x4F0
#define	CANBUS_DISPLAY_TX_IDNR_242	0x4F1
#define	CANBUS_DISPLAY_TX_IDNR_243	0x4F2
#define	CANBUS_DISPLAY_TX_IDNR_244	0x4F3
#define	CANBUS_DISPLAY_TX_IDNR_245	0x4F4
#define	CANBUS_DISPLAY_TX_IDNR_246	0x4F5
#define	CANBUS_DISPLAY_TX_IDNR_247	0x4F6
#define	CANBUS_DISPLAY_TX_IDNR_248	0x4F7
#define	CANBUS_DISPLAY_TX_IDNR_249	0x4F8
#define	CANBUS_DISPLAY_TX_IDNR_250	0x4F9
#define	CANBUS_DISPLAY_TX_IDNR_251	0x4FA
#define	CANBUS_DISPLAY_TX_IDNR_252	0x4FB
#define	CANBUS_DISPLAY_TX_IDNR_253	0x4FC
#define	CANBUS_DISPLAY_TX_IDNR_254	0x4FD
#define	CANBUS_DISPLAY_TX_IDNR_255	0x4FE
#define	CANBUS_DISPLAY_TX_IDNR_256	0x4FF
#define CANBUS_DISPLAY_TX_END   0x4FF   /*Define END Device ID for SEND*/

/*
* **************************************ID MEK->Display**********
*/
#define CANBUS_DISPLAY_RX_START		0x500   /*Define START Device ID*/
#define	CANBUS_DISPLAY_RX_USER_ID  	0x500
#define CANBUS_DISPLAY_RX_LOG_IN   	0x501
#define CANBUS_DISPLAY_RX_LOG_OUT  	0x502
#define CANBUS_DISPLAY_RX_LANGUAGE 	0x503
#define CANBUS_DISPLAY_RX_SCREEN	0x504
#define 	 CANBUS_DISPLAY_RX_IDNR_6   0x505
#define 	 CANBUS_DISPLAY_RX_IDNR_7	0x506
#define 	 CANBUS_DISPLAY_RX_IDNR_7	0x506
#define 	 CANBUS_DISPLAY_RX_IDNR_8	0x507
#define 	 CANBUS_DISPLAY_RX_IDNR_9	0x508
#define 	 CANBUS_DISPLAY_RX_IDNR_10	0x509
#define 	 CANBUS_DISPLAY_RX_IDNR_11	0x50A
#define 	 CANBUS_DISPLAY_RX_IDNR_12	0x50B
#define 	 CANBUS_DISPLAY_RX_IDNR_13	0x50C
#define 	 CANBUS_DISPLAY_RX_IDNR_14	0x50D
#define 	 CANBUS_DISPLAY_RX_IDNR_15	0x50E
#define 	 CANBUS_DISPLAY_RX_IDNR_16	0x50F
#define 	 CANBUS_DISPLAY_RX_IDNR_17	0x510
#define 	 CANBUS_DISPLAY_RX_IDNR_18	0x511
#define 	 CANBUS_DISPLAY_RX_IDNR_19	0x512
#define 	 CANBUS_DISPLAY_RX_IDNR_20	0x513
#define 	 CANBUS_DISPLAY_RX_IDNR_21	0x514
#define 	 CANBUS_DISPLAY_RX_IDNR_22	0x515
#define 	 CANBUS_DISPLAY_RX_IDNR_23	0x516
#define 	 CANBUS_DISPLAY_RX_IDNR_24	0x517
#define 	 CANBUS_DISPLAY_RX_IDNR_25	0x518
#define 	 CANBUS_DISPLAY_RX_IDNR_26	0x519
#define 	 CANBUS_DISPLAY_RX_IDNR_27	0x51A
#define 	 CANBUS_DISPLAY_RX_IDNR_28	0x51B
#define 	 CANBUS_DISPLAY_RX_IDNR_29	0x51C
#define 	 CANBUS_DISPLAY_RX_IDNR_30	0x51D
#define 	 CANBUS_DISPLAY_RX_IDNR_31	0x51E
#define 	 CANBUS_DISPLAY_RX_IDNR_32	0x51F
#define 	 CANBUS_DISPLAY_RX_IDNR_33	0x520
#define 	 CANBUS_DISPLAY_RX_IDNR_34	0x521
#define 	 CANBUS_DISPLAY_RX_IDNR_35	0x522
#define 	 CANBUS_DISPLAY_RX_IDNR_36	0x523
#define 	 CANBUS_DISPLAY_RX_IDNR_37	0x524
#define 	 CANBUS_DISPLAY_RX_IDNR_38	0x525
#define 	 CANBUS_DISPLAY_RX_IDNR_39	0x526
#define 	 CANBUS_DISPLAY_RX_IDNR_40	0x527
#define 	 CANBUS_DISPLAY_RX_IDNR_41	0x528
#define 	 CANBUS_DISPLAY_RX_IDNR_42	0x529
#define 	 CANBUS_DISPLAY_RX_IDNR_43	0x52A
#define 	 CANBUS_DISPLAY_RX_IDNR_44	0x52B
#define 	 CANBUS_DISPLAY_RX_IDNR_45	0x52C
#define 	 CANBUS_DISPLAY_RX_IDNR_46	0x52D
#define 	 CANBUS_DISPLAY_RX_IDNR_47	0x52E
#define 	 CANBUS_DISPLAY_RX_IDNR_48	0x52F
#define 	 CANBUS_DISPLAY_RX_IDNR_49	0x530
#define 	 CANBUS_DISPLAY_RX_IDNR_50	0x531
#define 	 CANBUS_DISPLAY_RX_IDNR_51	0x532
#define 	 CANBUS_DISPLAY_RX_IDNR_52	0x533
#define 	 CANBUS_DISPLAY_RX_IDNR_53	0x534
#define 	 CANBUS_DISPLAY_RX_IDNR_54	0x535
#define 	 CANBUS_DISPLAY_RX_IDNR_55	0x536
#define 	 CANBUS_DISPLAY_RX_IDNR_56	0x537
#define 	 CANBUS_DISPLAY_RX_IDNR_57	0x538
#define 	 CANBUS_DISPLAY_RX_IDNR_58	0x539
#define 	 CANBUS_DISPLAY_RX_IDNR_59	0x53A
#define 	 CANBUS_DISPLAY_RX_IDNR_60	0x53B
#define 	 CANBUS_DISPLAY_RX_IDNR_61	0x53C
#define 	 CANBUS_DISPLAY_RX_IDNR_62	0x53D
#define 	 CANBUS_DISPLAY_RX_IDNR_63	0x53E
#define 	 CANBUS_DISPLAY_RX_IDNR_64	0x53F
#define 	 CANBUS_DISPLAY_RX_IDNR_65	0x540
#define 	 CANBUS_DISPLAY_RX_IDNR_66	0x541
#define 	 CANBUS_DISPLAY_RX_IDNR_67	0x542
#define 	 CANBUS_DISPLAY_RX_IDNR_68	0x543
#define 	 CANBUS_DISPLAY_RX_IDNR_69	0x544
#define 	 CANBUS_DISPLAY_RX_IDNR_70	0x545
#define 	 CANBUS_DISPLAY_RX_IDNR_71	0x546
#define 	 CANBUS_DISPLAY_RX_IDNR_72	0x547
#define 	 CANBUS_DISPLAY_RX_IDNR_73	0x548
#define 	 CANBUS_DISPLAY_RX_IDNR_74	0x549
#define 	 CANBUS_DISPLAY_RX_IDNR_75	0x54A
#define 	 CANBUS_DISPLAY_RX_IDNR_76	0x54B
#define 	 CANBUS_DISPLAY_RX_IDNR_77	0x54C
#define 	 CANBUS_DISPLAY_RX_IDNR_78	0x54D
#define 	 CANBUS_DISPLAY_RX_IDNR_79	0x54E
#define 	 CANBUS_DISPLAY_RX_IDNR_80	0x54F
#define 	 CANBUS_DISPLAY_RX_IDNR_81	0x550
#define 	 CANBUS_DISPLAY_RX_IDNR_82	0x551
#define 	 CANBUS_DISPLAY_RX_IDNR_83	0x552
#define 	 CANBUS_DISPLAY_RX_IDNR_84	0x553
#define 	 CANBUS_DISPLAY_RX_IDNR_85	0x554
#define 	 CANBUS_DISPLAY_RX_IDNR_86	0x555
#define 	 CANBUS_DISPLAY_RX_IDNR_87	0x556
#define 	 CANBUS_DISPLAY_RX_IDNR_88	0x557
#define 	 CANBUS_DISPLAY_RX_IDNR_89	0x558
#define 	 CANBUS_DISPLAY_RX_IDNR_90	0x559
#define 	 CANBUS_DISPLAY_RX_IDNR_91	0x55A
#define 	 CANBUS_DISPLAY_RX_IDNR_92	0x55B
#define 	 CANBUS_DISPLAY_RX_IDNR_93	0x55C
#define 	 CANBUS_DISPLAY_RX_IDNR_94	0x55D
#define 	 CANBUS_DISPLAY_RX_IDNR_95	0x55E
#define 	 CANBUS_DISPLAY_RX_IDNR_96	0x55F
#define 	 CANBUS_DISPLAY_RX_IDNR_97	0x560
#define 	 CANBUS_DISPLAY_RX_IDNR_98	0x561
#define 	 CANBUS_DISPLAY_RX_IDNR_99	0x562
#define 	 CANBUS_DISPLAY_RX_IDNR_100	0x563
#define 	 CANBUS_DISPLAY_RX_IDNR_101	0x564
#define 	 CANBUS_DISPLAY_RX_IDNR_102	0x565
#define 	 CANBUS_DISPLAY_RX_IDNR_103	0x566
#define 	 CANBUS_DISPLAY_RX_IDNR_104	0x567
#define 	 CANBUS_DISPLAY_RX_IDNR_105	0x568
#define 	 CANBUS_DISPLAY_RX_IDNR_106	0x569
#define 	 CANBUS_DISPLAY_RX_IDNR_107	0x56A
#define 	 CANBUS_DISPLAY_RX_IDNR_108	0x56B
#define 	 CANBUS_DISPLAY_RX_IDNR_109	0x56C
#define 	 CANBUS_DISPLAY_RX_IDNR_110	0x56D
#define 	 CANBUS_DISPLAY_RX_IDNR_111	0x56E
#define 	 CANBUS_DISPLAY_RX_IDNR_112	0x56F
#define 	 CANBUS_DISPLAY_RX_IDNR_113	0x570
#define 	 CANBUS_DISPLAY_RX_IDNR_114	0x571
#define 	 CANBUS_DISPLAY_RX_IDNR_115	0x572
#define 	 CANBUS_DISPLAY_RX_IDNR_116	0x573
#define 	 CANBUS_DISPLAY_RX_IDNR_117	0x574
#define 	 CANBUS_DISPLAY_RX_IDNR_118	0x575
#define 	 CANBUS_DISPLAY_RX_IDNR_119	0x576
#define 	 CANBUS_DISPLAY_RX_IDNR_120	0x577
#define 	 CANBUS_DISPLAY_RX_IDNR_121	0x578
#define 	 CANBUS_DISPLAY_RX_IDNR_122	0x579
#define 	 CANBUS_DISPLAY_RX_IDNR_123	0x57A
#define 	 CANBUS_DISPLAY_RX_IDNR_124	0x57B
#define 	 CANBUS_DISPLAY_RX_IDNR_125	0x57C
#define 	 CANBUS_DISPLAY_RX_IDNR_126	0x57D
#define 	 CANBUS_DISPLAY_RX_IDNR_127	0x57E
#define 	 CANBUS_DISPLAY_RX_IDNR_128	0x57F
#define 	 CANBUS_DISPLAY_RX_IDNR_129	0x580
#define 	 CANBUS_DISPLAY_RX_IDNR_130	0x581
#define 	 CANBUS_DISPLAY_RX_IDNR_131	0x582
#define 	 CANBUS_DISPLAY_RX_IDNR_132	0x583
#define 	 CANBUS_DISPLAY_RX_IDNR_133	0x584
#define 	 CANBUS_DISPLAY_RX_IDNR_134	0x585
#define 	 CANBUS_DISPLAY_RX_IDNR_135	0x586
#define 	 CANBUS_DISPLAY_RX_IDNR_136	0x587
#define 	 CANBUS_DISPLAY_RX_IDNR_137	0x588
#define 	 CANBUS_DISPLAY_RX_IDNR_138	0x589
#define 	 CANBUS_DISPLAY_RX_IDNR_139	0x58A
#define 	 CANBUS_DISPLAY_RX_IDNR_140	0x58B
#define 	 CANBUS_DISPLAY_RX_IDNR_141	0x58C
#define 	 CANBUS_DISPLAY_RX_IDNR_142	0x58D
#define 	 CANBUS_DISPLAY_RX_IDNR_143	0x58E
#define 	 CANBUS_DISPLAY_RX_IDNR_144	0x58F
#define 	 CANBUS_DISPLAY_RX_IDNR_145	0x590
#define 	 CANBUS_DISPLAY_RX_IDNR_146	0x591
#define 	 CANBUS_DISPLAY_RX_IDNR_147	0x592
#define 	 CANBUS_DISPLAY_RX_IDNR_148	0x593
#define 	 CANBUS_DISPLAY_RX_IDNR_149	0x594
#define 	 CANBUS_DISPLAY_RX_IDNR_150	0x595
#define 	 CANBUS_DISPLAY_RX_IDNR_151	0x596
#define 	 CANBUS_DISPLAY_RX_IDNR_152	0x597
#define 	 CANBUS_DISPLAY_RX_IDNR_153	0x598
#define 	 CANBUS_DISPLAY_RX_IDNR_154	0x599
#define 	 CANBUS_DISPLAY_RX_IDNR_155	0x59A
#define 	 CANBUS_DISPLAY_RX_IDNR_156	0x59B
#define 	 CANBUS_DISPLAY_RX_IDNR_157	0x59C
#define 	 CANBUS_DISPLAY_RX_IDNR_158	0x59D
#define 	 CANBUS_DISPLAY_RX_IDNR_159	0x59E
#define 	 CANBUS_DISPLAY_RX_IDNR_160	0x59F
#define 	 CANBUS_DISPLAY_RX_IDNR_161	0x5A0
#define 	 CANBUS_DISPLAY_RX_IDNR_162	0x5A1
#define 	 CANBUS_DISPLAY_RX_IDNR_163	0x5A2
#define 	 CANBUS_DISPLAY_RX_IDNR_164	0x5A3
#define 	 CANBUS_DISPLAY_RX_IDNR_165	0x5A4
#define 	 CANBUS_DISPLAY_RX_IDNR_166	0x5A5
#define 	 CANBUS_DISPLAY_RX_IDNR_167	0x5A6
#define 	 CANBUS_DISPLAY_RX_IDNR_168	0x5A7
#define 	 CANBUS_DISPLAY_RX_IDNR_169	0x5A8
#define 	 CANBUS_DISPLAY_RX_IDNR_170	0x5A9
#define 	 CANBUS_DISPLAY_RX_IDNR_171	0x5AA
#define 	 CANBUS_DISPLAY_RX_IDNR_172	0x5AB
#define 	 CANBUS_DISPLAY_RX_IDNR_173	0x5AC
#define 	 CANBUS_DISPLAY_RX_IDNR_174	0x5AD
#define 	 CANBUS_DISPLAY_RX_IDNR_175	0x5AE
#define 	 CANBUS_DISPLAY_RX_IDNR_176	0x5AF
#define 	 CANBUS_DISPLAY_RX_IDNR_177	0x5B0
#define 	 CANBUS_DISPLAY_RX_IDNR_178	0x5B1
#define 	 CANBUS_DISPLAY_RX_IDNR_179	0x5B2
#define 	 CANBUS_DISPLAY_RX_IDNR_180	0x5B3
#define 	 CANBUS_DISPLAY_RX_IDNR_181	0x5B4
#define 	 CANBUS_DISPLAY_RX_IDNR_182	0x5B5
#define 	 CANBUS_DISPLAY_RX_IDNR_183	0x5B6
#define 	 CANBUS_DISPLAY_RX_IDNR_184	0x5B7
#define 	 CANBUS_DISPLAY_RX_IDNR_185	0x5B8
#define 	 CANBUS_DISPLAY_RX_IDNR_186	0x5B9
#define 	 CANBUS_DISPLAY_RX_IDNR_187	0x5BA
#define 	 CANBUS_DISPLAY_RX_IDNR_188	0x5BB
#define 	 CANBUS_DISPLAY_RX_IDNR_189	0x5BC
#define 	 CANBUS_DISPLAY_RX_IDNR_190	0x5BD
#define 	 CANBUS_DISPLAY_RX_IDNR_191	0x5BE
#define 	 CANBUS_DISPLAY_RX_IDNR_192	0x5BF
#define 	 CANBUS_DISPLAY_RX_IDNR_193	0x5C0
#define 	 CANBUS_DISPLAY_RX_IDNR_194	0x5C1
#define 	 CANBUS_DISPLAY_RX_IDNR_195	0x5C2
#define 	 CANBUS_DISPLAY_RX_IDNR_196	0x5C3
#define 	 CANBUS_DISPLAY_RX_IDNR_197	0x5C4
#define 	 CANBUS_DISPLAY_RX_IDNR_198	0x5C5
#define 	 CANBUS_DISPLAY_RX_IDNR_199	0x5C6
#define 	 CANBUS_DISPLAY_RX_IDNR_200	0x5C7
#define 	 CANBUS_DISPLAY_RX_IDNR_201	0x5C8
#define 	 CANBUS_DISPLAY_RX_IDNR_202	0x5C9
#define 	 CANBUS_DISPLAY_RX_IDNR_203	0x5CA
#define 	 CANBUS_DISPLAY_RX_IDNR_204	0x5CB
#define 	 CANBUS_DISPLAY_RX_IDNR_205	0x5CC
#define 	 CANBUS_DISPLAY_RX_IDNR_206	0x5CD
#define 	 CANBUS_DISPLAY_RX_IDNR_207	0x5CE
#define 	 CANBUS_DISPLAY_RX_IDNR_208	0x5CF
#define 	 CANBUS_DISPLAY_RX_IDNR_209	0x5D0
#define 	 CANBUS_DISPLAY_RX_IDNR_210	0x5D1
#define 	 CANBUS_DISPLAY_RX_IDNR_211	0x5D2
#define 	 CANBUS_DISPLAY_RX_IDNR_212	0x5D3
#define 	 CANBUS_DISPLAY_RX_IDNR_213	0x5D4
#define 	 CANBUS_DISPLAY_RX_IDNR_214	0x5D5
#define 	 CANBUS_DISPLAY_RX_IDNR_215	0x5D6
#define 	 CANBUS_DISPLAY_RX_IDNR_216	0x5D7
#define 	 CANBUS_DISPLAY_RX_IDNR_217	0x5D8
#define 	 CANBUS_DISPLAY_RX_IDNR_218	0x5D9
#define 	 CANBUS_DISPLAY_RX_IDNR_219	0x5DA
#define 	 CANBUS_DISPLAY_RX_IDNR_220	0x5DB
#define 	 CANBUS_DISPLAY_RX_IDNR_221	0x5DC
#define 	 CANBUS_DISPLAY_RX_IDNR_222	0x5DD
#define 	 CANBUS_DISPLAY_RX_IDNR_223	0x5DE
#define 	 CANBUS_DISPLAY_RX_IDNR_224	0x5DF
#define 	 CANBUS_DISPLAY_RX_IDNR_225	0x5E0
#define 	 CANBUS_DISPLAY_RX_IDNR_226	0x5E1
#define 	 CANBUS_DISPLAY_RX_IDNR_227	0x5E2
#define 	 CANBUS_DISPLAY_RX_IDNR_228	0x5E3
#define 	 CANBUS_DISPLAY_RX_IDNR_229	0x5E4
#define 	 CANBUS_DISPLAY_RX_IDNR_230	0x5E5
#define 	 CANBUS_DISPLAY_RX_IDNR_231	0x5E6
#define 	 CANBUS_DISPLAY_RX_IDNR_232	0x5E7
#define 	 CANBUS_DISPLAY_RX_IDNR_233	0x5E8
#define 	 CANBUS_DISPLAY_RX_IDNR_234	0x5E9
#define 	 CANBUS_DISPLAY_RX_IDNR_235	0x5EA
#define 	 CANBUS_DISPLAY_RX_IDNR_236	0x5EB
#define 	 CANBUS_DISPLAY_RX_IDNR_237	0x5EC
#define 	 CANBUS_DISPLAY_RX_IDNR_238	0x5ED
#define 	 CANBUS_DISPLAY_RX_IDNR_239	0x5EE
#define 	 CANBUS_DISPLAY_RX_IDNR_240	0x5EF
#define 	 CANBUS_DISPLAY_RX_IDNR_241	0x5F0
#define 	 CANBUS_DISPLAY_RX_IDNR_242	0x5F1
#define 	 CANBUS_DISPLAY_RX_IDNR_243	0x5F2
#define 	 CANBUS_DISPLAY_RX_IDNR_244	0x5F3
#define 	 CANBUS_DISPLAY_RX_IDNR_245	0x5F4
#define 	 CANBUS_DISPLAY_RX_IDNR_246	0x5F5
#define 	 CANBUS_DISPLAY_RX_IDNR_247	0x5F6
#define 	 CANBUS_DISPLAY_RX_IDNR_248	0x5F7
#define 	 CANBUS_DISPLAY_RX_IDNR_249	0x5F8
#define 	 CANBUS_DISPLAY_RX_IDNR_250	0x5F9
#define 	 CANBUS_DISPLAY_RX_IDNR_251	0x5FA
#define 	 CANBUS_DISPLAY_RX_IDNR_252	0x5FB
#define 	 CANBUS_DISPLAY_RX_IDNR_253	0x5FC
#define 	 CANBUS_DISPLAY_RX_IDNR_254	0x5FD
#define 	 CANBUS_DISPLAY_RX_IDNR_255	0x5FE
#define 	 CANBUS_DISPLAY_RX_IDNR_256	0x5FF
#define CANBUS_DISPLAY_RX_END   	0x5FF


//typedef struct {
//	bool ID_Received;               //CANBUS Receive IRQ Callback Enable
//	uint32_t DataSize;         //CANBUS Receive IRQ Data length
//} CAN2_HandleData;
//extern CAN_HandleTypeDef Can2Handle;
//extern CAN2_HandleData Can_MSG;
//extern bool Can_MSG_ID_Received;
/*
typedef enum {
	CAN_USER_ID = 0,
	CAN_STATUS_LOGIN,
	CAN_STATUS_LOGOUT,
	CAN_LANGAUGE,
	// CAN_ENUM_Nr muss auf ein nachvollziebaren Namen geändert werden.
	CAN_ENUM_4,
	CAN_ENUM_5,
	CAN_ENUM_6,
	CAN_ENUM_7,
	CAN_ENUM_8,
	CAN_ENUM_9,
	CAN_ENUM_10,
	CAN_ENUM_11,
	CAN_ENUM_12,
	CAN_ENUM_13,
	CAN_ENUM_14,
	CAN_ENUM_15,
	CAN_ENUM_16,
	CAN_ENUM_17,
	CAN_ENUM_18,
	CAN_ENUM_19,
	CAN_ENUM_20,
	CAN_ENUM_21,
	CAN_ENUM_22,
	CAN_ENUM_23,
	CAN_ENUM_24,
	CAN_ENUM_25,
	CAN_ENUM_26,
	CAN_ENUM_27,
	CAN_ENUM_28,
	CAN_ENUM_29,
	CAN_ENUM_30,
	CAN_ENUM_31,
	CAN_ENUM_32,
	CAN_ENUM_33,
	CAN_ENUM_34,
	CAN_ENUM_35,
	CAN_ENUM_36,
	CAN_ENUM_37,
	CAN_ENUM_38,
	CAN_ENUM_39,
	CAN_ENUM_40,
	CAN_ENUM_41,
	CAN_ENUM_42,
	CAN_ENUM_43,
	CAN_ENUM_44,
	CAN_ENUM_45,
	CAN_ENUM_46,
	CAN_ENUM_47,
	CAN_ENUM_48,
	CAN_ENUM_49,
	CAN_ENUM_50,
	CAN_ENUM_51,
	CAN_ENUM_52,
	CAN_ENUM_53,
	CAN_ENUM_54,
	CAN_ENUM_55,
	CAN_ENUM_56,
	CAN_ENUM_57,
	CAN_ENUM_58,
	CAN_ENUM_59,
	CAN_ENUM_60,
	CAN_ENUM_61,
	CAN_ENUM_62,
	CAN_ENUM_63,
	CAN_ENUM_64,
	CAN_ENUM_65,
	CAN_ENUM_66,
	CAN_ENUM_67,
	CAN_ENUM_68,
	CAN_ENUM_69,
	CAN_ENUM_70,
	CAN_ENUM_71,
	CAN_ENUM_72,
	CAN_ENUM_73,
	CAN_ENUM_74,
	CAN_ENUM_75,
	CAN_ENUM_76,
	CAN_ENUM_77,
	CAN_ENUM_78,
	CAN_ENUM_79,
	CAN_ENUM_80,
	CAN_ENUM_81,
	CAN_ENUM_82,
	CAN_ENUM_83,
	CAN_ENUM_84,
	CAN_ENUM_85,
	CAN_ENUM_86,
	CAN_ENUM_87,
	CAN_ENUM_88,
	CAN_ENUM_89,
	CAN_ENUM_90,
	CAN_ENUM_91,
	CAN_ENUM_92,
	CAN_ENUM_93,
	CAN_ENUM_94,
	CAN_ENUM_95,
	CAN_ENUM_96,
	CAN_ENUM_97,
	CAN_ENUM_98,
	CAN_ENUM_99,
	CAN_ENUM_100,
	CAN_ENUM_101,
	CAN_ENUM_102,
	CAN_ENUM_103,
	CAN_ENUM_104,
	CAN_ENUM_105,
	CAN_ENUM_106,
	CAN_ENUM_107,
	CAN_ENUM_108,
	CAN_ENUM_109,
	CAN_ENUM_110,
	CAN_ENUM_111,
	CAN_ENUM_112,
	CAN_ENUM_113,
	CAN_ENUM_114,
	CAN_ENUM_115,
	CAN_ENUM_116,
	CAN_ENUM_117,
	CAN_ENUM_118,
	CAN_ENUM_119,
	CAN_ENUM_120,
	CAN_ENUM_121,
	CAN_ENUM_122,
	CAN_ENUM_123,
	CAN_ENUM_124,
	CAN_ENUM_125,
	CAN_ENUM_126,
	CAN_ENUM_127,
	CAN_ENUM_128,
	CAN_ENUM_129,
	CAN_ENUM_130,
	CAN_ENUM_131,
	CAN_ENUM_132,
	CAN_ENUM_133,
	CAN_ENUM_134,
	CAN_ENUM_135,
	CAN_ENUM_136,
	CAN_ENUM_137,
	CAN_ENUM_138,
	CAN_ENUM_139,
	CAN_ENUM_140,
	CAN_ENUM_141,
	CAN_ENUM_142,
	CAN_ENUM_143,
	CAN_ENUM_144,
	CAN_ENUM_145,
	CAN_ENUM_146,
	CAN_ENUM_147,
	CAN_ENUM_148,
	CAN_ENUM_149,
	CAN_ENUM_150,
	CAN_ENUM_151,
	CAN_ENUM_152,
	CAN_ENUM_153,
	CAN_ENUM_154,
	CAN_ENUM_155,
	CAN_ENUM_156,
	CAN_ENUM_157,
	CAN_ENUM_158,
	CAN_ENUM_159,
	CAN_ENUM_160,
	CAN_ENUM_161,
	CAN_ENUM_162,
	CAN_ENUM_163,
	CAN_ENUM_164,
	CAN_ENUM_165,
	CAN_ENUM_166,
	CAN_ENUM_167,
	CAN_ENUM_168,
	CAN_ENUM_169,
	CAN_ENUM_170,
	CAN_ENUM_171,
	CAN_ENUM_172,
	CAN_ENUM_173,
	CAN_ENUM_174,
	CAN_ENUM_175,
	CAN_ENUM_176,
	CAN_ENUM_177,
	CAN_ENUM_178,
	CAN_ENUM_179,
	CAN_ENUM_180,
	CAN_ENUM_181,
	CAN_ENUM_182,
	CAN_ENUM_183,
	CAN_ENUM_184,
	CAN_ENUM_185,
	CAN_ENUM_186,
	CAN_ENUM_187,
	CAN_ENUM_188,
	CAN_ENUM_189,
	CAN_ENUM_190,
	CAN_ENUM_191,
	CAN_ENUM_192,
	CAN_ENUM_193,
	CAN_ENUM_194,
	CAN_ENUM_195,
	CAN_ENUM_196,
	CAN_ENUM_197,
	CAN_ENUM_198,
	CAN_ENUM_199,
	CAN_ENUM_200,
	CAN_ENUM_201,
	CAN_ENUM_202,
	CAN_ENUM_203,
	CAN_ENUM_204,
	CAN_ENUM_205,
	CAN_ENUM_206,
	CAN_ENUM_207,
	CAN_ENUM_208,
	CAN_ENUM_209,
	CAN_ENUM_210,
	CAN_ENUM_211,
	CAN_ENUM_212,
	CAN_ENUM_213,
	CAN_ENUM_214,
	CAN_ENUM_215,
	CAN_ENUM_216,
	CAN_ENUM_217,
	CAN_ENUM_218,
	CAN_ENUM_219,
	CAN_ENUM_220,
	CAN_ENUM_221,
	CAN_ENUM_222,
	CAN_ENUM_223,
	CAN_ENUM_224,
	CAN_ENUM_225,
	CAN_ENUM_226,
	CAN_ENUM_227,
	CAN_ENUM_228,
	CAN_ENUM_229,
	CAN_ENUM_230,
	CAN_ENUM_231,
	CAN_ENUM_232,
	CAN_ENUM_233,
	CAN_ENUM_234,
	CAN_ENUM_235,
	CAN_ENUM_236,
	CAN_ENUM_237,
	CAN_ENUM_238,
	CAN_ENUM_239,
	CAN_ENUM_240,
	CAN_ENUM_241,
	CAN_ENUM_242,
	CAN_ENUM_243,
	CAN_ENUM_244,
	CAN_ENUM_245,
	CAN_ENUM_246,
	CAN_ENUM_247,
	CAN_ENUM_248,
	CAN_ENUM_249,
	CAN_ENUM_250,
	CAN_ENUM_251,
	CAN_ENUM_252,
	CAN_ENUM_253,
	CAN_ENUM_254,
	CAN_ENUM_255,
	CAN_ENUM_256,
	MAX_CAN_MSG
} CAN_MSG;
*/
//extern CAN_MSG msgType;

extern uint8_t TxData[8];
extern uint8_t RxData[8];
extern CAN_TxHeaderTypeDef TxHeader;
extern CAN_RxHeaderTypeDef RxHeader;
extern uint32_t TxMailbox;
//CAN_HandleData CanHandleSt;

extern void CAN_Send(int CAN_ID, uint8_t dlc, uint8_t *Pdata);
extern void CAN_Receive(CAN_HandleTypeDef *hcan);
/* USER CODE END Private defines */

void MX_CAN2_Init(void);

/* USER CODE BEGIN Prototypes */
void MX_CAN2_Init(void);
void CANx_Config(CAN_HandleTypeDef *hcan);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __CAN_H__ */
